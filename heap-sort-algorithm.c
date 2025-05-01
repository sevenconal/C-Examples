#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    /*
    This function ensures the heap property is maintained at the given index i in the array.
    It is used to build a max heap or min heap.

    Time complexity: O(log n) for heapifying a single element

    :param arr: The array representing the heap
    :param n: The size of the array
    :param i: The index of the current subtree root to heapify
    */
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to implement heap sort
void heapSort(int arr[], int n) {
    /*
    This function sorts an array using the heap sort algorithm.
    It first builds a max heap, then repeatedly extracts the maximum element 
    from the heap and rebuilds the heap until the array is sorted.

    Time complexity:
    - Best case: O(n log n)
    - Worst case: O(n log n)
    - Space complexity: O(1) (it sorts in place)

    :param arr: The array to be sorted
    :param n: The size of the array
    */
    
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the heap sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
