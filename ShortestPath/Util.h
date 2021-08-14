//This Header holds the libraries for the program
//and general valid checks for the inputs from the user
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <stdlib.h>

using namespace std;

//this function checks if the input number is positive.
void checkN(int n); //input: input number of vertexes from stdin, output: exit(1) if invalid input

//this function checks if the input number is bigger than 0 and smaller than 'n'.
void checkInput(int input, int n); //input:vertex value from stdin, output: exit(1) if invalid input

