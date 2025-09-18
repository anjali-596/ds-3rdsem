#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) return i + 1;
    }
    return n;
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