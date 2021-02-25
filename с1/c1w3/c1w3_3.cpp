#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <set>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		year2FirstNames[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		year2LastNames[year] = last_name;
	}
	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
		int year4FirstName = GetMaxAvailibleYear(year2FirstNames, year);
		int year4LastName = GetMaxAvailibleYear(year2LastNames, year);
		if (year4FirstName == -1 && year4LastName == -1)
		{
			return "Incognito";
		}
		if (year4FirstName != -1 && year4LastName == -1)
		{
			return year2FirstNames[year4FirstName] + " with unknown last name";
		}
		if (year4FirstName == -1 && year4LastName != -1)
		{
			return year2LastNames[year4LastName] + " with unknown first name";
		}
		if(year4FirstName != -1 && year4LastName != -1)
		return year2FirstNames[year4FirstName] + ' ' + year2LastNames[year4LastName];

	}
private:
	// приватные поля
	map<int, string> year2FirstNames;
	map<int, string> year2LastNames;
	int GetMaxAvailibleYear(const map<int, string>& year2Names, int year)
	{
		int maxYear = -1;
		for (const auto& item : year2Names)
		{
			if (item.first <= year && item.first >= maxYear)
				maxYear = item.first;
		}
		return maxYear;
	}
};


int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
	int s;
	cin >> s;
	return 0;
}