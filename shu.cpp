 #include <iostream>
using namespace std;

template <class T>class TripleList;	// 三元组表声明
template <class T>
class Triple{
private:
    int row,col;					// 非零元素的行标和列标
    T val;							// 非零元素的值（T为抽象类型）
public:
    friend class TripleList<T>;		// 三元组表类可以使用其私有成员
    // 友元不具备传递性，重复申明输入/输出流函数为了能访问Triple私有成员。
    Triple(){}
    Triple(int r,int c,T v)
	{
         row = r;   col = c;   val = v;
    }
}; // 三元组类定义

template <class T>
class TripleList{
private:
    Triple<T> *data;		// data指向矩阵第一个非零元素首地址
    int rows,cols,nums;    	// 矩阵的最大行标、列标以及非零元素个数
    int maxSize;			// 定义最大空间
public:
    TripleList(int size = 40);				// 矩阵初始化
    ~TripleList() { delete []data; }		// 析构函数    
    bool Insert(Triple<T> value);			// 插入一个元素，用此函数可建立矩阵
    void Transpose(TripleList<T> &M);		// 矩阵转置
    void FastTranspose(TripleList<T> &M);	// 另一种矩阵转置方法 
	void CreateList();						// 建立一个三元组表
	void Traverse()const;					// 输出三元组表中所有元素的值
}; // 三元组顺序表类定义
template<class T>
void TripleList<T>::Traverse()const
{ //重载输出流输出一个稀疏矩阵
	cout<<"这是一个"<<rows<<"X"<<cols<<"的稀疏矩阵，它共有"<<nums<<"个非零元素！"<<endl;
	cout<<"行数"<<"  "<<"列数"<<"   "<<"值"<<endl;
    for(int i = 0; i < nums; i++)
	{
        cout<<data[i].row<<"      "<<data[i].col<<"      "<<data[i].val<<endl;
	}   
}

template <class T>
void TripleList<T>::Transpose(TripleList<T> &M)
{ // 稀疏矩阵转置，即元素的行列位置对换
   if(nums) 
   { // 如果是非空矩阵，则进行转置操作
        M.data = new Triple<T>[nums];  // M为转置后的矩阵，先进行初始化
        M.rows = cols;  M.cols = rows;
        for(int c = 0; c < cols; ++ c)
		{   // 按列号从小到大扫描所有的列
            for(int p = 0; p < nums; p++)
			{// 将列号为c的三元组行列互换
                if(data[p].col == c)
				{// 将元素行标和列标交换
                      Triple<T> t;
                      t.row = data[p].col;
                      t.col = data[p].row;
                      t.val = data[p].val;
                      M.Insert(t);  // 将转置后元素插入到M中
                 }
			}
		}
   }
}


template<class T>
TripleList<T>::TripleList(int size):maxSize(size)
{ // 构造函数，初始化一个三元组
    data = new Triple<T>[maxSize];
    rows = cols = nums = 0;
}

template <class T>
bool TripleList<T>::Insert(Triple<T> value)
{ // 在已有的三元组表尾加入一个三元组，即插入一个矩阵非零元素
    if(nums >= maxSize){ // 空间已满，无法插入
        return false;
    }
    if(value.row > rows-1 || value.row < 0 || value.col > cols-1 || value.col < 0){ 
         // 插入元素的行列标超范围，无法插入
       return false;
    }
    data[nums++] = value;	// 将非零元追加到三元组表表尾
    return true;
}
template <class T>
void TripleList<T>::FastTranspose(TripleList<T> &M)
{ // 改进后的转置算法
   if(nums) 
   {
        M.data = new Triple<T>[nums];
        M.rows = cols;  M.cols = rows;
		int *num = new int[cols], *cpot = new int[cols]; // 辅助数组分配空间
        int c,p;
        for(c = 0; c < cols; ++c)
		{ // num数组中所有元素清0
            num[c] = 0;
        }
        for(p = 0; p < nums; ++p)
		{ // num中相应列的非零数个数统计
            num[data[p].col]++; 
        }
        cpot[0] = 0;
        for(c = 1; c < cols; ++c) 
        { // 设置每列第一个元素在M中的位置数组cpot
			cpot[c] = cpot[c-1] + num[c-1];
        }
       for(p = 0; p < nums; ++p)
	   { //每个非零元素行列互换，进行转置
            c = cpot[data[p].col];  //c为data中当前元素在M中位置
            M.data[c].row = data[p].col;  
            M.data[c].col = data[p].row;
            M.data[c].val = data[p].val;
            cpot[data[p].col]++;  // 同列的下一个元素在M中位置
        }
       M.nums = nums;
   }

}

template<class T>
void TripleList<T>::CreateList()
{ // 建立一个稀疏矩阵
    int r,c,n;
    cout<<"输入稀疏矩阵的行数：";   cin>>r;
    cout<<"输入稀疏矩阵的列数：";   cin>>c;
    cout<<"输入稀疏矩阵的非零元个数：";   cin>>n;
    nums=n;   rows=r;   cols=c;
    cout<<"输入"<<nums<<"个元素的三元组数据值：(行列标从0开始)"<<endl;
    int i=0;
    while(i<nums) 
	{
        cin>>data[i].row>>data[i].col>>data[i].val;
        if(data[i].row >= r || data[i].col >= c) 
		{
			cout<<"行标或列标输入有误，请重新输入正确的值:"<<endl;
            continue; 
        }
        ++i;
    }
} 
	int main ()
	{
	TripleList<int>	s1,s2;
	
	s1.CreateList();
	cout<<"原三元表"<<endl; 

	s1.Traverse();
	s1.FastTranspose(s2); 
		cout<<"转置后三元表"<<endl; 
		s2.Traverse(); 
		
		
		return 0;
	 } 
