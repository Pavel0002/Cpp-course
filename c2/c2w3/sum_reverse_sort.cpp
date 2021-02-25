#include <string>
#include <vector>
#include <algorithm>
#include "sum_reverse_sort.h"

using namespace std;

int Sum(int x, int y)
{
	return x + y;
}
string Reverse(string s)
{
	string d = s;
	reverse(d.begin(), d.end());
	return d;
}
void Sort(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
}
