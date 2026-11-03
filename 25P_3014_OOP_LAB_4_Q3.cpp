#include <iostream>
using namespace std;

int countEven(int *arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0)
            count++;
    }
    return count;
}

int main() {
    int nums[] = {10, 3, 8, 15, 6, 7, 22};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = countEven(nums, size);
    cout << "Even numbers count: " << result << endl;

    return 0;
}