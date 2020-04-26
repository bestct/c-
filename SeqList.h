#include <iostream>
using namespace std;

template <class T>
class SeqList {
private:       
	T  *element;				// 顺序表项数据类型为T
	int maxSize;				// 最大允许长度 
	int length;					// 顺序表长度，即表中数据元素个数
public: 
	SeqList ( int size = 14 );	// 构造函数，默认为一个长度为10的空表
	~SeqList ( ) { delete []element; length =0; }       // 析构函数 
	bool Insert ( int k, const T &val ) ;				// 在第k个元素前插入值为val的元素
	bool Remove ( int k, T  &val);					// 删除表中第k个元素 
	void CreateList ( );							// 输入线性表 
	void Traverse( );	
	MergeList(const SeqList<T> &La, const SeqList<T> &Lb);							// 输出线性表 
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
{// 初始条件：顺序表已存在

  // 操作结果：若1≤k ≤length+1，且length≠maxSize，则在表中第k个元素前插入一个值为val的元素，函数返回true；否则，操作失败，返回false

    if (k<1 || k>length+1) { // 插入位置错误
       cout<<"theposition is not right!";   
       return false;
     }

    if (length == maxSize){ // 上溢
       cout<<"thelist is overflow!";
       return false;
    } 

    for(int i= length-1; i>= k-1; --i){ // 数据元素后移
         element[i+1]= element[i]; 
     } 

    element[k-1] = val;                       // 新数据元素插入到指定位置
    ++length;                                 // 表长增1
    return true;
}
template <class T>
void SeqList<T>::Traverse()
{ //初始条件：顺序表L已存在
  //操作结果：用输出流输出顺序表L中所有元素	
	cout<<"输出顺序表L中所有元素值："<<endl;
	for(int i = 0; i < length; ++i)
	{
		cout<<element[i]<<"   ";
	}
	cout<<endl;
}
template <class T>
bool SeqList<T>::Remove(int k, T &val)
{ // 初始条件：顺序表已存在
  // 操作结果：若≤k≤length，且表非空，则val返回顺序表中第k个元素值后将该元素删除，函数返回true；否则，操作失败，函数返回0
    if (k < 1 || k > length)  { // 删除位置超范围
        cout<<"the position is not right!";   return false;
     } 
    if (IsEmpty()) { // 空表不能删除元素
        cout<<"the list is empty!";    return false; 	
    }	
    val = element[k - 1];
    for(int i = k; i < length - 1;++i)
    { // 从删除的元素后1元素到表尾元素依次前移
		element[i - 1] = element[i];		
    }    					 
    --length;			// 表长减1
    return true;
}

template<class T>
void SeqList<T>::MergeList(const SeqList<T> &La, const SeqList<T> &Lb)
{ // 将非递减有序顺序表表 La 和 Lb 合并产生一个新表，即 Lc 也非递减有序
 
int La_length, Lb_length, i = 1, j = 1, k = 0; // k 为 Lc 中插入元素的位置
 
T tmpa,tmpb;
 
La_length = La.Length(); 
Lb_length = Lb.Length();
 
while ( i <= La_length && j <= Lb_length) { // La 与 Lb 均不为空
 
 
// tmpa 为 La 中第 i 个数据元素值，tmpb 为 Lb 中第 j 个数据元素值
tmpa = *La.getData(i); 
tmpb = *Lb.getData(j);
 
// 元素较小值插入到 Lc 中，指示器增 1
if (tmpa <= tmpb ) { 
Insert(++k,tmpa); 
++i;
}
 
else {
Insert(++k,tmpb); 
++j;
}
 
}
 
// 表中剩余数据的插入
 
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

