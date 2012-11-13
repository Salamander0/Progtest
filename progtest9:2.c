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

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Wrong parameters.\n");
        return EXIT_FAILURE;
    }
    FILE *file;
    char str1[STRINGSIZE], str2[STRINGSIZE], str3[STRINGSIZE];
    file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }
    if (fscanf(file,"%s %s %s", str1, str2, str3) !=3){
        printf("Error reading file.\n");
        return EXIT_FAILURE;
    }
    
    printf("Loaded OK.\n");
    if((strcmp(str1, str2) == 0) && (strcmp(str2, str3) == 0))
       printf("Strings are identical.\n");
    fclose(file);
    return EXIT_SUCCESS;
}