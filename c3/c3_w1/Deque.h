//#pragma once
#include <vector>
#include <exception>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Deque
{
public:
	Deque() = default;
	bool Empty() const
	{
		if (back.size() == 0 && front.size() == 0)
			return true;
		else return false;
	}
	int Size() const
	{
		return back.size() + front.size();
	}
	T& operator[](size_t index)
	{
		if (Size()  >= index + 1)
		{
			size_t frontSize = front.size();
			size_t backSize = back.size();
			if (backSize == 0)
			{
				size_t lastFrontIndex = front.size() - 1;
				return front[lastFrontIndex - index];

			}
			else if (frontSize == 0)
			{
				return back[index];
			}
			else
			{
				size_t lastFrontIndex = front.size() - 1;
				if (index > lastFrontIndex)
					return back[index - (lastFrontIndex + 1)];
				else
				{
					return front[lastFrontIndex - index];
				}
			}

		}
		//else throw out_of_range("deque is out of range");

	}
	const T& operator[](size_t index) const
	{
		T output;
		if (Size() >= index + 1)
		{
			size_t frontSize = front.size();
			size_t backSize = back.size();
			if (backSize == 0)
			{
				size_t lastFrontIndex = front.size() - 1;
				output = front[lastFrontIndex - index];

			}
			else if (frontSize == 0)
			{
				output = back[index];
			}
			else
			{
				size_t lastFrontIndex = front.size() - 1;
				if (index > lastFrontIndex)
					output = back[index - (lastFrontIndex + 1)];
				else
				{
					output = front[lastFrontIndex - index];
				}
			}

		}
		return output;

	}

	T& At(size_t index)
	{
		if (index + 1 <= Size())
		{
			return operator[](index);
		}
		else throw out_of_range("deque is out of range");
	}
	const T& At(size_t index) const
	{
		T output;
		if (index + 1 <= Size())
		{
			output = operator[](index);
		}
		else throw out_of_range("deque is out of range");
		return output;
	}
	T& Front()
	{
		return At(0);
	}
	const T& Front() const
	{
		T output;
		output = At(0);
		return output;
	}
	T& Back()
	{
		return At(Size() - 1);
	}
	const T& Back() const
	{
		T output;
		output = At(Size() - 1);
		return output;
	}


	void PushFront(T val)
	{
		front.push_back(val);
	}
	void PushBack(T val)
	{
		back.push_back(val);
	}
private:
	vector<T> front;
	vector<T> back;
};
