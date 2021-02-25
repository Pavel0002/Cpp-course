#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	int GetYear() const
	{
		return year;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}
	void SetYear(int new_year)
	{
		year = new_year;
	}
	void SetMonth(int new_month)
	{
		month = new_month;
	}
	void SetDay(int new_day)
	{
		day = new_day;
	}
private:
	int year = 0;
	int month = 0;
	int day = 0;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	int dateLhs = lhs.GetYear() * 10000 + lhs.GetMonth() * 100 + lhs.GetDay();
	int dateRhs = rhs.GetYear() * 10000 + rhs.GetMonth() * 100 + rhs.GetDay();
	return dateLhs < dateRhs;
}
ostream& operator<<(ostream& streamIn, const Date& lhs)
{
	streamIn << setw(4) << setfill('0') << lhs.GetYear() << '-' 
			 << setw(2) << setfill('0') <<lhs.GetMonth() << '-' 
		     << setw(2) << setfill('0') << lhs.GetDay();
	return streamIn;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event)
	{
		events[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event)
	{
		if (events.count(date) > 0)
		{
			if (events.at(date).count(event) != 0)
			{
				events[date].erase(event);
				return true;
			}
			else return false;
		}
		else return false;
	}
	int  DeleteDate(const Date& date)
	{
		int eventsCount = 0;
		if (events.count(date) > 0)
		{
			eventsCount = events[date].size();
			events.erase(date);
		}
		return eventsCount;
	}

	set<string> Find(const Date& date) const
	{
		if (events.count(date) > 0)
		{
			return events.at(date);
		}
		return set<string>();
	}
	void Print() const
	{
		for (const auto& eventDay : events)
		{
			for (const auto& event : eventDay.second)
			{   
				cout << eventDay.first << ' ' << event << endl;
			}
		}
	}
private:
	//события будут все непустые
	map<Date, set<string>> events;
};

vector<string> SplitString(const string& stringToSplit, char splittingChar = ' ')
{
	std::stringstream test(stringToSplit);
	std::string segment;
	std::vector<std::string> seglist;

	while (std::getline(test, segment, splittingChar))
	{
		seglist.push_back(segment);
	}
	return seglist;
}

bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

bool ReadDate(Date& currentDate, const string& dateString)
{
	bool isDateCorrect = true;
	vector<string> currentDateSegments = SplitString(dateString, '-');
	int datePositions = 3;
	if (currentDateSegments.size() == datePositions)
	{
		vector<int> yearMonthDay(datePositions);
		int currentIndex = 0;
		for (const auto& dateItem : currentDateSegments)
		{
			if (isInteger(dateItem))
			{
				yearMonthDay[currentIndex] = stoi(dateItem);
			}
			else
			{
				isDateCorrect = false;
			}
			currentIndex++;
		}
		int yearIndex = 0;
		int monthIndex = 1;
		int dayIndex = 2;
		currentDate.SetYear(yearMonthDay[yearIndex]);
		currentDate.SetMonth(yearMonthDay[monthIndex]);
		currentDate.SetDay(yearMonthDay[dayIndex]);
	}
	else
	{
		isDateCorrect = false;
	}
	if (!isDateCorrect)
	{
		cout << "Wrong date format: " << dateString << endl;
	}
	return isDateCorrect;
}

bool CheckDate(const Date& currentDate)
{
	bool isDateCorrect = true;
	int currentMonth = currentDate.GetMonth();
	int daysInMonth = 31;
	int monthsInYear = 12;
	if (!(1 <= currentMonth && currentMonth <= monthsInYear))
	{
		cout << "Month value is invalid: " + to_string(currentMonth);
		isDateCorrect = false;
		return isDateCorrect;
	}
	int currentDay = currentDate.GetDay();
	if (!(1 <= currentDay &&  currentDay <= daysInMonth))
	{
		cout << "Day value is invalid: " + to_string(currentDay);
		isDateCorrect = false;
		return isDateCorrect;
	}
	return isDateCorrect;
}

//лучше было записать это в функцию ReadDate
bool ReadDateAndCheck(Date& currentDate, const string& dateString)
{
	bool isDateCorrect = true;
	isDateCorrect = ReadDate(currentDate, dateString);
	if (isDateCorrect)
	{
		isDateCorrect = CheckDate(currentDate);
	}
	if (!isDateCorrect)
	{
		return false;
	}
	return true;
}



int main() {
	Database db;
	const int commandIndex = 0;
	const int dateIndex = 1;
	const int eventIndex = 2;
	string currentString;
	while (getline(cin, currentString)) {
		if (currentString == "") continue;
		vector<string> currentCommandSegments = SplitString(currentString);
		if (currentCommandSegments[commandIndex] == "Add")
		{
			//тут реализовать функцию bool ReadDate(Date& currentDate)
			bool isDateCorrect = true;
			string dateString = currentCommandSegments[dateIndex];
			Date currentDate;
			isDateCorrect = ReadDateAndCheck(currentDate, dateString);
			if (!isDateCorrect) return 1;
			db.AddEvent(currentDate, currentCommandSegments[eventIndex]);
		}
		else if (currentCommandSegments[commandIndex] == "Del")
		{
			bool isDateCorrect = true;
			string dateString = currentCommandSegments[dateIndex];
			Date currentDate;
			isDateCorrect = ReadDateAndCheck(currentDate, dateString);
			if (!isDateCorrect) return 1;
			int delDataSize = 2;
			int delEventSize = 3;
			if (currentCommandSegments.size() == delDataSize)
			{
				int eventsCount = db.DeleteDate(currentDate);
				cout << "Deleted " << eventsCount << +  " events" << endl;
			}
			else if (currentCommandSegments.size() == delEventSize)
			{
				if (db.DeleteEvent(currentDate, currentCommandSegments[delEventSize - 1]))
				{
					cout << "Deleted successfully" << endl;
				}
				else
				{
					cout << "Event not found" << endl;
				}
			}
		}
		else if (currentCommandSegments[commandIndex] == "Find")
		{
			bool isDateCorrect = true;
			string dateString = currentCommandSegments[dateIndex];
			Date currentDate;
			isDateCorrect = ReadDateAndCheck(currentDate, dateString);
			if (!isDateCorrect) return 1;
			set<string> events = db.Find(currentDate);
			for (const auto& event : events)
			{
				cout << event << endl;
			}
		}
		else if (currentCommandSegments[commandIndex] == "Print")
		{
			db.Print();
		}
		else
		{
			cout << "Unknown command: " + currentCommandSegments[commandIndex];
		}
	}
	int s;
	cin >> s;
	return 0;
}