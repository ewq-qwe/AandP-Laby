#include <iostream>
using namespace std;

int* func(int *a, int n, int &m)
{
	m=0;
	for(int i=1;i<n;i+=2)
	{
	if((int)a[i]%2==0)
	{
		m++;
	}
	}
	int *b=new int[m];
	int index=0;
	for(int i=1;i<n;i+=2)
	{
			if((int)a[i]%2==0)
			{
				b[index++]=(int)a[i];
			}
	}
	return b;
}

int main()
{
	int i,j,n,m;
	
	cin>>n;
	int *a=new int[n];

	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	cout<<"---------------"<<endl;
	
	int *b=func(a,n,m);
	
	for(i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	
	delete []a;
	delete []b;
	return 0;
}
