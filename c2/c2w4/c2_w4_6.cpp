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
#include <deque>


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


//int main() {
//	//TestRunner tr;
//	//tr.RunTest(TestWorks, "TestWorks");
//	int currentNumber;
//	deque<string> expression;
//	cin >> currentNumber;
//	expression.push_back(to_string(currentNumber));
//	expression.push_back(")");
//	expression.push_front("(");
//	int N;
//	cin >> N;
//	for (size_t i = 0; i < N; i++)
//	{
//		char operation;
//		cin >> operation;
//		cin >> currentNumber;
//		expression.push_back(" ");
//		expression.push_back(string(1,operation));
//		expression.push_back(" ");
//		expression.push_back(to_string(currentNumber));
//		expression.push_back(")");
//		expression.push_front("(");
//	}
//	expression.pop_back();
//	expression.pop_front();
//
//	for (auto item : expression)
//	{
//		cout << item;
//	}
//	int ss;
//	cin >> ss;
//	return 0;
//}
int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");
	int currentNumber;
	deque<string> expression;
	cin >> currentNumber;
	expression.push_back(to_string(currentNumber));
	int N;
	cin >> N;
	int currentPriority = 0;
	int prevPriority = 1;
	for (size_t i = 0; i < N; i++)
	{
		char operation;
		cin >> operation;
		if (operation == '*' || operation == '/')
			currentPriority = 1;
		else
			currentPriority = 0;
		cin >> currentNumber;
		if (currentPriority > prevPriority)
		{
			expression.push_back(")");
			expression.push_front("(");
		}
		expression.push_back(" ");
		expression.push_back(string(1,operation));
		expression.push_back(" ");
		expression.push_back(to_string(currentNumber));
		prevPriority = currentPriority;
	}

	for (auto item : expression)
	{
		cout << item;
	}
	int ss;
	cin >> ss;
	return 0;
}
