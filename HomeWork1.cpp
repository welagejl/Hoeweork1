#include <iostream>
#include <string>
#include<fstream>
#include <string>
using namespace std;

struct textInfo
{
	string title;
	string authorNameFirst;
	string authorNameLast;
	int wordCount;
	int lineCount;
	double letterFreq;
};

double calcLetFreq()
{
	return 0.0;
}
void wordCount(ifstream &info, int &wordCount) {
	string dataRead;
	while (info >> dataRead){
		if (dataRead == "Contents:")
			continue;
		else
			wordCount++;
	}
}

int main()
{
	ifstream info;
	string fileName;
	int words = 0;
	textInfo dataStore;

	cout << "Enter file name: " << endl;
	cin >> fileName;

	info.open(fileName, ios::in);
	string dataRead;

	if (info.is_open()) {
		getline(info, dataRead);
		dataStore.title = dataRead;
		info >> dataRead;
		dataStore.authorNameFirst = dataRead;
		info >> dataRead;
		dataStore.authorNameLast = dataRead;

		wordCount(info, words);
		dataStore.wordCount = words;
	}
	return 0;
}