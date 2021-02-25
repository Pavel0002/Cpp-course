#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int64_t N;
	cin >> N;
	uint64_t dencity;
	cin >> dencity;
	uint64_t w, h, d;
	uint64_t sum = 0;
	for (int64_t i = 0; i < N; i++)
	{
		cin >> w >> h >> d;
		sum += w * h * d * dencity;
	}
	cout << fixed << setprecision(0) << sum;
	int s;
	cin >> s;
	return 0;
}