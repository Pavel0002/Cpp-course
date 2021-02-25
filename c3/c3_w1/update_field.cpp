#include "airline_ticket.h"
#include "test_runner.h"

#include <iterator>
#include <map>
using namespace std;

#define UPDATE_FIELD(ticket, field, values) \
if (values.find(#field) != values.end()) {	\
	istringstream is(values.find(#field)->second);			\
	is >> ticket.field;						\
}
// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time

istream& operator >> (istream& iStr, Date& dt)
{
	iStr >> dt.year;
	iStr.ignore(1);
	iStr >> dt.month;
	iStr.ignore(1);
	iStr >> dt.day;
	return iStr;
}

istream& operator >> (istream& iStr, Time& dt)
{
	iStr >> dt.hours;
	iStr.ignore(1);
	iStr >> dt.minutes;
	return iStr;
}

bool operator==(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.year, lhs.month, lhs.day} ==
		vector<int>{rhs.year, rhs.month, rhs.day};
}

ostream& operator<<(ostream& outStr, const Date& rhs) {
	outStr << rhs.year << " " << rhs.month << " " << rhs.day;
	return outStr;
}

bool operator==(const Time& lhs, const Time& rhs) {
	return vector<int>{lhs.hours, lhs.minutes} ==
		vector<int>{rhs.hours, rhs.minutes};
}

ostream& operator<<(ostream& outStr, const Time& rhs) {
	outStr << rhs.hours << " " << rhs.minutes;
	return outStr;
}



void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };

  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
  int sdf;
  cin >> sdf;
}
