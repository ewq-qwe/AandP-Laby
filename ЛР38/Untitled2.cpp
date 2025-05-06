#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
class Vector
{
	private:
		vector<int>a;
	
	public:
		Vector()
		{
			a.resize(10);
		}
		Vector(vector<int>vect)
		{
			a=vect;
			a.resize(10);
		}
		
	void createrand()
	{
		srand(time(NULL));
		int min,max;
		cout<<"Min max ";
		cin>>min>>max;
		for(int i=0;i<10;i++)
		{
			a[i]=rand()%(max-min+1)+min;
		}
	}
	
	void createkey()
	{
		cout<<"Write numbers"<<endl;
		for(int i=0;i<10;i++)
		{
			cin>>a[i];
		}
	}
	
	void display()
	{
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i]<<" ";
		}cout<<endl;
	}

	void parnepar()
	{
		vector<int>result(10);
		int par=0,nepar;
		for(int i=0;i<a.size();i++)
		{

			if(i%2!=0)
			{
				result[par++]=a[i];
			}
		}
		for(int i=0;i<a.size();i++)
		{
			if(i%2==0)
			{
				result[par++]=a[i];
			}
		}
		a=result;
	}
	void delete1()
	{
		int numb;
		cout<<"Write number to delete ";
		cin>>numb;

				a.erase(remove(a.begin(),a.end(),numb),a.end());
	}
	
	Vector operator+(const Vector&arr) const 
	{
		Vector result;
    	for (int i=0;i<a.size();i++) 
		{
        	result.a[i]=this->a[i]+arr.a[i];
    	}
    	return result;
    }
	Vector operator++()
	{
		for(int i=0;i<a.size();i++)
		{
			a[i]+=10;
		}
		return *this;
	}
	
	int getsum() const
	{
		int sum=0;
		for(int i=0;i<a.size();i++)
		{
			sum+=a[i];
		}
		return sum;
	}
	
	bool operator>(const Vector&arr) const
	{
		return getsum()>arr.getsum();
	}
	
	bool operator<(const Vector&arr) const
	{
		return getsum()<arr.getsum();
	}
	bool operator==(const Vector&arr) const
	{
		return getsum()==arr.getsum();
	}
};

int main()
{
	int choice,n=10;
	Vector vec1,vec2;
	vec2.createrand();
	cout<<"1. Create random"<<endl;
	cout<<"2. Write masiv"<<endl;
	cin>>choice;
	if(choice==1)
	{
		vec1.createrand();
	}
	else if(choice==2)
	{
		vec1.createkey();
	}
	vec1.display();
	vec1.parnepar();
	vec1.display();

	cout<<"Delete number?"<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	int choice1;
	cin>>choice1;
	if(choice1==1)
	{
		vec1.delete1();
		vec1.display();
	}
	
	cout<<"--------"<<endl;
	cout<<"Vector 2"<<endl;
	vec2.display();
	cout<<"Vector 1"<<endl;
	vec1.display();
	Vector sum=vec1+vec2;
	sum.display();
	
	cout<<"--------"<<endl;
	vec1.display();cout<<endl;
	++vec1;
	vec1.display();
	cout<<"--------"<<endl;
	cout<<"Vector 1"<<endl;
	vec1.display();
	cout<<"Vector 2"<<endl;
	vec2.display();
	cout<<endl<<"--------"<<endl;
	cout<<"v1>v2? "<<endl;
	if(vec1>vec2)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	cout<<endl<<"--------"<<endl;
	cout<<"v1<v2? "<<endl;
	if(vec1<vec2)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	cout<<endl<<"--------"<<endl;
	cout<<"v1==v2? "<<endl;
		if(vec1==vec2)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}