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
    

    for (int i =0; i< sz/2 ; i++){
        int temp = arr[i];
        arr[i] = arr[sz-i-1];
        arr[sz-i-1] = temp;
    }
    cout << endl << "The reversed array is: " << endl;
    for (int i = 0; i < sz; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}