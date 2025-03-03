#include <iostream>
using namespace std;
int main()
{
	int n,i,*p,a[10],w=0;
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
	cout<<endl<<"Bilshe nizh livo"<<endl;
	p=a;
	for(i=0;i<n;i++)
	{
		if(p[i]>p[i-1]&&i>0)
		{
			cout<<p[i]<<" ";
			w++;
		}

	}
	cout<<endl<<"Skilki bilshe nizh livo = "<<w;
	return 0;
}
