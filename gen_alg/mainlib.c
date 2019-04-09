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
//CHECK - SHOULD IT RECOUNT FITNESS? IF YES (LIKE FUNCTION "CROSSOVER"), THEN IT SHOULD RETURN ARRAY OF GMEMBERS!!!
void generate_member(ushort member_value[], const ushort phenotype[]) {
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        ushort i = _get_random_ushort(0, 1);
        ushort j = _get_random_ushort(2, 4);
        member_value[i] = _ushort_concat(&phenotype[i], &phenotype[j]);
    }
}

void _swap_gmembers(Gmember* a, Gmember* b) {
    Gmember temp = *a;
    *a = *b;
    *b = temp;
}

ushort _get_bit_summ(ushort member_value) {
    ushort summ = 0;
    for (ushort i; i < MEMBER_LENGTH; i++) {
        (member_value & 0x80 )? summ++ : NULL;
        member_value <<= 1;
    }
}

void count_fitness(Gmember member[]) {
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        member[i].fitness = (float)_get_bit_summ(member[i].value)/NUMBER_OF_MEMBERS;
    }
}

float _get_fitness_summ(const float fitness[]) {
    float fitness_summ;
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        fitness_summ += fitness[i];
    }
    return fitness_summ;
}

void sort_members_by_fitness(Gmember member[]) {
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        for (ushort j = 0; j < NUMBER_OF_MEMBERS - i - 1; j++) {
            if(member[j].fitness > member[i].fitness) {
                _swap_gmembers(&member[j], &member[j+1]);
            }
        }
    }
}

//IS IT OPTIMISED???
float get_fitness_variation(Gmember member[]) {
    Gmember fit_cpy[NUMBER_OF_MEMBERS];
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        fit_cpy[i].fitness = member[i].fitness;
    }
    sort_members_by_fitness(fit_cpy);
    return fit_cpy[NUMBER_OF_MEMBERS - 1].fitness - fit_cpy[0].fitness;
}

//TODO Make it more flexible too
//THIS FUNCTION RECOUNTS FITNESS!!!
ushort do_crossover(Gmember member[]) {
    ushort crossover_point = _get_random_ushort(0, 6);
    Gmember temp_member[NUMBER_OF_MEMBERS];
    for (ushort i = 0; i < NUMBER_OF_MEMBERS / 2; i++) {
        ushort temp_member1R = member[i].value;
        ushort temp_member2R = member[i + NUMBER_OF_MEMBERS / 2].value;
        ushort temp_member1L = member[i].value;
        ushort temp_member2L = member[i + NUMBER_OF_MEMBERS / 2].value;
        temp_member1R &= ~(0xFFFF << crossover_point);
        temp_member2R &= ~(0xFFFF << crossover_point);
        temp_member1L &= (0xFFFF << crossover_point);
        temp_member2L &= (0xFFFF << crossover_point);
        temp_member[i].value = temp_member1L + temp_member2R;
        temp_member[i + NUMBER_OF_MEMBERS / 2] = temp_member2L + temp_member1R;
    }
    memccpy(member, temp_member, sizeof(temp_member));
    count_fitness(member);
    return crossover_point;
}

//THIS FUNCTION RECOUNTS FITNESS TOO!!!
//returns chance in percent (ushort) and mutation bit as array of 2 ushort values
ushort* do_mutation(Gmember member[]) {
    ushort chance = _get_random_ushort(0, 100);
    ushort mutation_bit = _get_random_ushort(0, 7);
    for (ushort i = 0; i < NUMBER_OF_MEMBERS; i++) {
        ushort temp_chance = _get_random_ushort(0, 100);
        if (temp_chance <= chance) {
            ushort mutation_mask = 1 << mutation_bit;
            member[i].value & mutation_mask ? (member[i].value &= ~(1 << mutation_bit)) :\
            (member[i].value |= (1 << mutation_bit));
        }
    }
    count_fitness(member);
    ushort results[2] = {chance, mutation_bit};
    return results;
}

//TODO All functions from main.c + printer
//TODO make one main.c file
//TODO full comments and description
//TODO optimization!!!