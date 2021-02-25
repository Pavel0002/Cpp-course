#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>


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

//vector<string> SplitIntoWords(const string& s)
//{
//	vector<string> outputStrings;
//	stringstream test(s);
//	string segment;
//	while (std::getline(test, segment, ' '))
//	{
//		outputStrings.push_back(segment);
//	}
//	return outputStrings;
//}


#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string& str) {
	// Готовим вектор, в который будем сохранять слова
	vector<string> result;

	// Эти два итератора будут ограничивать текущую не разбитую часть строки
	// str_begin будет двигаться вправо
	auto str_begin = begin(str);
	// str_end всегда будет указывать на конец строки (поэтому он константный)
	const auto str_end = end(str);

	// У цикла нет условия завершения, так что единственный способ закончить его —
	// сделать break
	while (true) {

		// Находим первый пробел в текущем «хвосте» строки
		auto it = find(str_begin, str_end, ' ');

		// Полуинтервал [str_begin, it) — очередное слово
		result.push_back(string(str_begin, it));

		if (it == str_end) {
			// Если пробелов больше нет, цикл пора завершить.
			// Последнее слово уже добавлено
			break;
		}
		else {
			// Иначе первый символ после пробела — начало очередного слова.
			// Туда и подвинем str_begin
			str_begin = it + 1;
		}

	}

	return result;
}

int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");

	int s;
	cin >> s;
	return 0;
}
