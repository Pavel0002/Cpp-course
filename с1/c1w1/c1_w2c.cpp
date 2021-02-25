#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//int Factorial(int N)
//{
//	if(N<0) return 1;
//	int res = 1;
//	for(int i = 1; i <= N; i++)
//	{
//		res *= i;
//	}
//	return res;
//}

//string revStr(string in)
//{
//	reverse(in.begin(), in.end());
//	return in;
//}
//vector<string> PalindromFilter(vector<string> words, int minLength)
//{
//	vector<string> res;
//	for(auto word : words)
//	{
//		if((word == revStr(word)) && (word.length() >= minLength) ) res.push_back(word);
//	}
//	return res;
//}

//void MoveStrings(vector<string>& source, vector<string>& destination)
//{
//	for(auto word : source)
//	{
//		destination.push_back(word);
//	}
//	source.clear();
//}

//void Reverse(vector<int>& v)
//{
//	reverse(v.begin(),v.end());
//}


int main() {

//	int N, flag;
//	string currentCommand;
//	cin >> N;
//	vector<bool> stack;
//	for(int i = 0; i < N; i++)
//	{
//		cin >> currentCommand;
//		if(currentCommand != "WORRY_COUNT")
//		{
//			cin >> flag;
//			if(currentCommand == "COME")
//			{
//				stack.resize(stack.size()+flag,0);
//			}
//			else if(currentCommand == "QUIET")
//			{
//				stack[flag] = false;
//			}
//			else stack[flag] = true;
//		}
//		else
//		{
//			cout << accumulate(stack.begin(), stack.end(), 0) << endl;
//		}
//	}


	int N, flag;
	cin >> N;
	string currentCommand;
	vector<vector<string>> actions(31);
	const vector<int> daysInMounth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int currentMounth = 0;

	for(int N = 0; N < 0; N++)
	{
		cin >> currentCommand;
		if(currentCommand == "NEXT")
		{
			for(auto vec: actions)
			{
				vec.clear();
			}
			if(currentMounth != 11) currentMounth++;
			else currentMounth = 0;
		}
		else
		{
			cin >> flag;
			if(currentCommand == "ADD")
			{
				string currentAct;
				cin >> currentAct;
				actions[flag].push_back(currentAct);
			}
			else
			{
				cout << actions[flag].size();
				int ln = actions[flag].size();
				for(int i = 0; i < ln; i++)
				{
					cout << actions[flag][i] << ' ';
				}

			}
		}

	}

	return 0;
}
