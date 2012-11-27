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