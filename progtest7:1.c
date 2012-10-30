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
#include <math.h>

int main(void)
{
    char input[256];
    int x=0, order=0, num=0;

    printf("Enter a hexadecimal number:\n");
    gets(input);
    
    while (input[x] != '\0'){
        if((input[x]>='0' && input[x]<='9') || (input[x]>='a' && input[x]<='f') || (input[x]>='A' && input[x]<='F')){
            order++;
        }
        else{ printf("Invalid input.\n"); return EXIT_FAILURE;}
   
    x++;
    }
    
    order--;
    for(int i=0; i<x; i++){
        if(input[i]>='0' && input[i]<='9'){
            num +=(input[i]-48)*pow(16.0f, order);
            order--;
            }
        else if (input[i]>='a' && input[i]<='f'){
            num +=(input[i]-87)*pow(16.0f, order);
            order--;
            }
        else if (input[i]>='A' && input[i]<='F'){
            num +=(input[i]-55)*pow(16.0f, order);
            order--;
        }
    }
    printf("Decimal: %d\n", num);
    return 0;
}