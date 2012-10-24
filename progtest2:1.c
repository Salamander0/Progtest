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


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, const char * argv[])
{
    double a, b, c, d, r, sa, sb; 
    
    // Ask the user to input two values.
    printf("Enter coordinates of points A and B:\n");
    
    //Check if both entered values are decimal. If not, then exit the program.
    if (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != 4) {
        printf("Invalid input.\n");
        return 1;
    }

	sa = ((a+c)/2);
	sb = ((b+d)/2);
	printf("Center point is: S[%5f,%5f]\n", sa, sb);

	r = sqrt(pow(c-a,2) + pow(d-b,2));

	printf("Circle radius r is: %5f\n", r/2);

	getchar();
	getchar();

    return 0;
}