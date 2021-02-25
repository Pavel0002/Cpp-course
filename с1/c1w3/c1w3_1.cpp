#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <set>

using namespace std;


int main() 
{
	int N;
	cin >> N;
	vector<int> numbers(N);
	for (auto& num : numbers)
	{
		cin >> num;
	}
	sort(begin(numbers), end(numbers), [](int x, int y) {return abs(x) < abs(y); });
	for (const auto& num : numbers)
	{
		cout << num << ' ';
	}
	int s;
	cin >> s;
	return 0;
}