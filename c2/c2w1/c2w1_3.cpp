#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

template <typename T>
T Sqr(const T& a);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p);

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m);

template <typename T>
vector<T> Sqr(const vector<T>& vl);




template <typename T>
T Sqr(const T& a)
{
	return a * a;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p)
{
	return make_pair(Sqr(p.first),Sqr(p.second));
}


template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
	map<Key, Value> output;
	for (const auto& item : m)
	{
		output[item.first] = Sqr(item.second);
	}
	return output;
}

template <typename T>
vector<T> Sqr(const vector<T>& vl) {
	vector<T> output(size(vl));
	for (int i = 0; i < size(vl); i++)
	{
		output[i] = Sqr(vl[i]);
	}
	return output;
}



//template <typename Collection> 
//Collection Sqr(Collection& a)
//{
//	for (auto& item : a)
//	{
//		item = item *item;
//	}
//	return a;
//}


int main() {

	//// Пример вызова функции
	//vector<int> v = { 1, 2, 3 };
	//cout << "vector:";
	//for (int x : Sqr(v)) {
	//	cout << ' ' << x;
	//}
	//cout << endl;

	//map<int, pair<int, int>> map_of_pairs = {
	//	{ 4,{ 2, 2 } },
	//	{ 7,{ 4, 3 } }
	//};
	//cout << "map of pairs:" << endl;
	//for (const auto& x : Sqr(map_of_pairs)) {
	//	cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	//}


	//std::map<int, std::vector<double>> maps;
	//auto res = Sqr(maps);


	int s;
	cin >> s;
	return 0;
}