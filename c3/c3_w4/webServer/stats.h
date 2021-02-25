#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
#include <vector>
using namespace std;


//vector<string_view> Split(const string& s, const char delim)
vector<string_view> Split(string_view str, const char delim);

class Stats {
public:
	Stats();
	void AddMethod(string_view method);
	void AddUri(string_view uri);
	const map<string_view, int>& GetMethodStats() const;
	const map<string_view, int>& GetUriStats() const;
private:
	map<string_view, int> methodStats;
	map<string_view, int> uriStats;
};

HttpRequest ParseRequest(string_view line);