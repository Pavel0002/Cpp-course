#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


int main() {
	ifstream input("input.txt");
	string line;
	ofstream output("output.txt");
	if (input) {
		while (getline(input, line)) {
			output << line << endl;
		}
	}
	else {
		cout << "error!" << endl;
	}
	int s;
	cin >> s;
	return 0;
}