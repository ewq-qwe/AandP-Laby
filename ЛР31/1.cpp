#include <iostream>
using namespace std;

class flat
{
	private:
	string address;
	int floor;
	int rooms;
	double area;
	
	public:
		flat():address(""),floor(0),rooms(2),area(55.0) {}
		flat(string addr,int fl):address(addr),floor(fl),rooms(2),area(55.0){}
		
		void input()
		{
			cout<<"Adress ";
			cin.ignore();
			getline(cin,address);
			cout<<"Floor ";
			cin>>floor;
			cout<<"Rooms ";
			cin>>rooms;
			cout<<"Area";
			cin>>area;
		}
		
		void display()
		{
			cout<<"Adress "<<address<<". Floor "<<floor<<". Rooms "<<rooms<<". Area "<<area<<endl;
		};
		
		int getroom() {return rooms;}
		int getarea(){return area;}
		int getfloor(){return floor;}
};
	void displayflat(flat flats[],int n,int countroom)
	{
		cout<<"Flat with "<<countroom<<" rooms."<<endl;
		for(int i=0;i<n;i++)
		{
			if(flats[i].getroom()==countroom)
			{
				flats[i].display();
			}
		}
	}
	void displayareafloor(flat flats[],int n,int maxfloor,int minfloor)
	{
		cout<<"Flats to 40 m2 and floor beetween "<<minfloor<<" and "<<maxfloor<<endl;
		for(int i=0;i<n;i++)
		{
			if(flats[i].getarea()<40&&flats[i].getfloor()>=minfloor&&flats[i].getfloor()<=maxfloor)
			{
				flats[i].display();
				cout<<endl;
			}
		}
	}
int main()
{
	int n=3;
	flat flats[n];
	flats[0]=flat("vul. Rus'ka, 10",5);
	flats[1]=flat("vul. Rivnenska, 15",3);
	cout<<"Add flat 3 "<<endl;
	flats[2].input();
	
	cout<<"Flats"<<endl;
	for(int i=0;i<n;i++)
	{
		flats[i].display();
	}
	int search;
	cout<<"Write rooms for search ";
	cin>>search;
	displayflat(flats,n,search);
	cout<<endl;
	int min,max;
	cout<<"Write min and max for search flat who have < 40 m2 "<<endl;
	cin>>min>>max;
	displayareafloor(flats,n,max,min);
	return 0;
}
