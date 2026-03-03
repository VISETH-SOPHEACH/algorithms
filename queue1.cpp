#include <iostream>
#include <queue> // Required header
using namespace std;

int main()
{
  queue<string> taskQueue;

  // Enqueue: Adding elements
  taskQueue.push("Task A");
  taskQueue.push("Task B");
  taskQueue.push("Task C");

  cout << "Queue size: " << taskQueue.size() << endl;

  // Access and Remove
  while (!taskQueue.empty())
  {
    cout << "Processing: " << taskQueue.front() << endl; // Look at the first element
    taskQueue.pop();                                     // Remove the first element
  }
  
  return 0;
}