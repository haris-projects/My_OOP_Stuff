#include <iostream>
using namespace std;

int main() {
    int arr[] = {45, 12, 67, 3, 89, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *ptr = arr;
    int minVal = *ptr;  

    for (int i = 1; i < n; i++) {
        if (*(ptr + i) < minVal)
            minVal = *(ptr + i);
    }

    cout << "Minimum element is: " << minVal << endl;

    return 0;
}