#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
using namespace std;

//vector<string_view> Split(const string& s, const char delim)
vector<string_view> Split(string_view str, const char delim)
{
	vector<string_view> result;
	while (true)
	{
		size_t dlm = str.find(delim);
		result.push_back(str.substr(0, dlm));
		if (dlm == str.npos)
		{
			break;
		}
		else
		{
			str.remove_prefix(dlm + 1);
		}
	}
	return result;
}

class Stats {
public:
	Stats()
	{
		methodStats["GET"] = 0;
		methodStats["POST"] = 0;
		methodStats["PUT"] = 0;
		methodStats["DELETE"] = 0;
		methodStats["UNKNOWN"] = 0;
		uriStats["/"] = 0;
		uriStats["/order"] = 0;
		uriStats["/product"] = 0;
		uriStats["/basket"] = 0;
		uriStats["/help"] = 0;
		uriStats["unknown"] = 0;
	}
	void AddMethod(string_view method)
	{
		if (method == "GET" || method == "POST" || method == "PUT" || method == "DELETE")
		{
			methodStats[method]++;
		}
		else methodStats["UNKNOWN"]++;
	}
	void AddUri(string_view uri) 
	{
		if (uri == "/" || uri == "/order" || uri == "/product" || uri == "/basket" || uri == "/help")
		{
			uriStats[uri]++;
		}
		else uriStats["unknown"]++;
	}
	const map<string_view, int>& GetMethodStats() const 
	{
		return methodStats;
	}
	const map<string_view, int>& GetUriStats() const 
	{
		return uriStats;
	}
private:
	map<string_view, int> methodStats;
	map<string_view, int> uriStats;
};

HttpRequest ParseRequest(string_view line)
{
	int firstNotSpaceIndex = line.find_first_not_of(" ");
	line.remove_prefix(firstNotSpaceIndex);
	vector<string_view> splitedRequest = Split(line, ' ');
	//size_t sz = splitedRequest[0].size();
	//splitedRequest[0] = splitedRequest[0].substr(0, sz - 2);
	//splitedRequest[0].remove_suffix(1);
	return { splitedRequest[0], splitedRequest[1], splitedRequest[2] };
}
