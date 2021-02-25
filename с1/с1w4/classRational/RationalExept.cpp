#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <set>
#include <map>

using namespace std;

long long MyGcd(long long a, long long b)
{
	while (a > 0 && b > 0)
	{
		if (a>b)
		{
			a = a%b;
		}
		else
		{
			b = b%a;
		}
	}
	return abs(a + b);
}

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

class Rational {
public:
	Rational() {
		// Реализуйте конструктор по умолчанию
		num = 0;
		den = 1;
	}

	Rational(long long numerator, long long denominator) {
		// Реализуйте конструктор
		if (denominator == 0)
		{
			throw invalid_argument("invalid argument, denominator should not be zero! denominator: " + denominator);
		}
		long long signNum = (numerator > 0) ? 1 : -1;
		long long signDen = (denominator > 0) ? 1 : -1;
		long long sign = signNum * signDen;
		numerator = abs(numerator);
		denominator = abs(denominator);
		long long gcd = MyGcd(numerator, denominator);
		if (gcd != 1)
		{
			numerator /= gcd;
			denominator /= gcd;
		}
		if (numerator == 0) denominator = 1;
		num = abs(numerator) * sign;
		den = abs(denominator);
	}

	long long Numerator() const {
		// Реализуйте этот метод
		return num;
	}

	long long Denominator() const {
		// Реализуйте этот метод
		return den;
	}

private:
	long long num = 0;
	long long den = 1;
};

Rational operator+(Rational r1, Rational r2)
{
	if(r1.Denominator() == r2.Denominator())
		return Rational(r1.Numerator() + r2.Numerator(), r1.Denominator());
	else
	{
		return Rational(r1.Numerator()*r2.Denominator() + r2.Numerator()*r1.Denominator(), r1.Denominator() * r2.Denominator());
	}
}
Rational operator-(Rational r1, Rational r2)
{
	Rational r3(-r2.Numerator(), r2.Denominator());
	return r1 + r3;
}

Rational operator*(Rational r1, Rational r2)
{
	long long a = r1.Numerator() * r2.Numerator();
	long long b = r1.Denominator() * r2.Denominator();
	//cout << a << ' ' << b << endl;
	return Rational(a, b);
}

bool operator==(Rational r1, Rational r2)
{
	return (r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator());
}

Rational operator/(Rational r1, Rational r2)
{
	if (r2 == Rational(0, 1))
	{
		throw domain_error("dividion by zero!");
	}
	Rational r3(r2.Denominator(), r2.Numerator());
	//cout << r1.Numerator() << ' ' << r1.Denominator() << ' ' << r3.Numerator() << ' ' << r3.Denominator() << endl;
	return r1 * r3;
}

ostream& operator<<(ostream& stream, const Rational& r)
{
	stream << to_string(r.Numerator()) + '/' + to_string(r.Denominator());
	return  stream;
}

istream& operator>>(istream& stream, Rational& r)
{
	string number;
	if (stream)
	{
		string number;
		stream >> number;
		if (count(number.begin(), number.end(), '/') == 1)
		{
			replace(number.begin(), number.end(), '/', ' ');
			stringstream curStream(number);
			vector<string> nums(2);
			string N;
			string D;
			curStream >> N >> D;
			if (isInteger(N) && isInteger(D))
			{
				long long numenator;
				long long denumenator;
				numenator = stoll(N);
				denumenator = stoll(D);
				r = Rational(numenator, denumenator);
			}
			else return stream;
		}
		else return stream;
	}
	return  stream;
}

bool operator<(Rational r1, Rational r2)
{
	double r1D = (double)r1.Numerator() / (double)r1.Denominator();
	double r2D = (double)r2.Numerator() / (double)r2.Denominator();
	return r1D < r2D;
}

int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	int s;
	cin >> s;
	return 0;
}