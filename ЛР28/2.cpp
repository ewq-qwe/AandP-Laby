#include <iostream>
using namespace std;
bool row(int **a,int n,int j)
{
    for(int i=0;i<n;i++)
    {
        if(a[i][j]<a[i+1][j])
        {
            return false;
        }
        return true;
    }

}
int main()
{
int i,j,n;
cin>>n;
int **a=new int *[n];
for(i=0;i<n;i++)
{
    a[i]=new int[n];
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    cin>>a[i][j];
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    cout<<a[i][j]<<" ";
    cout<<endl;
}
int sum=0;
for(j=0;j<n;j++)
{  
    if(row(a,n,j))
    {
        sum++;
    }
}
cout<<sum<<endl;
for(i=0;i<n;i++)
{
    delete []a[i];
}
delete []a;
    return 0;
}
