#include <iostream>
#include <string>
#include<fstream>
#include <string>
using namespace std;

struct textInfo{
	string title;
	string authorNameFirst;
	string authorNameLast;
	int wordCount;
	int lineCount;
	double letterFreq;
};

double calcLetFreq(ifstream &info, int pos){
	info.clear();
	info.seekg(pos);
	char letter;
	int countOfLetter[26], total;
	while (info >> letter) {
		switch (tolower(letter)) {
		case 'a':
			countOfLetter[0] += 1;
			total++;
			break;
		case 'b':
			countOfLetter[1] += 1;
			total++;
			break;
		case 'c':
			countOfLetter[2] += 1;
			total++;
			break;
		case 'd':
			countOfLetter[3] += 1;
			total++;
			break;
		case 'e':
			countOfLetter[4] += 1;
			total++;
			break;
		case 'f':
			countOfLetter[5] += 1;
			total++;
			break;
		case 'g':
			countOfLetter[6] += 1;
			total++;
			break;
		case 'h':
			countOfLetter[7] += 1;
			total++;
			break;
		case 'i':
			countOfLetter[8] += 1;
			total++;
			break;
		case 'j':
			countOfLetter[9] += 1;
			total++;
			break;
		case 'k':
			countOfLetter[10] += 1;
			total++;
			break;
		case 'l':
			countOfLetter[11] += 1;
			total++;
			break;
		case 'm':
			countOfLetter[12] += 1;
			total++;
			break;
		case 'n':
			countOfLetter[13] += 1;
			total++;
			break;
		case 'o':
			countOfLetter[14] += 1;
			total++;
			break;
		case 'p':
			countOfLetter[15] += 1;
			total++;
			break;
		case 'q':
			countOfLetter[16] += 1;
			total++;
			break;
		case 'r':
			countOfLetter[17] += 1;
			total++;
			break;
		case 's':
			countOfLetter[18] += 1;
			total++;
			break;
		case 't':
			countOfLetter[19] += 1;
			total++;
			break;
		case 'u':
			countOfLetter[20] += 1;
			total++;
			break;
		case 'v':
			countOfLetter[21] += 1;
			total++;
			break;
		case 'w':
			countOfLetter[22] += 1;
			total++;
			break;
		case 'x':
			countOfLetter[23] += 1;
			total++;
			break;
		case 'y':
			countOfLetter[24] += 1;
			total++;
			break;
		case 'z':
			countOfLetter[25] += 1;
			total++;
			break;
		default:
			break;
		}
		char letterRep = 'a';
		for (auto &i : countOfLetter) {
			cout << letterRep << ":%" << (double)(i / total) * 100.0;
			//https://stackoverflow.com/questions/8487255/how-do-i-increment-letters-in-c
			static_cast<char>(letterRep + 1);
		}
	}
	return 0.0;
}
void wordCount(ifstream &info, int &wordCount,int &pos) {
	string dataRead;
	while (info >> dataRead){
		if (dataRead == "Contents:") {
			pos = info.tellg();
			continue;
		}
		else
			wordCount++;
	}
}
void writeToFile(textInfo dataStore) { 
	
	fstream write;
	write.open("CardText.txt", ios::in);
	if (write.fail()) {
		write.open("CardText.txt", ios::out);
		write.close();
		write.open("CardText.txt", ios::in);
	}
	write << "Title: " << dataStore.title << endl;
	write << "Full Author: " << dataStore.authorNameFirst << " " << dataStore.authorNameLast << endl;
	write << "Author First Name: " << dataStore.authorNameFirst << endl;
	write << "Author Last Name: " << dataStore.authorNameLast << endl;
	write << "Word Count: " << dataStore.wordCount << endl;
	write << "Line count: " << dataStore.lineCount << endl;
	write.close()

 }

void lineCount(ifstream &info, int &lineCount, int pos) {
	string fillerLine;
	info.clear();
	info.seekg(pos);
	while (getline(info, fillerLine))
		lineCount++;

}

int main()
{
	ifstream info;
	string fileName;
	int words = 0, pos = 0, lines = 0;
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

		wordCount(info, words, pos);
		dataStore.wordCount = words;
		lineCount(info, lines, pos);
		dataStore.lineCount = lines - 1;
		writeToFile(dataStore);

		char choice;
		cout << "Do you want to calculate letter frequency?(y/n) " << endl;
		cin >> choice;
		if (choice == 'y')
			calcLetFreq(info, pos);
		else
			writeToFile(dataStore);
	}
	return 0;
}