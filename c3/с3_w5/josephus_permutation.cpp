#include "test_runner.h"
#include "profile.h"

#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>
#include <utility>
#include <list>

using namespace std;



template <typename RandomIt>
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size)
{
    list<typename RandomIt::value_type> pool;
    move(first, last, back_inserter(pool));
    auto currentIter = pool.begin();

    while (!pool.empty())
    {
        *(first++) = move(*currentIter);
        currentIter = pool.erase(currentIter);
        if (pool.empty())
        {
            break;
        }
        for (size_t i = 0; i < step_size - 1; ++i)
        {
            if (currentIter == pool.end())
            {
                currentIter = pool.begin();
            }
            currentIter = next(currentIter);
            if (currentIter == pool.end())
            {
                currentIter = pool.begin();
            }
        }
    }
}



//
//
//template <typename RandomIt>
//void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size)
//{
//    std::list<typename RandomIt::value_type> pool;
//    std::move(first, last, std::back_inserter(pool));
//    auto list_iter = pool.begin();
//
//    while (!pool.empty())
//    {
//        *(first++) = std::move(*list_iter);
//        list_iter = pool.erase(std::move(list_iter));
//
//        if (pool.empty())
//        {
//            break;
//        }
//
//        if (list_iter == pool.end())
//        {
//            list_iter = pool.begin();
//        }
//
//        for (uint32_t i = 0; i < step_size - 1; ++i)
//        {
//            if (list_iter == pool.end())
//            {
//                list_iter = pool.begin();
//            }
//            list_iter = std::move(std::next(list_iter));
//            if (list_iter == pool.end())
//            {
//                list_iter = pool.begin();
//            }
//        }
//    }
//}
//


//template <typename RandomIt>
//void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {
//    list<typename RandomIt::value_type> pool;
//    move(first, last, back_inserter(pool));
//
//    size_t cur_pos = 0;
//    auto currentIter = pool.begin();
//    //for (auto i = pool.begin(); i != pool.end; next(i,step_size))
//    //{
//    //    *(first++) = move(*i);
//    //    pool.erase(i);
//    //}
//    while (!pool.empty()) {
//        *(first++) = move(*currentIter);
//        //перед удалением заранее найдем следующий нужный итеретор пока текущий не инвалидировался:
//        auto nextIter = currentIter;
//        if (pool.size() != 1)
//        {
//
//            for (size_t step = 0; step < step_size; step++)
//            {
//
//                if (nextIter == pool.end())
//                {
//                    nextIter == pool.begin();
//                }
//                nextIter = next(nextIter);
//                if (nextIter == pool.end())
//                {
//                    nextIter == pool.begin();
//                }
//            }
//        }
//        pool.erase(currentIter);
//        currentIter = nextIter;
//        if (pool.empty())
//        {
//            break;
//        }
//
//        //*(first++) = pool(it);
//        //pool.erase(pool.begin() + cur_pos);
//        //if (pool.empty()) {
//        //    break;
//        //}
//        //cur_pos = (cur_pos + step_size - 1) % pool.size();
//    }
//}
//


//исходная
//template <typename RandomIt>
//void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {
//    vector<typename RandomIt::value_type> pool(first, last);
//    size_t cur_pos = 0;
//    while (!pool.empty()) {
//        *(first++) = pool[cur_pos];
//        pool.erase(pool.begin() + cur_pos);
//        if (pool.empty()) {
//            break;
//        }
//        cur_pos = (cur_pos + step_size - 1) % pool.size();
//    }
//}


vector<int> MakeTestVector() {
  vector<int> numbers(10);
  iota(begin(numbers), end(numbers), 0);
  return numbers;
}

void TestIntVector() {
  const vector<int> numbers = MakeTestVector();
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 1);
    ASSERT_EQUAL(numbers_copy, numbers);
  }
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 3);
    ASSERT_EQUAL(numbers_copy, vector<int>({0, 3, 6, 9, 4, 8, 5, 2, 7, 1}));
  }
}

// Это специальный тип, который поможет вам убедиться, что ваша реализация
// функции MakeJosephusPermutation не выполняет копирование объектов.
// Сейчас вы, возможно, не понимаете как он устроен, однако мы расскажем,
// почему он устроен именно так, далее в блоке про move-семантику —
// в видео «Некопируемые типы»

struct NoncopyableInt {
  int value;

  NoncopyableInt(int value) : value(value) {}

  NoncopyableInt(const NoncopyableInt&) = delete; //delete
  NoncopyableInt& operator=(const NoncopyableInt&) = delete; //delete

  NoncopyableInt(NoncopyableInt&&) = default;
  NoncopyableInt& operator=(NoncopyableInt&&) = default;
};

bool operator == (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
  return lhs.value == rhs.value;
}

ostream& operator << (ostream& os, const NoncopyableInt& v) {
  return os << v.value;
}

void TestAvoidsCopying() {
  vector<NoncopyableInt> numbers;
  numbers.push_back({1});
  numbers.push_back({2});
  numbers.push_back({3});
  numbers.push_back({4});
  numbers.push_back({5});

  MakeJosephusPermutation(begin(numbers), end(numbers), 2);

  vector<NoncopyableInt> expected;
  expected.push_back({1});
  expected.push_back({3});
  expected.push_back({5});
  expected.push_back({4});
  expected.push_back({2});

  ASSERT_EQUAL(numbers, expected);
}

int main() {
  TestRunner tr;
  
  {
  LOG_DURATION("total");
  RUN_TEST(tr, TestIntVector);
  RUN_TEST(tr, TestAvoidsCopying);
  return 0;
  }

}
