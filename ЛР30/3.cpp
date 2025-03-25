#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void generate(int *a,int *&b,int size,int &n,int min=5,int max=10)
{
	srand(time(NULL));
	n=min+rand()%(min-max+1);
	b=new int[n];
	for(int i=0;i<n;i++)
	{
		int randind=rand()%size;
		b[i]=a[randind];
	}
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
	int size=12;	
	int *b;
	int n;
	generate(a,b,size,n);
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	delete []b;
	return 0;
}
