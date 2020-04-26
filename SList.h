#include<iostream>
using namespace std;

class SList;
class Stud{
private:
	string id;				//���
	string name;			//����
	char sex;				//�Ա�
	int age;				//����
	string phone;			//��ϵ�绰
public:
	Stud(){}
	Stud(string id,string name,char sex,int age,string phone)
	{//��ʼ��һ������
		(*this).id = id;
		(*this).name = name;
		(*this).sex = sex;
		(*this).age = age;
		(*this).phone = phone;
	}
	friend class SList;
};//ѧ����

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

