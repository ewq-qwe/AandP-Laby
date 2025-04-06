#ifndef EMPLOYEE_H 
#define EMPLOYEE_H

#include <string>
using namespace std;
class Employee
{
	private:
	
	string lastname;
	string department;
	int hireyear;
	double salary;
	double bonus;
	
	public:
		Employee();
		Employee(string ln,string dp,int hy,double sal);
		string getlastname()const;
		string getdepartment()const;
		int gethireyear()const;
		double getsalary()const;
		double getbonus()const;
		int getexp(int currentyear)const;
		
		void setlastname(string ln);
		void setdepartment(string dp);
		void sethireyear(int hy);
		void setsalary(double sal);
		void calculatebonus(int currentyear);
		void printinfo(int currentyear) const;
		
		double avg(Employee* employee,int size,int currentyear);
		void sortexp(Employee* employee,int size,int currentyear);
};

#endif
