#include <iostream>
using namespace std;
int main()
{
	int n,**dp,*p[20],a[20][20],i,j,max,min;
	cin>>n;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	
	for(i=0;i<n;i++)
	p[i]=a[i];
	
	dp=p;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
	cout<<"--------------------------"<<endl;
	for(i=0;i<n;i+=2)
	{
	for(j=0;j<n;j++)
	{
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
	}
	cout<<"--------------------------"<<endl;
	for(i=1;i<n;i+=2)
	{
	for(j=n-1;j>=0;j--)
	{
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
	}
	return 0;
}
