#include "lib.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
    FILE *cerinte = fopen(argv[1], "r");
    FILE *date = fopen(argv[2], "r");
    FILE *printare = fopen(argv[3], "w");
    Node *head = NULL;
    int cNr =5, cerinta[5],teamNr;
    for(int i = 1; i <= cNr; i++)
    {
        fscanf(cerinte, "%d", &cerinta[i]);
    }
    if(cerinta[1] == 1)
    {
        int c;
        fscanf(date, "%d", &teamNr);            
        for(int t = 0; t < teamNr; t++)
            head = addAtBegining(date);
        for(c = 2; c <= cNr; c++)
            if(cerinta[c] == 1)
                break;
        if(c <= cNr)
            print(head, printare);
    }
    return 0;
}