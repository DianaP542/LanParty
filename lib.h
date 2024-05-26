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

//task 3
struct Q
{
    Node *front, *rear;
};
typedef struct Q Queue;

Node *addAtBegining(FILE *fisier);
Team teamInfo(FILE *fisier);
Student studentInfo(FILE *fisier);
void print(Node *head, FILE *fisier);
void erase(Team *team);
//task 2
int teamPointCount(Team team);
void delete(Node **head, int i);
void worstTeam(Node **head);
void nTeams(Node **head, int *i, int *teamNr);
//task 3
Queue* createQueue();
void enQueue(Queue *q, Team team);
Team deQueue(Queue *q);
int isEmpty(Queue *q);
void deleteQueue(Queue*q);
Team pop(Node **top);
void push(Node **top, Team team);
void Matches(int np, int *teamNr, Node **head, Node **top, FILE *printare);
void Round(Queue *q, Node **winList, Node **loseList);
void addPoints(Team *team);