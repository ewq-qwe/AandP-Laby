#include <iostream>
#include <vector>
using namespace std;

class instrument {
public:
    virtual void calculet() = 0;
    virtual ~instrument() {};
};

class pramokutnuk:public instrument
{
private:
    int n;
    int d;
public:
    pramokutnuk(int m, int dd) 
	{
        n=m; 
        d=dd;
    }
    void calculet() override 
	{
        cout<<"Pryamokytnik: "<<endl;
        cout<<"P = "<<n+n+d+d<<endl;
        cout<<"S = "<<n*d<< endl;
    }
};
class trukytnuk:public instrument
{
private:
    double n;
    double h;
public:
    trukytnuk(int nn, int hh) 
	{
        n=nn; 
        h=hh; 
    }
    void calculet() override 
	{
        cout<<"trukytnuk: "<<endl;
        cout<<"P = "<<n*3<<endl;
        cout<<"S = "<<(n*h)/2<<endl;
    }
};

class kolo:public instrument
{
private:
    int r;
public:
    kolo(int rr) 
	{
        r=rr;
    }
    void calculet() override 
	{
        cout<<"kolo: "<<endl;
        cout<<"C = pi"<<r*2<<endl;
        cout<<"S = pi"<<r*r<<endl;
    }
};

void playInstrument(vector<instrument*>&instrument) 
{
    for (const auto&inst:instrument) 
	{
        inst->calculet();
    }
}

int main()
{
    vector<instrument*> instruments;
	int kolo1,pram1,pram2,truk1,truk2;
	cout<<"Write for kolo ";
	cin>>kolo1;
	cout<<"Write for pramokutnuk 2 storony ";
	cin>>pram1>>pram2;
	cout<<"Write for trukytnuk 2 storony ";
	cin>>truk1>>truk2;
    instruments.push_back(new kolo(kolo1));
    instruments.push_back(new pramokutnuk(pram1,pram2));
    instruments.push_back(new trukytnuk(truk1,truk2));

    playInstrument(instruments);

    for (auto inst:instruments) 
	{
        delete inst;
    }

}