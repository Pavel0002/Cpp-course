#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>


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
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
	vector<T> outputVec;
	auto borderIt = find_if(elements.begin(), elements.end(), [border](T x) {return x > border; });
	if (borderIt != elements.end())
	{
		for (auto iter = borderIt; iter != elements.end(); iter++)
		{
			outputVec.push_back(*iter);
		}
	}
	return outputVec;
}
//
//template <typename T>
//vector<T> FindGreaterElements(const set<T>& elements, const T& border)
//{
//	vector<T> outputVec;
//	for (auto element : elements)
//	{
//		if (element > border)
//		{
//			outputVec.push_back(element);
//		}
//	}
//	return outputVec;
//}
//


int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
	int s;
	cin >> s;
	return 0;
}
