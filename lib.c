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
float teamPointCount(Team team)
{
    float ma=0;
    for(int i=0;i<team.studentNr;i++)
    {
        Student stud=team.student[i];
        ma=ma+stud.perPoints;
    }
    ma=ma/team.studentNr;
    return ma;
}

void delete(Node **head, int i) //deletes node
{
    Node *newNode=NULL;
    if(i!=0)
    {
        Node *prev=*head;
        for(int j=0;j<i;j++)
        {
            prev=prev->next;
        }
        newNode=prev->next;
        prev->next=newNode->next;
    }
    else
    {
        newNode=*head;
        *head=(*head)->next;
    }
    free(newNode);
}

void worstTeam(Node **head) //finds the team with the least amount of points
{
    float min;
    Node *newNode = (Node*)malloc(sizeof(*newNode));
    newNode=*head;
    min=newNode->info.teamPoints;
    while(newNode != NULL)
    {
        newNode=newNode->next;
        Team team;
        team= newNode->info;
        if(team.teamPoints < min)
            min=team.teamPoints;
    }
    newNode=*head;
    Node *aux= newNode;
    int i=0;
    while(newNode != NULL)
    {
        Team team;
        team=newNode->info;
        if(team.teamPoints == min)
        {
            delete(&newNode, i);
            break;
        }
        newNode=newNode->next;
        i++;
    }
    *head= aux;
}

void nTeams(Node **head, int *i, int *teamNr) //finds the number of teams needed to be deleted 
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
    printf("%d %d", *teamNr, n);
    while(*teamNr > n)
    {
        printf("intra");
        worstTeam(head);
        *teamNr--;
    }
    printf("%d", *teamNr);
}

//task 3
//coada

Queue* createQueue()
{
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q == NULL) 
        return NULL;	
	q->front = q->rear = NULL;
	return q;	
}

void enQueue(Queue *q, Team team)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->info = team;
	newNode->next = NULL;
	if (q->rear == NULL) 
        q->rear = newNode; 
	else
    {
		(q->rear)->next = newNode;
		(q->rear) = newNode;
	}
	if (q->front == NULL)    
        q->front = q->rear; 
    erase(&newNode->info);
    free(newNode);
}
 
Team deQueue(Queue *q) 
{  
	Node* aux; 
    Team d;
	if (isEmpty(q)) 
        exit (1);
	
	aux = q->front; 
	d = aux->info;
	q->front = (q->front)->next;
	free(aux);
	return d;  	
} 

int isEmpty(Queue *q)
{
	return (q->front == NULL);
}

void deleteQueue(Queue*q)
{
	Node* aux;
	while (!isEmpty(q))
    {
		aux = q->front;
		q->front = q->front->next;
		free(aux);
	}
	free(q);
}	

//stiva	

Team pop(Node **top) 
{
	Node *temp = (*top);  		
	Team aux = temp->info;			
	*top = (*top)->next;      		
	free(temp);
	return aux;
}

void push(Node **top, Team team) 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->info = team;
	newNode->next = *top;
	*top = newNode;
    while(newNode!=NULL)
    {
        Node *aux = newNode;
        newNode=newNode->next;
        erase(&aux->info);
        free(aux);
    }
    free(newNode);
}

void Matches(int np, int *teamNr, Node **head, Node **top, FILE *printare)
{
    Queue *q=createQueue();
    Node *aux=*head;
    while(aux != NULL)
    {
        enQueue(q, aux->info);
        aux = aux->next;
    }
    Node *winList = (Node*)malloc(sizeof(Node));
    Node *loseList = (Node*)malloc(sizeof(Node));
    for(int i = 0 ; i < np ; i++)
    {
        fprintf(printare,"\n--- ROUND NO:%d\n", i + 1);
        Round(q, &winList, &loseList, printare);
        fprintf(printare, "\nWINNERS OF ROUND NO:%d\n", i + 1);
        Node *newNode=winList;
        while (newNode != NULL)
        {
            fprintf(printare, "%-34s-  %.2f\n", newNode->info.name, newNode->info.teamPoints);
            newNode=newNode->next;
        }
        free(newNode);
        while(loseList != NULL)
        {
            Node *newNode=loseList;
            loseList=loseList->next;
            erase(&newNode->info);
            free(newNode);
            *teamNr--;
        }
        q->rear=NULL;

        while(winList != NULL)
        {
            Node *newNode = winList;
            winList=winList->next;
            enQueue(q , newNode->info);
            if(*teamNr == 8)
                push(top, newNode->info);
            erase(&newNode->info);
            free(newNode);
        }
    }
    free(loseList);
    free(winList);
}

void Round(Queue *q, Node **winList, Node **loseList, FILE *printare)
{
    Team t1, t2;
    while(q->front != NULL)
        {
            t1=deQueue(q);
            t2=deQueue(q);
            fprintf(printare,"%-33s-%33s\n", t1.name, t2.name);
            if(t1.teamPoints < t2.teamPoints)
            {
                push(winList, t2);
                push(loseList, t1);
                addPoints(&t2);
            }
            else
            {
                push(winList, t1);
                push(loseList, t2);
                addPoints(&t1);
            }
        }
}

void addPoints(Team *team)
{
    for(int i = 0 ; i < team->studentNr ; i++)
        (*team).student->perPoints++;
}

//task 4
Arb *new(Team team)
{
    Arb *newArb = (Arb*)malloc(sizeof(Arb));
    newArb->info = team;
    newArb->left=newArb->right=NULL;
    return newArb;
}

Arb *insert(Arb *newArb, Team team)
{
    if(newArb == NULL)
        return new(team);
    if(team.teamPoints < newArb->info.teamPoints)
        newArb->left = insert(newArb->left, team);
    else if(team.teamPoints > newArb->info.teamPoints)
        newArb->right=insert(newArb->right, team);
    else if(team.teamPoints == newArb->info.teamPoints)
        if(strcmp(team.teamPoints, newArb->info.teamPoints)<0)
            newArb->left=insert(newArb->left, team);
        else
            newArb->right=insert(newArb->right, team);
    return newArb;
}

void printArb(Arb *root, FILE *printare)
{
    if(root != NULL)
    {
        printArb(root->right, printare);
        fprintf(printare, "%s", root->info.name);
        printArb(root->left, printare);
    }
}

//task 5
