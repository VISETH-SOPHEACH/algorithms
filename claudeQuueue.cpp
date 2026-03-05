#include <iostream>
#include <queue>
using namespace std;

int main()
{
  queue<int> q;

  // Add elements
  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Front: " << q.front() << endl; // 10
  cout << "Back: " << q.back() << endl;   // 30
  cout << "Size: " << q.size() << endl;   // 3

  // Remove elements
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  // Output: 10 20 30

  return 0;
}