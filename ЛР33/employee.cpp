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
		
		double avg(Employee* employee,int size,int currentyear)
		{
			int total=0;
			for(int i=0;i<size;i++)
			{
				total+=employee[i].getexp(currentyear);
			}
			return (double)total/size;
		}
		
		void sortexp(Employee* employee,int size,int currentyear)
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

		void analyzdepartment(Employee* employee,int size)
		{
			string departments[100];
			int counts[100]={0};
			double salaries[100]={0};
			int uniquecount=0;
			
			for(int i=0;i<size;i++)
			{
				string dep=employee[i].department;
				bool found=false;
			
			for(int j=0;j<uniquecount;j++)
			{
				if(departments[j]==dep)
				{
					counts[j]++;
					salaries[j]+=employee[i].salary;
					found=true;
					break;
				}
			}
			if(!found)
			{
				departments[uniquecount]=dep;
				counts[uniquecount]=1;
				salaries[uniquecount]=employee[i].salary;
				uniquecount++;
			}
			}
			for(int i=0;i<uniquecount;i++)
			{
				cout<<"Department "<<departments[i]<<", employeers "<<counts[i]<<", total salaries "<<salaries[i]<<endl;
			}
		}
		
	Vacation::Vacation() 
	{
    startdate="01.07.2021";
    duration=0;
    enddate="01.07.2021";
}

Vacation::Vacation(Employee emp, int currentyear) 
{
    employee=emp;
    startdate="01.07.2021";
    calculateduration(currentyear);
    calculateenddate();
}


void Vacation::calculateduration(int currentyear) 
{
    int exp=employee.getexp(currentyear);
    double sal=employee.getsalary();
    if (exp<10&&sal<12000)
        duration=14;
    else if (exp>25&&sal>25000)
        duration=28;
    else
        duration=21;
}

    void Vacation::calculateenddate() 
	{
    if(duration==14)
        enddate="15.07.2021";
    else if(duration==21)
        enddate="22.07.2021";
    else
        enddate="29.07.2021";
    }

	void Vacation::printvacationinfo() const 
	{
        cout<<"Employee: "<<employee.getlastname()<<", Department: "<<employee.getdepartment()<<endl;
        cout<<"Vacation starts: "<<startdate<<", Duration: "<<duration<<" days, Ends: "<<enddate<< endl;
    }
