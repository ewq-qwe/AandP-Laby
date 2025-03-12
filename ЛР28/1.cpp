#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int n,i,j,k=0;
    cout<<"n= ";
    cin>>n;
    int **a=new int*[n];
    for(int i=0;i<n;i++) 
    {
        a[i] = new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=a[i][j];
        }
    }
    cout<<"serednye arifmetychne = ";
float ser=0;
ser=sum/(n*n);
cout<<ser<<endl;


int *b=new int[k];
for(i=0;i<n;i++)
{
	b[i]=0;
    for(j=0;j<n;j++)
    {
        if(a[i][j]<ser)
        {
            b[i]++;
        }
    }
}
ofstream outfile("1.txt");
outfile<<"Kilkist elementiv > za serednye u kozhnomu ryadku: "<<endl;
for(i=0;i<n;i++)
{
	outfile<<"Ryadok "<<i+1<<": "<<b[i]<<"elementiv"<<endl;
}
outfile.close();





    for(i=0;i<n;i++) 
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;
    return 0;
}
