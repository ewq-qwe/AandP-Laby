#include <iostream>
using namespace std;
int main()
{
	int a[10],i,n,w=0,*min;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	min=&a[1];
		for(i=3;i<n;i+=2)
		{
		if(*min>a[i])
		{
		min=&a[i];
		}
		}
	cout<<endl<<*min;
	return 0;
}
