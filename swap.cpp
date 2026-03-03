#include <iostream>
// #include <string>
using namespace std;

string reverseString(const string &str)
{
  string stack = str; // copy orihinal string 
  string result;
  result.reserve(str.length());

  while (!stack.empty())
  {
    result += stack.back();
    stack.pop_back();
  }

  return result;
}

int main()
{
  string s = "hello wolrd ";
  cout << "before  : " << s << "\n";
  cout << "after revers: " << reverseString(s) << "\n";
  return 0;
}