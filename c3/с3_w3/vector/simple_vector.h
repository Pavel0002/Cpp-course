#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
	SimpleVector()
	{
		data = nullptr;
		size_ = 0;
		capacity_ = 0;
	}
	explicit SimpleVector(size_t size)
	{
		data = new T[size];
		size_ = size;
		capacity_ = size;
	}
	~SimpleVector()
	{
		delete[] data;
	}

	T& operator[](size_t index)
	{
		return data[index];
	}
	const T& operator[](size_t index) const
	{
		return data[index];
	}
	T* begin()
	{
		return data;
	}
		
	T* end()
	{
		return data + size_;
	}
	const T* begin() const
	{
		return data;
	}

	const T* end() const
	{
		return data + size_;
	}


	size_t Size() const
	{
		return size_;
	}
		
	size_t Capacity() const
	{
		return capacity_;
	}
		
	void PushBack(const T& value)
	{
		if (capacity_ > size_)
		{
			data[size_] = value;
			size_++;
		}
		else
		{
			size_t newCapacity = (capacity_ > 0)? capacity_ * 2 : 1;

			T* newData = new T[newCapacity];
			for (size_t i = 0; i < capacity_; i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			data[size_] = value;
			size_++;
			capacity_ = newCapacity;
		}
	}


private:
  // Добавьте поля для хранения данных вектора
	T* data;
	size_t size_;
	size_t capacity_;
};
