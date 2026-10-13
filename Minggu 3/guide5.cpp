#include <iostream>
using namespace std;

void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y= temp;
}

int main(){
    int a = 4, b = 6;

    tukarValue(a, b);
    cout << "Setelah Call by value -> a = 
}