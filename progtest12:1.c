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
#include <math.h>

int main(void)
{
    double *vectors1, *vectors2, csm =0;
    int nvectors;
    
    //nacteni poctu vektoru
    if((scanf("%d", &nvectors) !=1) || (nvectors <= 0)){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    //alokace poli pro ulozeni vektoru
    vectors1 = (double *)malloc(sizeof(double)*nvectors);
    vectors2 = (double *)malloc(sizeof(double)*nvectors);
    //nacteni samotnych hodnot vektoru
    for(int i=0; i<nvectors; i++){
        if(scanf("%lf", &vectors1[i]) !=1){
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }
    }
    for(int i=0; i<nvectors; i++){
        if(scanf("%lf", &vectors2[i]) !=1){
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }
    }
    //vypocet vektorove podobnosti
    for(int i=0; i<nvectors; i++) {
        csm += (vectors1[i]*vectors2[i]);
    }
    csm = csm/pow(nvectors, 2);
    
    printf("CSM: %lf\n", csm);
    free(vectors1); free(vectors2);
    return EXIT_SUCCESS;
}