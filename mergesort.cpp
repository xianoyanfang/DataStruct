#include<iostream>
#include<vector>
using namespace std;
void mergesort(vector<int>& a,vector<int>&temp,int left,int right);
void merge(vector<int>& a,vector<int>& temp,int leftpos,int rightpos,int rightend);
void mergesort(vector<int>& a)
{
    vector<int> temp(a.size());
    mergesort(a,temp,0,a.size()-1);
}
void mergesort(vector<int>& a,vector<int>&temp,int left,int right)
{
    if(left<right){

    int center=(left+right)/2;
    mergesort(a,temp,left,center);
    mergesort(a,temp,center+1,right);
    merge(a,temp,left,center+1,right);}
}
void merge(vector<int>& a,vector<int>& temp,int leftpos,int rightpos,int rightend)
{
    int leftend=rightpos-1;
    int tempos=leftpos;
    int numElement=rightend-leftpos+1;
    while(leftpos<=leftend && rightpos<=rightend)
    {
        if(a[leftpos]<a[rightpos])
        {
            temp[tempos]=a[leftpos];
            tempos++;
            leftpos++;
        }
        else
        {
            temp[tempos]=a[rightpos];
            tempos++;
            rightpos++;
        }
    }
    for(int i=leftpos;i<=leftend;i++)
    {
        temp[tempos]=a[i];
        tempos++;
    }
    for(int i=rightpos;i<=rightend;i++)
    {
        temp[tempos]=a[i];
        tempos++;
    }
    for(int i=0;i<numElement;i++,rightend--)//这里不能用a.size()来表示 ，i是记录次数
    {
        a[rightend]=temp[rightend];
    }
}
int main()
{
    vector<int> a;
    a.push_back(12);
    a.push_back(3);
    a.push_back(5);
    a.push_back(2);
    a.push_back(31);
    mergesort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

