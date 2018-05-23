#pragma once
class atom
{
public:
	//Variables
	float x;
	float y;
	float z;

	float vx;
	float vy;
	float vz;

	int m = 4; //In this case, using a helium atom as a test mass

	//Constructors
	atom();
	atom(float,float,float); // Stores position data and placed inside a 3-d array 
};

