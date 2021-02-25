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

	int querryCount;
	cin >> querryCount;
	map<set<string>, int> paths2Buses;
	int currentNumber = 1;
	for (int queryIndex = 0; queryIndex < querryCount; queryIndex++)
	{
		int stopsCount;
		cin >> stopsCount;
		set<string> currentPath;
		string currentStop;
		for (int stopIndex = 0; stopIndex < stopsCount; stopIndex++)
		{
			cin >> currentStop;
			currentPath.insert(currentStop);
		}
		if (paths2Buses.count(currentPath) != 0)
		{
			cout << "Already exists for " << paths2Buses[currentPath] << endl;
		}
		else
		{
			paths2Buses[currentPath] = currentNumber;
			cout << "New bus " << currentNumber << endl;
			currentNumber++;
		}
	}
	//int s;
	//cin >> s;
	return 0;
}