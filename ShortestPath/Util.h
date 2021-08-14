//This Header holds the libraries for the program
//and general valid checks for the inputs from the user
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <iomanip>

using namespace std;
class Graph;		//forward declaration

//typedef to parameterialize a function that recieves 2 integers and Graph referance as arguments,
//and it's return value is a Graph referance
typedef Graph& (*Func)(int, int , Graph&);

//this function checks if the input number is positive.
void checkN(int n); //input: input number of vertexes from stdin, output: exit(1) if invalid input

//this function checks if the input number is bigger than 0 and smaller than 'n'.
void checkInput(int input, int n); //input:vertex value from stdin, output: exit(1) if invalid input

//this function recieves a Func f and its name and parameters, 
//measure its run-time and print it to the file 'Measure.txt'
void printRunTimeToFile(Func f ,string f_name, int p1, int p2, Graph& p3);

