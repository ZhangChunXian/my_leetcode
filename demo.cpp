#include <iostream>
using namespace std;


// addition是指针函数, 一个返回类型是指针的函数
int* addition(int a, int b) {
    int *sum = new int(a + b);
    return sum;
}

int subtraction(int a, int b) {
    return a - b;
}

int operation(int x, int y, int (*func)(int, int)) {
    return (*func)(x, y);
}

// minus是函数指针, 指向函数的指针
int (*minus)(int, int) = subtraction;

int *m = addition(1, 2);
int n = operation(3, *m, minus);



int main() {
    int *p = NULL;
    p = new(nothrow) int;
    if (!p)
        cout << "allocation of memory failed\n";
    else {
        *p = 29;
        cout << "Value of p:" << *p << endl;
    }

    float *r = new float(75.25);

    cout << "Value of r:" << *r << endl;

    int n = 5;
    int *q = new(nothrow) int[n];

    if (!q)
        cout << "allocation of memory failed\n";
    else {
        for (int i = 0; i < n; i++)
            q[i] = i + 1;

        cout << "Value store in block of memory: ";
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }

    delete p;
    delete r;
    delete[] q;

    return 0;
}