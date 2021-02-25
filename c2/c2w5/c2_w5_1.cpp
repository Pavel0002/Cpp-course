#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <deque>


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



using namespace std;

class Animal {
public:
	// ваш код
	Animal(string nm) : Name(nm)
	{}
	const string Name;
};


class Dog : public Animal{
public:
	// ваш код
	Dog(string dn) : Animal(dn)
	{}
	void Bark() {
		cout << Name << " barks: woof!" << endl;
	}
};

int main() {
	//TestRunner tr;
	//tr.RunTest(TestWorks, "TestWorks");
	//Dog d("doggy");
	//d.Bark();
	int ss;
	cin >> ss;
	return 0;
}
