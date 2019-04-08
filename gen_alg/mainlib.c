//
// Created by kolya on 08.04.2019.
//

#include "mainlib.h"

#define PHENOTYPE_MAX_VALUE ((1 << PHENOTYPE_LENGTH) - 1)
#define MEMBER_MAX_VALUE ((1 << MEMBER_LENGTH) - 1)

//Get current time in microseconds;
long _get_microtime() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

ushort _get_random_ushort(const ushort floor, const ushort celling) {
    sleep(0.07);
    srand(get_microtime());
    int seed = rand();
    srand(seed);
    return floor + (rand() % (celling - floor + 1));
}

//Concatinate two 'short' to get one Gmember in generation
ushort _ushort_concat(const ushort *high, const ushort *low){
    return (*high << 4) + *low;
}

//Generate binary string from ushort (UP TO 256!!!)
//TODO Make algorithm more flexible (for ushort)
char* short2bin(ushort number){
    char* binary_ushort;
    if (number <= PHENOTYPE_MAX_VALUE) {
        binary_ushort = malloc(PHENOTYPE_LENGTH + 1);
        strcpy(binary_ushort, "");
        for (ushort i = 0; i < PHENOTYPE_LENGTH; i++) {
            (number & 0x08) ? strcat(binary_ushort, "1") : strcat(binary_ushort, "0");
            number <<= 1;
        }
    }
    else if ((number > PHENOTYPE_MAX_VALUE) && (number < MEMBER_MAX_VALUE)) {
        binary_ushort = malloc(MEMBER_LENGTH + 1);
        strcpy(binary_ushort, "");
        for (ushort i = 0; i < MEMBER_LENGTH; i++) {
            (number & 0x80) ? strcat(binary_ushort, "1") : strcat(binary_ushort, "0");
            number <<= 1;
        }
    }
    else return NULL;
    return binary_ushort;
}

void generate_phenotype(ushort phenotype[]) {
    for (ushort i = 0; i < NUMBER_OF_PHENOTYPES; i++) {
        phenotype[i] = _get_random_ushort(0, PHENOTYPE_MAX_VALUE;
    }
}


//TODO More flexible too plz
void generate_member(ushort member[], const ushort phenotype[]) {
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        ushort i = _get_random_ushort(0, 1);
        ushort j = _get_random_ushort(2, 4);
        member[i] = _ushort_concat(&phenotype[i], &phenotype[j]);
    }
}

void _swap(ushort* a, ushort* b) {
    ushort temp = *a;
    *a = *b;
    *b = temp;
}

ushort _bit_summ(ushort member) {
    ushort summ = 0;
    for (ushort i; i < MEMBER_LENGTH; i++) {
        (member & 0x80 )? summ++ : NULL;
        member <<= 1;
    }
}

void count_fitness(Gmember member[]) {
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        member[i].fitness = (float)_bit_summ(member[i].value)/NUMBER_OF_MEMBERS;
    }
}

float _get_fitness_summ(const float fitness[]) {
    float fitness_summ;
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        fitness_summ += fitness[i];
    }
    return fitness_summ;
}

//TODO Make it more flexible too
void do_crossover();

//TODO All functions from main.c + printer
//TODO make one main.c file
//TODO full comments and description