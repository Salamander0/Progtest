/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PNUM 5

//struktura pro pacienta
typedef struct pacient{
    char prijmeni[50];
    char jmeno[50];
    int rodnec;
    char nemoc[50];
    char zp[50];
    struct pacient *next; //ukazatel na nasledujici polozku
    struct pacient *prev; //ukazatel na predchozi polozku
}TPacient;

//struktura pro list
typedef struct nemocnice{
    struct pacient *first; //ukazatel na prvni polozku v seznamu
    struct pacient *last;  //ukazatel na posledni polozku v seznamu
}TNemocnice;

int get_pacient(TNemocnice *nemocnice){
    TPacient * pacient = (TPacient *)malloc(sizeof(TPacient)); //vytvoreni nove polozky
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
    
    pacient->next = NULL;  //nasledujici polozka je NULL protoze pridavame na konec listu
    
    //zarazeni polozky do listu
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

//ulovneni dynamicky alokovane pameti
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
    TNemocnice nemocnice = {nemocnice.first = NULL, nemocnice.last = NULL}; //vytvoreni listu
    
    //nacteni polozek
    for(int i=0; i<PNUM; i++)
        get_pacient(&nemocnice);
    
    //vlastni podminky a reseni
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
    
    //uvolneni pameti
    free_nem(&nemocnice);
    return EXIT_SUCCESS;
}