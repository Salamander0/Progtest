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
#define PRICE 50

int salary(int income)
{
    int salary;
    if (income <2000)
        salary = 70;
    else if (income < 2500)
        salary = 80;
    else if (income < 3000)
        salary = 90;
    else if (income < 3500)
        salary = 100;
    else salary = 110;
    
    salary = salary*8;
    
    return salary;
}

int main(void)
{
    float vis, income;
    printf("Enter number of visitors:\n");
    if (scanf("%f", &vis) != 1) {printf("Invalid input.\n"); return EXIT_FAILURE;}
    if (vis<0) {printf("Invalid input.\n"); return EXIT_FAILURE;}
    
    //pocet navstevniku atrakce (7%)
    vis = (vis*0.07);
    //vydelek atrakce
    income = vis * PRICE;
    
    printf("The salary is: %d CZK\n", salary(income));
    
    return EXIT_SUCCESS;
}