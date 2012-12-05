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

#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define EASTER_OK 0
#define EASTER_INVALID_FILENAME 1
#define EASTER_INVALID_YEARS 2
#define EASTER_IO_ERROR 3

#endif /* __PROGTEST__ */

const char *HEADER =
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\"> <html>\n"
"<head>\n"
"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"> <title>C++</title>\n"
"</head>\n"
"<body>\n"
"<table width=\"300\">\n"
"<tr><th width=\"99\">day</th><th width=\"99\">month</th><th width=\"99\">year</th></tr>\n";

const char *FOOTER =
"</table>\n"
"</body>\n"
"</html>\n";

int check_filename(const char * outFileName){
    char *pch;
    
    //jestli tam vubec je .html
    if(strstr(outFileName, ".html") == NULL)
        return EASTER_INVALID_FILENAME;
    //jestli to neni jenom .html
    if(strlen(outFileName)<6)
        return EASTER_INVALID_FILENAME;
    //kontrola pozice .html
    pch = strrchr((char *)outFileName, '.');
    if(strcmp(pch, ".html") !=0)
        return EASTER_INVALID_FILENAME;
    //kontrola znaku
    for(unsigned int i=0; i<strlen(outFileName); i++){
        if(isalnum(outFileName[i]) == 0){
            switch(outFileName[i]){
                    case '/':
                    case '\\':
                    case '.':
                        break;
                default: return EASTER_INVALID_FILENAME;
            }
        }
    }
    return EASTER_OK;
}

int get_number(const char * years){
    int number=0;
    if((number = atoi(years)) == 0)
        return EASTER_INVALID_YEARS;
    if((number<1582) || (number>=2200))
        return EASTER_INVALID_YEARS;
    return number;
}

int easterReport(const char * years, const char * outFileName){
    int *data, *newdata, newnumber=0, pom=0, ind=0;
    char c = 1;
    size_t num = 0, allocated = 10;
    FILE *file;
    
    if(check_filename(outFileName) != EASTER_OK)
        return EASTER_INVALID_FILENAME;
    
    data = (int *)malloc(allocated*sizeof(int));                //allocate array for numbers
    
    //get first year
    if((newnumber = get_number(years)) == EASTER_INVALID_YEARS){
        free(data);
        return EASTER_INVALID_YEARS;
    }
    while(isdigit(years[0]))years++;
    if(years !=NULL)c = years[0];
    else c = '\0';
    years++;
    data[num++] = newnumber;
    
    //switch between , and -
    while(c != '\0'){
        switch(c){
            case ',':
                ind = 0;
                if((newnumber = get_number(years)) == EASTER_INVALID_YEARS){
                    free(data);
                    return EASTER_INVALID_YEARS;
                }
                num++;
                if(num>=allocated){
                    allocated += allocated;
                    newdata = (int *)realloc(data, sizeof(int)*allocated);
                    data = newdata;
                }
                while(isdigit(years[0]))years++;
                data[num-1] = newnumber;
                break;
            case '-':
                if(ind){
                    free(data);
                    return EASTER_INVALID_YEARS;
                }
                else ind = 1;
                if((pom = get_number(years)) == EASTER_INVALID_YEARS){
                    free(data);
                    return EASTER_INVALID_YEARS;
                }
                if(pom<newnumber){
                    free(data);
                    return EASTER_INVALID_YEARS;
                }
                while(isdigit(years[0]))years++;
                for(; newnumber<pom; newnumber++){
                    num++;
                    if(num>=allocated){
                        allocated += allocated;
                        newdata = (int *)realloc(data, sizeof(int)*allocated);
                        data = newdata;
                    }
                    data[num-1] = newnumber+1;
                }
                break;
            case '\0':
                break;
            case ' ':
                while(isdigit(years[0]))years++;
                break;
            default:
                free(data);
                return EASTER_INVALID_YEARS;
        }
        if(years !=NULL)c = years[0];
        else c = '\0';
        years++;
    }
    
    //file write
    file = fopen(outFileName, "w");
    if (file == NULL){
        free(data);
        return EASTER_INVALID_FILENAME;
    }
    fprintf(file, "%s", HEADER);
    for(unsigned int i=0; i<num; i++){
        int Year = data[i];
        int Month = 3;

		int G = Year % 19 + 1;
		int C = Year / 100 + 1;
		int X = ( 3 * C ) / 4 - 12;
		int Y = ( 8 * C + 5 ) / 25 - 5;
		int Z = ( 5 * Year ) / 4 - X - 10;
		int E = ( 11 * G + 20 + Y - X ) % 30;
		if (E == 24) {E++;}
		if ((E == 25) && (G > 11)) {E++;}
		int N = 44 - E;
		if (N < 21) {N = N + 30;}
		int P = ( N + 7 ) - ( ( Z + N ) % 7 );
		if ( P > 31 )
		{
			P = P - 31;
			Month = 4;
		}
        
        switch(Month){
            case 3:
                fprintf(file,"<tr><td>%d</td><td>March</td><td>%d</td></tr>", P, data[i]);
                break;
            case 4:
                fprintf(file,"<tr><td>%d</td><td>April</td><td>%d</td></tr>", P, data[i]);
                break;
        }
        
    }
    
    fprintf(file, "%s", FOOTER);
    fclose(file);
    free(data);
    return EASTER_OK;
}

#ifndef __PROGTEST__
int main (void)
{
    int s = easterReport( "2001 , 2002  ,  2003 ,2005,2006", "out2.html" );
    printf("return code: %d\n",s);
    return EASTER_OK;
}
#endif /* __PROGTEST__ */