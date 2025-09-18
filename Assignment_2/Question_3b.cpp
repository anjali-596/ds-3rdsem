#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int start = 0, end = n - 2;  
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == mid + 1) 
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return start + 1;
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


    cout << "Missing number: " << findMissing(arr, n) << endl;
    return 0;
}