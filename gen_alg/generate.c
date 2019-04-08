#define ATTRIBUTE_LENGTH 5
#define PHENOTYPE 1
#define MEMBER 0
3
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include "generate.h"

long getMicrotime(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void short_concat(unsigned short* high, unsigned short* low,\
                             unsigned short* result)
{

    //printf("High number: %d\nLow number: %d\n", *high, *low);
    *result = (*high << 4) + *low;
    //printf("Result of concat: %d\n", *result);
    //
}

char* short2bin(unsigned short* number, unsigned short type)
{
    unsigned short lel = *number;
    char* binary_view = malloc(9);
    strcpy(binary_view, "");
    if (type == PHENOTYPE)
    {
        for(unsigned short i = 0; i < 4; i++)
        {
            if (lel & (unsigned short)0x8)
            {
                strcat(binary_view, "1");
            }
            else
            {
                strcat(binary_view, "0");
            }
            lel <<= (unsigned short)1;
        }
    }
    else
    {
        for(unsigned short i = 0; i < 8; i++)
        {
            if (lel & (unsigned short)0x80)
            {
                strcat(binary_view, "1");
            }
            else
            {
                strcat(binary_view, "0");
            }
            lel <<= (unsigned short)1;
        }
    }
    return binary_view;
}

void generate_phenotype(unsigned short phenotype[])
{
    //printf("Generating phenotype...\n");
    for (unsigned short i = 0; i < 5; i++)
    {
        sleep(1);
        //srand(time(NULL));
        srand(getMicrotime());
        int seed = rand();
        srand(seed);
        phenotype[i] = (unsigned short)(rand() % 16);
        printf("Phenotype %d:\t%d\tBinary:\t%s\n", i+1, phenotype[i], short2bin(&phenotype[i], PHENOTYPE));
    }
    //printf("Done!\n\n");
}

void generate_member(unsigned short* phenotype, unsigned short* member)
{
    //printf("Randomizing...\n");
    sleep(1);
    //sleep();
    srand(getMicrotime());
    int seed = rand();
    srand(seed);
    unsigned short j = (unsigned short)(rand() % 2);
    //printf("Got HIGH value: %d\n", j+1);
    sleep(1);
    //srand(time(NULL));
    srand(getMicrotime());
    seed = rand();
    srand(seed);
    unsigned short l = 2 + (unsigned short)(rand() % 3);
    //printf("New values: HIGH: %d; LOW: %d\n", j+1, l+1);
    //printf("Start concatination...\n");
    short_concat(&phenotype[j], &phenotype[l], member);
    printf("Generated Gmember: %d\tBinary:%s\n", *member, short2bin(member, MEMBER));
}
