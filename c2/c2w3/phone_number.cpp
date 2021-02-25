
#include <sstream>
#include <exception>
#include <string>
#include <vector>
#include "phone_number.h"

using namespace std;


vector<string> SplitStringByChar(const string& stringToSplit, char delim)
{
	vector<string> outputStrings;
	stringstream test(stringToSplit);
	string segment;
	while (std::getline(test, segment, delim))
	{
		outputStrings.push_back(segment);
	}
	return outputStrings;
}

	PhoneNumber::PhoneNumber(const string &international_number)
	{
		stringstream inputStringStream(international_number);
		char currentChar = ' ';
		inputStringStream >> currentChar;
		if (currentChar != '+')
		{
			throw invalid_argument("error");
		}
		string NumberWithoutPlus;
		inputStringStream >> NumberWithoutPlus;
		vector<string> splitedNumber = SplitStringByChar(NumberWithoutPlus, '-');
		if (splitedNumber.size() < 3)
		{
			throw invalid_argument("error");
		}
		country_code_ = splitedNumber[0];
		city_code_ = splitedNumber[1];
		local_number_ = "";
		for (size_t i = 2; i < splitedNumber.size(); i++)
		{
			local_number_ += splitedNumber[i];
			local_number_ += "-";
		}
		if (local_number_.size() > 0)
		{
			local_number_.pop_back();
		}
	}

	string PhoneNumber::GetCountryCode() const
	{
		return country_code_;
	}
	string PhoneNumber::GetCityCode() const
	{
		return city_code_;
	}
	string PhoneNumber::GetLocalNumber() const
	{
		return local_number_;
	}
	string PhoneNumber::GetInternationalNumber() const
	{
		return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
	}


