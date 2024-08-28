#include<iostream>
using namespace std;

int count = 0;

int partition(int A[], int l, int r) {
    int x = l;
    int y = r;
    int pivot = A[l];
    
    count = count + 3;
    
    while(x < y) {
        while(A[x] <= pivot) {
            x++;
            count = count + 3;
        }
    
        while(A[y] > pivot) {
            y--;
            count = count + 3;
        }
    
        if(x < y) {
            int t = A[x];
            A[x] = A[y];
            A[y] = t;
            count = count + 4;
        }
    }
    A[l] = A[y];
    A[y] = pivot;
    count = count + 3;
    return y;
}

void QuickSort(int A[], int l, int r) {
    if(l < r) {
        count++;
        int p = partition(A, l, r);
        QuickSort(A, l, p - 1);
        QuickSort(A, p + 1, r);
    }    
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int *a = new int[n]; // Dynamically allocating array based on user input

    cout << "Enter the elements of the array: \n";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Before sorting: \n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    
    QuickSort(a, 0, n - 1);

    cout << "After sorting: \n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    
    cout << "No. of Steps required: " << count << endl;        
        
    delete[] a; // Free the dynamically allocated memory
    return 0;
}

