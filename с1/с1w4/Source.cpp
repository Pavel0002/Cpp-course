#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <sstream>
#include <iomanip>

using namespace std;

struct Time
{
	int hour = 0;
	int minute = 0;
	int second = 0;
};

string AskTimeServer() {
	//throw system_error(error_code());
	//throw domain_error("44");
	return("00:34:00");
}

class TimeServer {
public:
	string GetCurrentTime()
	{
		try {
			Time time;
			string out = AskTimeServer();
			last_fetched_time = out;
			//stringstream stream(AskTimeServer());
			//stream >> time.hour;
			//stringstream out;
			//out << setw(2) << setfill('0') << time.hour;
			//if (stream.eof())
			//{
			//	
			//	out << ':';
			//	out << setw(2) << setfill('0') << time.minute;
			//	out << ':';
			//	out << setw(2) << setfill('0') << time.second;
			//	last_fetched_time = out.str();
			//	return out.str();
			//}
			//if (stream.peek() != ':')
			//{
			//	throw exception();
			//}
			//out << ':';
			//stream.ignore(1);
			//stream >> time.minute;
			//out << setw(2) << setfill('0') << time.minute;
			//if (stream.eof())
			//{
			//	
			//	out << ':';
			//	out << setw(2) << setfill('0') << time.second;
			//	last_fetched_time = out.str();
			//	return out.str();
			//}
			//last_fetched_time = out.str();
			//if (stream.peek() != ':')
			//{
			//	throw exception();
			//}
			//out << ':';
			//stream.ignore(1);
			//stream >> time.second;
			//out << setw(2) << setfill('0') << time.second;
			//last_fetched_time = out.str();
		}
		catch (system_error& ex)
		{
			//ex.what();
			return last_fetched_time;
		}
		return last_fetched_time;
		//catch (exception& ex)
		//{
		//	throw;
		//}
	}
private:
	string last_fetched_time = "00:00:00";
};

int main() {
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	int s;
	cin >> s;
	return 0;
}