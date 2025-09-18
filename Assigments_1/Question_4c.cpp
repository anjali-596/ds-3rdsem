#include <iostream>
using namespace std;



int main(){
    
    int r1,r2 = 0;
    cout << endl << "Enter the number of rows in the first matrix: " << endl;
    cin >> r1;
    cout << "Enter the number of columns in the first matrix: " << endl;    
    cin >> r2;
    int matrix4[r1][r2];
    int transposedMatrix[r2][r1] = {0};
    cout << "Enter the elements of the first matrix: " << endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < r2; j++){
            cin >> matrix4[i][j];
        }
    }
    cout << "The entered matrix is: " << endl;
    for (int i = 0; i < r1; i++){   
        for (int j = 0; j < r2; j++){
            cout << matrix4[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < r1; i++){
        for (int j = 0; j < r2; j++){
            transposedMatrix[j][i] = matrix4[i][j];
        }
        cout << endl;
    }
    cout << "The transposed matrix is: " << endl;
    for (int i = 0; i < r2; i++){   
        for (int j = 0; j < r1; j++){
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

}