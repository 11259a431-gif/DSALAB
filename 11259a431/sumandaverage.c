#include <stdio.h>

int main() {
    int arr[100], n, i, sum = 0;
    float avg;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Read array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Calculate average
    avg = (float)sum / n;

    // Display results
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);

    return 0;
}