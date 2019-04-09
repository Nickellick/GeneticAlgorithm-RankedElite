//
// Created by kolya on 08.04.2019.
//

#include "print.h"

//TODO make it flexible too. Go away from (sizeof)
void print_member(Gmember member[]) {
    printf("#\tValue\tBinary\t\tFitness\n");
    for (int i = 0; i < NUMBER_OF_MEMBERS; i++) {
        printf("%d\t%d\t%s\t%.1f\n", i + 1, member[i].value, short2bin(member[i].value, MEMBER), member[i].fitness);
    }
}