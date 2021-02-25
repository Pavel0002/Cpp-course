#include <string>
#include "test_runner.h"
#include <list>

using namespace std;

class Editor {
 public:
  // Реализуйте конструктор по умолчанию и объявленные методы
     Editor()
     {
         cursor = mainText.begin();
     }
     void Left()
     {
         if (cursor != mainText.begin())
         {
             cursor = prev(cursor);
         }
         
     }
     void Right()
     {
         if (cursor != mainText.end())
         {
             cursor = next(cursor);
         }
     }
  void Insert(char token)
  {
      mainText.insert(cursor, token);
  }
  void Cut(size_t tokens = 1)
  {
      //раачитываем сдвиг курсора
      size_t cursorShift = min<size_t>(tokens, distance(cursor, mainText.end()));
      auto tempIter = next(cursor, cursorShift);
      //копируем в буфер
      buffer.clear();
      //buffer.assign(cursor, next(cursor, cursorShift));
      buffer.insert(buffer.end(), cursor, tempIter);
      //удаляем
      mainText.erase(cursor,tempIter);
      cursor = tempIter;
  }
  void Copy(size_t tokens = 1)
  {
      size_t cursorShift = min<size_t>(tokens, distance(cursor, mainText.end()));
      buffer.clear();
      //buffer.assign(cursor, next(cursor, cursorShift));
      buffer.insert(buffer.end(), cursor, next(cursor, cursorShift));
  }
  void Paste()
  {
      mainText.insert(cursor, buffer.begin(), buffer.end());
  }
  string GetText() const
  {
      //string ouputString;
      //size_t textSize = mainText.size();
      //ouputString.reserve(textSize);
      //size_t charIndex = 0;
      //for (const auto character:mainText)
      //{
      //    ouputString[charIndex] = character;
      //    charIndex++;
      //}

      //return ouputString;
      return string(mainText.begin(), mainText.end());
  }
private:
    list<char> mainText;
    list<char> buffer;
    list<char>::iterator cursor;
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}