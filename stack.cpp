#include<iostream>
using namespace std;

class S_tack
{
private:

int*v;
int top;
int mm;
public:
S_tack(int m):mm(m)
{
top=0;
v=new int[mm];
}
~S_tack()
{
delete []v;
}

void in_stack(int element)
{
if(top==mm)
{
cout<<"ջ�������޷�����"<<endl;
return;
}
top++;
v[top-1]=element;
}

void pop_stack()
{
if(top==0)
{
cout<<"����һ����ջ���޷�����"<<endl;
}
int y=v[top-1];
top--;
cout<<y<<endl;

}

int length_stack()
{
return top;
}
void tra_stack()
{
if(top==mm)
{
cout<<"����һ����ջ"<<endl;
return;
}

for(int i=top-1;i>=0;i--)
cout<<v[i]<<endl;
}
};

int main()
{
S_tack S(10);
S.in_stack(50);
S.in_stack(60);
S.in_stack(70);
S.in_stack(80);
S.in_stack(90);
S.in_stack(100);
cout<<"����Ϊ"<<S.length_stack()<<endl;
S.tra_stack();
cout<<"====================="<<endl;
S.pop_stack();
S.pop_stack();
S.pop_stack();
cout<<"����Ϊ"<<S.length_stack()<<endl;
return 0;
}
