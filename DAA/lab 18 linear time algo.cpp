#include <iostream>
#include <cstdlib>   // for std::rand and std::srand
#include <ctime>     // for std::time
using namespace std;
// Function prototypes
int partition(int arr[], int left, int right, int pivot_index);
int randomized_select(int arr[], int left, int right, int position); // Changed parameter name
// Main function
int main() {
    int n;
    // Prompt user for size of array
    cout << "Enter the size of the array: ";
    cin >> n;
    // Input array elements from user
    int arr[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // Prompt user for position (1-based index) of the smallest element to find
    int position;
    cout << "Enter the position (1-based index) of the smallest element to find: ";
    cin >> position;
    // Convert 1-based position to 0-based index
    int k = position - 1;
    srand(time(NULL));  // Seed the random number generator
    int result = randomized_select(arr, 0, n - 1, k);
    cout << "The smallest element from position "<< position <<" is:" <<result << endl;
    return 0;
}
// Function to perform randomized selection
int randomized_select(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }
    // Choose a random pivot index
    int pivot_index = left + rand() % (right - left + 1);
    // Partition the array around the pivot
    pivot_index = partition(arr, left, right, pivot_index);
    // The position of the pivot in the sorted array
    if (k == pivot_index) {
        return arr[k];
    } else if (k < pivot_index) {
        return randomized_select(arr, left, pivot_index - 1, k);
    } else {
        return randomized_select(arr, pivot_index + 1, right, k);
    }
}
// Function to partition the array around the pivot
int partition(int arr[], int left, int right, int pivot_index) {
    int pivot_value = arr[pivot_index];
    // Move pivot to end
    swap(arr[pivot_index], arr[right]);
    int store_index = left;
    // Move all smaller elements to the left
    for (int i = left; i < right; ++i) {
        if (arr[i] < pivot_value) {
            swap(arr[store_index], arr[i]);
            store_index++;
        }
    }
    // Move pivot to its final place
    swap(arr[right], arr[store_index]);
    return store_index;
}
