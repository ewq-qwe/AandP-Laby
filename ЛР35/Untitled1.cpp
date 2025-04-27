#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class wordstring 
{
    string word;
public:
    wordstring(const string& w) : word(w) {}
    string getword() const {return word;}
};


bool isvowels(char c)
{
	string vowels="aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";
	for(char v:vowels)
	{
		if(c==v)
		{
			return true;
		}
	}
	return false;
}

vector<string> splitsentences(const string& text) {
    vector<string> sentences;
    string sentence;
    for (char ch:text) {
        sentence+=ch;
        if (ch =='.'||ch=='!'||ch=='?') {
            sentences.push_back(sentence);
            sentence.clear();
        }
    }
    if (!sentence.empty())
        sentences.push_back(sentence);
    return sentences;
}

int countvowel(string&word)
{
	return count_if(word.begin(),word.end(),isvowels);
}

string joinwords(const vector<string>& words) 
{
    string result;
    for (const string& word:words) 
    {
        result+=word+" ";
    }
    return result;
}

vector<string>splitword(const string&text)
{
	vector<string> words;
	string word;
	for(char c:text)
	{
		if(isalnum(c)||c=='-')
		word+=c;
		else if(!word.empty())
		{
			words.push_back(word);
			word.clear();
		}
	}
	if(!word.empty())
	{
		words.push_back(word);
	}
	return words;
}

int countwordoccurrences(const string& text, const string& word) {
    vector<string> words=splitword(text);
    int count=0;
    for (const auto& w:words) 
	{
        if(w==word)
            count++;
    }
    return count;
}


string removebetweenfirstandlast(const string& text, const string& word) {
    size_t first=text.find(word);
    size_t last=text.rfind(word);

    if (first==string::npos||last==string::npos||first==last)
        throw runtime_error("Cannot remove text - word not found twice.");

    string result=text.substr(0,first+word.length())+text.substr(last);
    return result;
}

bool caseinsensitivecompare(const string& s1, const string& s2)
{
    if (s1.size() != s2.size())
        return false;

    for (size_t i = 0; i < s1.size(); i++) 
    {
        if (tolower(s1[i]) != tolower(s2[i]))
            return false;
    }
    return true;
}


void taskA(vector<string>& modifiedtext)
{
	ifstream fin("z1.txt");
	string text((istreambuf_iterator<char>(fin)),istreambuf_iterator<char>());
	fin.close();
	
	
	vector<string>words=splitword(text);
	
	for(string& word:words)
	{
		int count=countvowel(word);
		if(count>2)
		{
			modifiedtext.push_back(word+" "+word+" ");
		}
		else
		{
			modifiedtext.push_back(word);
		}
	}
}

void taskB(vector<pair<string,int>>&topwords)
{
	ifstream fin("z1.txt");
	string text((istreambuf_iterator<char>(fin)),istreambuf_iterator<char>());
	fin.close();
	
	vector<string> allwords=splitword(text);
	vector<pair<string,int>>uniquewords;
		for(string& w:allwords)
		{
			auto it=find_if(uniquewords.begin(),uniquewords.end(),[&](pair<string,int>&p)
			{
				return p.first==w;
			});
			
			if(it!=uniquewords.end())
			{
				it->second++;
			}
			else
			{
				uniquewords.emplace_back(w,1);
			}
		}
	sort(uniquewords.begin(), uniquewords.end(), [](const pair<string, int>& a, const pair<string, int>& b) 
	{
    	return a.first.size() > b.first.size();
	});

	for(int i=0;i<3&&i<uniquewords.size();i++)
	{
		topwords.push_back(uniquewords[i]);
	}
}

void taskC(const string&text,const string&keyword,vector<string>&foundword)
{
	vector<string>sentences=splitsentences(text);
	for(string&s:sentences)
	{
		vector<string>word=splitword(s);
		for(string&w:word)
		{
			if(caseinsensitivecompare(w,keyword))
			{
				foundword.push_back(s);
				break;
			}
		}
	}
}

void taskD(const string& originaltext) {
    cout<<"Write word to perevirka: ";
    string word;
    cin>>word;

    try {
        wordstring ws(word);
        int count=countwordoccurrences(originaltext, ws.getword());
        if (count<=1)
            throw runtime_error("Slovo znaideno 1 raz abo ne znaideno.");

        string modifiedtext=removebetweenfirstandlast(originaltext, ws.getword());

        ofstream fout("z3.txt");
        fout<<"Slovo: "<< ws.getword()<<endl;
        fout<<"Zustrichaetsya: "<<count<<" raziv"<<endl;
        fout<<"Result: "<<endl<<modifiedtext<<endl;
        fout.close();

        cout<<"Result writed in z3.txt"<<endl;
    }
    catch (runtime_error& e) {
        cout<<"Error: "<<e.what()<<endl;
    }
}

void taskE(const vector<string>& originalwords) {
    ifstream fin("t.txt");

	vector<string> twords;
    string word;
    while (fin>>word) 
	{
        twords.push_back(word);
        if (twords.size()==originalwords.size())
            break;
    }
    fin.close();
    string s1 = joinwords(twords);
    string s2 = joinwords(originalwords);
    vector<string>combinedwords=twords;
    combinedwords.insert(combinedwords.end(), originalwords.begin(), originalwords.end());
    sort(combinedwords.begin(),combinedwords.end());

    string s3 = joinwords(combinedwords);
    
    ofstream fout("z4.txt");
    fout<<"s1: "<<s1<<endl;
    fout<<"s2: "<<s2<<endl;
    fout<<"s3 (vidsortovanni): "<<s3<<endl;
    fout.close();

    cout << "Result in z4.txt"<<endl;
}

string readfile(const string& filename) {
    ifstream fin(filename);
    return string((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
}


int main()
{
	string inputPath;
    cout <<"Write path: ";
    getline(cin, inputPath);
    ifstream fin(inputPath);

	string filename="z1.txt"; 
    string text=readfile(filename);
    cout<<text;

    vector<string>words=splitword(text);
    vector<string>modifiedwords=words;
    vector<pair<string, int>> topwords;
    vector<string>matchedsentences;
	
	int choice;
    do {
        cout << "Menu"<<endl;
        cout << "1. Double words with >2 golosni(A)"<<endl;
        cout << "2. Znaity 3 naydovshih slova (B)"<<endl;
        cout << "3. Vyvesty rechennya z pevnym slovom (C)"<<endl;
        cout << "4. Vikonaty vse ta zberegty v z2.txt (D)"<<endl;
        cout << "5. Robota z parametrizovanym konstructorom (E)"<<endl;
        cout << "6. Robota z ryadkamy s1, s2, s3 (F)"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Your choice: "<<endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                taskA(modifiedwords);
                cout << "Dublyuvannya vikonano"<<endl;
                break;
            case 2:
                taskB(topwords);
                cout << "Znaideno 3 naydovshih slova"<<endl;
                for (auto& p : topwords)
                    cout << p.first << " - " << p.second << endl;
                break;
            case 3: {
                string searchword;
                cout << "Write slovo dlya poshyky: ";
                getline(cin, searchword);
                taskC(text, searchword, matchedsentences);
                for (auto& sentence : matchedsentences)
                    cout << sentence << endl;
                break;
            }
            case 4: {
                ofstream fout("z2.txt");
                fout << "Result a)"<<endl;
                fout << joinwords(modifiedwords) <<endl;

                fout << "Result b): "<<endl;
                for (auto& p : topwords)
                    fout << p.first << " – " << p.second <<endl;

                fout << "Result c): "<<endl;
                for (auto& sentence : matchedsentences)
                    fout << sentence << endl;

                fout.close();
                cout << "Result writed in z2.txt\n";
                break;
            }
            case 5:
                taskD(text);
                break;
            case 6:
                taskE(words);
                break;
            case 0:
                cout << "End"<<endl;
                break;
            default:
                cout << "Nevirniy vybir"<<endl;
        }
    }while(choice!=0);
	
	return 0;
}