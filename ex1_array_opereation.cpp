#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct array
{
    int n;
    int *arr = new int[n];
    int get(int i)
    {
        return arr[i];
    }
    void set(int i, int num)
    {
        arr[i] = num;
    }
    int max()
    {
        int x = -888;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > x)
            {
                x = arr[i];
            }
        }
        return x;
    }
    int min()
    {
        int x = 888;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < x)
            {
                x = arr[i];
            }
        }
        return x;
    }
    void search(int num)
    {
        bool a = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                cout << "The element is present at index no. : " << i << endl;
                a = 0;
                break;
            }
        }
        if (a)
        {
            cout << "The element is not present in array\n";
        }
    }
    void append(int num)
    {
        int *a = new int[n + 1];
        for (int i = 0; i < n; i++)
        {
            a[i] = arr[i];
        }
        a[n] = num;
        cout << "Previously the array was : {";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "}" << endl;
        delete[] arr;
        arr = a;
        n++;
        cout << "Now the array is : {";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "}" << endl;
    }
    void insert(int i, int num)
    {
        int *a = new int[n + 1];
        a[i] = num;
        for (int x = 0; x < n; x++)
        {
            if (x >= i)
            {
                a[x + 1] = arr[x];
            }
            else
            {
                a[x] = arr[x];
            }
        }
        cout << "Previously the array was : {";
        for (int x = 0; x < n; x++)
        {
            cout << arr[x] << " ";
        }
        cout << "}" << endl;
        delete[] arr;
        arr = a;
        n++;
        cout << "Now the array is : {";
        for (int x = 0; x < n; x++)
        {
            cout << arr[x] << " ";
        }
        cout << "}" << endl;
    }
} avi;
int main()
{
    avi arr;
    cout << "Please input the number of elements you want in your array\n";
    cin >> arr.n;
    int num;
    for (int i = 0; i < arr.n; i++)
    {
        cout << "Input " << (i + 1) << " : ";
        cin >> num;
        arr.set(i, num);
    }
    cout << "Now as you have set all the elements of an array , you can now access certain operations listed below: " << endl;
    while (1)
    {
        cout << "1.> get(i)\n2.> max()\n3.> min()\n4.> insert(i,num)\n5.> append(x)\n6.> search(num)\n7.> exit\n";
        int a, b, c;
        cout << "Please type the number corresponding to function you want to perform \n";
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "Please enter the index : ";
            cin >> b;
            cout << arr.get(b) << endl;
            break;

        case 2:
            cout << arr.max() << endl;
            break;

        case 3:
            cout << arr.min() << endl;
            break;

        case 4:
            cout << "Please input the index where you want to store the number : ";
            cin >> b;
            cout << "Now input the number : ";
            cin >> c;
            arr.insert(b, c);
            break;

        case 5:
            cout << "Please enter the number : ";
            cin >> b;
            arr.append(b);
            break;

        case 6:
            cout << "Please enter the number : ";
            cin >> b;
            arr.search(b);
            break;

        default:
            cout << "Exiting...........\n";
            goto end;
        }
    }
end:
    return 0;
}