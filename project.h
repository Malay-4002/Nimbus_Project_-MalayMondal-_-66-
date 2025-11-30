#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 3

// Applicant structure
typedef struct {
    char name[50];
    int marks;
    char category[10];
    char course[50];
    float meritScore;
} Applicant;

// Course structure
typedef struct {
    char courseName[50];
    int totalSeats;
    int filledSeats;
} Course;

// Function declarations
void inputApplicants(Applicant *apps, int n);
float calculateMerit(Applicant a);
void generateMeritList(Applicant *apps, int n);
void displayApplicants(Applicant *apps, int n);
void allocateSeats(Applicant *apps, int n, Course *courses);
void saveApplicantsToFile(Applicant *apps, int n);
void loadApplicantsFromFile();

#endif
