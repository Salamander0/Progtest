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
#include <ctype.h>


int getintfromstring(char * str, int poradi){
    int i;
    char pom[3];
    
    pom[0] = str[poradi];
    pom[1] = str[poradi +1];
    pom[2] = '\0';

    i = strtol(pom, NULL, 10);
    
    return i;
}

int checkdate(int year, int month, int day){
    int year2;
    if(year <54)
        year2 = year + 1900;
    else
        year2 = year + 2000;
  
    if (month > 50) month -= 50;
    
    if ((month >12) || (month <1) || (day <1))
        return EXIT_FAILURE;
    
    if(day >28){
        if(month==2){
            if((year%4 != 0) || (day >29))
                return EXIT_FAILURE;
        }
    }
    else if(day >31){
        switch(month){
            case 2:
            case 4:
            case 6:
            case 9:
            case 11:
                return EXIT_FAILURE;
            default:
                break;
            }
    }
    
    return EXIT_SUCCESS;
}



int main()
{
    char read;
    char cislo[80], mod[10];
    char * pom1,* pom2;
    long rodc, c;
    int i=0, modulo, year, month, day;
    
    printf("Enter an identification number:\n");
    while((read=getchar()) != '\n'){
        strcpy(&cislo[i], &read);
        i++;
    }
    cislo[i] = '\0';
    
    
    if(strlen(cislo) != 11){
        printf("The string is not an identification number.\n");
        return EXIT_FAILURE;
    }
    
    
    for(int j=0; j<10; j++){
        if(j ==6){
            if(cislo[j] != '/'){
                printf("The string is not an identification number.\n");
                return EXIT_FAILURE;
            }
        j++;
        }
        if(isdigit(cislo[j]) !=1){
            printf("The string is not an identification number.\n");
            return EXIT_FAILURE;
        }
    }
    
    pom1 = strtok(cislo, "/");
    pom2 = pom1;
    pom1 = strtok (NULL, "/");
    
    strcat(pom2, pom1);
    pom2[10] = '\0';
    strncpy(mod, pom2, 9);
    mod[9] = '\0';
    
    rodc = strtol(mod, NULL, 10);
    c = strtol(&pom2[9], NULL, 10);
    
    modulo = rodc % 11;
    
    if (modulo == 10) modulo = 0;
    
    if (modulo != c){
        printf("The string is not an identification number.\n");
        return EXIT_FAILURE;
    }

    year = getintfromstring(pom2, 0);
    month = getintfromstring(pom2, 2);
    day = getintfromstring(pom2, 4);
    
    if(checkdate(year,month,day) != EXIT_SUCCESS){
        printf("The string is not an identification number.\n");
        return EXIT_FAILURE;
    }
    else printf("The string could be an identification number.\n");

	return 0;
}