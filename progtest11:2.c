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

typedef struct pacient{
    char prijmeni[50];
    char jmeno[50];
    int rodnec;
    char nemoc[50];
    char zp[50];
}TPacient;

int main(void)
{
    TPacient pacient[PNUM];
    char c;
    
    for(int i=0; i<PNUM; i++){
        printf("Zadejte prijmeni, jmeno, rodne cislo, nemoc a zdravotni pojistovnu pacienta:\n");
        if(scanf("%s", pacient[i].prijmeni) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%s", pacient[i].jmeno) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%d", &pacient[i].rodnec) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%s", pacient[i].nemoc) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%s", pacient[i].zp) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
    }
    
    for(int i=0; i<PNUM; i++){
        if(strcmp(pacient[i].nemoc, "tbc") == 0)
            printf("Jmeno a prijmeni pacienta s tbc:\n %s %s\n", pacient[i].jmeno, pacient[i].prijmeni);
        if(strcmp(pacient[i].zp, "211") == 0)
             printf("Jmeno a prijmeni pacientu s pojistovnou 211 je:\n %s %s\n", pacient[i].jmeno, pacient[i].prijmeni);
    }
    printf("Prijmeni vsech pacientu jsou:\n");
    for(int i=0; i<PNUM; i++){
        printf("%s\n", pacient[i].prijmeni);
    }
    return EXIT_SUCCESS;
}