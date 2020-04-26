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
    LinkedQueue():rear(NULL),front(NULL){}       // ���캯������������û��ͷ��㣩
    ~LinkedQueue(){MakeEmpty();}                 // ��������
    void EnQueue(const T& val);                  // ������
    bool DeQueue(T& val);                        // ������
    bool GetFront(T& val)const;                  // ȡ��ͷԪ��
    void MakeEmpty();                            // �ÿն���
    bool IsEmpty()const{return front == NULL;}   // �ж��п�      
    int Length()const;                           // �������Ԫ�ظ���
	void Traverse()const;
public:
    Node<T> *front,*rear;						 // �ȵ������������һ��ָ��
}; // ��ʽ���е��ඨ��
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
{ // ����Ԫ��x���뵽���еĶ�β
	if ( front == NULL ) 
	{ // ����ǿն��У������Ԫ��Ϊ��ͷԪ��
        front= rear = new Node<T> (val);
	}
	else 
	{ // �����ڶ�β����Ԫ�ء������ڴ��㹻�󣬲����ж�����
       rear->link = new Node<T>( val);   
	   rear=rear->link;
    }
} // �㷨��ʱ�临�ӵ�ΪO��1��


template<class T>
bool LinkedQueue<T>::DeQueue (T& val)
{ // ɾȥ��ͷ��㣬�����ض�ͷԪ�ص�ֵ
	if (IsEmpty ( ) ) 
	{ // ���пղ���ɾ��
		return false;
	} 
	Node<T> *p = front;      
	val= p->data;        // �����ͷ��ֵ
	front = front->link;    
	delete p;             // front���¶�ͷ
	if (!front) 
	{ // �������ɾ�գ�rearָ�����¶�λ
		rear = front;
	}  
    return true;             
} // �㷨��ʱ�临�ӵ�ΪO��1��

template<class T>
bool LinkedQueue<T>::GetFront(T &val)const
{ // ɾȥ��ͷ��㣬�����ض�ͷԪ�ص�ֵ
	if (IsEmpty ( ) ) 
	{ // ���пղ���ȡԪ��
		return false;
	} 
	val= front->data;        
    return true;             
} // �㷨��ʱ�临�ӵ�ΪO��1��
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
