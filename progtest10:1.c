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

#define CLIMIT 100

int find_string(char str[], char src[]){
    char *ptr;
    long pos;
    size_t size;
    size = strlen(str);
    ptr = strcasestr(str, src);
    if(ptr == NULL){
        printf("Substring '%s' not found.\n", src);
        return EXIT_SUCCESS;
    }
    else{
        pos = size - strlen(ptr);
        printf("String '%s' found, position(s): %ld", src, pos);
        ptr++;
        while((ptr = strcasestr(ptr, src)) != NULL){
            if(ptr != NULL){
                printf(",");
                pos = size - strlen(ptr);
                printf("% ld", pos);
                ptr++;
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

int find_char(char str[], char c){
    size_t size, cnt=0;
    
    size = strlen(str);
    while((str =strchr(str,c)) != NULL){
        str++;
        if(str != NULL){
            cnt++;
        }
    }
    
    printf("Character '%c' found %lu times.\n", c, cnt);
    return EXIT_SUCCESS;
}

int main(void)
{
    char str[CLIMIT], strc[CLIMIT], src[CLIMIT], c, pch;
    
    printf("Enter a string, a substring, and a character:\n");
    
    if(scanf("%s", str) !=1){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    pch = getc(stdin);
    if(pch != ' '){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    if(scanf("%s", src) !=1){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    pch = getc(stdin);
    if(pch != ' '){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    c = getc(stdin);
    if((c == '\n') ||(c == '\0')){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    pch = getc(stdin);
    if(pch != '\n'){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    strncpy(strc, str, CLIMIT);
    
    if(find_string(str, src) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if(find_char(strc, c) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    
	return EXIT_SUCCESS;
}