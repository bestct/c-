#include<iostream>
using namespace std;
 template<class T>
 class SeqList{
 	private:
 		T *element;
		 int maxSize;
		 int length; 
 	public:
 		SeqList(int size=10);
 		~SeqList(){delete []element ;length=0;	 }
 		bool Insert(int k,const T &val);
 		bool Remove(int k,T &val);
 		void CreateList();
 		void Traverse();
 		bool find(T k,int a[],int &j);
 		bool change(int k,const T &val);
 	
 	
 	
 };
 template <class T>
 SeqList<T>::SeqList(int size)
 {	
 	maxSize=size;
 	element=new T [maxSize];
 	length=0;
 	
 
 }
 template <class T>
bool SeqList<T>::Insert(int k,const T &val)
{
	if(k>length+1||k<1)
	{
		cout<<"²Ù×÷´íÎó"<<endl;
		return false; 
		
	}
	if(length==maxSize)
	{
		cout<<"ÉÏÒç"<<endl;
		return false; 
	}
	int i;
	for(i=length-1;i>k-1;i--)
	{
		element[i+1]=element[i];
		
	}
	element[k-1]=val;
	length++;
	return true;
}
template <class T>
bool SeqList<T>::Remove(int k,T &val)
 {
 	if(k>length+1||k<1)
	 {
	 	cout<<"É¾³ý´íÎó"<<endl;
		 return false; 
	 	
	} 
	if(length==0){
		cout<<"¿Õ±í"<<endl;
		return false; 
		
	}
	val=element[k-1];
	int i;
	for(i=k-1;i<length-1;i++)
	{
		element[i]=element[i+1]; 
	
	} 
 	length--;
 	return true;
 }
 template <class T>
bool SeqList<T>::change(int k,const T &val)
 {
 	if(k>length+1||k<1)
	 {
	 	cout<<"¸ü¸Ä´íÎó"<<endl;
		 return false; 
	 	
	} 
	if(length==0){
		cout<<"¿Õ±í"<<endl;
		return false; 
		
	}
	element[k-1]=val; 
 	return true;
 }
 template <class T>
bool SeqList<T>::find(T k,int a[],int &j)
 {

	if(length==0){
		cout<<"¿Õ±í"<<endl;
		return false; 
		
	}
	
	int i;
	 j=0;
	for(i=0;i<length;i++)
	{		
		if(k==element[i]) 
		{
			a[j]=i+1;
			j++;
		}
	
	} 
  
 	return true;
 }
 template<class T>
 void SeqList<T>::Traverse()
 {	
 		if(length==0)
 		{
 			cout<<"¿Õ±í"<<endl;
 			
		 }
 	int i;
 	for(i=0;i<length;i++)
 	{
 		cout<<element[i]<<"  ";
 		
 		
	 }
	 cout<<endl;
 	
  } 
 
 
 
 
 
 
 
 
 
 
