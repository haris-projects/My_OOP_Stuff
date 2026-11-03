#include <iostream>
using namespace std;

int* mergeArrays(int *arr1, int size1, int *arr2, int size2) {
    int *merged = new int[size1 + size2];

    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    return merged;
}

int main() {
    int arr1[] = {2, 4, 6};
    int arr2[] = {1, 3, 5, 7};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int *result = mergeArrays(arr1, size1, arr2, size2);

    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;

    return 0;
}