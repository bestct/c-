#include<iostream>
using namespace std;

class SList;
class Stud{
private:
	string id;				//序号
	string name;			//姓名
	char sex;				//性别
	int age;				//年龄
	string phone;			//联系电话
public:
	Stud(){}
	Stud(string id,string name,char sex,int age,string phone)
	{//初始化一个新生
		(*this).id = id;
		(*this).name = name;
		(*this).sex = sex;
		(*this).age = age;
		(*this).phone = phone;
	}
	friend class SList;
};//学生类

class SList{
private:
	Stud *stud;
	int maxSize;
	int length;
public:
	SList(){}
	SList(int size);
	bool Insert(Stud st);
	bool Remove(string id);
	bool Find(string id);
	void CreateSList(int n);
	void Traverse();
};

