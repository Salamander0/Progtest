#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PNUM 5

typedef struct pacient{
    char prijmeni[50];
    char jmeno[50];
    int rodnec;
    char nemoc[50];
    char zp[50];
    struct pacient *next;
    struct pacient *prev;
}TPacient;

typedef struct nemocnice{
    struct pacient *first;
    struct pacient *last;
}TNemocnice;

int get_pacient(TNemocnice *nemocnice){
    TPacient * pacient = (TPacient *)malloc(sizeof(TPacient));
    if(pacient == NULL)
        return EXIT_FAILURE;
    char c;
    
    printf("Enter the surname, name, birth number, disease, insurance company of the patient:\n");
    if(scanf("%s", pacient->prijmeni) != 1){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if((c =getc(stdin)) != ' '){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if(scanf("%s", pacient->jmeno) != 1){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if((c =getc(stdin)) != ' '){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if(scanf("%d", &pacient->rodnec) != 1){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if((c =getc(stdin)) != ' '){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if(scanf("%s", pacient->nemoc) != 1){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if((c =getc(stdin)) != ' '){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    if(scanf("%s", pacient->zp) != 1){
        printf("Invaid input.\n");
        return EXIT_FAILURE;
    }
    
    pacient->next = NULL;
    if(nemocnice->last == NULL){
        nemocnice->first = pacient;
        nemocnice->last = pacient;
        pacient->prev = NULL;
    }
    else{
        nemocnice->last->next = pacient;
        pacient->prev = nemocnice->last;
        nemocnice->last = pacient;
    }
    return EXIT_SUCCESS;
}

int free_nem(TNemocnice *nemocnice){
    for (TPacient *pacient = nemocnice->first; pacient != NULL; pacient = pacient->next)
    {
        nemocnice->first = pacient->next;
        free(pacient);
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    TNemocnice nemocnice = {nemocnice.first = NULL, nemocnice.last = NULL};
    
    for(int i=0; i<PNUM; i++)
        get_pacient(&nemocnice);
    
    for (TPacient *pacient = nemocnice.first; pacient != NULL; pacient = pacient->next)
    {
        if(strcmp(pacient->nemoc, "tbc") == 0)
            printf("The name and surname of patients with tbc:\n%s %s\n", pacient->jmeno, pacient->prijmeni);
        if(strcmp(pacient->zp, "211") == 0)
            printf("The name and surname of patients with the insurance company 211 is:\n%s %s\n", pacient->jmeno, pacient->prijmeni);
    }
    
    printf("The surnames of all patients are:\n");
    for (TPacient *pacient = nemocnice.first; pacient != NULL; pacient = pacient->next)
    {
        printf("%s\n", pacient->prijmeni);
    }
    
    free_nem(&nemocnice);
    return EXIT_SUCCESS;
}