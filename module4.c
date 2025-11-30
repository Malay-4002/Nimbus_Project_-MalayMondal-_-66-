#include "project.h"

// Save all applicants to a text file
void saveApplicantsToFile(Applicant *apps, int n) {

    FILE *fp = fopen("admissions.txt", "w");

    for (int i = 0; i < n; i++) {

        fprintf(fp, "%s %d %s %.2f %s\n",
                apps[i].name,
                apps[i].marks,
                apps[i].category,
                apps[i].meritScore,
                apps[i].course);
    }

    fclose(fp);
}

// Load and display file data
void loadApplicantsFromFile() {

    FILE *fp = fopen("admissions.txt", "r");

    if (!fp) {
        printf("File not found.\n");
        return;
    }

    char name[50], category[10], course[50];
    int marks;
    float merit;

    printf("\n--- DATA LOADED FROM FILE ---\n");

    while (fscanf(fp, "%s %d %s %f %[^\n]s",
                  name,
                  &marks,
                  category,
                  &merit,
                  course) != EOF) {

        printf("%s | Marks: %d | Category: %s | Merit: %.2f | Course: %s\n",
               name,
               marks,
               category,
               merit,
               course);
    }

    fclose(fp);
}