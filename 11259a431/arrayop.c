#include <stdio.h>

int main() {
    int arr[100], n, choice, i, pos, value, found;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n----- Array Operations -----\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array elements: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 2:
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);

                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = n; i > pos; i--)
                        arr[i] = arr[i - 1];
                    arr[pos] = value;
                    n++;
                    printf("Element inserted successfully.\n");
                }
                break;

            case 3:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = pos; i < n - 1; i++)
                        arr[i] = arr[i + 1];
                    n--;
                    printf("Element deleted successfully.\n");
                }
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);

                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Element found at index %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("Element not found.\n");
                break;

            case 5:
                printf("Enter position to update (0 to %d): ", n - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    printf("Enter new value: ");
                    scanf("%d", &value);
                    arr[pos] = value;
                    printf("Element updated successfully.\n");
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}