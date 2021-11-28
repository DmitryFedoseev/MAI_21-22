#include <iostream>
#include <string>
#include <map>
using namespace std;

void mapFunction(string inputStr)
{
	map<string, int> mv;
	int first, last;
	first = last = 0;
	string word;

	for (int i = 0; i < inputStr.size(); i++)
	{
		if (inputStr[i] == ' ')
		{
			last = i;
			word = inputStr.substr(first, last - first);
			if (mv.find(word) == mv.end())
				mv.emplace(word, 1);
			else
				mv[word]++;
			first = last + 1;
		}
	}

	last = word.size();
	word = inputStr.substr(first, last - first);
	if (mv.find(word) == mv.end())
		mv.emplace(word, 1);
	else
		mv[word]++;

	map <string, int> ::iterator it = mv.begin();
	for (int i = 0; it != mv.end(); it++, i++) 
	{
		cout << it->first << ' ' << it->second << endl;
	}
}

int main()
{
	cout << "Enter the string:" << endl;
	string inputStr;
	getline(cin, inputStr);
	mapFunction(inputStr);
}