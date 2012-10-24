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

int main(void)
{
    double s, n;
    s = 0;
    printf("Enter the numbers:\n");
    
    while(scanf("%lf", &n) == 1){
        if(n == 1000){
            s = s + n;
            printf("The sum is: %.6f\n", s);
            return 0;
        }
        else s = s + n;
    }
    printf("Invalid input.\n");
    return 0;
}
