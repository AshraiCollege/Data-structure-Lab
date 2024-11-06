#include <stdio.h>

// Function to create an array
void createArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Linear Search Algorithm
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Binary Search Algorithm (requires sorted array)
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid; // Return index if key is found
        } else if (arr[mid] < key) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n, choice, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    createArray(arr, n);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Display Array\n");
        printf("2. Sort Array using Bubble Sort\n");
        printf("3. Search using Linear Search\n");
        printf("4. Search using Binary Search\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayArray(arr, n);
            break;

        case 2:
            bubbleSort(arr, n);
            printf("Array sorted using Bubble Sort.\n");
            break;

        case 3:
            printf("Enter the element to search (Linear Search): ");
            scanf("%d", &key);
            result = linearSearch(arr, n, key);
            if (result != -1) {
                printf("Element found at index %d (Linear Search)\n", result);
            } else {
                printf("Element not found (Linear Search)\n");
            }
            break;

        case 4:
            printf("Enter the element to search (Binary Search): ");
            scanf("%d", &key);
            result = binarySearch(arr, 0, n - 1, key);
            if (result != -1) {
                printf("Element found at index %d (Binary Search)\n", result);
            } else {
                printf("Element not found (Binary Search)\n");
            }
            break;

        case 5:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}
