 #include <iostream>
using namespace std;

template <class T>class TripleList;	// ��Ԫ�������
template <class T>
class Triple{
private:
    int row,col;					// ����Ԫ�ص��б���б�
    T val;							// ����Ԫ�ص�ֵ��TΪ�������ͣ�
public:
    friend class TripleList<T>;		// ��Ԫ��������ʹ����˽�г�Ա
    // ��Ԫ���߱������ԣ��ظ���������/���������Ϊ���ܷ���Triple˽�г�Ա��
    Triple(){}
    Triple(int r,int c,T v)
	{
         row = r;   col = c;   val = v;
    }
}; // ��Ԫ���ඨ��

template <class T>
class TripleList{
private:
    Triple<T> *data;		// dataָ������һ������Ԫ���׵�ַ
    int rows,cols,nums;    	// ���������бꡢ�б��Լ�����Ԫ�ظ���
    int maxSize;			// �������ռ�
public:
    TripleList(int size = 40);				// �����ʼ��
    ~TripleList() { delete []data; }		// ��������    
    bool Insert(Triple<T> value);			// ����һ��Ԫ�أ��ô˺����ɽ�������
    void Transpose(TripleList<T> &M);		// ����ת��
    void FastTranspose(TripleList<T> &M);	// ��һ�־���ת�÷��� 
	void CreateList();						// ����һ����Ԫ���
	void Traverse()const;					// �����Ԫ���������Ԫ�ص�ֵ
}; // ��Ԫ��˳����ඨ��
template<class T>
void TripleList<T>::Traverse()const
{ //������������һ��ϡ�����
	cout<<"����һ��"<<rows<<"X"<<cols<<"��ϡ�����������"<<nums<<"������Ԫ�أ�"<<endl;
	cout<<"����"<<"  "<<"����"<<"   "<<"ֵ"<<endl;
    for(int i = 0; i < nums; i++)
	{
        cout<<data[i].row<<"      "<<data[i].col<<"      "<<data[i].val<<endl;
	}   
}

template <class T>
void TripleList<T>::Transpose(TripleList<T> &M)
{ // ϡ�����ת�ã���Ԫ�ص�����λ�öԻ�
   if(nums) 
   { // ����Ƿǿվ��������ת�ò���
        M.data = new Triple<T>[nums];  // MΪת�ú�ľ����Ƚ��г�ʼ��
        M.rows = cols;  M.cols = rows;
        for(int c = 0; c < cols; ++ c)
		{   // ���кŴ�С����ɨ�����е���
            for(int p = 0; p < nums; p++)
			{// ���к�Ϊc����Ԫ�����л���
                if(data[p].col == c)
				{// ��Ԫ���б���б꽻��
                      Triple<T> t;
                      t.row = data[p].col;
                      t.col = data[p].row;
                      t.val = data[p].val;
                      M.Insert(t);  // ��ת�ú�Ԫ�ز��뵽M��
                 }
			}
		}
   }
}


template<class T>
TripleList<T>::TripleList(int size):maxSize(size)
{ // ���캯������ʼ��һ����Ԫ��
    data = new Triple<T>[maxSize];
    rows = cols = nums = 0;
}

template <class T>
bool TripleList<T>::Insert(Triple<T> value)
{ // �����е���Ԫ���β����һ����Ԫ�飬������һ���������Ԫ��
    if(nums >= maxSize){ // �ռ��������޷�����
        return false;
    }
    if(value.row > rows-1 || value.row < 0 || value.col > cols-1 || value.col < 0){ 
         // ����Ԫ�ص����б곬��Χ���޷�����
       return false;
    }
    data[nums++] = value;	// ������Ԫ׷�ӵ���Ԫ����β
    return true;
}
template <class T>
void TripleList<T>::FastTranspose(TripleList<T> &M)
{ // �Ľ����ת���㷨
   if(nums) 
   {
        M.data = new Triple<T>[nums];
        M.rows = cols;  M.cols = rows;
		int *num = new int[cols], *cpot = new int[cols]; // �����������ռ�
        int c,p;
        for(c = 0; c < cols; ++c)
		{ // num����������Ԫ����0
            num[c] = 0;
        }
        for(p = 0; p < nums; ++p)
		{ // num����Ӧ�еķ���������ͳ��
            num[data[p].col]++; 
        }
        cpot[0] = 0;
        for(c = 1; c < cols; ++c) 
        { // ����ÿ�е�һ��Ԫ����M�е�λ������cpot
			cpot[c] = cpot[c-1] + num[c-1];
        }
       for(p = 0; p < nums; ++p)
	   { //ÿ������Ԫ�����л���������ת��
            c = cpot[data[p].col];  //cΪdata�е�ǰԪ����M��λ��
            M.data[c].row = data[p].col;  
            M.data[c].col = data[p].row;
            M.data[c].val = data[p].val;
            cpot[data[p].col]++;  // ͬ�е���һ��Ԫ����M��λ��
        }
       M.nums = nums;
   }

}

template<class T>
void TripleList<T>::CreateList()
{ // ����һ��ϡ�����
    int r,c,n;
    cout<<"����ϡ������������";   cin>>r;
    cout<<"����ϡ������������";   cin>>c;
    cout<<"����ϡ�����ķ���Ԫ������";   cin>>n;
    nums=n;   rows=r;   cols=c;
    cout<<"����"<<nums<<"��Ԫ�ص���Ԫ������ֵ��(���б��0��ʼ)"<<endl;
    int i=0;
    while(i<nums) 
	{
        cin>>data[i].row>>data[i].col>>data[i].val;
        if(data[i].row >= r || data[i].col >= c) 
		{
			cout<<"�б���б���������������������ȷ��ֵ:"<<endl;
            continue; 
        }
        ++i;
    }
} 
	int main ()
	{
	TripleList<int>	s1,s2;
	
	s1.CreateList();
	cout<<"ԭ��Ԫ��"<<endl; 

	s1.Traverse();
	s1.FastTranspose(s2); 
		cout<<"ת�ú���Ԫ��"<<endl; 
		s2.Traverse(); 
		
		
		return 0;
	 } 
