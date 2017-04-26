#include<iostream>
using namespace std;
class Avltree
{
private:
    struct Node{
        int element;
        Node*left,*right;
        int height;
        Node(const int x,Node*lt,Node*rt,int h=0):element(x),left(lt),right(rt),height(h){}
    };
    Node*root;
public:
    Avltree()
    {
        root=NULL;

    }
    int heightt(Node*&t)
    {
        return t==NULL?-1:t->height;
    }
    void ins_tree(int x)
    {
        insert(x,root);
    }
    void insert(int x,Node*&t)
    {
        if(t==NULL)
        {
            t=new Node(x,NULL,NULL);
        }
        else if(t->element>x)
        {
            insert(x,t->left);
            if(heightt(t->left)-heightt(t->right)==2)
            {
                if(x<t->left->element)
                    rotatewithleftchild(t);//单旋转
                else
                    doublewithleftchild(t);//双旋转
            }
        }
        else if(t->element<x)
        {
            insert(x,t->right);
            if(heightt(t->right)-heightt(t->left)==2)
            {
                if(x>t->right->element)
                    rotatewithrightchild(t);//单旋转
                else
                    doublewithrightchild(t);//双旋转
            }
        }
        else
        ;
        t->height=max(heightt(t->left),heightt(t->right))+1;
    }
    void rotatewithleftchild(Node*&k2)//单旋转可以分成两种情况
    {
        Node*k1=k2->left;
        k2->left=k1->right;
        k1->right=k2;
        k1->height=max(heightt(k1->left),heightt(k1->right))+1;
        k2->height=max(heightt(k2->left),heightt(k2->right))+1;
    }
    void rotatewithrightchild(Node*&k2)
    {
        Node*k1=k2->right;
        k2->right=k1->left;
        k1->left=k2;
        k1->height=max(heightt(k1->left),heightt(k1->right))+1;
        k2->height=max(heightt(k2->left),heightt(k2->right))+1;
    }
    void doublewithleftchild(Node*&k3)//双旋转是由两次单旋转构成的
    {
        rotatewithrightchild(k3->left);
        rotatewithleftchild(k3);
    }
    void doublewithrightchild(Node*&k3)
    {
        rotatewithleftchild(k3->right);
        rotatewithrightchild(k3);
    }
    void i_tree()
    {
        in_tree(root);
    }
    void in_tree(Node*&p)
    {
        if(p!=NULL){//这里的if(p!=NULL)是非常重要的要是没有他就遍历不成
        in_tree(p->left);
        cout<<p->element<<endl;
        in_tree(p->right);   
    }
    }
    void height_tree()
    {
        cout<<heightt(root)<<endl;
    }

};
int main()
{
    Avltree A;
    A.ins_tree(16);
    A.ins_tree(52);
    A.ins_tree(2);
    A.ins_tree(6);
    A.i_tree();
    cout<<"高度为"<<endl;
    A.height_tree();
    return 0;
}

