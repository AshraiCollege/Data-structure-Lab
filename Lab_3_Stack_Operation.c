#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

int stack[MAX];  // Stack array
int top = -1;    // Variable to track the top of the stack

// Function to push an element onto the stack
void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push element.\n");

    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Function to display the status of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
// Function to display the top element of the stack
void displayTop() {
    if (top == -1) {
        printf("Stack is empty.\n");
    }
    else if(top == MAX-1)
    {
         printf("Stack is Full.\n");
         printf("Top element: %d\n", stack[top]);
    }

}
// Function to display the bottom element of the stack
void displayBottom() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Bottom element: %d\n", stack[0]);
    }
}



// Main function to drive the menu-driven program
int main() {
    int choice;
    while (1) {
        printf("\n***** Stack Menu *****\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Display Stack\n");
        printf("4. Display Top Element of Stack\n");
        printf("5. Display Bottom Element of Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                displayTop();
                break;
            case 5:
                displayBottom();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

