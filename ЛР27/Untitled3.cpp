#include <iostream>
using namespace std;

int *func(double *a,int n, int &m)
{
m=0;
for(int i=0;i<n;i++)
{
	if((int)a[i]%2==0)
	{
		m++;
	}
	
}
int *b=new int[m];
int index=0;
for(int i=0;i<n;i++)
{
	if((int)a[i]%2==0)
	{
		b[index++]=(int)a[i];
	}
}
for(int i=0;i<m-1;i++)
{
	for(int j=0;j<m-i-1;j++)
	{
		if(b[j]>b[j+1])
		{
			int t=b[j];
			b[j]=b[j+1];
			b[j+1]=t;
		}
	}
}
return b;
}


int main()
{
	int i,n,j,m;
	cin>>n;
	double *a=new double[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int *b=func(a,n,m);
	for(i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	delete []a;
	delete []b;
	return 0;
}
