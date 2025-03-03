#include <iostream>
using namespace std;
int main()
{
	int a[10],n,i,*p,*m,n1[10],w=0;
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
	cout<<endl<<"Elementi menshe 0 = ";
	p=a;
	for(i=0;i<n;i++)
	{
		if(*p<0)
		{
			cout<<*p<<" "<<p<<endl;
			w++;
		}
		p++;
	}
	cout<<endl;
	cout<<"Kilkist 0 = "<<w;
	return 0;
}
