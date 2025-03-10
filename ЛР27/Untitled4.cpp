#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int mini(int *a,int n)
{
int min=a[0];
for(int i=0;i<n;i++)
{
	if(min>a[i])
	min=a[i];
}
return min;
}
int maxi(int *a,int n)
{
int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	return max;
}

int main()
{
	srand(time(NULL));
	int n,m,i,size=0;
	cin>>n;
	int *a=new int[n];
	int *b=new int[n];
	for(i=0;i<n;i++)
	{
		a[i]=rand()%6-2;
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	int minval;
	int maxval;
	int index=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			minval=mini(a,i);
			maxval=maxi(a,i);
			b[index++]=maxval+minval;
		}
		b[index++]=a[i];
	}
	cout<<endl;
	for(i=0;i<index;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl<<n<<" "<<index;
	return 0;
}
