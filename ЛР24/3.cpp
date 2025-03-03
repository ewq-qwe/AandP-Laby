#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,*p,*p1,i;
	float w;
	cin>>a>>b>>c>>d;
	if(a==b||a==c||a==d||b==c||b==d||c==d)
	{
		cout<<"Ne unikalny"<<endl;
		return 0;
	}
	int *num[]={&a,&b,&c,&d};
	w=(a+b+c+d)/4.0;
	cout<<"Serednye = "<<w<<endl;
	
	p=&a;
	p1=&a;
	for(i=0;i<4;i++)
	{
	if(*num[i]<*p)
	p=num[i];
	if(*num[i]>*p1)
	p1=num[i];
	}
	cout<<"Ne max i min = ";
	for(i=0;i<4;i++)
	if(num[i]!=p&&num[i]!=p1)
	cout<<*num[i]<<" ";
	return 0;
}
