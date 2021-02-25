#include <iostream>
#include <vector>
#include <string>
#include <exception>


using namespace std;

string AskTimeServer() {
}

class TimeServer {
public:
	string GetCurrentTime()
	{
		try {
			last_fetched_time = AskTimeServer();
		}
		catch (system_error& ex)
		{
			//ex.what();
			return last_fetched_time;
		}
	}
private:
	string last_fetched_time = "00:00:00";
};

int main() {

	int s;
	cin >> s;
	return 0;
}