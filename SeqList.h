#include <iostream>
using namespace std;

template <class T>
class SeqList {
private:       
	T  *element;				// ˳�������������ΪT
	int maxSize;				// ��������� 
	int length;					// ˳����ȣ�����������Ԫ�ظ���
public: 
	SeqList ( int size = 14 );	// ���캯����Ĭ��Ϊһ������Ϊ10�Ŀձ�
	~SeqList ( ) { delete []element; length =0; }       // �������� 
	bool Insert ( int k, const T &val ) ;				// �ڵ�k��Ԫ��ǰ����ֵΪval��Ԫ��
	bool Remove ( int k, T  &val);					// ɾ�����е�k��Ԫ�� 
	void CreateList ( );							// �������Ա� 
	void Traverse( );	
	MergeList(const SeqList<T> &La, const SeqList<T> &Lb);							// ������Ա� 
};
template <class T>
SeqList<T>::SeqList ( int size )
{
	maxSize = size;
	length = 0;
	element = new T[maxSize];
}
template <class T>
bool SeqList<T>::Insert( int k, const T &val )
{// ��ʼ������˳����Ѵ���

  // �����������1��k ��length+1����length��maxSize�����ڱ��е�k��Ԫ��ǰ����һ��ֵΪval��Ԫ�أ���������true�����򣬲���ʧ�ܣ�����false

    if (k<1 || k>length+1) { // ����λ�ô���
       cout<<"theposition is not right!";   
       return false;
     }

    if (length == maxSize){ // ����
       cout<<"thelist is overflow!";
       return false;
    } 

    for(int i= length-1; i>= k-1; --i){ // ����Ԫ�غ���
         element[i+1]= element[i]; 
     } 

    element[k-1] = val;                       // ������Ԫ�ز��뵽ָ��λ��
    ++length;                                 // ����1
    return true;
}
template <class T>
void SeqList<T>::Traverse()
{ //��ʼ������˳���L�Ѵ���
  //�������������������˳���L������Ԫ��	
	cout<<"���˳���L������Ԫ��ֵ��"<<endl;
	for(int i = 0; i < length; ++i)
	{
		cout<<element[i]<<"   ";
	}
	cout<<endl;
}
template <class T>
bool SeqList<T>::Remove(int k, T &val)
{ // ��ʼ������˳����Ѵ���
  // �������������k��length���ұ�ǿգ���val����˳����е�k��Ԫ��ֵ�󽫸�Ԫ��ɾ������������true�����򣬲���ʧ�ܣ���������0
    if (k < 1 || k > length)  { // ɾ��λ�ó���Χ
        cout<<"the position is not right!";   return false;
     } 
    if (IsEmpty()) { // �ձ���ɾ��Ԫ��
        cout<<"the list is empty!";    return false; 	
    }	
    val = element[k - 1];
    for(int i = k; i < length - 1;++i)
    { // ��ɾ����Ԫ�غ�1Ԫ�ص���βԪ������ǰ��
		element[i - 1] = element[i];		
    }    					 
    --length;			// ����1
    return true;
}

template<class T>
void SeqList<T>::MergeList(const SeqList<T> &La, const SeqList<T> &Lb)
{ // ���ǵݼ�����˳���� La �� Lb �ϲ�����һ���±��� Lc Ҳ�ǵݼ�����
 
int La_length, Lb_length, i = 1, j = 1, k = 0; // k Ϊ Lc �в���Ԫ�ص�λ��
 
T tmpa,tmpb;
 
La_length = La.Length(); 
Lb_length = Lb.Length();
 
while ( i <= La_length && j <= Lb_length) { // La �� Lb ����Ϊ��
 
 
// tmpa Ϊ La �е� i ������Ԫ��ֵ��tmpb Ϊ Lb �е� j ������Ԫ��ֵ
tmpa = *La.getData(i); 
tmpb = *Lb.getData(j);
 
// Ԫ�ؽ�Сֵ���뵽 Lc �У�ָʾ���� 1
if (tmpa <= tmpb ) { 
Insert(++k,tmpa); 
++i;
}
 
else {
Insert(++k,tmpb); 
++j;
}
 
}
 
// ����ʣ�����ݵĲ���
 
while (i <= La_length) {
Insert(++k,*La.getData(i));
i++;
} 
 
while (j <= Lb_length) {
Insert(++k,*Lb.getData(j)); 
j++;
}
return; 
}

