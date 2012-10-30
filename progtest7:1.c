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


int main()
{
    char str[256];
    char loc[512];
    static char lookup[] = { '0', '1', '2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
    int j = 0;
    
    printf("Enter string\n");
    gets(str);
    printf("Entered string is: %s\n", str);
    
    
    for (int i=0; i<strlen(str); ++i)
    {
        loc[j++] = lookup[(str[i] & 0xf0) >> 4];
        loc[j++] = lookup[str[i] & 0xf];
    }
    loc[j] = 0;
    
    printf("Hex value is: %s", loc);
   
	return 0;
}