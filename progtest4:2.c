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


//counts the fibonacci sequence and returns the n'th number
int fibs(int n) {
    int m = 1;
    int k = 0;
    int i;
    
    for (i = 1; i <= n; i++) {
        int tmp = m + k;
        m = k;
        k = tmp;
    }
    return m;
}

int main(void){
    int i = 2; //start with number 2, because of Progtest ...
    char c = 0;
    printf("The Fibonacci sequence starts with 1,1,2\n");
    while(c != 'n') {
        i++;
        if(i > 4){
            printf("Display next? [any key/n]\n");
            c = getchar(); //user input
            if(c != '\n'){ //newline character?
                getchar(); //newline character!
            }
            if(c == 'n'){return 0;} // n - exit
            printf("Next number in Fibonacci sequence is: %d\n",fibs(i));
        }
    }
    return 0;
}

