#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "test_runner.h"
#include "bus_manager.h"
#include "query.h"

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


int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
	int s;
	cin >> s;
	return 0;
}
