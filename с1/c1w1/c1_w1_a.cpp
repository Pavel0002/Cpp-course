
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

//	double x1, x2;
//	double a, b, c, d;
//	cin >> a >> b >> c;
//	d = sqrt(b*b-4*a*c);
//	if(a == 0)
//	{
//		if(b!=0)
//		{
//			cout << -c/b;
//		}
//
//	}
//	else
//	{
//		if(d > 0)
//		{
//			x1 = (-b + d)/(2*a);
//			x2 = (-b - d)/(2*a);
//			cout << x1 << ' ' << x2;
//		}
//		if(d==0) cout << -b/(2*a);
//	}
//	return 0;

//	int a, b;
//	cin >> a >> b;
//	if(b==0) cout << "Impossible";
//	else
//	{
//		cout << a/b;
//	}
//	return 0;

	string s;
	cin >> s;
	int flag = -2;
	int n = 0;
	for(auto letter : s)
	{
		if(letter == 'f') flag++;
		if(flag == 0) cout << ++n;

	}
	cout << flag;
	return 0;
}
