#include <stdio.h>

// Define a structure
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    // Declare a structure variable
    struct Student s1;

    // Assign values
    s1.rollNo = 101;
    sprintf(s1.name, "Alice");
    s1.marks = 89.5;

    // Display values
    printf("Student Details:\n");
    printf("Roll No: %d\n", s1.rollNo);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}