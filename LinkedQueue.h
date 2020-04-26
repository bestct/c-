#include<iostream>
using namespace std;


template <class T> class LinkedQueue;
template<class T>
class Node{
private:
	T data;
	Node<T> *link;
public:
	Node(Node *ptr = NULL):link(ptr){}
	Node(T val, Node *ptr = NULL):data(val),link(ptr){}
	friend class LinkedQueue<T>;
};

template<class T>
class LinkedQueue{
public:
    LinkedQueue():rear(NULL),front(NULL){}       // 构造函数（空链队列没有头结点）
    ~LinkedQueue(){MakeEmpty();}                 // 析构函数
    void EnQueue(const T& val);                  // 进队列
    bool DeQueue(T& val);                        // 出队列
    bool GetFront(T& val)const;                  // 取队头元素
    void MakeEmpty();                            // 置空队列
    bool IsEmpty()const{return front == NULL;}   // 判队列空      
    int Length()const;                           // 求队列中元素个数
	void Traverse()const;
public:
    Node<T> *front,*rear;						 // 比单向链表多设置一个指针
}; // 链式队列的类定义
template<class T>
void LinkedQueue<T>::MakeEmpty()
{
	Node<T> *p;
	while(front)
	{
		p = front;
		front = front->link;
		delete p;
	}
}

template<class T>
int LinkedQueue<T>::Length()const
{
	int counter = 0;
	Node<T> *p = front;
	while(p)
	{
		++counter;
		p = p->link;
	}
	return counter;
}

template<class T>
void LinkedQueue<T>:: EnQueue ( const T &val)
{ // 将新元素x插入到队列的队尾
	if ( front == NULL ) 
	{ // 如果是空队列，则插入元素为队头元素
        front= rear = new Node<T> (val);
	}
	else 
	{ // 否则，在队尾插入元素。假设内存足够大，不用判断上溢
       rear->link = new Node<T>( val);   
	   rear=rear->link;
    }
} // 算法的时间复杂点为O（1）


template<class T>
bool LinkedQueue<T>::DeQueue (T& val)
{ // 删去队头结点，并返回队头元素的值
	if (IsEmpty ( ) ) 
	{ // 队列空不能删除
		return false;
	} 
	Node<T> *p = front;      
	val= p->data;        // 保存队头的值
	front = front->link;    
	delete p;             // front是新队头
	if (!front) 
	{ // 如果队列删空，rear指针重新定位
		rear = front;
	}  
    return true;             
} // 算法的时间复杂点为O（1）

template<class T>
bool LinkedQueue<T>::GetFront(T &val)const
{ // 删去队头结点，并返回队头元素的值
	if (IsEmpty ( ) ) 
	{ // 队列空不能取元素
		return false;
	} 
	val= front->data;        
    return true;             
} // 算法的时间复杂点为O（1）
template<class T>
 void LinkedQueue<T>::Traverse()const
{
	
		cout<<"data in this queue is: "<<endl;
	Node<T> *p,*q=front;
	while(q)
	{
		p = q;
		cout<<q->data<<"   ";
		q = q->link;
	//	delete p;
	}	
	
}
