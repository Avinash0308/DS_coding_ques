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
char pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        char c = ptr->arr[ptr->top];
        ptr->top--;
        return c;
    }
}
int isOperator(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
int prec(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {

        return 1;
    }
    return 0;
}
char StackTop(Stack *ptr)
{
    return ptr->arr[ptr->top];
}
char *intopo(char *infix)
{
    Stack *postfix = new Stack;
    postfix->size = 100;
    postfix->top = -1;
    postfix->arr = new char(postfix->size);
    int i = 0, j = 0;
    char *c = new char(postfix->size);
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            c[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (prec(infix[i]) > prec(StackTop(postfix)))
            {
                push(postfix, infix[i]);
                i++;
            }
            else
            {
                c[j] = pop(postfix);
                j++;
            }
        }
    }
    while (!isEmpty(postfix))
    {
        c[j] = pop(postfix);
        j++;
    }
    c[j] = '\0';
    return c;
}

int main()
{

    char arr[] = "x-y/x-k*d";

    cout <<endl<<endl<< "The postfix is :: ";
    cout << intopo(arr) << endl<<endl<<endl;
    return 0;
}