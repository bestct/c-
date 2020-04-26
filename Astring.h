#include <iostream>
#include <string.h>
#include <stdlib.h>
//using namespace std;
#define DEFAULTSIZE 128

using namespace std;
//#define DEFAULTSIZE 128 

class AString{  
private:
    char *ch;			//字符串定义
    int curLength;   	//字符串当前长度
    int maxSize;		//字符串允许最大长度
public:
    AString (int sz = DEFAULTSIZE);				//构造一个实际长度为0的字符串
    AString (const char *init);					//构造值为init的字符串对象
    AString (const AString &ob);				//复制构造函数
    ~AString ( ){delete []ch;}
    int Length ( )const{return curLength;}		//计算字符串的长度
    AString operator() (int pos, int len); 	//字符串截取 
	bool operator == (AString &ob)const{ return strcmp(ch,ob.ch) == 0;}
	bool operator!=(AString  ob)const{ return strcmp(ch,ob.ch) != 0;}
	int operator!()const { return curLength==0;}
	AString& operator = (AString& ob);
	AString& operator += (AString& ob);
	char& operator[](int i);					//取字符串中第i个字符
	int Find (AString &p, int k)const;			//字符串匹配
	friend istream& operator >> (istream& in,AString& str);
	friend ostream& operator << (ostream& out, AString& str);
	bool InsertStr(int i, char *str);		//在第i个字符前插入一个字符串str
	bool DeleteStr(int i,int len);			//删除从第i个字符开始的len长度的字符串
	void Replace(AString &ss,AString &ds);
};
AString::AString(int sz)
:maxSize(sz)
{ //构造一个最大长度为sz，实际长度为0的字符串
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
{ //复制构造函数
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
{ //构造一个最大长度为sz，值为init的字符串对象
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
{ //构造一个最大长度为sz，值为init的字符串对象
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

