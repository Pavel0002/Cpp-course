
#include <vector>
#include <algorithm>

using namespace std;

//template <typename Token>
//using Sentence = vector<Token>;
//
//// Класс Token имеет метод bool IsEndSentencePunctuation() const
//template <typename Token>
//vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
//  // Напишите реализацию функции, не копируя объекты типа Token
//    vector<Sentence<Token>> sentences;//может тут лучше заранее выделить память? да, резервом
//    //const int maxTokens = 1000000;
//    //sentences.reserve(maxTokens);
//    //auto sentenceBeginIter = tokens.begin();
//    //auto sentenceEndIter = sentenceBeginIter;
//	auto tokensBeginIter = tokens.begin();
//	auto tokensEndIter = tokens.end();
//    while (tokensBeginIter != tokensEndIter)
//    {
//        auto sentenceEndIter = adjacent_find(tokensBeginIter, tokensEndIter, [](Token& tkL, Token& tkR) {return tkL.IsEndSentencePunctuation() && !(tkR.IsEndSentencePunctuation()); });
//		//auto tokensEndIter = (tempEndIter == tokensEndIter) ? tokensEndIter : next(tempEndIter);
//        if (sentenceEndIter != tokens.end())
//        {
//            sentenceEndIter = next(sentenceEndIter);
//        }
//		Sentence<Token> sentence;
//		for(;tokensBeginIter != sentenceEndIter; tokensBeginIter++)
//		{
//			sentence.push_back(move(sentence));
//		}
//    }
//    return sentences;
//}
template <typename Token>
using Sentence = vector<Token>;

// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
  // Напишите реализацию функции, не копируя объекты типа Token
    vector<Sentence<Token>> sentences;//может тут лучше заранее выделить память? да, резервом

	auto tokensBeginIter = tokens.begin();
	auto tokensEndIter = tokens.end();
    while (tokensBeginIter != tokensEndIter)
    {
        auto sentenceEndIter = adjacent_find(tokensBeginIter, tokensEndIter, [](Token& tkL, Token& tkR) {return tkL.IsEndSentencePunctuation() && !(tkR.IsEndSentencePunctuation()); });
        if (sentenceEndIter != tokens.end())
        {
            sentenceEndIter = next(sentenceEndIter);
        }
		Sentence<Token> sentence;
		for(;tokensBeginIter != sentenceEndIter; tokensBeginIter++)
		{
			sentence.push_back(move(*tokensBeginIter));
		}
		sentences.push_back(move(sentence));
    }
    return sentences;
}
