#ifndef __CALC_23572098352093_H__
#define __CALC_23572098352093_H__
#pragma once

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

typedef enum { CMD_HELP, CMD_TEST, CMD_MULTIPLY, CMD_DIVIDE, CMD_SUBTRACT, CMD_ADD, CMD_MODULUS, CMD_INVALID } Command;

// Calc
void calculate();
int getCommand(char* arg, Command* out);
int getDouble(char* c, double* out);
int getLineAndParse(char* raw_buf, int raw_bufsiz, Command* cmd, double* a, double* b);
double multiply(double a, double b);
double divide(double a, double b);
double add(double a, double b);
double subtract(double a, double b);
double modulus(double a, double b);

//Test
void runTests();
void multiplyTest();
void divideTest();
void addTest();
void subtractTest();
void modulusTest();

#endif