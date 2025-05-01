#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    /*
    This function sorts an array using the selection sort algorithm.
    The idea is to repeatedly find the smallest (or largest, depending on sorting order) element
    in the unsorted part of the array and swap it with the first unsorted element.

    Think of it like picking the smallest card and putting it in the correct place in your hand.

    Time complexity:
    - Best case: O(n^2)
    - Worst case: O(n^2)
    - Space complexity: O(1) (it sorts in place)

    :param arr: The array to be sorted
    :param n: The size of the array
    */
    
    // Traverse the array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume the current element is the smallest

        // Find the smallest element in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the smallest element found with the first unsorted element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the selection sort
int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
