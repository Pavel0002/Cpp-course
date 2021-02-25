#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <set>

using namespace std;


// ���� ��� ����������, ���������� ������ ������
string FindNameByYear(const map<int, string>& names, int year) {
	string name;  // ���������� ��� ����������

				  // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
	for (const auto& item : names) {
		// ���� ��������� ��� �� ������ �������, ��������� ���
		if (item.first <= year) {
			name = item.second;
		}
		else {
			// ����� ���� ������������, ��� ��� ��� ������ � ��� ����������� ��������� � ��������
			break;
		}
	}

	return name;
}

vector<string> FindHistoryByYear(const map<int, string>& names, int year) {
	vector<string> nameHistory;  // ���������� ��� ����������

				  // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
	for (const auto& item : names) {
		// ���� ��������� ��� �� ������ �������, ��������� ���
		string currentName = item.second;
		if (item.first <= year && count_if(nameHistory.begin(), nameHistory.end(), [currentName](string s) {return currentName == s; }) == 0) 
		{
			nameHistory.push_back(currentName);
		}
		else {
			// ����� ���� ������������, ��� ��� ��� ������ � ��� ����������� ��������� � ��������
			break;
		}
	}
	reverse(nameHistory.begin(), nameHistory.end());
	return nameHistory;
}

class Person {
public:
	Person(const string& firstName, const string& lastName, int year)
	{
		ChangeFirstName(year, firstName);
		ChangeLastName(year, lastName);
		birthYear = year;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year < birthYear) return;
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year < birthYear) return;
		last_names[year] = last_name;
	}
	string GetFullName(int year) const{
		// �������� ��� � ������� �� ��������� �� ��� year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);


		if (first_name.empty() || last_name.empty()) {
			return "No person";

			// ���� ���������� ������ ���
		}
		else {
			return first_name + " " + last_name;
		}
	}

	string GetFullNameWithHistory(int year) const{
		// �������� ��� � ������� �� ��������� �� ��� year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);
		vector<string> firstNameHistory = FindHistoryByYear(first_names, year);
		vector<string> lastNameHistory = FindHistoryByYear(last_names, year);
		if (!first_name.empty() && firstNameHistory.size() != 0)
		{
			if (firstNameHistory[0] == first_name) firstNameHistory.erase(firstNameHistory.begin());
		}
		if (!last_name.empty() && lastNameHistory.size() != 0)
		{
			if (lastNameHistory[0] == last_name) lastNameHistory.erase(lastNameHistory.begin());
		}
		


		// ���� � ���, � ������� ����������
		if (first_name.empty() || last_name.empty()) {
			return "No person";

			// ���� ���������� ������ ���
		}
		else {
			string out = first_name;

			if (firstNameHistory.size() != 0)
			{
				out += " (";
				for (const auto& nm : firstNameHistory)
				{
					out += nm + ", ";
				}
				out.erase(out.size() - 2, 2);
				out += ')';
			}

			out += ' ' + last_name;
			if (lastNameHistory.size() != 0)
			{
				out += " (";
				for (const auto& nm : lastNameHistory)
				{
					out += nm + ", ";
				}
				out.erase(out.size() - 2, 2);
				out += ')';
			}
			return out;
		}
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
	int birthYear = 0;
};

//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//	person.ChangeFirstName(1990, "Polina");
//	person.ChangeLastName(1990, "Volkova-Sergeeva");
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1966, "Pauline");
//	cout << person.GetFullNameWithHistory(1966) << endl;
//
//	person.ChangeLastName(1960, "Sergeeva");
//	for (int year : {1960, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1961, "Ivanova");
//	cout << person.GetFullNameWithHistory(1967) << endl;
//	int sl;
//	cin >> sl;
//	return 0;
//}
//int main() {
//	Person person;
//
//	person.ChangeFirstName(1900, "Eugene");
//	person.ChangeLastName(1900, "Sokolov");
//	person.ChangeLastName(1910, "Sokolov");
//	person.ChangeFirstName(1920, "Evgeny");
//	person.ChangeLastName(1930, "Sokolov");
//	cout << person.GetFullNameWithHistory(1940) << endl;
//	int s;
//	cin >> s;
//	return 0;
//}

//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeFirstName(1965, "Appolinaria");
//
//	person.ChangeLastName(1965, "Sergeeva");
//	person.ChangeLastName(1965, "Volkova");
//	person.ChangeLastName(1965, "Volkova-Sergeeva");
//
//	for (int year : {1964, 1965, 1966}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//	int s;
//	cin >> s;
//	return 0;
//}
int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
		int s;
		cin >> s;
	return 0;
}