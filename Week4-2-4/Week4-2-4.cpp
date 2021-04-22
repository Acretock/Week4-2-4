#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void bad(ofstream& f) { f << "bad request" << endl; }
struct Person {
	int year;
	int month;
	int day;
	string FirstName;
	string LastName;
};
int main()
{
	int n, m;								// n-students m-commands
	vector<Person> table;
	ifstream fin("text.txt");
	ofstream fout("out.txt");
	string command;
	int num;
	fin >> n ;
	Person tmp;
	for (int i = 0; i < n; i++) {
		fin >> tmp.FirstName >> tmp.LastName >> tmp.day >> tmp.month >> tmp.year;
		table.push_back(tmp);
	}
	//reverse(begin(table), end(table));
	 //while (fin)
	fin >> m;
		 for (int i = 0; i < m; i++) {
			 fin >> command >> num;
			 if (command == "name") {
				 if ((num - 1) < n)
					 fout << table[num - 1].FirstName << ' ' << table[num - 1].LastName << endl;
				 else bad(fout);
			 }
			 else if (command == "date") {
				 if ((num - 1) < n)
					 fout << table[num - 1].day << '.' << table[num - 1].month << '.' << table[num - 1].year << endl;
				 else bad(fout);
			 }
			 else bad(fout);
		 }
	return 0;
}
