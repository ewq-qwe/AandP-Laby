#include <iostream>
using namespace std;

int *create(int *a,int n,int index1,int index2,int &size)
{
	size=index2-index1+1;
	int *b=new int[size];
	for(int i=0;i<size;i++)
	{
		b[i]=a[index1+i];
	}
	return b;
	
}

int main()
{
int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
	int n=12;
	int g,h;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Write index from to"<<endl;
	cin>>g>>h;
	
	
	int size;
	int *b=create(a,n,g,h,size);
	for(int i=0;i<size;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	delete []b;
	
	
	return 0;
}
