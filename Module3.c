#include "project.h"

// Sort by highest merit
void generateMeritList(Applicant *apps, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (apps[j].meritScore < apps[j+1].meritScore) {
                Applicant temp = apps[j];
                apps[j] = apps[j+1];
                apps[j+1] = temp;
            }
        }
    }
}

// Display merit list
void displayApplicants(Applicant *apps, int n) {

    printf("\n--- MERIT LIST ---\n");

    for (int i = 0; i < n; i++) {
        printf("%d. %s | Marks: %d | Category: %s | Merit: %.2f | Course: %s\n",
               i + 1,
               apps[i].name,
               apps[i].marks,
               apps[i].category,
               apps[i].meritScore,
               apps[i].course
        );
    }
}

// Allocate seats based on course availability
void allocateSeats(Applicant *apps, int n, Course *courses) {

    printf("\n--- SEAT ALLOCATION ---\n");

    for (int i = 0; i < n; i++) {

        for (int c = 0; c < MAX_COURSES; c++) {

            if (strcmp(apps[i].course, courses[c].courseName) == 0) {

                if (courses[c].filledSeats < courses[c].totalSeats) {

                    courses[c].filledSeats++;

                    printf("%s allocated seat in %s.\n",
                           apps[i].name,
                           courses[c].courseName);

                } else {
                    printf("%s could NOT get seat in %s (FULL).\n",
                           apps[i].name,
                           courses[c].courseName);
                }
            }
        }
    }
}s