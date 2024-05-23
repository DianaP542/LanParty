#include "lib.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
    FILE *cerinte = fopen(argv[1], "r");
    FILE *date = fopen(argv[2], "r");
    FILE *printare;
    printare= fopen("r.out","wt");
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
    After checking- arguments work as long as the c.in /d.in files are in the same folder as the code
    */
    Node *head = NULL;
    int cNr =5, cerinta[5],teamNr;
    for(int i = 0; i < cNr; i++)
    {
        fscanf(cerinte, "%d", &cerinta[i]);
    }
    if(cerinta[0] == 1)
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
    fclose(cerinte);
    fclose(printare);
    fclose(date);
    erase(head);
    return 0;
}