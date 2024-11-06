#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case 1: 0th Fibonacci number is 0
    } else if (n == 1) {
        return 1; // Base case 2: 1st Fibonacci number is 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int choice, n, i;

    // Menu for selecting the operation
    printf("Select an operation:\n");
    printf("1. Calculate Factorial\n");
    printf("2. Display Fibonacci Sequence\n");
    scanf("%d", &choice);

    // Factorial calculation
    if (choice == 1) {
        printf("Enter a number to calculate its factorial: ");
        scanf("%d", &n);

        if (n < 0) {
            printf("Factorial is not defined for negative numbers.\n");
        } else {
            printf("Factorial of %d is %d\n", n, factorial(n));
        }
    }

    // Fibonacci sequence display
    else if (choice == 2) {
        printf("Enter the number of Fibonacci terms to display: ");
        scanf("%d", &n);

        if (n < 1) {
            printf("Please enter a positive integer.\n");
        } else {
            printf("Fibonacci sequence of %d terms:\n", n);
            for (i = 0; i < n; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
        }
    }

    // Invalid choice
    else {
        printf("Invalid choice. Please select 1 or 2.\n");
    }

    return 0;
}
