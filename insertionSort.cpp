#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int> & a)
{

    for(int i=0;i<a.size()-1;i++)
    {
        int tmp=a[i];
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]>a[j])
            {
                a[i]=a[j];
                a[j]=tmp;
            }

        }

    }
}
int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(7);
    a.push_back(69);
    a.push_back(5);
    insertionSort(a);
    for(int k=0;k<a.size();k++)
    {
        cout<<a[k]<<endl;
    }
    return 0;
}

