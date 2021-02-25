#include "profile.h"

#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

class Learner {
private:
    set<string> dict;
public:

    int Learn(const vector<string>& words) {
        int newWords = dict.size();
        for (const auto& word : words) {
            dict.insert(word);
        }
        return dict.size() - newWords;
    }

    vector<string> KnownWords() {
        vector<string> newVec(dict.begin(), dict.end());
        return newVec;
    }
};


int main() {
    {
        Learner learner;
        string inputWords = "cat\ndog\ncat\nraven\nsss\nbms\ndog";
        stringstream inputStream(inputWords);
        string line;
        while (getline(inputStream, line)) {
            vector<string> words;
            stringstream ss(line);
            string word;
            while (ss >> word) {
                words.push_back(word);
            }
            cout << learner.Learn(words) << "\n";
        }
        cout << "=== known words ===\n";
        for (auto word : learner.KnownWords()) {
            cout << word << "\n";
        }
    }
    
    {
        LOG_DURATION("Total");
        for (size_t i = 0; i < 10000; i++)
        {
            Learner learner;
            string inputWords = "cat\ndog\ncat\nraven\nsss\nbms\ndog";
            stringstream inputStream(inputWords);
            string line;
            while (getline(inputStream, line)) {
                vector<string> words;
                stringstream ss(line);
                string word;
                while (ss >> word) {
                    words.push_back(word);
                }
                //cout << learner.Learn(words) << "\n";
            }
            //cout << "=== known words ===\n";
            //for (auto word : learner.KnownWords()) {
            //    cout << word << "\n";
            //}

        }

    }
}