// Improved selection sort
#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    for (int i = 0, j = n-1; i < j; i++, j--) {
        int minIndex = i, maxIndex = i;
        
        // Find min and max in current range
        for (int k = i; k <= j; k++) {
            if (arr[k] < arr[minIndex]) minIndex = k;
            if (arr[k] > arr[maxIndex]) maxIndex = k;
        }
        
        // Place min at beginning
        swap(arr[i], arr[minIndex]);
        
        // If max was at i, it got swapped to minIndex
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        
        // Place max at end
        swap(arr[j], arr[maxIndex]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    improvedSelectionSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}