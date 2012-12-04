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

#define EASTER_OK 0
#define EASTER_INVALID_FILENAME 1
#define EASTER_INVALID_YEARS 2
#define EASTER_IO_ERROR 3

#endif /* __PROGTEST__ */

const char *HEADER =
"------8<-----\n"
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
"</html>\n"
"------8<-----\n";

int get_number(const char * years){
    int number=0;
    if((number = atoi(years)) == 0){
        printf("Invalid input.\n");
        return EASTER_INVALID_YEARS;
    }
    return number;
}

int easterReport(const char * years, const char * outFileName){
    int *data, *new_data, new=0, pom=0;
    char c = 1;
    size_t num = 0, allocated = 10;
    
    data = (int *)malloc(allocated*sizeof(int));
    
    while(c != '\0'){
        new = get_number(years);
        years++;years++;years++;years++;
        c = years[0];
        
        switch(c){
            case ',':
                years++;
                num++;
                if(num>=allocated){
                    allocated += allocated;
                    new_data = realloc(data, sizeof(double)*allocated);
                    data = new_data;
                }
                data[num-1] = new;
                break;
            case '-':
                years++;
                pom = get_number(years);
                years++;years++;years++;years++;
                for(new; new<=pom; new++){
                    num++;
                    if(num>=allocated){
                        allocated += allocated;
                        new_data = (int *)realloc(data, sizeof(int)*allocated);
                        data = new_data;
                    }
                    data[num-1] = new;
                }
                c = years[0];
                break;
            case '\0':
                break;
            default:
                printf("Invalid input.\n");
                return EASTER_INVALID_YEARS;
        }
        }
    
    for(int i=0; i<num; i++){
        printf("%d\n", data[i]);
    }
    
    return EASTER_OK;
}

#ifndef __PROGTEST__
int main (void)
{
    easterReport("2012,2013,2015-2020", "out0.html");
    return EASTER_OK;
}
#endif /* __PROGTEST__ */