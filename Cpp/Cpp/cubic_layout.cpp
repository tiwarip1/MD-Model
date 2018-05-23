#include <cmath>
using std::pow;

#include "cubic_layout.h"
#include "atom.h"

cubic_layout::cubic_layout(int dimension,float temperature) {
	// This is a constructor that uses 3 for loops and creates the array with atoms and appends that to cubic_array
	// It is o Big-O n^3, so very inefficient
	vector<atom> rows;
	vector<vector<atom>> columns;

	for (int i = 0; i < dimension; i++) {
		columns.clear();
		for (int j = 0; j < dimension; j++) {
			rows.clear();
			for (int k = 0; k < dimension; k++) {
				atom a(i / inter_atomic_dist, j / inter_atomic_dist, k / inter_atomic_dist);
				randomize_velocities(a,temperature);
				rows.push_back(a);
			}
			columns.push_back(rows);
		}
		cubic_array.push_back(columns);
	}
}

void cubic_layout::randomize_velocities(atom& input,float temperature) {
	//Finds the root mean square velocity and gives that as the magnitude of every particle velocity and spreads it out across each dimension
	double total_velocity = pow(3 * 1.38064852*pow(10, -23)*temperature / input.m, .5);
	float randx = (rand() % 100) + 1;
	float randy = (rand() % 100) + 1;
	float randz = (rand() % 100) + 1;
	float normalization = pow(randx*randx + randy*randy + randz*randz, .5);//This is incorrect, but it doesn't really matter too much

	input.vx = total_velocity * randx / normalization;
	input.vy = total_velocity * randy / normalization;
	input.vz = total_velocity * randz / normalization;
}