#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Student
struct Student {
    int id;
    char name[50];
    char dept[30];
    int sem;
    char mobile[15];
    struct Student* next;  // Pointer to the next node
};

// Function to create a new student node
struct Student* createNode(int id, char name[], char dept[], int sem, char mobile[]) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->dept, dept);
    newNode->sem = sem;
    strcpy(newNode->mobile, mobile);
    newNode->next = NULL;
    return newNode;
}

// a. Insert student at the front of the SLL
void insertFront(struct Student** head, int id, char name[], char dept[], int sem, char mobile[]) {
    struct Student* newNode = createNode(id, name, dept, sem, mobile);
    newNode->next = *head;
    *head = newNode;
}

// b. Display the list and count the nodes
void displayList(struct Student* head) {
    int count = 0;
    struct Student* temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Dept: %s, Sem: %d, Mobile: %s\n", temp->id, temp->name, temp->dept, temp->sem, temp->mobile);
        temp = temp->next;
        count++;
    }
    printf("Total number of students: %d\n", count);
}

// c. Insert student at the end of the SLL
void insertEnd(struct Student** head, int id, char name[], char dept[], int sem, char mobile[]) {
    struct Student* newNode = createNode(id, name, dept, sem, mobile);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Student* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// c. Delete student at the end of the SLL
void deleteEnd(struct Student** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Student* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// d. Delete student at the front of the SLL
void deleteFront(struct Student** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Student* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// e. Insert student after a given node
void insertAfter(struct Student* prevNode, int id, char name[], char dept[], int sem, char mobile[]) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Student* newNode = createNode(id, name, dept, sem, mobile);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// e. Delete a student after a given node
void deleteAfter(struct Student* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("No node exists after the given node\n");
        return;
    }
    struct Student* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

int main() {
    struct Student* head = NULL; // Initialize the list as empty

    // Adding some students using front insertion
    insertFront(&head, 1, "Alice", "CSE", 3, "9876543210");
    insertFront(&head, 2, "Bob", "ECE", 5, "9876543211");
    insertFront(&head, 3, "Charlie", "EEE", 2, "9876543212");

    printf("Initial List:\n");
    displayList(head);  // Displaying list

    // Inserting a student at the end
    insertEnd(&head, 4, "David", "ME", 4, "9876543213");
    printf("\nList after inserting at the end:\n");
    displayList(head);  // Displaying list

    // Deleting a student at the end
    deleteEnd(&head);
    printf("\nList after deleting at the end:\n");
    displayList(head);

    // Deleting a student at the front
    deleteFront(&head);
    printf("\nList after deleting at the front:\n");
    displayList(head);

    // Inserting after a given node (for example, after the first node)
    insertAfter(head, 5, "Eve", "IT", 1, "9876543214");
    printf("\nList after inserting after first node:\n");
    displayList(head);

    // Deleting a node after a given node (for example, after the first node)
    deleteAfter(head);
    printf("\nList after deleting node after first node:\n");
    displayList(head);

    return 0;
}
