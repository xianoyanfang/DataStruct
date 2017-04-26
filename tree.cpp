#include<iostream>
using namespace std;
class B_tree
{
private:
    struct Node{int element;Node*left,*right;};
    Node*root;
public:
    B_tree()
    {
        root=NULL;
    }
    void creat_tree(int data)
    {
        Node*newnode=new Node;
        newnode->element=data;//�����װ��һ���ڵ�
        newnode->left=newnode->right=NULL;
        if(root==NULL)
            root=newnode;
        else
        {
            Node*back;
            Node*now;
            now=root;
            while(now!=NULL)
            {
                back=now;
                if(now->element>data)
                    now=now->left;
                else
                    now=now->right;
            }
            if(back->element>data)
                back->left=newnode;
            else
                back->right=newnode;
        }
    }
    void f_tree(Node *t)
    {
        if(t!=NULL)
        {
        cout<<t->element<<endl;
        f_tree(t->left);
        f_tree(t->right);
        }
    }
    void i_tree(Node *t)
    {
        if(t!=NULL)
        {
        i_tree(t->left);
        cout<<t->element<<endl;
        i_tree(t->right);
        }
    }
    void l_tree(Node*t)
    {if(t!=NULL){l_tree(t->left);
    l_tree(t->right);
    cout<<t->element<<endl;}
    }
    void display1()
    {
        f_tree(root);
    }
    void display2()
    {
        i_tree(root);
    }
    void display3()
    {
        l_tree(root);
    }
    void findmin()
    {
        Node*p;
        Node*back;
        p=root;
        if(p==NULL)
            return ;
        else
        {
            while(p!=NULL)
            {
                back=p;
                p=p->left;
            }
            cout<<back->element<<endl;
        }
    }
    void findmax()
    {
        Node*p;
        Node*back;
        p=root;
        if(p==NULL)
            return ;
        else
        {
            while(p!=NULL)
            {
                back=p;
                p=p->right;
            }
            cout<<back->element<<endl;
        }
    }
    Node*Findmin(Node*p)
    {
        Node*back;
        while(p!=NULL)
        {
            back=p;
            p=p->left;
        }
        return back;
    }
    //����ɾ�����������������1��Ϊ��Ҷ��2�������������������������е�һ�֣�3����������
    void remove(const int data,Node*&p)//��ɾ����һ�����Ǳ���ҪNode* &p��ʵ�Σ�����һ������Ҫ                                              //      ��û�еĻ��Ͳ��ܹ����ɾ����
    {
        if(p==NULL)
        {
            return;
        }
        if(data<p->element)
        {
            remove(data,p->left);
        }
        else if(p->element<data)
        {
            remove(data,p->right);
        }
        else if(p->left!=NULL && p->right!=NULL)
        {
            p->element=Findmin(p->right)->element;
            remove(p->element,p->right);
        }
        else
        {
            Node*t=p;
            p=(p->left!=NULL)?p->left:t->right;
            delete t;
        }
    }

    void Remove(int data)
    {
        remove(data,root);
    }   


};
int main()
{
    B_tree B;
    B.creat_tree(56);
    B.creat_tree(23);
    B.creat_tree(1);
    B.creat_tree(6);
    B.creat_tree(16);
    B.display1();
    B.display2();
    B.display3();
    B.findmin();
    B.findmax();
    B.Remove(16);
    B.Remove(6);
    cout<<endl;
    B.display1();
    B.display2();
    B.display3();
    return 0;
}

