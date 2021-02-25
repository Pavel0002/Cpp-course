#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <set>

using namespace std;

bool HasWordsPair(const set<vector<string>>& sinonims, string word1, string word2)
{
	
	return ((sinonims.count( { word1,word2 }) + sinonims.count({ word2,word1 })) > 0);
}
int main() 
{
	int querryCount;
	cin >> querryCount;
	//какой контейнер использовать?
	set<vector<string>> sinonims;
	map<string, int> wordCounts;
	for (int querryIndex = 0; querryIndex < querryCount; querryIndex++)
	{
		string currentQuerry;
		cin >> currentQuerry;
		if (currentQuerry == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;

			if (!HasWordsPair(sinonims, word1, word2))
			{
				sinonims.insert({ word1,word2 });
				if (wordCounts.count(word1) != 0) wordCounts[word1]++;
				else wordCounts[word1] = 1;
				if (wordCounts.count(word2) != 0) wordCounts[word2]++;
				else wordCounts[word2] = 1;
			}
		}
		else if (currentQuerry == "COUNT")
		{
			string word;
			cin >> word;
			
			//vector<string> temp(begin(sinonims),end(sinonims));
			//cout << count(begin(temp), end(temp), word);
			//видимо так не эффективно
		//	int count = 0;
		//	for (const auto& item : sinonims)
		//	{
		//		if ( (item[0] == word) || (item[1] == word) )
		//			count++;
		//	}
		//	cout << count << endl;
			cout << wordCounts[word] << endl;
		  }
		else if (currentQuerry == "CHECK")
		{
			string word1, word2;
			cin >> word1 >> word2;
			if (HasWordsPair(sinonims, word1, word2)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	//int s;
	//cin >> s;
	return 0;
}