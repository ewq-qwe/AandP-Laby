#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int *randm(int n,int x,int y)
{
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%(y-x-1)+x;
	}
	return a;
}

int* createmat(int n)
{
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	return a;
}
void printr(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void prints(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}

void dbminmax(int *&a,int &n)
{
	int min,max,index;
	min=a[0];
	max=a[0];
	bool f=false,h=false;
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
		min=a[i];
		if(a[i]>max)
		max=a[i];
	}
	int *temp=new int[n];
	for(int i=0;i<n;i++)
	{
		if(a[i]==min&&!f)
		{
			temp[index++]=a[i];
			f=true;
		}
		else if(a[i]==max&&!h)
		{
			temp[index++]=a[i];
			h=true;
		}
		else if(a[i]!=min&&a[i]!=max)
		{
			temp[index++]=a[i];
		}
		
	}
	delete []a;
	a=temp;
	n=index;
}

void suv(int *&a,int n)
{
	int min,minind=0;
	min=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			minind=i;
		}
	}
		for(int i=minind;i>0;i--)
		{
			a[i]=a[i-1];
		}
		a[0]=min;
}

void parnepar(int *a,int n)
{
	int parni,neparni;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			parni++;
		}
		else 
		{
			neparni++;
		}
	}
	int*b=new int[n];
	int index;
	for(int i=0;i<n;i++)
	{
	if((neparni>parni&&a[i]%2!=0)||(parni>=neparni&&a[i]%2==0))
	{
		b[index++]=a[i];
	}
	}
	for(int i=0;i<index;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	delete[]b;
}

int main()
{
	srand(time(NULL));

	int j,n,x,y,l;
	int*a;
	cout<<"Write n = ";
		cin>>n;
	cout<<"Choose variant to create masiv"<<endl;
	cout<<"1. Write"<<endl;
	cout<<"2. Random"<<endl;
	cin>>j;
	if(j==1)
	{
		a=createmat(n);
	}
	else
	if(j==2)
	{
		cout<<"Rand from and to"<<endl;
		cin>>x>>y;
		a=randm(n,x,y);

	}
	cout<<"Choose vivid masivu"<<endl;
	cout<<"1. Ryadok"<<endl;
	cout<<"2. Stovbets"<<endl;
	cin>>l;
	cout<<"----------------------"<<endl;
	cout<<"Masiv"<<endl;
	if(l==1)
	{
		printr(a,n);
	}
	else
	if (l==2)
	{
		prints(a,n);
	}
	cout<<endl<<"----------------------"<<endl;
	cout<<"Delete dublicats min and max in masiv"<<endl;
	dbminmax(a,n);
	printr(a,n);
	cout<<endl<<"----------------------"<<endl;
	cout<<"Zsuv masivu"<<endl;
	suv(a,n);
	printr(a,n);
	cout<<endl<<"----------------------"<<endl;
	cout<<"Delete parni abo ne parni"<<endl;
	parnepar(a,n);
	return 0;
}
