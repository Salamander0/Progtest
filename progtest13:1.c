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

char * strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;
    
	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int print_unique(char *loaded){
    char * ptr, *unique, *addr;
    
    addr = unique = (char *)malloc(sizeof(loaded));
    if(unique == NULL)
        return EXIT_FAILURE;
    strcpy(unique, "");
    
    ptr = strtok(loaded, "\n");
    do{
        if(strnstr(unique, ptr, strlen(ptr)) == NULL){
            strcat(unique, ptr);
            strcat(unique, "\n");
        }
        ptr = strtok(NULL, "\n");
    }while(ptr != NULL);
    
    printf("Unique strings:\n%s", unique);
    free(addr);
    return EXIT_SUCCESS;
}


int main (void)
{
    char * loaded, slovo[128];
    size_t size = 0, allocated = 128;
    
    loaded = (char *)malloc(allocated*sizeof(char));
    if(loaded == NULL)
        return EXIT_FAILURE;
    strcpy(loaded, "");
    
    while(scanf("%s", slovo) != EOF){
        if(strcmp(slovo, "konec") ==0){
            print_unique(loaded);
            free(loaded);
            return EXIT_SUCCESS;
        }
        size = strlen(slovo);
        if(size >=allocated){
            allocated += 128;
            loaded = (char *)realloc(loaded, allocated*sizeof(char));
            if(loaded == NULL)
                return EXIT_FAILURE;
        }
        strcat(loaded, slovo);
        strcat(loaded, "\n");
    }
    
    free(loaded);
    return EXIT_SUCCESS;
}