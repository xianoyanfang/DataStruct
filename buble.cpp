#include<iostream>
#include<vector>

using namespace std;
template<class T>
void buble(vector<T> &a){
    int i,j,k,m;T d;//k���Ǽٶ�Ϊ��ߣ�m���Ǽٶ�Ϊ�ұ�
    k=0;
    m=a.size()-1;
    while(k<m)
    {
        j=m-1;
        m=0;
        for(i=k;i<=j;i++)//��ǰ���
        {
            if(a[i]>a[i+1])
            {
                d=a[i];
                a[i]=a[i+1];
                a[i+1]=d;
                m=i;
            }
        }
        j=k+1;k=0;//����k=0��Ϊ���Է���һ
        for(i=m;i>=j;i--)//�Ӻ���ǰ
        {
            if(a[i]<a[i-1])
            {
                d=a[i];
                a[i]=a[i-1];
                a[i-1]=d;
                k=i;
            }
        }
    }
}

int main()
{
    vector<double> a;

    a.push_back(4.53);
    a.push_back(7.12);
    a.push_back(1.22);
    a.push_back(5);
    a.push_back(12.4);
    buble(a);
    for(int i=0;i<a.size();i++)
    {
        std::cout<<a[i]<<endl;
    }
    return 0;   
 }

