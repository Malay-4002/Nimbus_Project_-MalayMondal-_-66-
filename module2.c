#include "project.h"

// Calculate merit with category bonus
float calculateMerit(Applicant a) {
    float bonus = 0;

    if (strcmp(a.category, "OBC") == 0) bonus = 2;
    else if (strcmp(a.category, "SC") == 0) bonus = 4;
    else if (strcmp(a.category, "ST") == 0) bonus = 5;

    return a.marks + bonus;
}

// Collect applicant data
void inputApplicants(Applicant *apps, int n) {

    for (int i = 0; i < n; i++) {

        printf("\nEnter details for Applicant %d\n", i + 1);

        printf("Name: ");
        scanf("%s", apps[i].name);

        printf("Marks (0-100): ");
        scanf("%d", &apps[i].marks);

        printf("Category (GEN/OBC/SC/ST): ");
        scanf("%s", apps[i].category);

        printf("Preferred Course: ");
        scanf(" %[^\n]s", apps[i].course);

        // Calculate merit
        apps[i].meritScore = calculateMerit(apps[i]);
    }
}