#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>


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


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
	Human(string _Name, const string& _humanType) : humanType(_humanType), Name(_Name)
	{
	}
	virtual void Walk(const string& destination) const
	{
		cout << humanType + ": " << Name << " walks to: " << destination << endl;
	}
	const string humanType;
	const string Name;
};


class Student : public Human {
public:

	Student(const string& name, const string& favouriteSong) : Human(name, "Student"), FavouriteSong(favouriteSong)
	{
	}

	void Learn() {
		cout << "Student: " << Name << " learns" << endl;
	}

	void Walk(const string& destination) const override {
		Human::Walk(destination);
		SingSong();
	}

	void SingSong() const {
		cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
	}

private:
	const string FavouriteSong;
};


class Teacher : public Human {
public:

	Teacher(const string& name, const string& subject) : Human(name, "Teacher"), Subject(subject) {
	}

	void Teach() {
		cout << "Teacher: " << Name << " teaches: " << Subject << endl;
	}

private:
	const string Subject;
};


class Policeman : public Human {
public:
	Policeman(const string& name) : Human(name, "Policeman")
	{
	}
	void Check(Human& h)
	{
		cout << "Policeman: " << Name << " checks Teacher. Teacher's name is: " << h.Name << endl;
	}

};


void VisitPlaces(Human& h, const vector<string>& places) {
	for (auto p : places) {
		h.Walk(p);
	}
}



int main() {

	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });

	int ss;
	cin >> ss;
	return 0;
}