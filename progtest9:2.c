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

#define STRINGSIZE 80

int main(void)
{
    char str1[STRINGSIZE], str2[STRINGSIZE], str3[STRINGSIZE], ch;
    
    printf("Enter the 3 words:\n");
    
    if (scanf("%s", str1) !=1){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    ch = getc(stdin);
    if(ch != ' '){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    if (scanf("%s", str2) !=1){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    ch = getc(stdin);
    if(ch != ' '){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    if (scanf("%s", str3) !=1){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    ch = getc(stdin);
    if((ch != '\n') && (ch != '\0')){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }

    if(strcasecmp(str1, str2) == 0)
        printf("Word1 and word2 are the same.\n");
    else printf("Word1 and word2 are not the same.\n");
    if(strcasecmp(str1, str3) == 0)
        printf("Word1 and word3 are the same.\n");
    else printf("Word1 and word3 are not the same.\n");
    if(strcasecmp(str2, str3) == 0)
        printf("Word2 and word3 are the same.\n");
    else printf("Word2 and word3 are not the same.\n");
    
    printf("The number of characters in word1 is: %lu\n", strlen(str1));
    printf("The number of characters in word2 is: %lu\n", strlen(str2));
    printf("The number of characters in word3 is: %lu\n", strlen(str3));
    
    return EXIT_SUCCESS;
}