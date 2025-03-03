#include <iostream>
using namespace std;
int main()
{
	int a,c,n,i,*p;
	a=2;
	c=5;
	p=&a;
	*p=*p*3;
	cout<<"a= "<<a<<endl;
	cout<<"c= "<<c<<endl;
	cout<<"*3 "<<*p<<endl;
	*p=*p+c;
	cout<<"+c "<<*p<<endl;
	cout<<"adress a "<<&a<<endl;
	cout<<"adress c "<<&c<<endl;
	cout<<"adress *p "<<&p<<endl;
	return 0;
}
