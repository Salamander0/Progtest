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

typedef struct params{
    double x;
    double y;
    double fi;
    double v;
    double delta;
    double omega;
}Tparams;

int main(void)
{
    int iterations=0;
    Tparams *params = (Tparams *)malloc(sizeof(Tparams));
    
    if((scanf("%d", &iterations) !=1) || (iterations <= 0)){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    if(scanf("%lf %lf %lf %lf %lf %lf", &params->x, &params->y, &params->fi, &params->delta, &params->v, &params->omega) != 6){
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    for(int i=0; i<iterations; i++){
        params->x = params->x + params->v * params->delta * cos(params->fi);
        params->y = params->y + params->v * params->delta * sin(params->fi);
        
        params->fi = params->fi + (params->delta * params->omega);
        while(params->fi > 2*M_PI)params->fi -= 2*M_PI;
        
        printf("x: %.2f, y: %.2f, phi: %.2f\n", params->x, params->y, params->fi);
    }
    
    free(params);
    return EXIT_SUCCESS;
}