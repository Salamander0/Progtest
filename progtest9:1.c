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

#define MINLENGTH 5

int main (void)
{
    char passwd[80];
    int alpha = 0, num = 0, nonal = 0;
    size_t len;
    if(scanf("%s", passwd) !=1){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    len = strlen(passwd);
    if(len<MINLENGTH){
        printf("The password does not meet the requirements.\n");
        return EXIT_FAILURE;
    }
    for(unsigned int i=0;i<len;i++){
        if(isalpha(passwd[i]))
            alpha++;
        else if(isdigit(passwd[i]))
            num++;
        else nonal++;
    }
    
    if((alpha == 0)||(num == 0)||(nonal==0)){
        printf("The password does not meet the requirements.\n");
        return EXIT_FAILURE;
    }
    else printf("The password meets the requirements.\n");
    return EXIT_SUCCESS;
}
