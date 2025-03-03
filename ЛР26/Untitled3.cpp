#include <iostream>
using namespace std;
int main()
{
	int n,**dp,*p[20],a[20][20],i,j,res[20],min=0;
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
	{

		for(j=1;j<n;j++)
		{
			if(a[i][j]<a[i][min])
			{
				min=j;
			}
		}
		res[i]=min;
	}
	cout<<endl<<"Result = "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<res[i]<<" ";
	}
	return 0;
}


