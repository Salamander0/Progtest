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

static inline int bitshift(char *sum, int index){
    for(int i=index; i>0; i--){
        sum[i] = sum[i-1];
    }
    return EXIT_SUCCESS;
}

//exterminate leading zeros
int exterminate(char * bin, int length){
    while(bin[0] == '0'){
        if(length <= 2)
            return EXIT_SUCCESS;
        for(int k =0; k<length; k++){
            bin[k]=bin[k+1];
        }
        length--;
        bin[length] = '\0';
    }
    return EXIT_SUCCESS;
}

int binaryAdd(char *first, char *second){
    size_t a,b;
    int index=0, size=1;
    int num, carry=0;
    char * tmp;
    char * sum = (char *)malloc(1*sizeof(char));
    
    a = strlen(first);
    b = strlen(second);
    
    while((a>0) || (b>0) || (carry ==1)){
        if((a<1) &&(b<1)){
            num = 0;
        }
        else if(a<1){
            num = 0 + (second[b-1]-'0');
        }
        else if(b<1){
            num = (first[a-1]-'0') + 0;
        }
        else num = (first[a-1]-'0') + (second[b-1]-'0');
        
        if(a !=0)a--;
        if(b !=0)b--;
        num = num + carry;
        
        if (size-1 <=index){
            size += 5;
            tmp = (char *)realloc(sum, size*sizeof(char));
            if(tmp == NULL){
                free(sum);
                return EXIT_FAILURE;
            }
            sum = tmp;
        }
        bitshift(sum, index);
        sum[0] = num%2+'0';
        carry = num/2;
        index++;
    }
    sum[index] = '\0';
    
    exterminate(sum, index);
    
    printf("Sum: %s\n", sum);
    free(sum);
    return EXIT_SUCCESS;
}

int get_number(char **bin_addr){
    char * tmp, * bin;
    char ch=1;
    int size = 1, index = 0;
    bin = *bin_addr;
    
    while(ch){
        ch = getc(stdin);
        
        if((ch == '\n') || (ch == ' ')){
            ch = '\0';
        }
        
        if((ch-'0' != 0) && (ch-'0' != 1) && (ch != '\0')){
            return EXIT_FAILURE;
        }
        
        if (size-1 <=index){
            size += 5;
            tmp = (char *)realloc(bin, size*sizeof(char));
            if(tmp == NULL){
                return EXIT_FAILURE;
            }
            bin = tmp;
            *bin_addr = bin;
        }
        bin[index++] = ch;
    }
    
    exterminate(bin, index);
    
    return EXIT_SUCCESS;
}

int main (void)
{
    char * bin1 = (char *)malloc(sizeof(char));
    if(bin1 == NULL)
        return EXIT_FAILURE;
    char * bin2 = (char *)malloc(sizeof(char));
    if(bin2 == NULL){
        free(bin1);
        return EXIT_FAILURE;
    }
    
    printf("Enter two binary numbers:\n");
    
    //number1 load
    if(get_number(&bin1) != EXIT_SUCCESS){
        free(bin1);free(bin2);
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    //number2 load
    if(get_number(&bin2) != EXIT_SUCCESS){
        free(bin1);free(bin2);
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    if(binaryAdd(bin1, bin2) != EXIT_SUCCESS){
        free(bin1);free(bin2);
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    free(bin1); free(bin2);
    return EXIT_SUCCESS;
}
