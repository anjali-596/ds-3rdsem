#include <iostream>
using namespace std;

#define MAX 100

struct Sparse {
    int data[MAX][3];
    int rows, cols, nonZero;
};

void createSparse(Sparse &s, int mat[10][10], int r, int c) {
    s.rows = r;
    s.cols = c;
    s.nonZero = 0;

    int k = 1;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(mat[i][j] != 0) {
                s.data[k][0] = i;
                s.data[k][1] = j;
                s.data[k][2] = mat[i][j];
                k++;
                s.nonZero++;
            }
        }
    }
    s.data[0][0] = r;
    s.data[0][1] = c;
    s.data[0][2] = s.nonZero;
}

void displaySparse(Sparse s) {
    cout << "Row Col Val\n";
    for(int i=0; i<=s.nonZero; i++) {
        cout << s.data[i][0] << "   "
             << s.data[i][1] << "   "
             << s.data[i][2] << endl;
    }
}

Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.nonZero = s.nonZero;
    t.data[0][0] = t.rows;
    t.data[0][1] = t.cols;
    t.data[0][2] = t.nonZero;

    int k=1;
    for(int col=0; col<s.cols; col++) {
        for(int i=1; i<=s.nonZero; i++) {
            if(s.data[i][1] == col) {
                t.data[k][0] = s.data[i][1];
                t.data[k][1] = s.data[i][0];
                t.data[k][2] = s.data[i][2];
                k++;
            }
        }
    }
    return t;
}

Sparse add(Sparse a, Sparse b) {
    Sparse c;
    if(a.rows != b.rows || a.cols != b.cols) {
        cout << "Addition not possible!\n";
        c.nonZero = 0;
        return c;
    }

    c.rows = a.rows;
    c.cols = a.cols;
    int i=1, j=1, k=1;
    while(i<=a.nonZero && j<=b.nonZero) {
        if(a.data[i][0] < b.data[j][0] ||
          (a.data[i][0]==b.data[j][0] && a.data[i][1] < b.data[j][1])) {
            c.data[k][0]=a.data[i][0];
            c.data[k][1]=a.data[i][1];
            c.data[k][2]=a.data[i][2];
            i++; k++;
        }
        else if(b.data[j][0] < a.data[i][0] ||
               (b.data[j][0]==a.data[i][0] && b.data[j][1] < a.data[i][1])) {
            c.data[k][0]=b.data[j][0];
            c.data[k][1]=b.data[j][1];
            c.data[k][2]=b.data[j][2];
            j++; k++;
        }
        else {
            c.data[k][0]=a.data[i][0];
            c.data[k][1]=a.data[i][1];
            c.data[k][2]=a.data[i][2] + b.data[j][2];
            i++; j++; k++;
        }
    }
    while(i<=a.nonZero) {
        c.data[k][0]=a.data[i][0];
        c.data[k][1]=a.data[i][1];
        c.data[k][2]=a.data[i][2];
        i++; k++;
    }
    while(j<=b.nonZero) {
        c.data[k][0]=b.data[j][0];
        c.data[k][1]=b.data[j][1];
        c.data[k][2]=b.data[j][2];
        j++; k++;
    }
    c.nonZero = k-1;
    c.data[0][0]=c.rows;
    c.data[0][1]=c.cols;
    c.data[0][2]=c.nonZero;
    return c;
}

Sparse multiply(Sparse a, Sparse b) {
    Sparse c;
    if(a.cols != b.rows) {
        cout << "Multiplication not possible!\n";
        c.nonZero=0;
        return c;
    }

    int matA[10][10] = {0}, matB[10][10] = {0}, matC[10][10] = {0};

    for(int i=1;i<=a.nonZero;i++) {
        matA[a.data[i][0]][a.data[i][1]] = a.data[i][2];
    }
    for(int i=1;i<=b.nonZero;i++) {
        matB[b.data[i][0]][b.data[i][1]] = b.data[i][2];
    }

    for(int i=0;i<a.rows;i++) {
        for(int j=0;j<b.cols;j++) {
            for(int k=0;k<a.cols;k++) {
                matC[i][j] += matA[i][k]*matB[k][j];
            }
        }
    }

    createSparse(c, matC, a.rows, b.cols);
    return c;
}

int main() {
    int A[3][3] = {{0,5,0},{0,0,8},{0,0,3}};
    int B[3][3] = {{0,2,0},{0,0,6},{7,0,0}};

    Sparse s1, s2;
    createSparse(s1, A, 3, 3);
    createSparse(s2, B, 3, 3);

    cout << "Matrix A in triplet form:\n";
    displaySparse(s1);
    cout << "\nMatrix B in triplet form:\n";
    displaySparse(s2);

    cout << "\nTranspose of A:\n";
    displaySparse(transpose(s1));

    cout << "\nA + B:\n";
    displaySparse(add(s1, s2));

    cout << "\nA * B:\n";
    displaySparse(multiply(s1, s2));

    return 0;
}