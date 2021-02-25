#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <set>

using namespace std;

string String2Lower(string num)
{
	transform(num.begin(), num.end(), num.begin(),
		[](unsigned char c) { return tolower(c); });
	return num;
}
int main() 
{
	int N;
	cin >> N;
	vector<string> numbers(N);
	for (auto& num : numbers)
	{
		cin >> num;
	}
	sort(begin(numbers), end(numbers), [](string x, string y) {return String2Lower(x).compare(String2Lower(y)) < 0; });

	for (const auto& num : numbers)
	{
		cout << num << ' ';
	}
	int s;
	cin >> s;
	return 0;
}