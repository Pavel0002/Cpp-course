#include <iostream>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

const map<string, QueryType> strQ2enumQ = { { "NEW_BUS", QueryType::NewBus },{ "BUSES_FOR_STOP", QueryType::BusesForStop },
{ "STOPS_FOR_BUS", QueryType::StopsForBus },{ "ALL_BUSES", QueryType::AllBuses } };

istream& operator >> (istream& is, Query& q) {
	// ���������� ��� �������
	string operation_code;
	cin >> operation_code;
	q.type = strQ2enumQ.at(operation_code);
	if (operation_code == "NEW_BUS") {

		string bus;
		cin >> bus;
		int stop_count;
		cin >> stop_count;
		q.bus = bus;
		q.stops.resize(stop_count);

		for (string& stop : q.stops) {
			cin >> stop;
		}

	}
	else if (operation_code == "BUSES_FOR_STOP") {

		string stop;
		cin >> stop;
		q.stop = stop;

	}
	else if (operation_code == "STOPS_FOR_BUS") {

		string bus;
		cin >> bus;
		q.bus = bus;
	}
	//else if (operation_code == "ALL_BUSES") {

	//}
	return is;
}

struct BusesForStopResponse {
	// ��������� ������ ��� ���������
	string response;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	// ���������� ��� �������
	os << r.response;
	return os;
}

struct StopsForBusResponse {
	// ��������� ������ ��� ���������
	string response;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	// ���������� ��� �������
	os << r.response;
	return os;
}

struct AllBusesResponse {
	// ��������� ������ ��� ���������
	string response;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	// ���������� ��� �������
	os << r.response;
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		// ���������� ���� �����
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}
	BusesForStopResponse GetBusesForStop(const string& stop) const {
		// ���������� ���� �����
		BusesForStopResponse rs;
		if (stops_to_buses.count(stop) == 0) {
			rs.response += "No stop\n";
		}
		else {
			for (const string& bus : stops_to_buses.at(stop)) {
				rs.response += bus + " ";
			}
			rs.response += "\n";
		}
		return rs;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		// ���������� ���� �����
		StopsForBusResponse rs;
		if (buses_to_stops.count(bus) == 0) {
			rs.response += "No bus\n";
		}
		else {
			for (const string& stop : buses_to_stops.at(bus)) {
				rs.response += "Stop " + stop + ": ";
				if (stops_to_buses.at(stop).size() == 1) {
					rs.response += "no interchange";
				}
				else {
					for (const string& other_bus : stops_to_buses.at(stop)) {
						if (bus != other_bus) {
							rs.response += other_bus + " ";
						}
					}
				}
				rs.response += "\n";
			}
		}
		return rs;

	}

	AllBusesResponse GetAllBuses() const {
		// ���������� ���� �����
		AllBusesResponse rs;
		if (buses_to_stops.empty()) {
			rs.response +=  "No buses\n" ;
		}
		else {
			for (const auto& bus_item : buses_to_stops) {
				rs.response += "Bus " + bus_item.first + ": ";
				for (const string& stop : bus_item.second) {
					rs.response +=  stop + " ";
				}
				rs.response += "\n";
			}
		}
		return rs;
	}
private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

// �� ����� ���� ������� main, ���������� ������� � ������ ����

int main() {
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
}
