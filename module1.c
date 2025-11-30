#include "project.h"

// MAIN FUNCTION – controls full program
int main() {

    int n;

    Course courses[MAX_COURSES] = {
        {"Computer Science", 3, 0},
        {"Electronics", 2, 0},
        {"Mechanical", 2, 0}
    };

    printf("Enter number of applicants: ");
    scanf("%d", &n);

    Applicant *apps = (Applicant*) malloc(n * sizeof(Applicant));

    inputApplicants(apps, n);
    generateMeritList(apps, n);
    displayApplicants(apps, n);
    allocateSeats(apps, n, courses);

    saveApplicantsToFile(apps, n);
    loadApplicantsFromFile();

    free(apps);
    return 0;
}
