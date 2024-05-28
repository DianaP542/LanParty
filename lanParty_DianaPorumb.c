#include "lib.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
    FILE *cerinte = fopen(argv[1], "r");
    FILE *date = fopen(argv[2], "r");
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
    int nrCerinte =5, cerinta[5],teamNr;
    for(int i = 0; i < nrCerinte; i++)
    {
        fscanf(cerinte, "%d", &cerinta[i]);
    }
    if(cerinta[0] == 1) //task 1
    {   
        int np;
        fscanf(date, "%d", &teamNr);
        for(int t = 0; t < teamNr; t++)
            head = addAtBegining(date);
        if(cerinta[1] == 0)
            print(head, printare);
        else
        if(cerinta[1] == 1) //task 2
        {
            Node *newNode=head;
            while (newNode !=NULL)
            {
                newNode->info.teamPoints=teamPointCount(newNode->info);
                newNode=newNode->next;
            }
            nTeams(&head, &np, &teamNr);
            print(head, printare);
            fprintf(printare, "\n");
            if(cerinta[2]==1) //task 3
            {
                Node *top= (Node*)malloc(sizeof(Node));
                Matches(np, &teamNr, &head, &top, printare);
                fprintf(printare, "\n");
                if(cerinta[3]==1) //task 4
                {
                    newNode = top;
                    Arb *root=NULL;
                    while(newNode !=NULL)
                    {
                        root=insert(root, newNode->info);
                        newNode=newNode->next;
                        printArb(root, printare);
                    }
                    free(newNode);
                    fprintf(printare, "\n");
                }
            }
        }
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