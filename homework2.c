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

typedef struct binary{
    char * number;
    size_t length;
}Tbinary;

//exterminate leading zeros
size_t exterminate(char * bin, size_t length){
    char * pch = NULL;
    long position = 0;
    
    pch = strchr(bin, '1');
    if(pch==NULL){
        bin[1] = '\0';
        length = 2;
    }
    else{
        position = pch-bin;
        strcpy(bin, pch);
    }
    
    return (length-position);
}

int binaryAdd(Tbinary first, Tbinary second){
    int a=0, b=0, sum=0, carry=0;
    size_t index = first.length;
    first.number[first.length] = '\0';
    
    while((first.length != 0) || (carry != 0)){
        if(first.length>1) a= first.number[first.length-2]-'0';
        else a = 0;
        if(second.length>1) b= second.number[second.length-2]-'0';
        else b = 0;
        sum = (a+b+carry)%2;
        first.number[first.length-1] = (sum)+'0';
        carry = (a+b+carry)/2;
        if(first.length >0)first.length--;
        if(second.length >0)second.length--;
    }
    
    exterminate(first.number,index);
    
    printf("Sum: %s\n", first.number);
    return EXIT_SUCCESS;
}

int get_number(Tbinary *bin_addr){
    char * tmp, * bin;
    char ch=1;
    int size = 1, index = 0;
    bin = bin_addr->number;
    
    while(ch){
        ch = getc(stdin);
        
        if((ch == '\n') || (ch == ' ')) ch = '\0';
        
        if((ch-'0' != 0) && (ch-'0' != 1) && (ch != '\0')) return EXIT_FAILURE;
        
        if (size-1 <=index){
            size += 5;
            tmp = (char *)realloc(bin, size*sizeof(char));
            if(tmp == NULL){
                return EXIT_FAILURE;
            }
            bin = tmp;
            bin_addr->number = bin;
        }
        bin[index++] = ch;
    }
    
    bin_addr->length = index;
    bin_addr->length = exterminate(bin_addr->number, bin_addr->length);
    
    return EXIT_SUCCESS;
}

int main (void)
{
    Tbinary bin1 = {bin1.number = NULL, bin1.length = 0};
    Tbinary bin2 = {bin2.number = NULL, bin2.length = 0};
    
    //allocate space for first number
    bin1.number = (char *)malloc(sizeof(char));
    if(bin1.number == NULL)
        return EXIT_FAILURE;
    
    //allocate space for second number
    bin2.number = (char *)malloc(sizeof(char));
    if(bin2.number == NULL){
        free(bin1.number);
        return EXIT_FAILURE;
    }
    
    printf("Enter two binary numbers:\n");
    
    //number1 load
    if(get_number(&bin1) != EXIT_SUCCESS){
        free(bin1.number);
        free(bin2.number);
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    //number2 load
    if(get_number(&bin2) != EXIT_SUCCESS){
        free(bin1.number);
        free(bin2.number);
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    //add the two numbers
    if(bin1.length >= bin2.length){
        if(binaryAdd(bin1, bin2) != EXIT_SUCCESS){
            free(bin1.number);
            free(bin2.number);
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }
    }
    else{
        if(binaryAdd(bin2, bin1) != EXIT_SUCCESS){
            free(bin1.number);
            free(bin2.number);
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }
    }
    
    free(bin1.number);
    free(bin2.number);
    return EXIT_SUCCESS;
}
