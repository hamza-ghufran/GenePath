#pragma once

#include "ofMain.h"

#include "Obstacle.h"
#include "Rocket.h"
#include "Dna.h"




class Population {

public:
	float mutationrate;
	vector<Rocket> population;
	vector<Rocket>matingpool;
	int generations;

	Population();
	Population(ofVec2f position, float m, int num);
	void live(Obstacle target);
	bool targetreached();
	void fitness();
	void selection();
	void reproduction();
	int getgenerations();
	float maxfitness();
	void display();

};
