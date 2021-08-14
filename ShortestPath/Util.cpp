#include "Util.h"
#include "Graph.h"


void checkN(int n)
{
	if (n <= 0)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
}

void checkInput(int input, int n)
{
	if (input <= 0 || input > n)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
}

void printRunTimeToFile(Func f ,string f_name, int p1, int p2, Graph& p3) {
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	f(p1,p2,p3);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function " << f_name << " is : " << fixed
		<< time_taken << setprecision(9);
	cout << "Time taken by function " << f_name << " is : " << fixed
		<< time_taken << setprecision(9);
	cout << " sec" << endl;
	myfile.close();
}