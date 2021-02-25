
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
//	int a;
//	int b;
//
//	cin >> a;
//	cin >> b;
//	cout << a+b;
//	return 0;

//	string a, b, c;
//	cin >> a >> b >> c;
//	string minstring = a;
//	if(b < minstring) minstring = b;
//	if(c < minstring) minstring = c;
//	cout << minstring;
//	return 0;

	double x1, x2;
	double a, b, c;
	cin >> a >> b >> c;
	x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
	x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
	cout << x1 << ' ' << x2;
}
