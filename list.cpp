#include<iostream>
using namespace std;
template<class T>
class myList
{
private:
	int mm;
	int nn;
	T*v;
public:
	myList(){mm=0;nn=0;return;}
	template<class T>
	myList(int m)//动态构造数组
	{
		mm=m;nn=0;v=new T[mm];return;
	}
	bool full_list()
	{
		if(mm==nn)return true;
		else return false;
	}
	bool empty_list()
	{
		if(nn==0)
		{
		return true;
		}
	return false;
	}
	template<class T>
	void ins_list(int i,T element)
	{
	if(nn==mm)
	{
		cout<<"上溢，插入不成功"<<endl;
		return;
	}
	if(i>nn)
	{
		i=nn+1;
	}
	if(i<1)
	{
		i=1;
	}
	for(int k=nn;k>=i;k--)
		v[k]=v[k-1];
	v[i-1]=element;
	nn++;
	return;
	}
	void del_list(int i)
	{
		if(nn==0)
		{
			cout<<"下溢，删除不成功"<<endl;
			return;
		}
		if(i>nn || i<1)
		{
			cout<<"没有这个位置"<<endl;
			return;
		}
		for(int k=i;k<nn;k++)
			v[k-1]=v[k];
		nn--;
	}
	void trav_list()
	{
		int i;
		cout<<nn<<endl;
		for(i=0;i<nn;i++)
		cout<<v[i]<<endl;
	}
	int l_list()
	{
		return nn;
	}
	void destroy_list()
	{
		delete []v;
	}
}

int main()
{
myList L(4);
L.ins_list(1,5);
L.ins_list(1,4);
L.ins_list(3,3);
L.trav_list();
L.ins_list(3,2);
L.ins_list(2,1);
L.destroy_list();
return 0;
}
