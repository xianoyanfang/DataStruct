#include<iostream>
using namespace std;
class list_node
{
private:
struct Node
{
int element;
Node * next;
};
Node * head;
int length;
public:
list_node()
{
head=NULL;//���ﲻ��Ϊд��head->next=NULL;������Ϊ���ǲ�û��Ϊhead����ռ䣻���Ϊhead������һ���ռ�head=new Node����ܹ����Ϊhead->next=NULL;
length=0;
}

void push_lit(int data)
{
Node*pt;
pt=new Node;
pt->element=data;
pt->next=head;
head=pt;
length++;
}
void ins_list(int i,int data)
{
int k=1;
Node * np;
np=new Node;
np->element=data;
np->next=NULL;
Node*p;
p=head;
p=p->next;
while(k<i && p!=NULL)
{
p=p->next;
k++;
}
np->next=p->next;
p->next=np;
length++;
}
void del_list(int i)
{
if(head->next==NULL)
{
cout<<"������Ϊ�գ��޷�ɾ��"<<endl;
return ;
}
Node*p;
p=head;
int k=1;
while(k<i && p->next!=NULL)
{
p=p->next;
k++;
}
p->next=p->next->next;
delete p->next;
length--;
}
void tra_list()
{
Node*p;
p=head;
int i=0;
while(i<length)
{
cout<<p->element<<endl;
p=p->next;
i++;
}
}
};
int main()
{
list_node L;
L.push_lit(6);
L.push_lit(8);
L.push_lit(1);
L.push_lit(70);
L.ins_list(2,1000);
cout<<"==================================="<<endl;
L.tra_list();
return 0;
}
