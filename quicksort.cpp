#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int>&a,int left,int right);
void quicksort(vector<int>&a)
{
    quicksort(a,0,a.size()-1);
}
void quicksort(vector<int> &v, int left, int right){
        if(left < right){
                int key = v[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && v[high] > key){//从后向前扫
                                high--;
                        }
                        v[low] = v[high];
                        while(low < high && v[low] < key){//从前向后扫
                                low++;//自增跳过v[low];
                        }
                        v[high] = v[low];
                }
                v[low] = key;
                quicksort(v,left,low-1);
                quicksort(v,low+1,right);
        }
}
int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(12);
    a.push_back(3);
    a.push_back(4);
    a.push_back(15);
    a.push_back(5);
    quicksort(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}

