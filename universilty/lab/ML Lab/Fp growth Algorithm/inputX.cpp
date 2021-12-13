#include <bits/stdc++.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
using namespace std ;

int main()
{
    FILE *fp,*tp;
    fp = fopen("inputX.txt", "r");
    tp = fopen("input.txt", "w");
    const size_t line_size = 300;
    char line[300];
    int len;
    while (fgets(line, line_size, fp) != NULL)
    {
        len=strlen(line);
        line[len-1]='-';
        line[len]='1';
        line[len+1]='\n';
        line[len+2]=0;
        fprintf(tp,"%s",line);
    }
    fclose(fp);
}
