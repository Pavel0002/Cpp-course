#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


int main() {
	ifstream input("input.txt");
	string line;
	//ofstream output("D:/output.txt");

	//if (!output) cout << "errorOutput!";
	if (input) {
		int N, M;
		input >> N >> M;
		for (int rowIndex = 0; rowIndex < N; rowIndex++)
		{
			for (int colIndex = 0; colIndex < M; colIndex++)
			{
				int currentNum;
				input >> currentNum;
				cout << setw(10) << currentNum;
				//output << setw(10) << currentNum;
				if (colIndex != M - 1)
				{
					input.ignore(1);
					cout << ' ';
					//output << ' ';
				}
			}
			if (rowIndex != N - 1)
			{
				//output << endl;
				cout << endl;
			}
		}
	}
	else {
		cout << "error!" << endl;
	}
	int s;
	cin >> s;
	return 0;
}


//int main() {
//
//	std::ofstream ofs("c:/test.txt", std::ofstream::out);
//
//	ofs << "lorem ipsum";
//
//	ofs.close();
//
//	return 0;
//}