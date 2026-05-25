#include <iostream>
using namespace std;

void swapNumbers(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int a = 3, b = 7;
    cout << "before: a=" << a << " b=" << b << '\n';
    swapNumbers(&a, &b);
    cout << "after: a=" << a << " b=" << b << '\n';
    return 0;
}
