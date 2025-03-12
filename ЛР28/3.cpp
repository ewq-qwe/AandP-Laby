#include <iostream>
#include <fstream>
#include <cstdlib>

void sort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

using namespace std;
int main()
{
int n,i,j,k;
int **a=new int*[n];
cin>>n;
for(int i=0;i<n;i++) 
{
    a[i] = new int[n];
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        a[i][j]=rand()%900+100;
    }
}
cout<<"Matrix"<<endl;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}
for(i=0;i<n;i++)
{
    sort(a[i],n);
}
cout<<"Sort matrix"<<endl;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}

ofstream outfile("2.txt");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        outfile<<a[i][j]<<" ";
    }
    outfile<<endl;
}
outfile.close();
for(i=0;i<n;i++)
{
    delete []a[i];
}
delete []a; 


return 0;
}
