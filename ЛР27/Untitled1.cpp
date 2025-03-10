#include <iostream>
using namespace std;
int main()
{
	int i,j,n,m,k=0,w=0;
	cout<<"Vvedit rozmir a ";
	cin>>n;
	cout<<"Vvedim rozmir b ";
	cin>>m;
	int *a=new int[n];
	int *b=new int[j];
	cout<<"Vvedit masiv a"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Vvedit masiv b"<<endl;
	for(j=0;j<m;j++)
	{
		cin>>b[j];
	}
	cout<<"---------------------"<<endl<<"Masiv a"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Masiv b"<<endl;
	for(j=0;j<n;j++)
	{
		cout<<b[j]<<" ";
	}
	cout<<endl<<"Masiv kratni 3 = ";
	for(i=0;i<n;i++)
	{
		if(a[i]%3==0)
		{
			k++;
		}
	}
	for(j=0;j<n;j++)
	{
		if(b[j]%3==0)
		{
			w++;
		}
	}
	
	
		if(k>w)
		{
			for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		}
		else
		{
			for(j=0;j<m;j++)
			cout<<b[j]<<" ";
		}
	
	delete []a;
	delete []b;
	return 0;
}
