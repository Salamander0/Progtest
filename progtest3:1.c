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

int main(int argc, char *argv[]) {
    
    int i = 0, j = 0;
    
    char *word = (char*) malloc(81);
    char *output = (char*) malloc(81);
    
    scanf("%s", word);
    
    while (word[i] != '\0')
    {
        //lower case letters
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            output[j] = word[i] - 32;
            j++;
        }
        
        //capital letters
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            output[j] = word[i] + 32;
            j++;
        }
        
        //numbers
        if (word[i] >= '0' && word[i] <= '9')
        {
            output[j] = word[i] + 49;
            j++;
        }
        
        //
        i++;
    }
    
    output[j] = '\0';
    
    printf("%s\n", output);
    
    free (word);
    free(output);
    
    return 0;
}
