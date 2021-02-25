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

bool IsPalindrom(const string& str) {
	// Вы можете вставлять сюда различные реализации функции,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
}

void TestOne() {
	Assert(IsPalindrom(""), "empty is not Palindrom");
	Assert(IsPalindrom("f"), "f is not Palindrom");
	Assert(IsPalindrom("f f"), "f f is not Palindrom");
	Assert(IsPalindrom("asa"), "asa is not Palindrom");
	Assert(IsPalindrom(" asa "), "asa is not Palindrom");
	Assert(IsPalindrom("wasitacaroracatisaw"), "wasitacaroracatisaw is not Palindrom");
	Assert(!IsPalindrom("wasitacaroracatisa"), "wasitacaroracatisa is  Palindrom");
	Assert(!IsPalindrom("asitacaroracatisaw"), "asitacaroracatisaw is  Palindrom");
	Assert(IsPalindrom("wasitacar0racatisaw"), "wasitacar0racatisaw is not Palindrom");
	Assert(IsPalindrom("w asi	tacar o racat	isa w"), "wasitacar0racatisaw is not Palindrom");
	Assert(IsPalindrom("777777"), "777777 is not Palindrom");
	Assert(IsPalindrom("77777"), "77777 is not Palindrom");
	Assert(!IsPalindrom("777778"), "777778");
	Assert(!IsPalindrom("77778"), "777778");
	Assert(!IsPalindrom(" 777778 "), " 777778 ");
	Assert(!IsPalindrom(" 77778 "), " 777778 ");
	Assert(!IsPalindrom("   AbA  "), "AbA");
	Assert(!IsPalindrom("  bAb   "), "AbA");


}

void TestSymbols() {
	Assert(IsPalindrom("madam"), "madam");
	Assert(IsPalindrom("wasitacaroracatisaw"), "wasitacaroracatisaw");
	Assert(IsPalindrom("a a"), "a a");
}

void TestFirstLastSymbolIgnore() {
	Assert(!IsPalindrom("ZBCDmadamDCBA"), "ABCDmadamDCBA");
	Assert(!IsPalindrom("ABCDmadamDCBZ"), "ABCDmadamDCBZ");
}

void TestEarlyStop() {
	Assert(!IsPalindrom("wasitacaRoracatisaw"), "wasitacaRoracatisaw");
	Assert(!IsPalindrom("wasitacAroracatisaw"), "wasitacAroracatisaw");
	Assert(!IsPalindrom("wasitaCaroracatisaw"), "wasitaCaroracatisaw");
	Assert(!IsPalindrom("wasitAcaroracatisaw"), "wasitAcaroracatisaw");
	Assert(!IsPalindrom("wasiTacaroracatisaw"), "wasiTacaroracatisaw");
	Assert(!IsPalindrom("wasItacaroracatisaw"), "wasItacaroracatisaw");
	Assert(!IsPalindrom("waSitacaroracatisaw"), "waSitacaroracatisaw");
	Assert(!IsPalindrom("wAsitacaroracatisaw"), "wAsitacaroracatisaw");
	Assert(!IsPalindrom("wasitacaRracatisaw"), "wasitacaRoracatisaw");
	Assert(!IsPalindrom("wasitacArracatisaw"), "wasitacAroracatisaw");
	Assert(!IsPalindrom("wasitaCarracatisaw"), "wasitaCaroracatisaw");
	Assert(!IsPalindrom("wasitAcarracatisaw"), "wasitAcaroracatisaw");
	Assert(!IsPalindrom("wasiTacarracatisaw"), "wasiTacaroracatisaw");
	Assert(!IsPalindrom("wasItacarracatisaw"), "wasItacaroracatisaw");
	Assert(!IsPalindrom("waSitacarracatisaw"), "waSitacaroracatisaw");
	Assert(!IsPalindrom("wAsitacarracatisaw"), "wAsitacaroracatisaw");

}

void TestIgnoreSpaces() {
	Assert(!IsPalindrom(" ABCCBA"), " ABCCBA");
	Assert(!IsPalindrom("ABCCBA "), "ABCCBA ");
	Assert(!IsPalindrom("ABCCB A"), "ABCCB A");
	Assert(!IsPalindrom("A BCCBA"), "A BCCBA");
	Assert(!IsPalindrom("AB CCBA"), "AB CCBA");
	Assert(!IsPalindrom("ABCC BA"), "ABCC BA");
	Assert(!IsPalindrom("AB CCBA"), "AB CCBA");
	Assert(!IsPalindrom("ABCcBA"), "ABCcBA");
	Assert(!IsPalindrom("ABC CbA"), "ABC CbA");
	Assert(!IsPalindrom("ABC cbA"), "ABC cbA");
}



int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	runner.RunTest(TestOne, "TestOne");
	runner.RunTest(TestIgnoreSpaces, "TestIgnoreSpaces");
	runner.RunTest(TestEarlyStop, "TestEarlyStop");
	runner.RunTest(TestFirstLastSymbolIgnore, "TestFirstLastSymbolIgnore");
	runner.RunTest(TestSymbols, "TestSymbols");
	return 0;
}
