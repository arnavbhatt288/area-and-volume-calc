/*
	Program: Area and volume calculator
	
	Module: header.h
	
	Purpose: A header file with neccessary headers, prototypes, variables and definations.
*/


/* Headers */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Functions Prototypes */

int areaEngine(void);
int volumeEngine(void);
int startEngine(void);
void printError(char errorString[]);

/* Defines */

#define PI 		3.14285714286
#define SQUARE(x)		x * x
#define CUBE(x)		x * x * x
