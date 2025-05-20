#include <iostream>
using namespace std;

class Notification
{
  public:
  string title;
  string message;
  Notification(){}
  Notification(string t, string m)
  {
    title=t;
    message=m;
  }
  virtual void display()
  {
    cout<<"Title: "<<title<<endl;
    cout<<"Message: "<<message<<endl;
  }
};

class Important:public Notification
{
  public:
  string level;
  Important(string t,string m,string l)
  {
    title=t;
    message=m;
    level=l;
  }
  void display() override
  {
    cout<<"Title: "<<title<<endl;
    cout<<"Message: "<<message<<endl;
    cout<<"Level: "<<level<<endl;
  }
  void displayWithAction(auto action)
  {
    display();
    if (level=="high")
    {
      action();
    }
  }
};

int main()
{
  Important n("Attention!","Emergency!","high");
  Important n1("Attention!","Emergency!","low");
  n.displayWithAction([]()
  {
    cout<<"Need to approve!"<<endl;
  });
  cout<<endl;
  n1.displayWithAction([]()
  {
    cout<<"Need to approve!"<<endl;
  });

  return 0;
}
