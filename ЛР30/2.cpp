#include <iostream>
using namespace std;

double p(int a, int b=1, int c=1)
{
	return 2*(a*b+b*c+a*c);
}

int main()
{
	cout<<"Z vsima parametrami "<<p(3,4,5)<<endl;
	cout<<"Tilki z default shirinoyu i visotoyu "<<p(3)<<endl;
	cout<<"Z default visotoyu "<<p(3,4)<<endl;
	
	
	return 0;
}
