#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstring>
using namespace std;

char** createmat(int n)
{
	char vowels[]="aeiou";
	char consonants[]="bcdfghjklmnpqrstvwxyz";
	char**matrix=new char*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i]=new char[n];
	}
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
	if(i==j||i+j==n-1)
	{
		matrix[i][j]=vowels[rand()%5];
		}	
		else
		{
			matrix[i][j]=consonants[rand()%21];
		}
	}
	}
	return matrix;
}

bool searchrow(char**matrix,int n,char *word, int &row, int &colstart,int &colend)
{
	int wordlen=strlen(word);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n-wordlen;j++)
		{
		bool found=true;
		for(int k=0;k<wordlen;k++)
		{
			if(matrix[i][j+k]!=word[k])
			{
				found=false;
				break;
			}
		}
			if(found)
			{
				row=i;
				colstart=j;
				colend=j+wordlen-1;
				return true;
			}
		
		}
	}
	return false;
}

bool searchcol(char**matrix,int n,char* word,int &col,int &rowstart,int &rowend)
{
	int wordlen=strlen(word);
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<=n-wordlen;i++)
		{
			bool found=true;
			for(int k=0;k<wordlen;k++)
			{
				if(matrix[i+k][j]!=word[k])
				{
					found=false;
					break;
				}
			}
				if(found)
				{
					col=j;
					rowstart=i;
					rowend=i+wordlen-1;
					return true;
				}
			
		}
	}
	return false;
}

int main()
{
	srand(time(NULL));
	int n,i,j;
	
	cout<<"n= ";
	cin>>n;
	char**matrix=createmat(n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	char word[20];
	cout<<"Vpishit slovo ";
	cin>>word;
	int row,colstart,colend;
	if(searchrow(matrix,n,word,row,colstart,colend))
	{
		cout<<"Slovo znaideno u ryadku "<<row+1<<" (vid "<<row+1<<","<<colstart+1<<" do "<<row+1<<","<<colend+1<<")"<<endl;
	}
	else
	{
		cout<<"Slovo ne znaideno"<<endl;
	}
	int col,rowstart,rowend;
	if(searchcol(matrix,n,word,col,rowstart,rowend))
	{
		cout<<"Slovo znaideno u stovbtsi "<<col+1<<" (vid "<<rowstart+1<<","<<col+1<<" do "<<rowend+1<<","<<col+1<<")"<<endl;
	}
	else
	{
		cout<<"Slovo ne znaideno"<<endl;
	}
	for(i=0;i<n;i++)
	{
		delete []matrix[i];
	}
	delete []matrix;

	return 0;	
}
