#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char subjectName[50];
    int score;
    int grade;
} Subject;

int calculateGrade(int score) {
    if (score >= 90) return 5;
    else if (score >= 80) return 4;
    else if (score >= 70) return 3;
    else if (score >= 60) return 2;
    else if (score >= 50) return 1;
    else return 0;
}

int main() {
    char studentName[50];
    int subjectCount, i;
    int totalGrades = 0;
    float averageGrade;

    printf("Welcome to the Student Grade Calculator!\n");

    printf("Please enter your name: ");
    fgets(studentName, 50, stdin);
    studentName[strcspn(studentName, "\n")] = 0;

    // Error handling
    while (1) {
        printf("How many subjects do you want to calculate grades for? ");
        if (scanf("%d", &subjectCount) == 1 && subjectCount > 0) break;
        printf("Invalid input! Number of subjects must be a positive integer.\n");
        while (getchar() != '\n');
    }

    Subject subjects[subjectCount];

    // Get score and subject names
    for (i = 0; i < subjectCount; i++) {
        printf("Enter subject %d name: ", i + 1);
        getchar();
        fgets(subjects[i].subjectName, 50, stdin);
        subjects[i].subjectName[strcspn(subjects[i].subjectName, "\n")] = 0; // Remove newline character

        // Error handling
        while (1) {
            printf("Enter your score for %s (0-100): ", subjects[i].subjectName);
            if (scanf("%d", &subjects[i].score) == 1 && subjects[i].score >= 0 && subjects[i].score <= 100) break;
            printf("Invalid score! Please enter a number between 0 and 100.\n");
            while (getchar() != '\n');
        }

        subjects[i].grade = calculateGrade(subjects[i].score);
        totalGrades += subjects[i].grade;  // Add grade to totalGrades
    }

    // Calculate average grade based from totalGrades
    averageGrade = (float)totalGrades / subjectCount;

    printf("------------------------------------------\n");
    printf("Student: %s\n", studentName);
    printf("------------------------------------------\n");
    printf("Subject                 Score       Grade\n");
    printf("------------------------------------------\n");

    FILE *file = fopen("Projekti_grade_calculator/student_grade_report.txt", "w");
    if (!file) {
        printf("Error: Could not create report file.\n");
        return 1;
    }

    fprintf(file, "------------------------------------------\n");
    fprintf(file, "Student: %s\n", studentName);
    fprintf(file, "------------------------------------------\n");
    fprintf(file, "Subject                 Score       Grade\n");
    fprintf(file, "------------------------------------------\n");


    // Print formatting
    for (i = 0; i < subjectCount; i++) {
        printf("%-25s %d%%          %-10d\n", subjects[i].subjectName, subjects[i].score, subjects[i].grade);
        fprintf(file, "%-25s %d%%          %-10d\n", subjects[i].subjectName, subjects[i].score, subjects[i].grade);
    }

    printf("------------------------------------------\n");
    printf("Average Grade: %.2f\n", averageGrade);
    printf("------------------------------------------\n");
    fprintf(file, "------------------------------------------\n");
    fprintf(file, "Average Grade: %.2f\n", averageGrade);
    fprintf(file, "------------------------------------------\n");

    fclose(file);
    printf("Report has been saved to student_grade_report.txt.\n");

    return 0;
}