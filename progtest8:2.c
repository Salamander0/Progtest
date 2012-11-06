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

#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#endif /* __PROGTEST__ */

int evenOdd (const char * srcFileName, const char * dstFileName){
    FILE *file, *output;
    int evennum[80], oddnum[80], number = 0, ei=0, oi=0;
    
    file = fopen(srcFileName, "r");
    if (file == NULL) //soubor neotevren
    {
		return EXIT_FAILURE;
    }
    output = fopen(dstFileName, "w");
    if (output == NULL) //soubor neotevren
    {
		return EXIT_FAILURE;
    }
    
    while(!feof(file)){
        if(fscanf(file, "%d", &number) !=1)
            break;
        if((number%2) !=0){
            evennum[ei]=number;
            ei++;
        }
        else{
            oddnum[oi]=number;
            oi++;
        }
    }
    
    evennum[ei] = '\0';
    oddnum[oi] = '\0';
    
    for(int j=0; j<oi; j++)
        fprintf(output, "%d\n", oddnum[j]);

    for(int j=0; j<ei; j++)
        fprintf(output, "%d\n", evennum[j]);
    
    if (fclose(file) != 0) return EXIT_FAILURE;
    if (fclose(output) != 0) return EXIT_FAILURE;
	return EXIT_SUCCESS;
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
    evenOdd("/Users/daprok/Downloads/sample 2/0002_in.txt", "/Users/daprok/Downloads/sample 2/0002_outm.txt");
    return 0;
}
#endif /* __PROGTEST__ */