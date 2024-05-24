#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student
{
    char *perName;
    char *famName;
    int perPoints;
};
typedef struct student Student;

struct team
{
    int studentNr, teamPoints;
    char *name;
    Student *student;
};
typedef struct team Team;

struct Elem
{
    Team info;
    struct Elem *next;
};

typedef struct Elem Node;

Node *addAtBegining(FILE *fisier);
Team teamInfo(FILE *fisier);
Student studentInfo(FILE *fisier);
void print(Node *head, FILE *fisier);
void erase(Node **head);
//task 2
int teamPointCount();
void delete(Node **head, int i);
void worstTeam(Node **head);
void nTeams(Node **head);
