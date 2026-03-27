#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;  // orta eleman

        if (arr[mid] == target) {
            return mid;  // bulundu
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // sag tarafa bak
        }
        else {
            right = mid - 1; // sol tarafa bak
        }
    }
    return -1; // bulunamadi
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Eleman bulundu! Index: %d\n", result);
    else
        printf("Eleman bulunamadi.\n");

    return 0;
}
