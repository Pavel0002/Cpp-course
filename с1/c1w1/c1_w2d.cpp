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
int GetNextMounth(int currentMounth)
{
	if(currentMounth != 11) currentMounth++;
	else currentMounth = 0;
	return currentMounth;
}

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

	int dumbCount = 0;
	int N, flag;
	cin >> N;
	string currentCommand;
	vector<vector<string>> actions(31);
	const vector<int> daysInMounth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int currentMounth = 0;

	for(int comandIndex = 0; comandIndex < N; comandIndex++)
	{
		cin >> currentCommand;
		if(currentCommand == "NEXT")
		{
//			for(auto vec: actions)
//			{
//				vec.clear();
//			}
			int nextMounth = GetNextMounth(currentMounth);
			int daysNextMounth = daysInMounth[nextMounth];
			int daysCurrentMounth = daysInMounth[currentMounth];
			if(daysNextMounth < daysCurrentMounth)
			{
				for(int daysDiff = daysCurrentMounth - daysNextMounth;daysDiff>0;daysDiff--)
				{
					for(auto action : actions[daysCurrentMounth - daysDiff])
					{
						actions[daysNextMounth - 1].push_back(action);
					}
					actions[daysCurrentMounth - daysDiff].clear();

				}
			}
			currentMounth = nextMounth;
		}
		else
		{
			cin >> flag;
			if(currentCommand == "ADD")
			{
				string currentAct;
				cin >> currentAct;
				actions[flag-1].push_back(currentAct);
			}
			else
			{
				int ln = actions[flag-1].size();
				cout << ln << ' ';
				for(int i = 0; i < ln; i++)
				{
					cout << actions[flag-1][i] << ' ';
				}
				cout << endl;
				dumbCount++;

			}
		}
	}
	return 0;
}
