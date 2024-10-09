/* Write a program to demonstrate insertion, deletion, search and displaying of an element in an array.*/
#include <stdio.h>
#define MAX_SIZE 100
// Function to display the elements of the array
void display(int arr[], int size) {
 printf("Array elements: ");
 for (int i = 0; i < size; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
}
// Function to search for an element in the array
int search(int arr[], int size, int key) {
 for (int i = 0; i < size; i++) {
 if (arr[i] == key) {
 return i;
 }
}
 return -1; // Element not found
}
// Function to insert an element at the end of the array
int insert(int arr[], int *size, int element) {
 if (*size >= MAX_SIZE) {
 printf("Array is full. Insertion failed.\n");
 return 0; // Insertion failed
 }
 arr[*size] = element;
 (*size)++;
 printf("Element inserted successfully.\n");
 return 1; // Insertion successful
}
// Function to delete an element from the array
int deleteElement(int arr[], int *size, int element) {
 int position = search(arr, *size, element);
 if (position == -1) {
 printf("Element not found. Deletion failed.\n");
 return 0; // Deletion failed
 }
 // Shift elements to the left to fill the gap created by deletion
 for (int i = position; i < *size - 1; i++) {
 arr[i] = arr[i + 1];
 }
 (*size)--;
 printf("Element deleted successfully.\n");
 return 1; // Deletion successful
}
int main() {
 int arr[MAX_SIZE];
 int size = 0;
 int choice;
while (1) {
 printf("\nMenu:\n");
 printf("1. Insert an element\n");
 printf("2. Delete an element\n");
 printf("3. Search for an element\n");
 printf("4. Display elements\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
printf("Enter the element to insert: ");
 int elementToInsert;
 scanf("%d", &elementToInsert);
 insert(arr, &size, elementToInsert);
 break;
 case 2:
 printf("Enter the element to delete: ");
 int elementToDelete;
 scanf("%d", &elementToDelete);
 deleteElement(arr, &size, elementToDelete);
 break;
 case 3:
 printf("Enter the element to search: ");
 int key;
 scanf("%d", &key);
 int position = search(arr, size, key);
 if (position != -1) {
 printf("Element %d found at position %d\n", key, position);
 } else {
 printf("Element %d not found\n", key);
 }
 break;
 case 4:
 display(arr, size);
 break;
 case 5:
 printf("Exiting program.\n");
 return 0;
default:
 printf("Invalid choice. Please try again.\n");
 }
 }
 return 0;
}
