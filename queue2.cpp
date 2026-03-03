#include <iostream>

struct Node
{
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

class MyQueue
{
private:
  Node *front, *rear;

public:
  MyQueue() : front(nullptr), rear(nullptr) {}

  void enqueue(int x)
  {
    Node *temp = new Node(x);
    if (rear == nullptr)
    {
      front = rear = temp;
      return;
    }
    rear->next = temp;
    rear = temp;
  }

  void dequeue()
  {
    if (front == nullptr)
      return;
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    delete temp;
  }

  int getFront()
  {
    return (front != nullptr) ? front->data : -1;
  }
};

int main()
{
  // 1. Create an instance of your queue
  MyQueue q;

  // 2. Add some data
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  // 3. View the front element
  std::cout << "Front element is: " << q.getFront() << std::endl; // Output: 10

  // 4. Remove an element
  q.dequeue();
  std::cout << "Front element after 1 dequeue: " << q.getFront() << std::endl; // Output: 20

  return 0; // Signals the OS that the program finished successfully
}