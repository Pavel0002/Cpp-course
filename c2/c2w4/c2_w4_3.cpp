#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>


using namespace std;

//void TestWorks() {
//	//AssertEqual(1, 1, "Just to check that Assert works");
//	PhoneNumber n1("+7-495-111-22-33");
//	PhoneNumber n2("+7-495-1112233");
//	PhoneNumber n3("+1-2-coursera-cpp");
//	AssertEqual(n1.GetCityCode(), "495", "T1");
//	AssertEqual(n1.GetCountryCode(), "7", "T2");
//	AssertEqual(n1.GetLocalNumber(), "111-22-33", "T3");
//	AssertEqual(n1.GetInternationalNumber(), "+7-495-111-22-33", "T4");
//
//}

//bool f(int s)
//{
//	return s > 6;
//}
int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");

	int N;
	cin >> N;

	vector<int> numbers(N);
	
	for (size_t i = 1; i <= N; i++)
	{
		numbers[i-1] = i;
	}

	set<vector<int>> permutations;

	do {
		permutations.insert(numbers);
	} while (next_permutation(numbers.begin(), numbers.end()));

	for (auto rIt = permutations.rbegin(); rIt != permutations.rend(); rIt++)
	{
		for (size_t vecIndex = 0; vecIndex < N; vecIndex++)
		{
			cout << (*rIt)[vecIndex] << ' ';
		}
		cout << endl;
	}


	int ss;
	cin >> ss;
	return 0;
}
