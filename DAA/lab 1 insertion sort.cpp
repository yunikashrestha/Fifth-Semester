#include <iostream>
using namespace std;

int count = 0;

void InsertionSort(int A[], int n) {
    int key;
    int j;
    for (int i = 1; i <= n - 1; i++) {
        key = A[i];
        for (j = i - 1; A[j] > key && j >= 0; j--) {
            A[j + 1] = A[j];
            count += 7;
        }
        A[j + 1] = key;
        count += 7;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* a = new int[n]; // dynamically allocate array

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }

    InsertionSort(a, n);

    cout << "\nAfter sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }

    cout << "\nRequired number of steps for " << n << " sized data: " << count << endl;

    delete[] a; // free dynamically allocated array

    return 0;
}

