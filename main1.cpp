#include"SeqList.h" 
int main()
{
	SeqList<int> list;
	for(int i = 1; i < 15; ++i)
	{
		list.Insert(1,i);
	}
	list.Traverse();
	return 1;
}

