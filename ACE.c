#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    int num_students;
    char name[100];
    char course[100];
    int age;
    printf("Writing Student Database:\n");
    printf("How many students do you want to record? ");
    if (scanf("%d", &num_students) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
        getchar(); 


    file = fopen("student_records.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create student_records.txt\n");
        return 1;
    }
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

//ambot onsa ni basta ga gana

        fprintf(file, "Student %d\n", i);
        fprintf(file, "Name: %s\n", name);
        fprintf(file, "Age: %d\n", age);
        fprintf(file, "Course: %s\n", course);
        fprintf(file, "-----------------------\n\n");
    }


    fclose(file);
    printf("\nStudent database successfully saved to file.\n\n");



    printf("Reading Student Database:\n\n");
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

    fclose(file);

    return 0;
}


    // Properly close the file after reading
    fclose(file);

    return 0;
}
