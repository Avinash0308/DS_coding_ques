#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int top;
    int size;
    char *arr;
};
int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(Stack *ptr)
{
    if (ptr->top + 1 == ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// void show(Stack *ptr)
// {
//     cout << "The array is :-" << endl;
//     for (int i = 0; i <= ptr->top; i++)
//     {
//         cout << ptr->arr[i] << " ";
//     }
//     cout << endl;
// }
void push(Stack *ptr, char value)
{
    if (isFull(ptr))
    {
        cout << "!!!!Stack Overflow!!!! The stack is full , you can't add any element in it." << endl;
    }
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        ptr->top--;
        return 1;
    }
}
int solveit(string s)
{
    Stack *a = new Stack;
    a->size = s.length();
    a->top = -1;
    a->arr = new char(a->size);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            push(a, '(');
        }
        if (s[i] == ')')
        {
            if (!pop(a))
            {
                return 0;
            }
        }
    }
    if (a->top != -1)
    {
        return 0;
    }
    return 1;
}

int main()
{
    string s = "((((((((*))))))))";
    if (solveit(s))
    {
        cout << "Parathesis Matched" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
    return 0;
}