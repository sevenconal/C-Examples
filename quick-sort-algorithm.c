#include <stdio.h>

// Function to partition the array
int partition(int arr[], int low, int high) {
    /*
    This function takes the last element as pivot and places it at its correct 
    position in the sorted array. All elements smaller than the pivot are moved 
    to the left of the pivot, and all elements larger are moved to the right.

    Time complexity of partition: O(n)

    :param arr: The array to be partitioned
    :param low: The starting index of the array to be partitioned
    :param high: The ending index of the array to be partitioned
    :return: The index where the pivot is placed
    */
    
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = (low - 1);  // Index of smaller element

    // Traverse through the array and rearrange elements
    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element with the element at index i + 1
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  // Return the partition index
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high) {
    /*
    This function sorts an array using the quicksort algorithm. It uses divide-and-conquer 
    by selecting a pivot, partitioning the array around the pivot, and recursively sorting 
    the subarrays.

    Time complexity:
    - Best case: O(n log n) (when the pivot divides the array evenly)
    - Worst case: O(n^2) (when the pivot divides the array unevenly)
    - Space complexity: O(log n) (due to recursion)

    :param arr: The array to be sorted
    :param low: The starting index of the array
    :param high: The ending index of the array
    */
    
    if (low < high) {
        // Find pivot index such that the element at pivot is in the correct position
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the quicksort
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
