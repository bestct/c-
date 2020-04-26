#include<iostream>
 using namespace std;
 //#define NULL 0
template<class T> class LinkList;
template <class T>
class Node{
	private:
		T data;
		Node<T> *link;
	public:
		Node(Node *ptr=NULL):link(ptr){
		}
		Node(T val,Node *ptr=NULL):data(val),link(ptr){
		}			
	friend class LinkList<T>;
	
	
	
};
template<class T>
class LinkList{
	private:
		Node<T> *first;
		int length;
	
	public:
	LinkList();	
//	~LinkList(){
//		MakeEmpty();
//		delete first;
//	}
	bool MakeEmpty();
	bool IsEmpty(){
		return first->link==NULL;
	}
	bool Insert(int k, const T &val); 
	 void CreateList1(int n);
	void CreateList2(int n);
	bool Remove(int,T &val);
	bool Find(int k,T &val);
	void Traverse();
	bool Change(int k);
		
};
template<class T>
LinkList<T>::LinkList()
{
	first=new Node<T>();
	length=0;
	
 } 
 

template <class T>
void LinkList<T>::CreateList2(int n)
{//后插法建立链表
	int i = 1;
	Node<T> *p,*q = first;
	T val;
	while(i <= n)
	{
		cout<<"input the "<<i<<"th data:";
		cin>>val;
		p = new Node<T>(val);
		q->link = p;
		q = p;
		++i;
	}
	length = n;
}
template <class T>
void LinkList<T>::CreateList1(int n)
{//前插法 
	int i=1;
	 Node<T> *p;
	T val;
	while(i <= n)
	{
		cout<<"input the "<<i<<"th data:";
		cin>>val;
		p = new Node<T>(val);
		p->link=first->link;
		first->link=p; 
		i++;
	 } 
	
	length = n;
}
template<class T>
bool LinkList<T>::Insert(int k,const T &val)
{
	if(k>length+1||k<1)
	{
	cout<<"插入错误";
	return false; 
		
		
	}
	Node<T> *p=first,*ptr;
	int i=0;
	 while(p!=NULL&&i<k-1){
	 	p=p->link;
	 	i++;
	 	
	 }
	 ptr=new Node<T>(val);
	 ptr->link=p->link;
	 p->link=ptr;
	length++;
	return true;
}
template<class T>
bool LinkList<T>::Change(int k)
{	T a; int i=0;
	if(k>length||k<1)
	{
		cout<<"更改错误";
		return false; 
		
	}

		cout<<"请输入第个"<<k<<"想改变成的值:" ;	
		cin>>a;
		Node<T> *p=first;
		while(p!=NULL&&i<k)
		{
			p=p->link;
			i++;
		}
	
	p->data=a;
	return true;
}	
template<class T>
bool LinkList<T>::Find(int k,T &val)
{
	if(k>length+1||k<1)
	{
	cout<<"查找错误";
	return false; 
		
		
	}
	int i=0; 
	Node<T> *p=first;
	while(p!=NULL&&i<k)
	{
		p=p->link;
		i++;
		
	}
	val=p->data;
	return true;
}
template<class T>
void LinkList<T>::Traverse()
{
	Node<T>*p=first->link;
	while(p!=NULL)
	{
		cout<<p->data<<"  ";
		p=p->link;
	}
	
 } 
 template<class T>
bool LinkList<T>::MakeEmpty(){
	if(IsEmpty())
	{
		cout<<"已空";
		return false; 
	}
	else
	{
	Node<T> *p=first->link;	
		while(p!=NULL)
		{
			first->link=p->link;
			delete p;
			p=first->link;
			
		}
		cout<<"已删除"; 
		return true;
	}
	
}
int main()
{
	LinkList<int> l1;
//	int i;
//	for(i=1;i<=10;i++) 
//	{
//		l1.Insert(1,i);
//		
//	}
//	
	l1.CreateList2(10);
	l1.Insert(4,100);
	l1.Traverse();
//	int l;
//	l1.Change(3);
//	l1.Find(1,l);
//	cout<<"查找第"<<i<<"个数是"<<l; 

//	l1.MakeEmpty();
	
return 0;	
}


