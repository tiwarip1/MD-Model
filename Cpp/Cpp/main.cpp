#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <ctime> // For timing
using std::clock;

#include "atom.h"
#include "cubic_layout.h"

/*This is a pet project, where I try to simulate molecular dynamics for an arbitarily sized cube of atoms with a given mass and orientation. What I hope to see from 
this project is how correct certain force equations are and comparing them with different lattice orientations*/

/*
The layout of this program is as follows:
At first, a layout is initialized and atoms are placed in a 3-d vector of atoms each of which gather their individual positions. This class also gives each atom a random
temperature dependent on the root mean square velocity due to this temperature.
*/


int main() {
	clock_t tock = clock();
	cubic_layout i = cubic_layout(100);
	clock_t tick = clock();
	double diff = tick - tock;
	cout << diff/CLOCKS_PER_SEC << endl;

	system("pause");
}