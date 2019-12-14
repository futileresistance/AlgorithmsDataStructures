#include <iostream>
using namespace std;
#define MAX 1000
class Stack
{
    int top;
    public:
    int a[MAX];
    Stack() {top = -1;}

bool isEmpty()
    {
        return (top < 0);
    }

bool isFull()
    {
        return (top == MAX - 1);
    }

bool push(int x)
{
    if (isFull())
    {
        cout << "Stack overflow" << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    else
    {
    int x = a[top];
    return x;
    }
}

void displayItems()
{
    int i;
    for (i=top; i>=0; i--)
    {
        cout<<a[i]<< " ";
    }
    cout << endl;
}
};

int main()
{
    Stack myStack;
    myStack.pop();
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);
    myStack.displayItems();
    return 0;
}
