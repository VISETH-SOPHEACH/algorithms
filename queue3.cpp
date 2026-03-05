#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
  queue<string> q;

  // Adding elements
  q.push("Task 1 - render thumbnail");
  q.push("Task 2 - compress video");
  q.push("Task 3 - upload to cloud");

  // or more modern (C++17+)
  // q.emplace("Task 4 - send notification");

  cout << "Queue size: " << q.size() << "\n\n"; // 3

  // Processing queue (classic pattern)
  while (!q.empty())
  {
    cout << "Processing: " << q.front() << "\n";
    q.pop(); // IMPORTANT: pop() does NOT return the value!
  }

  cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << "\n";

  return 0;
}