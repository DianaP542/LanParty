#include "lib.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
    FILE *cerinte = fopen(argv[1], "r");
    FILE *date = fopen(argv[2], "r");

    //de uitat cum functioneaza checker-ul
    FILE *printare = fopen(argv[3], "w");
    /*if (cerinte == NULL)
    {
        puts("cerinte file error");
        exit(1);
    }

    if (date == NULL)
    {
        puts("date file error");
        exit(1);
    }

    if (printare == NULL)
    {
        puts("print file error");
        exit(1);
    }
    */
    Node *head = NULL;
    int cNr =5, cerinta[5],teamNr;
    for(int i = 0; i < cNr; i++)
    {
        fscanf(cerinte, "%d", &cerinta[i]);
    }
    if(cerinta[0] == 1) //task 1
    {
        fscanf(date, "%d", &teamNr);            
        for(int t = 0; t < teamNr; t++)
            head = addAtBegining(date);
        if(cerinta[1] == 0)
            print(head, printare);
    }
    if(cerinta[1] == 1) //task 2
    {
        int np;
        Node *newNode=head;
        while (newNode !=NULL)
        {
            newNode->info.teamPoints=teamPointCount(newNode->info);
            newNode=newNode->next;
        }
        nTeams(&head, &np, &teamNr);
        print(head, printare);
    }
    fclose(cerinte);
    fclose(printare);
    fclose(date);
    
    while(head!=NULL)
    {
        Node *aux = head;
        head=head->next;
        erase(&aux->info);
        free(aux);
    }
    free(head);  
    return 0;
}