#include <stdio.h>

int main() {
    int arr[100], n, i, largest;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Read array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume the first element is the largest
    largest = arr[0];

    // Find the largest element
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Display the largest element
    printf("Largest element = %d\n", largest);

    return 0;
}