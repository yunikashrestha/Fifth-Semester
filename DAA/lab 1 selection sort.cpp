#include <iostream>
using namespace std;

int count = 0;

void selectionsort(int A[], int n) {
    int least, loc, temp;
    for (int i = 0; i < n - 1; ++i) {
        least = A[i];
        loc = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < least) {
                least = A[j];
                loc = j;
            }
            count += 6;
        }
        temp = A[i];
        A[i] = A[loc];
        A[loc] = temp;
    }
    count += 8;
}

int main() {
    int n, A[20];
    cout << "Enter the number of data you want to enter: ";
    cin >> n;
    cout << "Enter the value of data items: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    selectionsort(A, n);

    cout << "After the data is sorted: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << "\t";
    }
    cout << endl << "The no of count is: " << count << endl;

    return 0;
}

