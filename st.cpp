#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

bool isEmpty()
{
  return (top == -1);
}

bool isFull()
{
  return (top == MAX - 1);
} 

void push(int value)
{
  if (isFull())
  {
    cout << "Stack Overflow\n";
  }
  else
  {
    stack[++top] = value;
  }
}

void pop()
{
  if (isEmpty())
  {
    cout << "Stack Underflow\n";
  }
  else
  {
    cout << "Deleted: " << stack[top--] << endl;
  }
}

int peek()
{
  if (isEmpty())
  {
    cout << "Stack is Empty\n";
    return -1;
  }
  return stack[top];
}

void display()
{
  if (isEmpty())
  {
    cout << "Stack is Empty\n";
  }
  else
  {
    for (int i = top; i >= 0; i--)
    {
      cout << stack[i] << endl;
    }
  }
}

int main()
{
  push(10);
  push(20);
  push(30);

  display();

  pop();

  cout << "Top element: " << peek() << endl;

  return 0;
}