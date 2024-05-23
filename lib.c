#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//code debugging log- all mallocs in function, still get segmentation fault
Node *addAtBegining(FILE *fisier) //edited code from class course
{
    Node *head = NULL;
    Node *newNode = (Node*)malloc(sizeof(*newNode)); 
    newNode->info = teamInfo(fisier);
    newNode->next = head;
    head = newNode;
    return head;
}

Team teamInfo(FILE *fisier) //reads information about the team
{
    Team team;
    char *p = NULL;
    char aux[51];
    fscanf(fisier, "%d", &team.studentNr);
    team.name = (char*)malloc(50); 
    team.student = (Student*)malloc(team.studentNr * sizeof(Student)); 
    fgets(aux, 50, fisier); //takes 50 characters and reputs the team name back together word by word
    p = strtok(aux, " ");
    if(p != NULL)
        strcpy(team.name, p);
    p = strtok(NULL, " ");
    while (p != NULL)
    {
        strcat(team.name, " ");
        strcat(team.name, p);
        p = strtok(NULL, " ");
    }
    for(int i = 0; i < team.studentNr; i++)
        team.student[i] = studentInfo(fisier);
    return team;
}

Student studentInfo(FILE *fisier) //reads info about each student competing at LanParty
{
    Student student;
    char aux[30];

    fscanf(fisier, "%s", aux);
    student.perName = (Student*)malloc(strlen(aux) * sizeof(Student));//uses an aux in order to have the exact number of characters needed to be allocated
    strcpy(student.perName, aux);
    fscanf(fisier, "%s", aux);
    student.famName = (Student*)malloc(strlen(aux) * sizeof(Student));
    strcpy(student.famName, aux);
    fscanf(fisier, "%d", &student.perPoints);
    return student;
}

void print(Node *head, FILE *fisier) //simple printing function
{
    while (head != NULL)
	{
		fprintf(fisier, "%s\n", head->info.name);
		head = head->next;
	}
}

void erase(Node **head) //deallocates memory for head list
{
    Node *current = *head;
    while (current != NULL)
    {
        *head = current->next;
        free(current->info.name);
        
        for (int i = 0; i < current->info.studentNr; i++)
        {
            free(current->info.student[i].perName);
            free(current->info.student[i].famName);
        }
        free(current->info.student);
        free(current);
        current = *head;
    }
    *head = NULL;
}