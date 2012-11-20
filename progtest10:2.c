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

int intersection(double * mA, double * mB, int sizea, int sizeb){
    double * mV;
    mV = (double *)malloc((sizea+1)*sizeof(double));
    size_t index=0;
    
    for(int i=0; i<sizea; i++)
        for(int j=0; j<sizeb; j++){
            if(mA[i] == mB[j]){
                mV[index] = mA[i];
                index++;
            }
        }
    
    printf("Set intersection:\n{");
    
    if(index == 0)printf("}\n");
    else{
    for(unsigned int k=0; k<index; k++){
        printf("%.0f", mV[k]);
        if(k != (index-1))
            printf(", ");
        else printf("}\n");
    }
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    double * mA, * mB;
    int sizea=0, sizeb=0;
    
    printf("Enter size of set A:\n");
    if(scanf("%d", &sizea) !=1){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    if(sizea <= 0){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    mA = (double *)malloc((sizea+1) * sizeof(double));
    if(mA == NULL)
        return EXIT_FAILURE;
    
    printf("Enter members of set A:\n");
    for(int i=0; i<sizea; i++){
        if(scanf("%lf", &mA[i]) !=1){
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }
        for(int j=0; j<(i-1); j++)
            if(mA[j] == mA[i]){
                printf("Invalid input.\n");
                return EXIT_FAILURE;
            }
    }

printf("Enter size of set B:\n");
if(scanf("%d", &sizeb) !=1){
    printf("Invalid input.\n");
    return EXIT_FAILURE;
}
if(sizeb <= 0){
    printf("Invalid input.\n");
    return EXIT_FAILURE;
}

mB = (double *)malloc((sizeb+1) * sizeof(double));
if(mB == NULL)
return EXIT_FAILURE;

    printf("Enter members of set B:\n");
    for(int i=0; i<sizeb; i++){
        if(scanf("%lf", &mB[i]) !=1){
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }
        for(int j=0; j<(i-1); j++)
            if(mB[j] == mB[i]){
                printf("Invalid input.\n");
                return EXIT_FAILURE;
            }
    }
        
intersection(mA, mB, sizea, sizeb);

free(mA);
free(mB);

return EXIT_SUCCESS;
}