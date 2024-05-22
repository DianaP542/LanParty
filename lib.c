#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Node *addAtBegining(FILE *fisier)
{
    Node *head = NULL;
    Node *newNode = (Node*)malloc(sizeof(*newNode));
    newNode->info = teamInfo(fisier);
    newNode->next = *head;
    *head = newNode;
    return head;
}

Team teamInfo(FILE *fisier)
{
    Team team;
    char *p = NULL;

    fscanf(fisier, "%d", &team.studentNr);
    team.name = (char*)malloc(50);
    team.student = (Student*)malloc(team.studentNr * sizeof(Student));
    fgets(aux, 50, f);
    p = strtok(aux, " ");
    if(p != NULL)
        strcpy(team.name, p);
    p = strtok(NULL, " ");
    while (p != NULL)
    {
        strcat(team.name, " ");
        strcpy(team.name, p);
        p = strtok(NULL, " ");
    }
    for(int i = 0; i < team.studentNr; i++)
        team.student[i] = studentInfo(fisier);
    return team;
}

Student studentInfo(FILE *fisier)
{
    Student student;
    char aux[30];

    fscanf(f, "%s", aux);
    student.perName = (Student*)malloc(strlen(aux) * sizeof(Student));
    strcpy(student.perName, aux);
    fscanf(f, "%s", aux);
    student.famName = (Student*)malloc(strlen(aux) * sizeof(Student));
    strcpy(student.famName, aux);
    fscanf(f, "%d", &student.perPoints);
    return student;
}

void print(Node *head, FILE *fisier)
{
    while (head != NULL)
	{
		fprintf(f, "%s\n", head->info.name);
		head = head->next;
	}
}
