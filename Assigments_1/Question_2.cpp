#include <iostream>
using namespace std;



int main(){
    int sz;
    cout << "Enter the size of the array: ";
    cin >> sz;
    int arr[sz];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < sz; i++){
        cin >> arr[i];
    }
    

    bool isUnique = true;
    int uniqueCount = 0;

    int i = 0;
    while (i < sz){
        isUnique = true;
        for (int j = 0; j<sz; j++){
            if (i != j && arr[i] == arr[j]){
                isUnique = false;
                break;
            }
        }
        if (!isUnique){
            for (int j = i; j< sz;j++){
                arr[j] = arr[j+1];
            }
            sz--;
        } else {
            i++;
        }
    }
    cout << "The new array is: " << endl;
    for (int i = 0; i < sz-uniqueCount; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}