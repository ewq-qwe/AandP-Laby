#include <iostream>
using namespace std;
int main()
{
	int n,**dp,*p[20],a[20][20],i,j,max,min;
	cin>>n;
	dp=p;
	
	
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		cin>>a[i][j];
	}
	
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
	max=a[0][0];
	for(i=0;i<n;i++)
	{
		if(*(*(a+i)+i)>max)
		max=*(*(a+i)+i);
	}
	min=a[0][n-1];
	for(i=0;i<n;i++)
	{
		if(*(*(a+i)+i)+n-1<min)
		min=*(*(a+i))+(n-1-i);
	}
	cout<<"max "<<max<<" "<<"min "<<min<<endl;
	cout<<"Riznitsya = "<<max-min;
	return 0;
}
