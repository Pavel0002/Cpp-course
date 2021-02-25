#include "test_runner.h"

#include <ostream>
#include <string>

using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl  << (y) << endl

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    PRINT_VALUES(output, 5, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
  }, "PRINT_VALUES usage example");

  //ostringstream output;
  //if (true)
	 // PRINT_VALUES(output, 5, "red belt");
  //else
	 // PRINT_VALUES(output, 5, "red belt");

  int a = 2, b = 3;
  if (false) PRINT_VALUES(std::cout, a, b);

 

  int ss;
  cin >> ss;
  return 0;
}
