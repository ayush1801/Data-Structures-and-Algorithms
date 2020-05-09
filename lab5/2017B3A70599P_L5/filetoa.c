#include "credit.h"

CC * conv(char * filename)
{
        FILE * fptr=fopen(filename,"r");
        int size=10;
        CC * cc=(CC *)malloc(size*sizeof(CC));
        int i=0;
        while((fscanf(fptr,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n",&(cc[i].cn),cc[i].bc,cc[i].ed,cc[i].fn,cc[i].ln))!=EOF)
        {
                if(size==++i)
                {
                        size=size*2;
                        cc=(CC *)realloc(cc,size*sizeof(CC));
                }
        }
        fclose(fptr);
        return cc;
}
