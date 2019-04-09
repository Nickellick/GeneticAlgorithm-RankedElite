#include <stdio.h>

//#include "gen_alg/generate.h"
#include "gen_alg/mainlib.h"
#include "gen_alg/print.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ATTRIBUTE_LENGTH 5
#define PHENOTYPE 1
#define MEMBER 0
#define MEMBER_COUNT 10

//typedef unsigned short ushort;

//void swap(short *xp, short *yp)
//{
//    short temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}

//typedef struct {
//    ushort value[10];
//    ushort fitness[10];
//} memer;
//
////typedef struct member memer;
//unsigned short do_random_ushort(unsigned short floor, unsigned short celling)
//{
//    memer hehe;
//    hehe.fitness;
//    sleep(1);
//    //srand(time(NULL));
//    srand(getMicrotime());
//    int seed = rand();
//    srand(seed);
//    return floor + (unsigned short)(rand() % (celling - floor + 1));
//}
//
//void do_crossover(unsigned short members_origin[], unsigned short members_aftercross[])
//{
//    sleep(1);
//    //srand(time(NULL));
//    srand(getMicrotime());
//    int seed = rand();
//    srand(seed);
//    short crossover_point = (unsigned short)(rand() % 7);
//    printf("Crossover point between %d and %d bit\n", crossover_point, crossover_point + 1);
//    for (short i = 0; i < MEMBER_COUNT / 2; i++)
//    {
//        unsigned short *temp1R = malloc(2);
//        unsigned short *temp2R = malloc(2);
//        *temp1R = members_origin[i];
//        *temp2R = members_origin[i + MEMBER_COUNT / 2];
//        *temp1R &= ~(0xFFFF << crossover_point);
//        *temp2R &= ~(0xFFFF << crossover_point);
//        unsigned short *temp1L = malloc(2);
//        unsigned short *temp2L = malloc(2);
//        *temp1L = members_origin[i];
//        *temp2L = members_origin[i + MEMBER_COUNT / 2];
//        *temp1L &= (0xFFFF << crossover_point);
//        *temp2L &= (0xFFFF << crossover_point);
//        members_aftercross[i] = *temp1L + *temp2R;
//        members_aftercross[i + MEMBER_COUNT / 2] = *temp2L + *temp1R;
//        printf("Cross Gmember: %s\t%s\n", short2bin(&members_aftercross[i], MEMBER), short2bin(&members_aftercross[i + MEMBER_COUNT / 2], MEMBER));
//        free(temp1R);
//        free(temp2R);
//        free(temp1L);
//        free(temp2L);
//    }
//}
//
//void sort_members_by_fitness(unsigned short members[], double fitness[])
//{
//    for (short i = 0; i < MEMBER_COUNT - 1; i++)
//    {
//        for (short j = 0; j < MEMBER_COUNT - i - 1; j++)
//        {
//            if(fitness[j] > fitness[j+1])
//            {
////                printf("GOT INTO BUBBLE!\n");
//                short swap = members[j];
//                members[j] = members[j+1];
//                members[j+1] = swap;
//                double swapd = fitness[j];
//                fitness[j] = fitness[j+1];
//                fitness[j+1] = swapd;
////                swap(&fitness[j], &fitness[j+1]);
////                swap(&members[j], &members[j+1]);
//            }
//        }
//    }
//}
//
//unsigned short bit_summ(unsigned short Gmember)
//{
//    unsigned short summ = 0;
//    for(unsigned short i = 0; i < 8; i++)
//    {
//        if (Gmember & (unsigned short)0x80)
//        {
//            summ++;
//        }
//        Gmember <<= (unsigned short)1;
//    }
//    return summ;
//}
//
//void mutate(unsigned short* value, unsigned short* bit_number)
//{
//    short *temp = malloc(2);
//    *temp = 0;
//    *temp = 1 << *bit_number;
//    if ((*value & *temp))
//    {
//        *value &= ~(1 << *bit_number);
//    }
//    else *value |= (1 << *bit_number);
//}
//
//void do_mutation(short members[], short* bit_number, short* chance_in_percent)
//{
//    for (short i = 0; i < MEMBER_COUNT; i++)
//    {
//        short temp_value = do_random_ushort(0, 100);
//        if (temp_value <= *chance_in_percent)
//        {
//            printf("Got mutation of Gmember %d in bit %d\n", i + 1, *bit_number);
//            mutate(&members[i], bit_number);
//        }
//        else continue;
//    }
//}

int main()
{
    Gmember member[10];
    ushort phenotype[5];
    printf("Generating phenotypes...\n");
    generate_phenotype(phenotype);
    for (ushort i = 0; i < 5; i++)
    {
        printf("%d\n", phenotype[i]);
    }
    printf("Generate members...\n");
    generate_member(&member[0], phenotype);
    for (ushort i = 0; i < 10; i++)
    {
        printf("%d\n", member[i].value);
    }
//    printf("Printing elements...\n");
//    print_member(member);

//    unsigned short phenotype[5];
//    unsigned short Gmember[MEMBER_COUNT];
//    printf("Step 1. Generating phenotype...\n");
//    generate_phenotype(phenotype);
//    printf("Done!\n\n");
//    printf("Step 2. Generating members...\n");
//    for (short i = 0; i < (short)(sizeof(Gmember)/sizeof(Gmember[0])); i++)
//    {
//        generate_member(phenotype, &Gmember[i]);
//    }
//    printf("Done!\n\n");
//    printf("Step 3. Computing fitness function...\n");
//    double fitness_value[MEMBER_COUNT];
//    double summ_fitness = 0;
//    for (short i = 0; i < (short)(sizeof(fitness_value)/sizeof(fitness_value[0])); i++)
//    {
//        fitness_value[i] = (double)bit_summ(Gmember[i])/(double)MEMBER_COUNT;
//        summ_fitness += fitness_value[i];
//        printf("Fitness value for Gmember %d:\t%.3f\n", i+1, fitness_value[i]);
//    }
//    double rang[MEMBER_COUNT];
//    //short rand_chooser[1000];
//    short buff = 0;
//    short chance_summ_int = 0;
//    for (short i = 0; i < (short)(sizeof(fitness_value)/sizeof(fitness_value[0])); i++)
//    {
//        rang[i] = fitness_value[i]/summ_fitness;
////      printf("Made in int %d\n", (short)(rang[i]*1000));
//        chance_summ_int += (short)(rang[i]*1000);
//    }
//    short rand_chooser[chance_summ_int];
//    for (short i = 0; i < (short)(sizeof(fitness_value)/sizeof(fitness_value[0])); i++)
//    {
//        for (short j = 0; j < (short)(rang[i]*1000); j++)
//        {
//            rand_chooser[buff+j] = Gmember[i];
//        }
//        buff += (int)(rang[i]*1000);
//    }
//    //short rand_chooser[chance_summ_int];
//
//    printf("\nSorting members by fitness value...\n");
//    sort_members_by_fitness(Gmember, fitness_value);
//    for (short i = 0; i < (short)(sizeof(fitness_value)/sizeof(fitness_value[0])); i++)
//    {
//        printf("Fitness value for Gmember\t%d:\t%.3f\n", Gmember[i], fitness_value[i]);
//    }
//    printf("Done!\n\n");
//    printf("Step 4. Making new population...\n\n");
//    for (short i = 0; i < 8; i++)
//    {
//        sleep(1);
//        //srand(time(NULL));
//        srand(getMicrotime());
//        int seed = rand();
//        srand(seed);
//        short indx = (unsigned short)(rand() % chance_summ_int);
//        if (i%2 == 0)
//            Gmember[i] = rand_chooser[indx];
//    }
//    for (short i = 0; i < (short)(sizeof(Gmember)/sizeof(Gmember[0])); i++)
//    {
//        printf("Member value: %d\t Binary: %s\n", Gmember[i], short2bin(&Gmember[i], MEMBER));
//    }
//    unsigned short member_at_end[MEMBER_COUNT];
//    printf("Done!\n\n");
//    printf("Step 5. Making crossover...\n\n");
//    do_crossover(Gmember, member_at_end);
//    printf("\nMembers after cross operation: \n");
//    for (short i = 0; i < (short)(sizeof(member_at_end)/sizeof(member_at_end[0])); i++)
//    {
//        printf("Member value: %d\t Binary: %s\n", member_at_end[i], short2bin(&member_at_end[i], MEMBER));
//    }
//    printf("Done!\n\n");
//    printf("Step 6. Making mutatation...\n\n");
//    short* chance_mutation = malloc(2);
//    *chance_mutation = do_random_ushort(0, 100);
//    printf("Chance of mutation is %d%%\n", *chance_mutation);
//    short* mutation_bit = malloc(2);
//    *mutation_bit = do_random_ushort(0, 7);
//    printf("Mutation bit is %d\n", *mutation_bit);
//    do_mutation(member_at_end, mutation_bit, chance_mutation);
//    free(chance_mutation);
//    free(mutation_bit);
//    printf("Population after %d iteration:\n", 1);
//    for (short i = 0; i < (short)(sizeof(member_at_end)/sizeof(member_at_end[0])); i++)
//    {
//        printf("Member value: %d\t Binary: %s\n", member_at_end[i], short2bin(&member_at_end[i], MEMBER));
//    }
    return 0;
}
