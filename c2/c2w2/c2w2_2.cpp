#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

//class Rational {
//public:
//	// Вы можете вставлять сюда различные реализации,
//	// чтобы проверить, что ваши тесты пропускают корректный код
//	// и ловят некорректный
//
//	Rational();
//	Rational(int numerator, int denominator) {
//	}
//
//	int Numerator() const {
//	}
//
//	int Denominator() const {
//	}
//};

void TestConstructor() {
	Rational rt;
	AssertEqual(rt.Numerator(), 0, "Default numenator is not zero");
	AssertEqual(rt.Denominator(), 1, "Default denominator is not one");
}

void TestSimplify() {
	Rational rt(2, 6);
	Rational rt2(1, 3);
	AssertEqual(rt.Numerator(),rt2.Numerator(), "2/6 is not eq 1/3");
	AssertEqual(rt.Denominator(), rt2.Denominator(), "2/6 is not eq 1/3");
	Rational rt3(-2, 6);
	Rational rt4(1, -3);
	AssertEqual(rt3.Numerator(), rt4.Numerator(), "-2/6 is not eq -1/3");
	AssertEqual(rt3.Denominator(), rt4.Denominator(), "-2/6 is not eq -1/3");
	Rational rt5(0, 666);
	AssertEqual(rt5.Denominator(), 1, "If N == 0, D should be 1");

}
void TestNegativeNum()
{
	Rational rt3(-2, 6);
	Rational rt4(1, -3);
	Assert(rt3.Numerator() < 0 && rt3.Denominator() > 0,
		"should be N < 0, D > 0 for negative rational");
	Assert(rt4.Numerator() < 0 && rt4.Denominator() > 0,
		"should be N < 0, D > 0 for negative rational");
	Rational rt5(-1, -3);
	Assert(rt5.Numerator() > 0 && rt5.Denominator() > 0,
		"should be N > 0, D > 0 for positive rational");
}



int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	runner.RunTest(TestConstructor, "TestConstructor");
	runner.RunTest(TestSimplify, "TestSimplify");
	runner.RunTest(TestNegativeNum, "TestNegativeNum");
	return 0;
}
