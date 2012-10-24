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

int main(int argc, const char * argv[])
{

    double v, w, h, err;
    
    printf("Enter values v, w, and h:\n");
    
    //input
    if ((scanf("%lf %lf %lf", &v, &w, &h) != 3) || (v <= 0) || (w <= 0) || (h <= 0)){
        printf("Invalid input.\n");
        return -1;
    }
    
    //factorization
    h = h * ((w * v) / (w * w * h));
    
    w = w * ((v * h) / (w * h * h));
    
    //calculating error
    err = v - (h * w);
    
    //output
    printf("Number %.3f can be factorized to %.3f x %.3f. The error is %.3f.\n", v, w, h, err);
    
    return 0;
}

