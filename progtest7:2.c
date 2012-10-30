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
#include <float.h>
#include <stdlib.h>

long double factorial(long double a)
{
    if (a == 1)
        return 1;
    else
    {
        a *= factorial(a-1);
        return a;
    }
}

long double combination(long double a, long double b)
{
    return factorial(a) / (factorial(b) * factorial(a-b));
}


int main()
{
    long double a, b;
    printf("Enter combination number\n");
    if (scanf("%Lf %Lf", &a, &b) != 2){
        printf("Error");
        return EXIT_FAILURE;
    }

    a=combination(a,b);
	printf("%.Lf\n", a);
	return 0;
}