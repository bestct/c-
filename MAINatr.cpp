 
#include <iostream>
#include <string.h>
#include <stdlib.h>
//using namespace std;
#define DEFAULTSIZE 128

using namespace std;
//#define DEFAULTSIZE 128 

class AString{  
private:
    char *ch;			//�ַ�������
    int curLength;   	//�ַ�����ǰ����
    int maxSize;		//�ַ���������󳤶�
public:
    AString (int sz = DEFAULTSIZE);				//����һ��ʵ�ʳ���Ϊ0���ַ���
    AString (const char *init);					//����ֵΪinit���ַ�������
    AString (const AString &ob);				//���ƹ��캯��
    ~AString ( ){delete []ch;}
    int Length ( )const{return curLength;}		//�����ַ����ĳ���
    AString operator() (int pos, int len); 	//�ַ�����ȡ 
	bool operator == (AString &ob)const{ return strcmp(ch,ob.ch) == 0;}
	bool operator!=(AString  ob)const{ return strcmp(ch,ob.ch) != 0;}
	int operator!()const { return curLength==0;}
	AString& operator = (AString& ob);
	AString& operator += (AString& ob);
	char& operator[](int i);					//ȡ�ַ����е�i���ַ�
	int Find (AString &p, int k)const;			//�ַ���ƥ��
	friend istream& operator >> (istream& in,AString& str);
	friend ostream& operator << (ostream& out, AString& str);
	bool InsertStr(int i, char *str);		//�ڵ�i���ַ�ǰ����һ���ַ���str
	bool DeleteStr(int i,int len);			//ɾ���ӵ�i���ַ���ʼ��len���ȵ��ַ���
	void Replace(AString &ss,AString &ds);
};
AString::AString(int sz)
:maxSize(sz)
{ //����һ����󳤶�Ϊsz��ʵ�ʳ���Ϊ0���ַ���
    curLength = 0;
    ch = new char[maxSize + 1];
    if (!ch) 
    {
         cerr<<"Allocation Error\n";  
         exit(1);
    }
    ch[0] = '\0';
}
AString::AString(const AString &ob)
{ //���ƹ��캯��
    maxSize = ob.maxSize;  
    curLength = ob.curLength;
    ch = new char[maxSize + 1];
    if (!ch) 
    {
        cerr<<"Allocation Error\n";  exit(1);
    }
    strcpy(ch,ob.ch);
}
AString::AString(const char*init)
{ //����һ����󳤶�Ϊsz��ֵΪinit���ַ�������
   int len = strlen(init);    
   curLength = len;      
   maxSize = (len > DEFAULTSIZE)?len:DEFAULTSIZE;
   ch = new char[maxSize+1];
   if (!ch) 
   {
        cerr<<"Allocation Error\n";  exit(1);
   } 
   strcpy(ch,init);
}
AString::AString(const char *init)
{ //����һ����󳤶�Ϊsz��ֵΪinit���ַ�������
   int len = strlen(init);    
   curLength = len;      
   maxSize = (len > DEFAULTSIZE)?len:DEFAULTSIZE;
   ch = new char[maxSize+1];
   if (!ch) 
   {
        cerr<<"Allocation Error\n";  exit(1);
   } 
   strcpy(ch,init);
}
istream& operator>>(istream &in, AString &ob)
{
	char str[DEFAULTSIZE];
	cout<<"input a string: ";
	in.getline(str,DEFAULTSIZE);
	ob.curLength = (int)(strlen(str));
	strcpy(ob.ch,str);
	return in;
}

ostream& operator<<(ostream &out, AString &ob)
{
	if(ob.curLength == 0)
	{
		out<<"This an empty string!"<<endl;
	}
	else
	{
		out<<ob.ch<<endl;
	}
	return out;
}

