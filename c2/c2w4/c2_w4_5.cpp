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

//template <typename RandomIt>
//pair<RandomIt, RandomIt> FindStartsWith(
//	RandomIt range_begin, RandomIt range_end,
//	char prefix)
//{
//	RandomIt outRange_begin = lower_bound(range_begin, range_end, string(1,prefix));
//	RandomIt outRange_end = lower_bound(range_begin, range_end, string(1,prefix + 1));
//	return make_pair(outRange_begin, outRange_end);
//
//}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt range_begin, RandomIt range_end,
	string prefix)
{
	RandomIt outRange_begin = lower_bound(range_begin, range_end, prefix);
	prefix[size(prefix) - 1]++;
	RandomIt outRange_end = lower_bound(range_begin, range_end,  prefix);
	return make_pair(outRange_begin, outRange_end);

}


int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");

	const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

	const auto mo_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto mt_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
	cout << (mt_result.first - begin(sorted_strings)) << " " <<
		(mt_result.second - begin(sorted_strings)) << endl;

	const auto na_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	cout << (na_result.first - begin(sorted_strings)) << " " <<
		(na_result.second - begin(sorted_strings)) << endl;


	int ss;
	cin >> ss;
	return 0;
}
