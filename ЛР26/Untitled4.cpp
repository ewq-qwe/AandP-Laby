#include <iostream>
using namespace std;
int main()
{
	int a[20][20],i,j,n,*p[20],k=0,*ch,zero=0;
	float pos,neg,ncount=0,negsum=0,possum=0,pcount=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
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
	{
	for(j=0;j<n;j++)
	{
		ch=&a[i][j];
		if(*ch>0)
		{
			pcount++;
			possum+=*ch;
		}
		else if(*ch<0)
		{
			ncount++;
			negsum+=*ch;
		}
		else
		{
			zero++;
		}
	}
	}
	
	if(pcount>0)
	{
		pos=float(possum)/pcount;
	}
	else
	{
		pos=0;
	}
	
	if(ncount>0)
	{
		neg=float(negsum)/ncount;
	}
	else
	{
		neg=0;
	}
	cout<<"Positive = "<<pos<<endl;
	cout<<"Negative = "<<neg<<endl;
	cout<<"Zero = "<<zero<<endl;
	return 0;
}
