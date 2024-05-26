#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//code debugging log- all mallocs in function, still get segmentation fault
Node *addAtBegining(FILE *fisier) //edited code from class course
{
    Node *head;
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
    student.perName = (char*)malloc(strlen(aux) * sizeof(char));//uses an aux in order to have the exact number of characters needed to be allocated
    strcpy(student.perName, aux);
    fscanf(fisier, "%s", aux);
    student.famName = (char*)malloc(strlen(aux) * sizeof(char));
    strcpy(student.famName, aux);
    fscanf(fisier, "%d", &student.perPoints);
    return student;
}

void print(Node *head, FILE *fisier) //simple printing function
{
    while (head != NULL)
	{
		fprintf(fisier, "%s", head->info.name);
		head = head->next;
	}
}

void erase(Team *team) //deallocates memory for head list
{
    Team temp;
    temp= *team;
    free(temp.name);
    for (int i = 0; i < team->studentNr ; i++)
    {
        free(temp.student[i].perName);
        free(temp.student[i].famName);
    }
    free(temp.student);
}

//task 2
int teamPointCount()
{
    Team team;
    int ma=0;
    for(int i=0;i<team.studentNr;i++)
    {
        ma=ma+team.student->perPoints;
    }
    ma=ma/team.studentNr;
    return ma;
}

void delete(Node **head, int i) //deletes node
{
    Node *prev=*head;
    for(int j=0;j<i;j++)
    {
            prev=prev->next;
    }
    Node *newNode=prev->next;
    prev->next=newNode->next;
    free(newNode);
}

void worstTeam(Node **head) //finds the team with the least amount of points
{
    int min;
    Node *newNode = (Node*)malloc(sizeof(*newNode));
    newNode=*head;
    min=newNode->info.teamPoints;
    while(newNode != NULL)
    {
        newNode=newNode->next;
        if(newNode->info.teamPoints < min)
            min=newNode->info.teamPoints;
    }
    newNode=*head;
    int i=0;
    while(newNode != NULL)
    {
        if(newNode->info.teamPoints == min)
        {
            delete(head, i);
            break;
        }
        newNode=newNode->next;
        i++;
    }
}

void nTeams(Node **head, int *i, int *teamNr) //finds the number of temas needed to be deleted 
{
    int n = 2;
    *i=1;
    while(n <= *teamNr)
    {
        n = n*2;
        *i++;
    }
    n = n/2;
    *i--;
    while(*teamNr < n)
    {
        worstTeam(head);
        *teamNr--;
    }
}