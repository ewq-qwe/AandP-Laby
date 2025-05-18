#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>
using namespace std;

class Pracivnuk 
{
protected:
    int id; 
    string surname; 
public:
    Pracivnuk(int i, string s) 
	{
        id = i; 
        surname = s; 
    }
    int getId() 
	{
        return id;
    }
    string getSurname() 
	{
        return surname;
    }
    virtual double rothrahunok() const = 0; 
    bool operator==(const Pracivnuk& other) const 
	{
        return this->id == other.id;
    }
    virtual void printInfo() const 
	{
        cout << "ID: " << id << ", Surname " << surname;
    }

};
class manager : public Pracivnuk
{
private:
    double stavka; 
    double pidlag; 
public:
    manager(int i, string sur, int st , int pid):Pracivnuk(i, sur), stavka(st), pidlag(pid){}
    double rothrahunok()const  
	{
        if (pidlag > 5) {
            return (stavka * 0.10) + stavka;
        }
        else {
            return stavka;
        }
        
    }
    void printInfo() const override 
	{
        Pracivnuk::printInfo();
        cout << "manager: " << rothrahunok() << endl;
    }
};
class Rozrobnyk : public Pracivnuk 
{
    double stavkaZaHod;
    int kilkistHodyn;

public:
    Rozrobnyk(int id, string sur, double sta, int kilki)
        : Pracivnuk(id, sur), stavkaZaHod(sta), kilkistHodyn(kilki) {}

    double rothrahunok() const override 
	{
        return stavkaZaHod * kilkistHodyn;
    }

    void printInfo() const override 
	{
        Pracivnuk::printInfo();
        cout << "Rozrobnuk zp = " << rothrahunok()  << endl;
    }
};


int main()
{
    vector<Pracivnuk*> prat; 
    prat.push_back(new manager(1, "Ivanov ", 1000, 6));
    prat.push_back(new Rozrobnyk(1, "Petrov ", 100, 7));
    prat.push_back(new manager(1, "Shevchenko ", 1000, 2));

    for (auto& p : prat) 
	{
        p->printInfo();
        cout << endl;
    }

    cout<<"==:"<<endl;
    cout<<"worker 1 and 2 ";
    if (*prat[0] == *prat[1])
        cout<<" the same id"<<endl;
    else
        cout<<" diferent"<<endl;

    for (auto p : prat) 
	{
        delete p;
    }

}
