#include<iostream>
#include<vector>
using namespace std;
template<class T>
void shellsort(vector<T> &a)
{
    int i,j;
    for(int len=a.size()/2;len>0;len/=2)//确定分组的h
    {
        for(int i=len;i<a.size();i++)//确定分组的界限 //插入排序
        {
            j=i;
            T d=a[i];
            for(;j>=len && d<a[j-len];j-=len)
            {
                a[j]=a[j-len];
            }

            a[j]=d;
        }
    }
}
int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(6);
    a.push_back(2);
    a.push_back(5);
    a.push_back(23);
    a.push_back(4);
    shellsort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

