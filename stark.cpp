#include<iostream>
using namespace std;
#define END 999
template <class T> 
class SeqStack {    
private: T *theArray;			// theArray为连续空间首地址 
	int top;                    // top为栈顶元素位序指示器 
    int maxSize;				// 顺序栈所允许的最大空间
public: 
	SeqStack (int sz = 20 ) 
	{ // 建立一个空栈 
       maxSize = sz;   
	   theArray  = new T[maxSize];   
	   top = -1;   
	} 
    ~SeqStack(){delete [  ]theArray; }					// 析构函数
	bool Push (const T val);							// 栈未满，将元素val进栈
	bool Pop (T &val );									// 栈不空，弹出栈顶元素赋予val
    bool GetTop (T &val  )const;						// 栈不空，val保存栈顶元素值 
    bool IsEmpty ( ) const{  return top == -1;}			// 判栈空 
    bool IsFull ( ) const{ return  top == maxSize - 1;}		// 判栈满 
    void Traverse ( )const;								// 自栈顶到栈底输出所有元素   
}; // 顺序栈类定义
template<class T>
bool SeqStack<T>::GetTop(T &val)const
{ // 取栈顶元素（若栈空，则操作失败）
	if (IsEmpty())
	{ 
		cout<<"栈下溢，操作失败！"<<endl;    
		return false; 
	}
	val = theArray[top];   
	return true;

} // 算法的时间复杂点为O（1）
template<class T>
bool SeqStack<T>::Push(const T val)
{ // 进栈（若上溢，则操作失败）
	if (IsFull())
	{ 
		cout<<"栈上溢，操作失败！"<<endl;    
		return false; 
	}
	theArray[++top]= val;   
	return true;

} // 算法的时间复杂点为O（1）
template<class T>
 void SeqStack<T>::Traverse ( )const{
 	int i=top;
 	while(i!=-1){
	 
 cout<<theArray[i]<<endl;
 i--;
}
 }
//#include "string.h"

template<class T>
bool SeqStack<T>::Pop(T &val){
	if (IsEmpty())
	{
		cout << "空栈" << endl;
		return false;
	}
	cout<<"出栈"<<endl; 
	val =theArray[top--] ;
	return true;
}
void conversion()
{  //输入的任意一个非负十进制整数，打印输出等值的八进制数
     SeqStack<int> S;
      int N,e;
     cout<<"输入一个十进制数：";    cin>>N;
     while ( N ) 
	 {
         S.Push(N % 8);    
         N=N/8; 
     }
     while(!S.IsEmpty()) 
	 {
        S.Pop(e);
        cout<<e; 
     }
     cout<<endl;
     return;
}

int main()
{
	//conversion();
	SeqStack<int> s;
	int val;
	cout<<"input the data to stack:"<<endl;
cin>>val;
s.Push(val);

	while(val != END)
	{		
		s.Push(val);
		cin>>val;
	}
	//s.Traverse();
//	s.Pop(val);
//	//s.Pop(val);
	s.Traverse();
	return 1;
}

