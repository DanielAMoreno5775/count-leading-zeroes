#ifndef MAJOR1_H_
#define MAJOR1_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

void displayMenu();
char getUserChoice();
char evaluateUserChoice();
uint32_t getUnsignedInt(char *, unsigned long, unsigned long);
int countLeadingZeroes (uint32_t);
#endif
