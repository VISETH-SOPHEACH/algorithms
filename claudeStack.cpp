#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ============================================================================
// STACK IN C++ - COMPLETE TUTORIAL
// ============================================================================
// A stack is a Last-In-First-Out (LIFO) data structure
// Think of it like a stack of plates - you add and remove from the top

// ============================================================================
// 1. BASIC STACK OPERATIONS
// ============================================================================
void basicStackOperations()
{
  cout << "\n=== BASIC STACK OPERATIONS ===\n";

  stack<int> s;

  // push() - Add elements to the top
  s.push(10);
  s.push(20);
  s.push(30);
  cout << "Pushed: 10, 20, 30\n";

  // top() - Access the top element
  cout << "Top element: " << s.top() << "\n";

  // pop() - Remove the top element
  s.pop();
  cout << "After pop(), top is: " << s.top() << "\n";

  // size() - Get number of elements
  cout << "Stack size: " << s.size() << "\n";

  // empty() - Check if stack is empty
  cout << "Is empty? " << (s.empty() ? "Yes" : "No") << "\n";
}

// ============================================================================
// 2. DISPLAYING STACK CONTENTS
// ============================================================================
void displayStack(stack<int> s)
{
  cout << "Stack contents (top to bottom): ";
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << "\n";
}

void stackDisplay()
{
  cout << "\n=== DISPLAYING STACK ===\n";
  stack<int> s;
  s.push(5);
  s.push(15);
  s.push(25);
  s.push(35);

  displayStack(s);
}

// ============================================================================
// 3. PRACTICAL EXAMPLE: BALANCED PARENTHESES CHECKER
// ============================================================================
bool isBalanced(string expr)
{
  stack<char> s;

  for (char ch : expr)
  {
    // Push opening brackets
    if (ch == '(' || ch == '{' || ch == '[')
    {
      s.push(ch);
    }
    // Check closing brackets
    else if (ch == ')' || ch == '}' || ch == ']')
    {
      if (s.empty())
        return false;

      char top = s.top();
      if ((ch == ')' && top == '(') ||
          (ch == '}' && top == '{') ||
          (ch == ']' && top == '['))
      {
        s.pop();
      }
      else
      {
        return false;
      }
    }
  }

  return s.empty();
}

void balancedParenthesesDemo()
{
  cout << "\n=== BALANCED PARENTHESES CHECKER ===\n";

  string test1 = "{[()]}";
  string test2 = "{[(])}";
  string test3 = "((()))";
  string test4 = "({[]})";

  cout << test1 << " is " << (isBalanced(test1) ? "balanced" : "not balanced") << "\n";
  cout << test2 << " is " << (isBalanced(test2) ? "balanced" : "not balanced") << "\n";
  cout << test3 << " is " << (isBalanced(test3) ? "balanced" : "not balanced") << "\n";
  cout << test4 << " is " << (isBalanced(test4) ? "balanced" : "not balanced") << "\n";
}

// ============================================================================
// 4. PRACTICAL EXAMPLE: REVERSE A STRING
// ============================================================================
string reverseString(string str)
{
  stack<char> s;

  // Push all characters
  for (char ch : str)
  {
    s.push(ch);
  }

  // Pop all characters (LIFO gives reverse)
  string reversed = "";
  while (!s.empty())
  {
    reversed += s.top();
    s.pop();
  }

  return reversed;
}

void reverseStringDemo()
{
  cout << "\n=== REVERSE STRING USING STACK ===\n";

  string original = "Hello, World!";
  string reversed = reverseString(original);

  cout << "Original: " << original << "\n";
  cout << "Reversed: " << reversed << "\n";
}

// ============================================================================
// 5. PRACTICAL EXAMPLE: UNDO FUNCTIONALITY
// ============================================================================
class TextEditor
{
private:
  string text;
  stack<string> history;

public:
  void write(string newText)
  {
    history.push(text); // Save current state
    text += newText;
    cout << "Text: " << text << "\n";
  }

  void undo()
  {
    if (!history.empty())
    {
      text = history.top();
      history.pop();
      cout << "After undo: " << text << "\n";
    }
    else
    {
      cout << "Nothing to undo!\n";
    }
  }

  string getText()
  {
    return text;
  }
};

void undoDemo()
{
  cout << "\n=== UNDO FUNCTIONALITY (TEXT EDITOR) ===\n";

  TextEditor editor;
  editor.write("Hello");
  editor.write(" World");
  editor.write("!");
  editor.undo();
  editor.undo();
  editor.write(" C++");
}

// ============================================================================
// 6. STACK WITH CUSTOM CLASS
// ============================================================================
class Person
{
public:
  string name;
  int age;

  Person(string n, int a) : name(n), age(a) {}

  void display()
  {
    cout << name << " (" << age << ")\n";
  }
};

void customClassStack()
{
  cout << "\n=== STACK WITH CUSTOM CLASS ===\n";

  stack<Person> people;

  people.push(Person("Alice", 25));
  people.push(Person("Bob", 30));
  people.push(Person("Charlie", 35));

  cout << "Top person: ";
  people.top().display();

  cout << "\nAll people (top to bottom):\n";
  while (!people.empty())
  {
    people.top().display();
    people.pop();
  }
}

// ============================================================================
// 7. IMPLEMENTING YOUR OWN STACK (using array)
// ============================================================================
class MyStack
{
private:
  int arr[100];
  int topIndex;

public:
  MyStack() : topIndex(-1) {}

  void push(int value)
  {
    if (topIndex >= 99)
    {
      cout << "Stack overflow!\n";
      return;
    }
    arr[++topIndex] = value;
  }

  void pop()
  {
    if (topIndex < 0)
    {
      cout << "Stack underflow!\n";
      return;
    }
    topIndex--;
  }

  int top()
  {
    if (topIndex < 0)
    {
      cout << "Stack is empty!\n";
      return -1;
    }
    return arr[topIndex];
  }

  bool empty()
  {
    return topIndex < 0;
  }

  int size()
  {
    return topIndex + 1;
  }
};

void customStackDemo()
{
  cout << "\n=== CUSTOM STACK IMPLEMENTATION ===\n";

  MyStack s;
  s.push(100);
  s.push(200);
  s.push(300);

  cout << "Top: " << s.top() << "\n";
  cout << "Size: " << s.size() << "\n";

  s.pop();
  cout << "After pop, top: " << s.top() << "\n";
}

// ============================================================================
// 8. PRACTICAL EXAMPLE: EVALUATE POSTFIX EXPRESSION
// ============================================================================
int evaluatePostfix(string expr)
{
  stack<int> s;

  for (char ch : expr)
  {
    // If digit, push to stack
    if (isdigit(ch))
    {
      s.push(ch - '0');
    }
    // If operator, pop two operands and apply
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
      int operand2 = s.top();
      s.pop();
      int operand1 = s.top();
      s.pop();

      int result;
      switch (ch)
      {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
      }
      s.push(result);
    }
  }

  return s.top();
}

void postfixDemo()
{
  cout << "\n=== POSTFIX EXPRESSION EVALUATION ===\n";

  string expr = "23*54*+9-"; // (2*3) + (5*4) - 9 = 6 + 20 - 9 = 17
  cout << "Expression: " << expr << "\n";
  cout << "Result: " << evaluatePostfix(expr) << "\n";
}

// ============================================================================
// MAIN FUNCTION - RUN ALL EXAMPLES
// ============================================================================
int main()
{
  cout << "========================================\n";
  cout << "   C++ STACK TUTORIAL WITH EXAMPLES\n";
  cout << "========================================\n";

  basicStackOperations();
  stackDisplay();
  balancedParenthesesDemo();
  reverseStringDemo();
  undoDemo();
  customClassStack();
  customStackDemo();
  postfixDemo();

  cout << "\n========================================\n";
  cout << "KEY TAKEAWAYS:\n";
  cout << "- Stack is LIFO (Last In, First Out)\n";
  cout << "- Main operations: push(), pop(), top()\n";
  cout << "- Useful for: undo, recursion, parsing\n";
  cout << "- Time complexity: O(1) for all ops\n";
  cout << "========================================\n";

  return 0;
}