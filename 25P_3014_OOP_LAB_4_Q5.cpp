#include <iostream>
using namespace std;

int findMax(int **arr, int rows, int *colCounts) {
    int maxVal = arr[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colCounts[i]; j++) {
            if (arr[i][j] > maxVal)
                maxVal = arr[i][j];
        }
    }

    return maxVal;
}

int main() {
    int rows = 3;
    int colCounts[3] = {2, 5, 3};
   int i , j ;

    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[colCounts[i]];
    }

    cout<<"Enter values of a Arr : "<<endl;
    for(i=0 ; i<rows ; i++){
        for(j=0 ; j<colCounts[i] ; j++){
            cin>>arr[i][j];
        }
           }

    
    // arr[0][0] = 5;  arr[0][1] = 9;
    // arr[1][0] = 3;  arr[1][1] = 17; arr[1][2] = 2; arr[1][3] = 8; arr[1][4] = 11;
    // arr[2][0] = 20; arr[2][1] = 6;  arr[2][2] = 14;


    int maxVal = findMax(arr, rows, colCounts);
    cout << "Maximum element is: " << maxVal << endl;

    
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}