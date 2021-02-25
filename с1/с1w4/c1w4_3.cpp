#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


int main() {
	ifstream input("input.txt");
	string line;
	if (input) {
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "error!" << endl;
	}
	int s;
	cin >> s;
	return 0;
}