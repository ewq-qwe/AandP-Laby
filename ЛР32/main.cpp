#include "employee.h"
#include "employee.cpp"
#include <iostream>
using namespace std;
int main()
{
	int currentyear=2025;
	Employee emp1;
	emp1.calculatebonus(currentyear);
	emp1.printinfo(currentyear);
	Employee emp2("Petrov","Yurist",2010,25000);
	emp2.calculatebonus(currentyear);
	emp2.printinfo(currentyear);
	
	int n,i;
	cout<<"Write how much employeers ";
	cin>>n;
	Employee* employee=new Employee[n];
	for(int i=0;i<n;i++)
	{
		string name,dep;
		int year;
		double sal;
		cout<<"Employeer "<<i+1<<endl;
		cout<<"Lastname "<<endl;
		cin>>name;
		cout<<"Department "<<endl;
		cin>>dep;
		cout<<"Year "<<endl;
		cin>>year;
		cout<<"Salary "<<endl;
		cin>>sal;
		
		employee[i]=Employee(name,dep,year,sal);
		employee[i].calculatebonus(currentyear);
	}
	
	cout<<"All employeers "<<endl;
	for(i=0;i<n;i++)
	{
		employee[i].printinfo(currentyear);
	}
	double avgg=emp1.avg(employee,n,currentyear);
	cout<<"Average stazh job "<<avgg<<endl;
	emp1.sortexp(employee,n,currentyear);
	for(i=0;i<n;i++)
	{
		employee[i].printinfo(currentyear);
	}
	delete[]employee;
	return 0;
}
