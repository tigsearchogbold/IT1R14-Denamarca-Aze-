#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    int num_students;
    char name[100];
    char course[100];
    int age;

    // --- PHASE 1: WRITING TO THE DATABASE ---
    printf("Writing Student Database:\n");
    printf("How many students do you want to record? ");
    if (scanf("%d", &num_students) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    
    // Consume the trailing newline character left in the buffer by scanf
    getchar(); 

    // Open the file in write mode "w"
    file = fopen("student_records.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create student_records.txt\n");
        return 1;
    }

    // Loop to collect information based on user entry
    for (int i = 1; i <= num_students; i++) {
        printf("\nStudent %d\n", i);
        
        printf("Enter Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Strip the trailing newline

        printf("Enter Age: ");
        scanf("%d", &age);
        getchar(); // Consume the trailing newline

        printf("Enter Course: ");
        fgets(course, sizeof(course), stdin);
        course[strcspn(course, "\n")] = '\0'; // Strip the trailing newline

        // Write the formatted record to the text file
        fprintf(file, "Student %d\n", i);
        fprintf(file, "Name: %s\n", name);
        fprintf(file, "Age: %d\n", age);
        fprintf(file, "Course: %s\n", course);
        fprintf(file, "-----------------------\n\n");
    }

    // Properly close the file after writing
    fclose(file);
    printf("\nStudent database successfully saved to file.\n\n");


    // --- PHASE 2: READING FROM THE DATABASE ---
    printf("Reading Student Database:\n\n");

    // Open the file in read mode "r"
    file = fopen("student_records.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open student_records.txt for reading\n");
        return 1;
    }

    char line[256];
    // Read the file line-by-line using fgets() and print to terminal until EOF
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    // Properly close the file after reading
    fclose(file);

    return 0;
}
