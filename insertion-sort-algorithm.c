#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    /*
    This function sorts an array using the insertion sort algorithm.
    The basic idea is to take each element from the unsorted part and 
    place it into its correct position in the sorted part.

    Think of it like sorting playing cards in your hands: you pick a card, 
    find where it fits, and insert it there.

    Time complexity:
    - Best case: O(n) (if the array is already sorted)
    - Worst case: O(n^2) (if the array is in reverse order)
    - Space complexity: O(1) (it sorts in place)

    :param arr: The array to be sorted
    :param n: The size of the array
    */
    
    // Traverse the array from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The current element to be inserted
        int j = i - 1;

        // Move elements that are greater than the key one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place the key at the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the insertion sort
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
