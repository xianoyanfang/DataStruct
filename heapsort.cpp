#include<iostream>
#include<vector>
using namespace std;
void builtheap(vector<int> & a,int i,int j);
void heapsort(vector<int>&a)
{
    for(int i=a.size()/2;i>=0;i--)//�������ɴ󶥶�
        builtheap(a,i,a.size());
    for(int j=a.size()-1;j>0;j--)
    {
        swap(a[0],a[j]);
        builtheap(a,0,j);
    }
}
int leftchild(int i)
{
    return 2*i+1;
}
void builtheap(vector<int> & a,int i,int n)//�������ϣ���������
{
    int child;
    int temp;
    for(temp=a[i];leftchild(i)<n;i=child)//�����Լ�����һ��ģ��������
    {
        child=leftchild(i);
        if(child!=n-1 && a[child]<a[child+1])
            child++;
        if(temp<a[child])
            a[i]=a[child];
        else
            break;
    }
    a[i]=temp;
}
int main()
{
    vector<int> a;
    a.push_back(6);
    a.push_back(8);
    a.push_back(1);
    a.push_back(60);
    a.push_back(7);
    heapsort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

