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


//prompts for side of square and calculates area and perimeter
int square(void){
    double a, area, perimeter;
    
    printf("Enter the side of the square:\n");

    if (scanf("%lf", &a) != 1) return EXIT_FAILURE;
    
    if(a <= 0) return EXIT_FAILURE;
    
    area = a*a;
    perimeter = 4*a;
    
    printf("Square area is: %f\n", area);
    printf("Square perimeter is %f\n", perimeter);
    return EXIT_SUCCESS;
}

//prompts for sides of rectangle and calculates area and perimeter
int rectangle(void){
    double a, b, area, perimeter;
    
    printf("Enter the sides of the rectangle:\n");
    
    if (scanf("%lf %lf", &a, &b) != 2) return EXIT_FAILURE;
    
    if((a <= 0) || (b <= 0)) return EXIT_FAILURE;
    
    area = a*b;
    perimeter = 2*a + 2*b;
    
    printf("Rectangle area is: %f\n", area);
    printf("Rectangle perimeter is: %f\n", perimeter);
    return EXIT_SUCCESS;
}

//prompts for radius and calculates circle area and circumreference
int circle(){
    double a, area, circumference;
    
    printf("Enter the radius of the circle:\n");
    
    if (scanf("%lf", &a) != 1) return EXIT_FAILURE;
    
    if(a <= 0) return EXIT_FAILURE;

    area = M_PI*(pow(a,2));
    circumference = 2*M_PI*a;
    
    printf("Circle area is: %f\n", area);
    printf("Circumference is: %f\n", circumference);
    return EXIT_SUCCESS;
}

//main function
int main(void){
    char sw = 0;
    
    printf("Enter a 2D shape to compute area and perimeter: a - square, b - rectangle, c -circle\n");
    scanf("%c", &sw);
    
    switch(sw){
        case 'a':
            if (square() != EXIT_SUCCESS){
                printf("Invalid input.\n");
                return EXIT_FAILURE;
            }
            break;
        case 'b':
            if (rectangle() != EXIT_SUCCESS){
                printf("Invalid input.\n");
                return EXIT_FAILURE;
            }
            break;
        case 'c':
            if (circle() != EXIT_SUCCESS){
                printf("Invalid input.\n");
                return EXIT_FAILURE;
            }
            break;
        default:
            printf("Invalid input.\n");
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}




