#include<iostream>
using namespace std;
class Queue
{
private:
int*v;
int front;
int rear;
int s;
int mm;
public:
Queue(int m)
{
mm=m;
v=new int[mm];
front=rear=mm;s=0;
}
~Queue()
{
delete []v;
}
void push_queue(int element)
{
if(s==1 && front==rear)
{
cout<<"队列已满，无法插入"<<endl;
return;
}
rear++;
if(rear==mm+1)
{
rear=1;
}
v[rear-1]=element;s=1;
}
void pop_queue()
{
if(s==0)
{
cout<<"队列是空的"<<endl;
return;
}
front++;
if(front==mm+1)
{
front=1;
}
cout<<v[front-1]<<endl;

if(rear==front){s=0;}
}
bool empty_queue()
{
if(s==1 && front==rear)
{
return false;
}
if(s==0)
{
return true;
}
}
void tra_queue()
{
if(s==0)
{
cout<<"这个队列是空的，没有元素"<<endl;
return;
}
int i=front;
do{
i++;
if(i==mm+1)
{
i=1;
}
cout<<v[i-1]<<endl;
}while(i!=rear);
}
};
int main()
{
Queue Q(6);
Q.pop_queue();
Q.push_queue(4);
Q.push_queue(6);
Q.push_queue(8);
Q.push_queue(1);
Q.pop_queue();
Q.pop_queue();
Q.pop_queue();
Q.tra_queue();
return 0;
}
