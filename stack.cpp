#include <iostream>
#include <stack>
using namespace std;

using namespace std;

int main () {

  stack<int> s;

  s.push(10);
  s.push(20);
  s.push(30);

  cout << "Top element : " << s.top() << endl;  // output 30

  s.pop();  // remove 30

  cout << "Top after pop : " << s.top() << endl;
  cout << "Stack size : " << s.size() << endl ;

  return 0;
}