#include <iostream>
using namespace std;



int main(){
    
    int rows;
    int cols;
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;
    int matrix1[rows][cols];
    cout << "Enter the elements of the first matrix: ";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> matrix1[i][j];
        }
    }
    int matrix2[rows][cols];
    cout << "Enter the elements of the second matrix: ";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> matrix2[i][j];
        }
    }
    
    int sumRows[rows] = {0};
    int sumCols[cols] = {0};

   for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            sumRows[i] += matrix1[i][j];
            sumCols[j] += matrix1[i][j];
        }
    }

    cout << endl << "The sum of the rows is: " << endl;
    for (int i = 0; i < rows; i++){
        cout << sumRows[i] << " ";
    }
    cout << endl;
    cout << "The sum of the columns is: " << endl;
    for (int i = 0; i < cols; i++){
        cout << sumCols[i] << " ";
    }

}