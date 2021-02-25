#include "test_runner.h"
#include "profile.h"

#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <future>
#include <functional>

using namespace std;


template <typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end)
        : first(begin)
        , last(end)
        , size_(distance(first, last))
    {
    }

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }

    size_t size() const {
        return size_;
    }

private:
    Iterator first, last;
    size_t size_;
};

template <typename Iterator>
class Paginator {
private:
    vector<IteratorRange<Iterator>> pages;

public:
    Paginator(Iterator begin, Iterator end, size_t page_size) {
        for (size_t left = distance(begin, end); left > 0; ) {
            size_t current_page_size = min(page_size, left);
            Iterator current_page_end = next(begin, current_page_size);
            pages.push_back({ begin, current_page_end });

            left -= current_page_size;
            begin = current_page_end;
        }
    }

    auto begin() const {
        return pages.begin();
    }

    auto end() const {
        return pages.end();
    }

    size_t size() const {
        return pages.size();
    }
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(begin(c), end(c), page_size);
}


struct Stats {
  map<string, int> word_frequences;
  void operator += (const Stats& other) {
      for (auto const& [key, value] : other.word_frequences){
          if (word_frequences.count(key) == 0){
              word_frequences[key] = value;
          }
          else{
              word_frequences[key] += value;
          }
      }
  }
};

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


//если не проходит по времени, проблемма скорее всего здесь!!!
Stats ExploreLine(const set<string>& key_words, const string& line) {
    char delim = ' ';
    vector<string_view> words = Split(line, delim);
    ////если 2 одинаковых новых слова в line, засчитывается только одно
    Stats result;
    //добавляем в result слова, содержащиеся в words и key_words
    for (const auto& current_word : words)
    {
        //auto currentWordString = string(current_word);
        if (key_words.count(string(current_word)) != 0)
        {
            if (result.word_frequences.count(string(current_word)) == 0) {
                result.word_frequences[string(current_word)] = 1;
            }
            else {
                result.word_frequences[string(current_word)]++;
            }
        }

    }
    return result;
}

Stats ExploreKeyWordsSingleThread(
  const set<string>& key_words, istream& input
) {
  Stats result;
  for (string line; getline(input, line); ) {
    result += ExploreLine(key_words, line);
  }
  return result;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
  // Реализуйте эту функцию
    //вариант 1: считать все строки, распараллелить их разбор
    //считываем все строки
    vector<string> allStrings;
    for (string line; getline(input, line); ) {
        allStrings.push_back(line);
    }
    Stats result;
    vector<future<Stats>> futures;
    int coresCount = 4;
    int pageSize = allStrings.size() / coresCount;
    for (auto page : Paginate(allStrings, pageSize)) {
        futures.push_back(async([page, key_words] { 
            Stats statsOfPage;
            //для каждой строки вызываем ExploreLine
            for (const auto& line : page)
            {
                statsOfPage += ExploreLine(key_words, line);
            }
            return statsOfPage;
            }));
    }

    //это можно не писать, но лучше написать в явном виде
    for (auto& f : futures) {
        result += f.get();
    }

    return result;
    //вариант 2: считать часть строк, распараллелить разбор, продолжить считывание, пока разбираются предыдущие
}

void TestBasic() {
  const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  ss << "this new yangle service really rocks\n";
  ss << "It sucks when yangle isn't available\n";
  ss << "10 reasons why yangle is the best IT company\n";
  ss << "yangle rocks others suck\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);//ExploreKeyWordsSingleThread(key_words, ss);//ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  LOG_DURATION("total");
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
}
