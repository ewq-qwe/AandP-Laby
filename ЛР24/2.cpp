#include <iostream>
using namespace std;
int main()
{
	int a,b,c,*p,*p1;
	cin>>a>>b>>c;
	p=&a;
	if(*p>b)
	p=&b;
	if(*p>c)
	p=&c;
	p1=&a;
	if(*p1<b)
	p1=&b;
	if(*p1<c)
	p1=&c;
	cout<<"min "<<*p<<"   adress min "<<p<<endl<<"max "<<*p1<<"   adress max "<<p1;
	return 0;
}
