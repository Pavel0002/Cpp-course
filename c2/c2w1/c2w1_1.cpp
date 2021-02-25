#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int64_t N;
	cin >> N;
	double averegeTemp = 0;
	int64_t currentTemp = 0;
	vector<int64_t> temps(N);
	for (int i = 0; i < N; i++)
	{
		cin >> currentTemp;
		averegeTemp += static_cast <double> (currentTemp) / static_cast <double>(N);
		temps[i] = currentTemp;
	}
	//vector<int64_t>::iterator it = find_if(temps.begin(), temps.end(), [averegeTemp](int64_t temp) {return temp < averegeTemp; });
	int64_t countAboveAv = 0;
	vector<int64_t> indexesTempAbove;
	for (int i = 0; i < N; i++)
	{
		if (temps[i] > averegeTemp)
		{
			countAboveAv++;
			indexesTempAbove.push_back(i);
		}

	}
	cout << countAboveAv << endl;
	for (const auto& index : indexesTempAbove)
	{
		cout << index << ' ';
	}
	int s;
	cin >> s;
	return 0;
}