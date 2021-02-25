#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <exception>

using namespace std;

template <typename KeyType, typename ValueType>
ValueType& GetRefStrict(map<KeyType, ValueType>& mp, KeyType k)
{
	try
	{
		return mp.at(k);
	}
	catch(exception& e)
	{
		throw runtime_error(e.what());
	}
	
}



int main() {

	map<int, string> m = { { 0, "value" } };
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue

	int s;
	cin >> s;
	return 0;
}