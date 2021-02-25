#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
	T* Allocate()
	{
		if (deAllocatedObjects.size() != 0)
		{
			T* newObject = deAllocatedObjects.front();
			deAllocatedObjects.pop();
			allocatedObjects.insert(newObject);
			return newObject;
		}
		else
		{
			T* newObject = new T();
			allocatedObjects.insert(newObject);
			return newObject;
		}
	}
	T* TryAllocate()
	{
		if (deAllocatedObjects.size() != 0)
		{
			T* newObject = deAllocatedObjects.front();
			deAllocatedObjects.pop();
			allocatedObjects.insert(newObject);
			return newObject;
		}
		else
		{
			return nullptr;
		}
	}

	void Deallocate(T* object)
	{
		//если содержится в множестве выделеных переместить в множество освобожденных
		auto iterForDealloc = allocatedObjects.find(object);
		if (allocatedObjects.find(object) != allocatedObjects.end())
		{
			deAllocatedObjects.push(*iterForDealloc);
			allocatedObjects.erase(iterForDealloc);
		}
		//если нет, то исключение
		else
		{
			throw invalid_argument("Object was not found");
		}
	}

	~ObjectPool()
	{
		for (auto object : allocatedObjects)
		{
			delete object;
		}
		while (!deAllocatedObjects.empty())
		{
			delete deAllocatedObjects.front();
			deAllocatedObjects.pop();
		}
	}

private:
	set<T*> allocatedObjects;
	queue<T*> deAllocatedObjects;

};

void TestObjectPool() {
	ObjectPool<string> pool;

	auto p1 = pool.Allocate();
	auto p2 = pool.Allocate();
	auto p3 = pool.Allocate();

	*p1 = "first";
	*p2 = "second";
	*p3 = "third";

	pool.Deallocate(p2);
	ASSERT_EQUAL(*pool.Allocate(), "second");

	pool.Deallocate(p3);
	pool.Deallocate(p1);
	ASSERT_EQUAL(*pool.Allocate(), "third");
	ASSERT_EQUAL(*pool.Allocate(), "first");

	pool.Deallocate(p1);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestObjectPool);
	return 0;
}
