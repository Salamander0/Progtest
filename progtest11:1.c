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

#define BOOKNUM 5

typedef struct book{
    char nazev[30];
    char prijmeni[30];
    char jmeno[30];
    char zanr[30];
    int rok;
    int cena;
    int id;
}TBook;

int main(void)
{
    TBook book[BOOKNUM];
    char c;
    
    //nacteni knizek
    for(int i=0; i<BOOKNUM; i++){
        printf("Zadej nazev knihy, prijmeni autora, jmeno autora, zanr knihy, rok vydani, cenu a id:\n");
        if(scanf("%s", book[i].nazev) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%s", book[i].prijmeni) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%s", book[i].jmeno) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%s", book[i].zanr) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%d", &book[i].rok) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%d", &book[i].cena) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if((c =getc(stdin)) != ' '){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
        if(scanf("%d", &book[i].id) != 1){
            printf("Invaid input.\n");
            return EXIT_FAILURE;
        }
    }
    
    printf("Romany jsou:\n");
    for(int i=0; i<BOOKNUM; i++){
        if(strcmp(book[i].zanr, "roman") == 0)
            printf("%s\n", book[i].nazev);
    }
    printf("\n");
    printf("Knihy s cenou mensi nez 300,- Kc jsou:\n");
    for(int i=0; i<BOOKNUM; i++){
        if(book[i].cena < 300)
            printf("%s\n", book[i].nazev);
    }
    printf("\n");
    printf("Prijmeni vsech autoru jsou:\n");
    for(int i=0; i<BOOKNUM; i++){
            printf("%s\n", book[i].prijmeni);
    }
    printf("\n");
    return EXIT_SUCCESS;
}