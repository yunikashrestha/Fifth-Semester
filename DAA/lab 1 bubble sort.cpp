#include <iostream>
using namespace std;

int count = 0;

void BubbleSort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (A[j] > A[j + 1]) {
                int t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
            count += 8;
        }
        count += 4;
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

    cout << "Before sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    BubbleSort(a, n);

    cout << "After sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    cout << "No. of steps required: " << count << endl;

    delete[] a; // free dynamically allocated array

    return 0;
}

