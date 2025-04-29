#include <iostream>
using namespace std;

class Engine
{
	protected:
		int power;
		int number;
	
	public:
		Engine(int p,int n):power(p),number(n){};
		Engine():power(0),number(0){};
		~Engine(){};
		void input()
		{
			cout<<"Power ";
			cin>>power;
			cout<<"Number ";
			cin>>number;
		}
		void output()
		{
			cout<<"Power "<<power<<" Number "<<number<<endl;
		}
};

class Car:public Engine
{
	protected:
		string brand;
		int price;
	public:
		Car(string b,int p):brand(b),price(p){};
		Car():brand(""),price(0){};
		~Car(){};
		
		void input()
		{
			Engine::input();
			cout<<"Brand ";
			cin>>brand;
			cout<<"Price ";
			cin>>price;
		}
		void output()
		{
			Engine::output();
			cout<<"Brand "<<brand<<", price "<<price<<endl;
		}
		
};

class Truck:public Car
{
	private:
		int loadcapacity;
	public:
		Truck(int lc):loadcapacity(lc){};
		Truck():loadcapacity(0){};
		~Truck(){};	
		void input()
		{
			Car::input();
			cout<<"Loadcapacity ";
			cin>>loadcapacity;
		}
		void output()
		{
			Car::output();
			cout<<"Loadcapacity "<<loadcapacity<<endl;
		}
};

int main()
{
	int n=3,i;
	Engine engines[3];
	for(i=0;i<n;i++)
	{
		cout<<"Enter engine #"<<i+1<<endl;
		engines[i].input();
	}
	cout<<endl;
		for(i=0;i<n;i++)
	{
		cout<<"Engine #"<<i+1<<endl;
		engines[i].output();
	}
	cout<<endl;
	Car cars[3];
	for(i=0;i<n;i++)
	{
		cout<<"Enter car #"<<i+1<<endl;
		cars[i].input();
	}
		cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Car #"<<i+1<<endl;
		cars[i].output();
	}
		cout<<endl;
	Truck trucks[3];
	for(i=0;i<n;i++)
	{
		cout<<"Enter truck #"<<i+1<<endl;
		trucks[i].input();
	}
		cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Truck #"<<i+1<<endl;
		trucks[i].output();
	}
		cout<<endl;
	return 0;
}