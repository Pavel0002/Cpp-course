#include "stats.h"

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

Stats::Stats()
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
void Stats::AddMethod(string_view method)
{
	if (method == "GET" || method == "POST" || method == "PUT" || method == "DELETE")
	{
		methodStats[method]++;
	}
	else methodStats["UNKNOWN"]++;
}
void Stats::AddUri(string_view uri)
{
	if (uri == "/" || uri == "/order" || uri == "/product" || uri == "/basket" || uri == "/help")
	{
		uriStats[uri]++;
	}
	else uriStats["unknown"]++;
}
const map<string_view, int>& Stats::GetMethodStats() const
{
	return methodStats;
}
const map<string_view, int>& Stats::GetUriStats() const
{
	return uriStats;
}


HttpRequest ParseRequest(string_view line)
{
	int firstNotSpaceIndex = line.find_first_not_of(" ");
	line.remove_prefix(firstNotSpaceIndex);
	vector<string_view> splitedRequest = Split(line, ' ');
	return { splitedRequest[0], splitedRequest[1], splitedRequest[2] };
}

