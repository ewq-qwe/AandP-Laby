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
		
		friend double avg(Employee* employee,int size,int currentyear);
		friend void sortexp(Employee* employee,int size,int currentyear);
		friend void analyzdepartment(Employee* employee,int size);
};
class Vacation {
private:
    Employee employee;
    string startdate;
    int duration;
    string enddate;

public:
    Vacation();
    Vacation(Employee emp,int currentyear);
    
    void calculateduration(int currentyear);
    void calculateenddate();
    void printvacationinfo() const;
};


#endif
