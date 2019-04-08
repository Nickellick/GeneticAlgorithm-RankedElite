//
// Created by kolya on 08.04.2019.
//

#ifndef GEN_ALG_MAINLIB_H
#define GEN_ALG_MAINLIB_H

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef PHENOTYPE
#warning "'PHENOTYPE' is not defined. Set value to default '0'"
#define PHENOTYPE 0
#endif //PHENOTYPE

#ifndef MEMBER
#warning "'MEMBER' is not defined. Set value to default '1'"
#define MEMBER 1
#endif //MEMBER

#if PHENOTYPE == MEMBER
#error "'Values of 'PHENOTYPE' and 'MEMBER'" are the same!
#endif

#ifndef PHENOTYPE_LENGTH
#warning "'PHENOTYPE_LENGTH' is not defined. Set value to default '4'"
#define PHENOTYPE_LENGTH 4
#endif //MEMBER

#ifndef MEMBER_LENGTH
#warning "'MEMBER_LENGTH' is not defined. Set value to default '8'"
#define MEMBER_LENGTH 8
#endif //MEMBER_LENGTH

#if (MEMBER_LENGTH % PHENOTYPE_LENGTH) != 0
#error "Can't put phenotypes in Gmember! Check that (MEMBER_LENGTH % PHENOTYPE_LENGTH) != 0"
#endif

#ifndef NUMBER_OF_PHENOTYPES
#warning "'NUMBER_OF_PHENOTYPES' is not defined. Set value to default '5'"
#define NUMBER_OF_PHENOTYPES 5
#endif //NUMBER_OF_PHENOTYPES

#ifndef NUMBER_OF_MEMBERS
#warning "'NUMBER_OF_MEMBERS' is not defined. Set value to default '10'"
#define NUMBER_OF_MEMBERS 10
#endif //NUMBER_OF_MEMBERS

//Defining "ushort" type
#ifndef _USHORT
typedef unsigned short ushort;
#else
#warning "type 'ushort' already defined! Use code carefully!"
#endif //_GMEMBER

//Defining "Gmember" type
#ifndef _GMEMBER
typedef struct {
    ushort value;
    float fitness;
} Gmember;
#else
#warning "type 'gmember' already defined! Redefine it inside"
#endif //_GMEMBER


long get_microtime();
ushort _ushort_concat(const ushort *high, const ushort *low);
char* short2bin(ushort number);
#endif //GENETICALGORITHM_RANKEDELITE_MAINLIB_H