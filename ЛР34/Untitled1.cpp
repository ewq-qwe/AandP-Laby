#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds>=60) {
            minutes+=seconds/60;
            seconds%=60;
        } 

        if (minutes>=60) {
            hours+=minutes/60;
            minutes%=60;
        }
    }
    
    public:
    Time(int h=0, int m=0, int s=0) {
        hours=h;
        minutes=m;
        seconds=s;
        normalize();
    }

    ~Time() {}

    void input() {
        cout<<"Hours: ";
        cin>>hours;
        cout<<"Minutes: ";
        cin>>minutes;
        cout<<"Seconds: ";
        cin>>seconds;
        normalize();
    }

	void display() const {
        cout<<hours <<":";
        cout<<minutes<<":";
        cout<<seconds<<endl;
    }
    
    Time operator+(const Time&t) const {
        return Time(hours+t.hours,minutes+t.minutes,seconds+t.seconds);
    }

    Time operator-(const Time&t) const {
        return Time(hours-t.hours,minutes-t.minutes,seconds-t.seconds);
    }

    bool operator>(const Time&t) const {
        if (hours!=t.hours) return hours>t.hours;
        if (minutes!=t.minutes) return minutes>t.minutes;
        return seconds>t.seconds;
    }

    bool operator<(const Time& t) const {
        if (hours!=t.hours) return hours<t.hours;
        if (minutes!=t.minutes) return minutes<t.minutes;
        return seconds<t.seconds;
    }

    bool operator==(const Time& t) const {
        return hours==t.hours&&minutes==t.minutes&&seconds==t.seconds;
    }
};
int main() {
    Time t1, t2;
    cout<<"First hour: "<<endl;
    t1.input();

    cout<<"Second hour: "<<endl;
    t2.input();

    cout<<"First hour: ";
    t1.display();

    cout<<"Second hour: ";
    t2.display();

    Time sum=t1+t2;
    cout<<"Sum chasu: ";
    sum.display();

    Time diff=t1-t2;
    cout<<"Different: ";
    diff.display();

    cout<<endl<<"Porivnyannya:"<<endl;
    cout<<"t1 > t2: "<<(t1>t2 ?"Yes":"No")<<endl;
    cout<<"t1 < t2: "<<(t1 < t2 ?"Yes":"No")<<endl;
    cout<<"t1 == t2: "<<(t1 == t2 ?"Yes":"No")<<endl;

    return 0;
}
