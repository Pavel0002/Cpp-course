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


class Figure
{
public:
	Figure()
	{}
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
	virtual ~Figure() = default;

protected:
	double perimeter;
	double area;
};

class Rect : public Figure
{
public:
	Rect(double width, double height)
	{
		_width = width;
		_height = height;
	}
	string Name()
	{
		return "RECT";
	}
	double Perimeter()
	{
		return 2.0 * (_width + _height);
	}
	double Area()
	{
		return _width * _height;
	}
private:
	double _width;
	double _height;

};

class Triangle : public Figure
{
public:
	Triangle(double _a, double _b, double _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
	string Name()
	{
		return "TRIANGLE";
	}
	double Perimeter()
	{
		return a + b + c;
	}
	double Area()
	{
		double p = Perimeter() / 2.0;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
private:
	double a;
	double b;
	double c;
};

class Circle : public Figure
{
public:
	Circle(double _r)
	{
		r = _r;
	}
	string Name()
	{
		return "CIRCLE";
	}
	double Perimeter()
	{
		return 2*pi * r;
	}
	double Area()
	{
		return pi * r * r;
	}
private:
	const double pi = 3.14;
	double r;
};

shared_ptr<Figure> CreateFigure(istringstream& inStream)
{
	string figure;
	inStream >> figure;
	if (figure == "RECT")
	{
		double width, height;
		inStream >> width >> height;
		return make_shared<Rect>(width, height);
	}
	else if (figure == "CIRCLE")
	{
		double r;
		inStream >> r;
		return make_shared<Circle>(r);
	}
	else if (figure == "TRIANGLE")
	{
		double a, b, c;
		inStream >> a >> b >> c;
		return make_shared<Triangle>(a,b,c);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			is >> ws;
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	int s;
	cin >> s;
	return 0;
}