#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {4, 8, 1},
        {6, 5, 3},
        {9, 2, 7}
    };

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for(int j=0 ; j<3 ; j++){
            if(i==j)
            sum+=matrix[i][j];
        }
    }

    cout << "Diagonal sum is: " << sum << endl;

    return 0;
}