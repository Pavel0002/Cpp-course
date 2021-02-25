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
//template <typename RandomIt>
//void MergeSort(RandomIt range_begin, RandomIt range_end)
//{
//	int inputLength = (range_end - range_begin);
//	if ((range_end - range_begin) < 2)
//		return;
//	//посмотреть, как это реализовано в решении coursera
//	//auto workVec = {range_begin, range_end};
//	vector<typename RandomIt::value_type> workVec(range_begin, range_end);
//	auto halfIter = workVec.begin() + inputLength / 2;
//	MergeSort(workVec.begin(), halfIter);
//	MergeSort(halfIter, workVec.end());
//	merge(workVec.begin(), halfIter, halfIter, workVec.end(), range_begin);
//}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
	int inputLength = (range_end - range_begin);
	if ((range_end - range_begin) < 2)
		return;
	//посмотреть, как это реализовано в решении coursera
	//auto workVec = {range_begin, range_end};
	vector<typename RandomIt::value_type> workVec(range_begin, range_end);
	auto thirdIter1 = workVec.begin() + inputLength / 3;
	auto thirdIter2 = workVec.begin() + 2 * inputLength / 3;
	MergeSort(workVec.begin(), thirdIter1);
	MergeSort(thirdIter1, thirdIter2);
	MergeSort(thirdIter2, workVec.end());
	vector<typename RandomIt::value_type> temp;//(thirdIter2 - workVec.begin())
	merge(workVec.begin(), thirdIter1, thirdIter1, thirdIter2, back_inserter(temp));
	merge(temp.begin(), temp.end(), thirdIter2, workVec.end(), range_begin);
}

int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");

	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;

	//vector<int> a = { 1, 2, 3, 4};
	//vector<int> b = { 5, 6, 7, 8 };
	//vector<int> c(8);
	//merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	//for (int x : c) {
	//	cout << x << " ";
	//}
	//cout << endl;


	int ss;
	cin >> ss;
	return 0;
}
