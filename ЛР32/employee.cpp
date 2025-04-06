#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee()
{
	lastname="Ivanov";
	department="Buhalter";
	hireyear=2000;
	salary=15000;
	bonus=0;	
}
Employee::Employee(string ln,string dp,int hy,double sal)
{
	lastname=ln;
	department=dp;
	hireyear=hy;
	salary=sal;
	bonus=0;
}

		string Employee::getlastname() const
		{
		return lastname;
		}
		string Employee::getdepartment() const
		{
			return department;
		}
		int Employee::gethireyear() const
		{
			return hireyear;
		}
		double Employee::getsalary() const
		{
			return salary;
		}
		double Employee::getbonus() const
		{
			return bonus;
		}
		int Employee::getexp(int currentyear) const
		{
			return currentyear-hireyear;
		}
		
		
		void Employee::setlastname(string ln)
		{
			lastname=ln;
		}
		void Employee::setdepartment(string dp)
		{
			department=dp;
		}
		void Employee::sethireyear(int hy)
		{
			hireyear=hy;
		}
		void Employee::setsalary(double sal)
		{
			salary=sal;
		}
		void Employee::calculatebonus(int currentyear)
		{
			int exp=getexp(currentyear);
			if(exp<10)
			bonus=salary*0.1;
			else if(exp<=25)
			bonus=salary*0.25;
			else
			bonus=salary*0.4;
		}
		void Employee::printinfo(int currentyear) const
		{
		cout<< "Lastname: " << lastname<< ", Department: " << department<< ", Hire Year: " << hireyear
        << ", Stazh: " << getexp(currentyear)<< ", Salary: " << salary<< ", Bonus: " << bonus << endl;
		}
		
		double Employee::avg(Employee* employee,int size,int currentyear)
		{
			int total=0;
			for(int i=0;i<size;i++)
			{
				total+=employee[i].getexp(currentyear);
			}
			return (double)total/size;
		}
		
		void Employee::sortexp(Employee* employee,int size,int currentyear)
		{
			for(int i=0;i<size-1;i++)
			{
				for(int j=i+1;j<size;j++)
				{
					if(employee[i].getexp(currentyear)>employee[j].getexp(currentyear))
					swap(employee[i],employee[j]);
				}
			}
		}

