#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    char shu[10];
    gets(shu);
    int a = 0;
        if(shu[0]=='S'){
            if(shu[2]=='o'){
                a = 76;
            }
            else if(shu[3]=='E'){
                a = 73;
            }
            else if(shu[3]=='J'){
                a = 75;
            }
        }
        else if(shu[0]=='F'){
            a = 74;
        }
        else if(shu[0]=='Z'){
            if(shu[3]=='Z'){
                a = 77;
            }
            else {
                a = 79;
            }
        }
        printf("193%d299", a);

        //fclose(stdin);
}