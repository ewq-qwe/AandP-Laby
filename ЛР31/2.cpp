#include <iostream>
#include <string>
using namespace std;

class People {
private:
    string surname;
    string country;
    string gender;
    string education;
    int birthyear;
    int age;

    void calculateage(int currentyear) {
        age=currentyear-birthyear;
    }

public:
    People() : surname(""), country("Ukraine"), gender(""), education("Nema"), birthyear(2006), age(0) {} // Конструктор за замовчуванням

    People(string surname, string gender, string education, int birthyear): // Параметризований конструктор
        surname(surname), gender(gender), education(education), birthyear(birthyear) {
            calculateage(2025); 
    }

    People(People& other): surname(other.surname), country(other.country), gender(other.gender), //Конструктор копіювання
                                  education(other.education), birthyear(other.birthyear), age(other.age) {}


    void input() {
        cout<<"Surname ";
        cin.ignore();
        getline(cin,surname);
        cout<<"Woman or man ";
        getline(cin,gender);
        cout<<"Osvita ";
        getline(cin,education);
        cout<<"Year birthday ";
        cin>>birthyear;
        calculateage(2025);
    }

    void display()
	{
        cout<<"Surname "<<surname<<". country "<<country<<". stat' "<<gender
		<<". Osvita "<<education<<". birth year "<<birthyear<<". Age "<<age<< endl;
    }

    bool highandage(int minage) {
        return(education=="high"&&age>minage);
    }

   
    int getage() {
        return age;
    }

    string getgender() {
        return gender;
    }

};


void removegender(People people[],int& size,string& gendertoremove) {
    for (int i=0;i<size;i++) {
        if (people[i].getgender() == gendertoremove) {
            for (int j=i;j<size-1;j++) //Зміщуємо елементи
			{        
                people[j]=people[j+1];
            }
            size--;
            i--;
        }
    }
}

int main() {
    int maxsize = 10;  
    People people[maxsize];
    int size = 0;
	int i;
    people[size++] = People("Ivanov", "Man", "high", 1995);
    people[size++] = People("Petronenko", "woman", "average", 2000);
    people[size++] = People("Koval", "Man", "high", 1990);

//  Створення копії одного об'єкта за допомогою конструктора копіювання
    People copyperson = people[0];
    for (i=size;i>0;i--) 
	{
        people[i]=people[i-1];
    }
    people[0]=copyperson; // Вставка копії на початок
    size++;

    cout << "All people" << endl;
    for (i=0;i<size;i++) 
	{
        people[i].display();
    }

    
    cout << "People with higher osvita and >18 age" << endl;
    for (int i = 0; i < size; i++) {
        if (people[i].highandage(18)) 
		{
            people[i].display();
        }
    }

    string gendertoremove;
    cout<<"Write woman or man for delete: ";
    cin>>gendertoremove;
    removegender(people,size,gendertoremove);
    
    cout <<"Peoples "<<gendertoremove<<":"<<endl;
    for (i=0;i<size;i++) 
	{
        people[i].display();
    }

    return 0;
}
