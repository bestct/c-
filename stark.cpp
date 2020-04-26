#include<iostream>
using namespace std;
#define END 999
template <class T> 
class SeqStack {    
private: T *theArray;			// theArrayΪ�����ռ��׵�ַ 
	int top;                    // topΪջ��Ԫ��λ��ָʾ�� 
    int maxSize;				// ˳��ջ����������ռ�
public: 
	SeqStack (int sz = 20 ) 
	{ // ����һ����ջ 
       maxSize = sz;   
	   theArray  = new T[maxSize];   
	   top = -1;   
	} 
    ~SeqStack(){delete [  ]theArray; }					// ��������
	bool Push (const T val);							// ջδ������Ԫ��val��ջ
	bool Pop (T &val );									// ջ���գ�����ջ��Ԫ�ظ���val
    bool GetTop (T &val  )const;						// ջ���գ�val����ջ��Ԫ��ֵ 
    bool IsEmpty ( ) const{  return top == -1;}			// ��ջ�� 
    bool IsFull ( ) const{ return  top == maxSize - 1;}		// ��ջ�� 
    void Traverse ( )const;								// ��ջ����ջ���������Ԫ��   
}; // ˳��ջ�ඨ��
template<class T>
bool SeqStack<T>::GetTop(T &val)const
{ // ȡջ��Ԫ�أ���ջ�գ������ʧ�ܣ�
	if (IsEmpty())
	{ 
		cout<<"ջ���磬����ʧ�ܣ�"<<endl;    
		return false; 
	}
	val = theArray[top];   
	return true;

} // �㷨��ʱ�临�ӵ�ΪO��1��
template<class T>
bool SeqStack<T>::Push(const T val)
{ // ��ջ�������磬�����ʧ�ܣ�
	if (IsFull())
	{ 
		cout<<"ջ���磬����ʧ�ܣ�"<<endl;    
		return false; 
	}
	theArray[++top]= val;   
	return true;

} // �㷨��ʱ�临�ӵ�ΪO��1��
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
		cout << "��ջ" << endl;
		return false;
	}
	cout<<"��ջ"<<endl; 
	val =theArray[top--] ;
	return true;
}
void conversion()
{  //���������һ���Ǹ�ʮ������������ӡ�����ֵ�İ˽�����
     SeqStack<int> S;
      int N,e;
     cout<<"����һ��ʮ��������";    cin>>N;
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

