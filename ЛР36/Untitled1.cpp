#include <iostream>
#include <string>
using namespace std;

class Worker
{
	protected:
		string lastname;
		int age;
		int exp;
	public:
		Worker(string ln,int a,int e):lastname(ln),age(a),exp(e){}
			
	void setdata(string lastname,int age,int exp)
	{
		this->lastname=lastname;
		this->age=age;
		this->exp=exp;
	}
	void display() const
	{
		cout<<"Latname "<<lastname<<", age "<<age<<", exp "<<exp<<endl;
	}
	void currentexp()
	{
		int currentyear=2025;
		int expi=currentyear-exp;
	}
};

class Car
{
	protected:
		int year;
		string regnum;
	private:
		
		string brand;
		int mileage;
	
	public:
		Car():regnum(""),brand(""),year(0),mileage(0){}
		Car(string rn,string br,int y,int m):regnum(rn),brand(br),year(y),mileage(m){}

	void setdata(string regnum,string brand,int year,int mileage)
	{
		this->regnum=regnum;
		this->brand=brand;
		this->year=year;
		this->mileage=mileage;
	}
	void displayInfo() const 
	{
    	cout<< "Reg number: "<<regnum<<endl
        << "Brand: "<< brand<<endl
        << "Year vipusky: "<<year<<endl
    	<< "Mileage: "<<mileage<<" km"<<endl;
    }
    double averagemileage(int years) const 
	{
        if (years<=0) 
		return 0;
        return static_cast<double>(mileage) / years;
    }
    void setMileage(int mileage) {
        if(mileage >= 0) 
		{ 
            this->mileage=mileage;
        } 
		else 
		{
            cout << "mileage -number"<<endl;
        }
    }
    int getMileage() const 
	{
        return mileage;
    }	
};

class Driver:public Worker,public Car 
{
private:
    int yearstartedusingcar;
    bool fines;

public:
    Driver(string lastname, int age, int exp, string regnum, 
           string brand, int year, int mileage, int yearstartedusingcar, bool fines)
        : Worker(lastname, age, exp), Car(regnum, brand, year, mileage),
          yearstartedusingcar(yearstartedusingcar), fines(fines) {}

void setData(string lastName, int age, int drivingExperience, string regNumber,
string brand, int year, int mileage, int yearStartedUsingCar, bool hasFines) 
{
    Worker::setdata(lastName, age, drivingExperience);
    Car::setdata(regNumber, brand, year, mileage);
    this->yearstartedusingcar=yearstartedusingcar;
    this->fines=hasFines;
}


void displayInfo() const 
{
        Worker::display();
        Car::displayInfo();
        cout << "Year of vehicle use: " << yearstartedusingcar <<endl
             << "Hires: "<<(fines?"Yes":"No")<<endl;
}

void compareageexp() const 
{
        int carage =2025-year;
        if (carage>exp)
            cout << "The car is older than the driver"<<endl;
        else
            cout << "The driver has more driving experience than the age of the car"<<endl;
}
};
int main()
{
	string lastName, regNumber, brand;
    int age, drivingExperience, year, mileage, yearStartedUsingCar;
    bool hasFines;

    cout << "Enter the driver's last name: ";
    getline(cin, lastName);
    cout << "Enter the driver's age: ";
    cin >> age;
    cout << "Enter the driver's driving experience: ";
    cin >> drivingExperience;

    cin.ignore();
    cout << "Enter the car's registration number: ";
    getline(cin, regNumber);
    cout << "Enter the car's brand: ";
    getline(cin, brand);
    cout << "Enter the car's year of manufacture: ";
    cin >> year;
    cout << "Enter the car's mileage (in km): ";
    cin >> mileage;
    cout << "Enter the year the driver started using the car: ";
    cin >> yearStartedUsingCar;
    cout << "Does the driver have fines (1 for yes, 0 for no): ";
    cin >> hasFines;

    Driver driver(lastName, age, drivingExperience, regNumber, brand, year, mileage, yearStartedUsingCar, hasFines);

    driver.displayInfo();
    driver.compareageexp();

    cout << "Changing data"<<endl;
    cin.ignore(); 
    cout << "Enter the driver's new last name: ";
    getline(cin, lastName);
    cout << "Enter the driver's new age: ";
    cin >> age;
    cout << "Enter the driver's new driving experience: ";
    cin >> drivingExperience;
    
    cin.ignore();
    cout << "Enter the new car's registration number: ";
    getline(cin, regNumber);
    cout << "Enter the new car's brand: ";
    getline(cin, brand);
    cout << "Enter the new car's year of manufacture: ";
    cin >> year;
    cout << "Enter the new car's mileage (in km): ";
    cin >> mileage;
    cout << "Enter the new year the driver started using the car: ";
    cin >> yearStartedUsingCar;
    cout << "Does the driver have fines (1 for yes, 0 for no): ";
    cin >> hasFines;

    driver.setData(lastName, age, drivingExperience, regNumber, brand, year, mileage, yearStartedUsingCar, hasFines);

    cout <<endl<< "\nAfter data changes:"<<endl;
    driver.displayInfo();
    driver.compareageexp();

    return 0;
}

