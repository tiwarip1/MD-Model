#pragma once
#include <vector>
using std::vector;

#include "atom.h"

class cubic_layout
{
public:
	//Variables
	double inter_atomic_dist = pow(10,-11);
	vector<vector<vector<atom>>> cubic_array; // a 3-d array of atom classes each of which have their own positions

	//Constructors
	cubic_layout(int dimension, float temperature=1.0); // Creates cubic array of a certain dimension

	//Methods
	void randomize_velocities(atom&,float);
};