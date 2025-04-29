#include <iostream>
#include <vector>
using namespace std;

class Schoolboy
{
	public:
	string firstname;
	string lastname;
	string middlename;
	int birthyear;
	int years;
	string stat;
	
	Schoolboy():firstname(""),lastname(""),middlename(""),birthyear(0),years(0),stat(""){};
	
	Schoolboy(string fn,string ln,string mn,int by,int y,string st):firstname(fn),lastname(ln),middlename(mn),birthyear(by),
	years(y),stat(st){};
	void howmanyyears()
	{
		int currentyear=2025;
		years=currentyear-birthyear;
	}
	void print() const
	{
		cout<<"PIB "<<lastname<<" "<<firstname<<" "<<middlename<<", Years old "<<years<<", stat' "<<stat<<endl;
	}
	
};

class Employeer: public Schoolboy
{
	public:
	int salary;
	string job;
	
	Employeer(string fn,string ln,string mn,int by,int y,string st,int sal,string j):Schoolboy(fn,ln,mn,by,y,st),
	salary(sal),job(j){};
	
	Employeer():Schoolboy(),salary(0),job(""){};
	
	
	void printdet() const
	{
		print();
		cout<<"Salary "<<salary<<", Job "<<job<<endl;
	}
};




int main()
{
	Schoolboy m={"Mykyta","Pavliyk","Ghnnadiyovich",2007,0,"boy"};
	m.howmanyyears();
	m.print();
	Employeer employeers={"Petro","Petrov","Petrovich",2000,0,"boy",25000,"builder"};
	employeers.howmanyyears();
	employeers.printdet();
	return 0;
}