#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    /*
    This function merges two sorted subarrays into a single sorted array.

    Time complexity of merge: O(n)

    :param arr: The array to be merged
    :param left: The starting index of the left subarray
    :param mid: The middle index (dividing point between left and right subarrays)
    :param right: The ending index of the right subarray
    */
    
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;  // Size of the right subarray

    // Create temporary arrays to hold the values
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    /*
    This function sorts an array using the merge sort algorithm. It divides 
    the array into two halves, recursively sorts them, and then merges the sorted halves.

    Time complexity:
    - Best case: O(n log n)
    - Worst case: O(n log n)
    - Space complexity: O(n) (since it requires extra space for merging)

    :param arr: The array to be sorted
    :param left: The starting index of the array
    :param right: The ending index of the array
    */
    
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle point
        mergeSort(arr, left, mid);  // Recursively sort the left half
        mergeSort(arr, mid + 1, right);  // Recursively sort the right half
        merge(arr, left, mid, right);  // Merge the sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the merge sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
