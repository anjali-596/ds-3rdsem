#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main() {
    cout << "Enter size of array: ";
    int sz;
    cin >> sz;
    int arr[sz];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < sz; i++) {
        cin >> arr[i];
    }
    int n = sz;
    cout << "Enter element to search: ";
    int target;
    cin >> target;

    int bin = binarySearch(arr, n, target);

    cout << "Element found at Index: " << bin << endl;

    return 0;
}