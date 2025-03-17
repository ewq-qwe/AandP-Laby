#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	ifstream file("1.txt");
	if(!file)
	{
		cout<<"Do not open";
		return 1;
	}
	char text[1000];
	file.read(text,sizeof(text));
	file.close();
	char* threewords[1000];
	char* nonwords[1000];
	int cthree=0,cnon=0,i;
	
	char* token=strtok(text," ,.-\n\r\t");
	while(token)
	{
		char *word=new char[strlen(token)+1];
		strcpy(word,token);
		if(strlen(word)==3)
		{
			threewords[cthree]=word;
			cthree++;
		}
		if(!(word[0]>='A'&&word[0]<='Z'))
		{
			nonwords[cnon]=word;
			cnon++;
		}
		token=strtok(NULL," ,.-\n\r\t");
	}
	
	cout<<"3 letters"<<endl;
	for(i=0;i<cthree;i++)
	{
		cout<<threewords[i]<<" ";
	}
	cout<<endl;
	cout<<"without big letter"<<endl;
	for(i=0;i<cnon;i++)
	{
		cout<<nonwords[i]<<" ";
	}
	cout<<endl;
	
	char searchword[20];
	cout<<"Vvedit slovo dlya poshuku"<<endl;
	cin>>searchword;
	
	for(i=0;searchword[i];i++)
	{
		if(searchword[i]>='A'&&searchword[i]<='Z')
		{
			searchword[i]+=('a'-'A');
		}
	}
	file.open("1.txt");
	file.read(text,sizeof(text));
	file.close();
	int cword=0;
	token=strtok(text," ,.-\n\r\t");
	while(token)
	{
		char *word=new char[strlen(token)+1];
		strcpy(word,token);
		for(i=0;word[i];i++)
	{
		if(word[i]>='A'&&word[i]<='Z')
		{
			word[i]+=('a'-'A');
		}
	}
	if(strcmp(word,searchword)==0)
	cword++;
	delete[]word;
	token=strtok(NULL," ,.-\n\r\t");
	}
	cout<<"Kilkist povtoren "<<cword;
	
	for(i=0;i<cthree;i++) 
	delete []threewords[i];
	
	for(i=0;i<cnon;i++) 
	delete []nonwords[i];
	
	
	
	return 0;
}
