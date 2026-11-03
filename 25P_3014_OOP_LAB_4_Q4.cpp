#include <iostream>
using namespace std;

int* rowSums(int **matrix, int rows, int cols) {
    int *sums = new int[rows];

    for (int i = 0; i < rows; i++) {
        sums[i] = 0;
        for (int j = 0; j < cols; j++) {
            sums[i] += matrix[i][j];
        }
    }

    return sums;
}

int main() {
    int rows = 3, cols = 3;

    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // fill it with some values
    // int val = 1;
    cout<<"Enter values of a matrix"<<endl;
        for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin>>matrix[i][j];
        }
    }

    int *result = rowSums(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << " sum: " << result[i] << endl;
    }

    // cleanup
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] result;

    return 0;
}