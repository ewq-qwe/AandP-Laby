#include <iostream>
using namespace std;
int main()
{
	int w,n,i,*p,a[10],j,*z,b[10],*x,c[10];
	cin>>n;
	p=a;
	for(i=0;i<n;i++)
	{
		cin>>*p;
		p++;
	}
	p=a;
	for(i=0;i<n;i++)
	{
		cout<<*p<<" ";
		p++;
	}
	cout<<endl;
	p=a;
	z=b;
	for(i=0;i<n;i++)
	{
		if(*p%2==0)
		{
			*z=*p;	
			z++;
			w++;
		}
		p++;
	}
	z=b;
	for(i=0;i<w-1;i++)
	for(j=0;j<w-i-1;j++)
	{
		if(*(b+j)>*(b+j+1))
		{
			swap(*(z+j),*(z+j+1));
		}
	}
	cout<<endl;
	z=b;
	for(i=0;i<w;i++)
	{
		cout<<*z<<" ";
		z++;
	}
	
	
	
	w=0;
	p=a;
	x=c;
	for(i=0;i<n;i++)
	{
		if(*p%2!=0)
		{
			*x=*p;
			x++;
			w++;
		}
		p++;
	}
	x=c;
	for(i=0;i<w-1;i++)
	for(j=0;j<w-i-1;j++)
	{
		if(*(c+j)<*(c+j+1))
		{
			swap(*(x+j+1),*(x+j));
		}
	}
	cout<<endl;
	x=c;
	for(i=0;i<w;i++)
	{
		cout<<*x<<" ";
		x++;
	}
	return 0;
}
