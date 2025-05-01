#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    /*
    This function sorts an array using the bubble sort algorithm.
    The idea is to repeatedly step through the list, compare adjacent elements, 
    and swap them if they are in the wrong order. This process repeats until the list is sorted.

    Think of it like bubbles rising to the surface: larger elements "bubble up" to their correct position.

    Time complexity:
    - Best case: O(n) (when the array is already sorted)
    - Worst case: O(n^2) (when the array is in reverse order)
    - Space complexity: O(1) (it sorts in place)

    :param arr: The array to be sorted
    :param n: The size of the array
    */
    
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted, no need to check them again
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements and swap them if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

// Main function to test the bubble sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
