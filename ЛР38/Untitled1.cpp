#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void createmat(vector<int>&a,int n)
{
	int min,max;
	cout<<"Min max ";
	cin>>min>>max;
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%(max-min+1)+min;
	}

}

void display(vector<int> a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;
}

void howmany(vector<int> a,int n)
{
	int count;
	for(int i=1;i<n;i++)
	{
		if(a[0]==a[i])
		count++;
	}
	cout<<"Kilkist elementiv = 1 elemntu : "<<count<<endl;
}

void swapelements(vector<int>&a,int n) 
{
	int ind1,ind2;
	cout<<"Write index 1 and index 2 for swap "<<endl;
	cin>>ind1>>ind2;
	swap(a[ind1],a[ind2]);
}

void vstavka(vector<int>&a,int&n)
{
	int ind,numb;
	cout<<"Write index to vstavky ";
	cin>>ind;
	cout<<"Write element ";
	cin>>numb;
	n++;
	a.insert(a.begin()+ind,numb);
}
void longest(vector<int> a,int n)
{
	int c,maxlenth=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			c++;
			maxlenth=max(maxlenth,c);
		}
		else
		{
			
			c=1;
		}
	}
	cout<<"Naidovshi dilyanki z odnakovim znachennyam "<<maxlenth<<endl;
}

void sortminmax(vector<int>&a,int n)
{
	int min=a[0],max=a[0],minind=0,maxind=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			maxind=i;
		}
		if(a[i]<min)
		{
			min=a[i];
			minind=i;
		}
	}
	
	if(minind>maxind)
		swap(minind,maxind);
	if(minind+1<maxind)
	sort(a.begin()+minind+1,a.begin()+maxind);
}

int main()
{
	srand(time(NULL));
	int n,i;
	cout<<"n= ";
	cin>>n;
	vector<int>a(n);
	
	createmat(a,n);
	display(a,n);
	
	howmany(a,n);
	
	swapelements(a,n);
	display(a,n);
	
	vstavka(a,n);
	display(a,n);
	
	longest(a,n);
	
	sortminmax(a,n);
	display(a,n);
	return 0;
}