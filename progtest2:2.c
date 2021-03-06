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
    double a, b, c, disc, r1, r2;
    
    // Ask the user to input two values.
    printf("Enter parameters a, b, and c of the quadratic equation:\n");
    
    //Check if both entered values are decimal. If not, then exit the program.
    if ((scanf("%lf %lf %lf", &a, &b, &c) != 3) || (a == 0)) {
        printf("Invalid input.\n");
        return 1;
    }
    
	disc = pow(b,2) - (4*a*c);

	if (disc < 0){
		printf("No solutions exist in real numbers.\n");
	}
    
	else{
		r1 = ((-b -sqrt(disc))/(2*a));
		r2 = ((-b +sqrt(disc))/(2*a));
		printf("Root #1, x1: %5f\n", r1);
		printf("Root #2, x2: %5f\n", r2);
	}

    return 0;
}