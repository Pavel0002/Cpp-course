#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>


using namespace std;


//int getnextmounth(int currentmounth)
//{
//	if (currentmounth != 11) currentmounth++;
//	else currentmounth = 0;
//	return currentmounth;
//}

int main() {

	//int dumbcount = 0;
	//int n, flag;
	//cin >> n;
	//string currentcommand;
	//vector<vector<string>> actions(31);
	//const vector<int> daysinmounth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//int currentmounth = 0;

	//for (int comandindex = 0; comandindex < n; comandindex++)
	//{
	//	cin >> currentcommand;
	//	if (currentcommand == "next")
	//	{
	//		int nextmounth = getnextmounth(currentmounth);
	//		int daysnextmounth = daysinmounth[nextmounth];
	//		int dayscurrentmounth = daysinmounth[currentmounth];
	//		if (daysnextmounth < dayscurrentmounth)
	//		{
	//			for (int daysdiff = dayscurrentmounth - daysnextmounth; daysdiff>0; daysdiff--)
	//			{
	//				for (auto action : actions[dayscurrentmounth - daysdiff])
	//				{
	//					actions[daysnextmounth - 1].push_back(action);
	//				}
	//				actions[dayscurrentmounth - daysdiff].clear();

	//			}
	//		}
	//		currentmounth = nextmounth;
	//	}
	//	else
	//	{
	//		cin >> flag;
	//		if (currentcommand == "add")
	//		{
	//			string currentact;
	//			cin >> currentact;
	//			actions[flag - 1].push_back(currentact);
	//		}
	//		else
	//		{
	//			int ln = actions[flag - 1].size();
	//			cout << ln << ' ';
	//			for (int i = 0; i < ln; i++)
	//			{
	//				cout << actions[flag - 1][i] << ' ';
	//			}
	//			cout << endl;
	//			dumbcount++;

	//		}
	//	}
	//}
	//return 0;

	//map<string, int> s = { {"one",1}, {"two",2} };
	//for (const auto& item : s)
	//{
	//	cout << item.first << ' ' << item.second << endl;
	//}
	//int ss;
	//cin >> ss;

	int queryCount;
	cin >> queryCount;
	map<string, vector<string>> buses2stops;
	map<string, vector<string>> stops2buses;
	string currentCommand;
	for (int queryIndex = 0; queryIndex < queryCount; queryIndex++)
	{
		cin >> currentCommand;
		if (currentCommand == "ALL_BUSES")
		{
			if (buses2stops.size() != 0)
			{
				for (const auto& bus : buses2stops)
				{
					cout << "Bus " << bus.first << ": ";
					for (int stopIndex = 0; stopIndex < bus.second.size(); stopIndex++)
					{
						cout << bus.second[stopIndex] << ' ';
					}
					cout << endl;
				}
			}
			else  cout << "No buses" << endl;
		}
		else if (currentCommand == "NEW_BUS")
		{
			string busName;
			string stopName;
			int stopsCount;
			cin >> busName >> stopsCount;
			for (int stopIndex = 0; stopIndex < stopsCount; stopIndex++)
			{
				cin >> stopName;
				buses2stops[busName].push_back(stopName);
				//тут возможно нужно проверить не содержится уже этот автобус для остановки
				stops2buses[stopName].push_back(busName);
			}
		}
		else if(currentCommand == "BUSES_FOR_STOP")
		{
			string currentStop;
			cin >> currentStop;
			if (stops2buses.count(currentStop) != 0)
			{
				//cout << "Stop " << currentStop << ": ";
				for (const auto& bus : stops2buses[currentStop])
				{
					cout << bus << ' ';
				}
				cout << endl;
			}
			else cout << "No stop" << endl;
		}
		else if (currentCommand == "STOPS_FOR_BUS")
		{
			string currentBus;
			cin >> currentBus;
			if (buses2stops.count(currentBus) != 0)
			{
				//cout << "Bus " << currentBus << ": ";
				for (const auto& stop : buses2stops[currentBus])
				{
					cout << "Stop " <<  stop << ": ";
					int busCount = 0;
					for (const auto& bus : stops2buses[stop])
					{
						if (bus != currentBus)
						{
							cout << bus << ' ';
							busCount++;
						}

					}
					if (busCount == 0) cout << "no interchange";
					cout << endl;
				}
			}
			else cout << "No bus" << endl;
		}
	}
	int s;
	cin >> s;
	return 0;
}