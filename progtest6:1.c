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

long bin2dec(char binary)
{
    long decimal = 0;
    while(binary != '\n')
    {
        if((binary == '0') || (binary == '1'))
        {
        	//left bitshift + bin , 0x30 = 48 - ASCII
            decimal = (decimal << 1) + (binary - 0x30);
            scanf("%c", &binary);
        }
        else
        {
            printf("Invalid input.\n");
            return -1;
        }
    }
    return decimal;
}

int main(void)
{
    long dec;
    char input;
    
    printf("Input a binary number:\n");
    scanf("%c", &input);
    
    //checks for empty input
    if(input == '\n') {printf("Invalid input.\n"); return EXIT_FAILURE;}
    
    //calling function bin2dec (-1 = EXIT_FAILURE)
    if((dec = bin2dec(input)) != -1)
    {
        printf("Decimal number is: %ld\n", dec);
        return EXIT_SUCCESS;
    }
    else return EXIT_FAILURE;
}