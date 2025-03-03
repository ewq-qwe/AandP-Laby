#include <iostream>
using namespace std;
int main()
{
	int n,**dp,*p[20],a[20][20],i,j,res[20],min=0,d[n],t;
	cin>>n;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++){
	cin>>a[i][j];
	}
	
	for(i=0;i<n;i++)
	p[i]=a[i];
	
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		cout<<*(*(p+i)+j)<<" ";
	}
	cout<<endl;
	}
	
	for(i=0;i<n;i++)
	d[i]=*(*(p+i)+i);
	
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1-i;j++)
	{
		if(d[j]>d[j+1])
		{
			t=d[j];
			d[j]=d[j+1];
			d[j+1]=t;
		}
	}
	for(i=0;i<n;i++)
	*(*(p+i)+i)=d[i];
	
	cout<<"------------------------------"<<endl;
	
		for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		cout<<*(*(p+i)+j)<<" ";
	}
	cout<<endl;
	}
	return 0;
}
