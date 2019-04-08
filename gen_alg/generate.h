#ifndef GENERATE_H
#define GENERATE_H

long getMicrotime();
void short_concat(unsigned short* high, unsigned short* low,\
                             unsigned short* result);
char* short2bin(unsigned short* number, unsigned short type);
void generate_phenotype(unsigned short* phenotype);
void generate_member(unsigned short* phenotype, unsigned short* member);
#endif
