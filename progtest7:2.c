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
#include <stdio.h>
#include <float.h>
#include <stdlib.h>

long int factorial(long int a)
{
    if ((a == 1) || (a == 0))
        return 1;
    else
    {
        a *= factorial(a-1);
        return a;
    }
}

long int combination(long int a, long int b)
{
    return factorial(a) / (factorial(b) * factorial(a-b));
}


int main()
{
    long int a, b;
    printf("Enter n and k:\n");
    if ((scanf("%ld %ld", &a, &b) != 2) || (a<0) || (b<0) || (a<b)){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
        a=combination(a,b);
	printf("C = %.ld\n", a);
	return 0;
}