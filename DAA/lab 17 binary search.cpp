#include <iostream>
using namespace std;
int binarySearch(int arr[], int target, int left, int right, int& count) {
    if (left > right) {
        count += 1; 
        return -1;
    }
    int mid = left + (right - left) / 2;
count+=4;
    if (arr[mid] == target) {
        count += 1; 
        return mid;
    } else if (arr[mid] < target) {
        count += 2; 
        return binarySearch(arr, target, mid + 1, right, count);
    } else {
        count += 2; 
        return binarySearch(arr, target, left, mid - 1, count);
    }
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements in sorted order:\n ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
    int target;
    cout << "Enter the element to search:";
    cin >> target;
    int count = 0;
    int result = binarySearch(arr, target, 0, size - 1, count);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;
    cout << "The total number of steps required are: " << count << endl;
    return 0;
}

