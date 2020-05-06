#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string wordCleaner(string word)
{
	string cleanWord;
	int length = word.length();
	int origin = 0;
	int end = length;
	
	if(!((65 <= word[0] && word[0] <= 90) || (97 <= word[0] && word[0] <= 122)))
	{
		origin++;			
	}
	if(!((65 <= word[length - 1] && word[length - 1] <= 90) || (97 <= word[length - 1] && word[length - 1] <= 122)))
	{
		end--;			
	}
	cleanWord = word.substr(origin,end);
	
	
	
return cleanWord;
}

bool repeatWordControl(string word)
{
	
	int length = word.length();
	ifstream rFile( to_string(length) + "_characters.txt");
	if (!rFile.is_open()) 
	{ return false; }
	
	string savedWords;

	while (rFile >> savedWords) {
		if(word == savedWords)
		{ return true; }
	}
	rFile.close();
	return false;
}
void writeToFile(string word)
{
	string fileName = to_string(word.length()) + "_characters.txt";
	ofstream wFile(fileName ,ios::app);
	wFile << word << endl;
	wFile.close();
	
}

void readToFile(string myTextFile)
{
	ifstream rFile(myTextFile);
	if (!rFile.is_open()) 
	{ return; }
	
	string word;
	while (rFile >> word) {
		word = wordCleaner(word);
		if(!repeatWordControl(word))
		{ writeToFile(word); }
		
	}
	rFile.close();
}

int main(void) {

	readToFile("deneme.txt");

	return 0;
}

