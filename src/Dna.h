#pragma once

#include "ofMain.h"

class DNA {

	public:
		vector<ofVec2f> genes;
		float maxforce = 0.1;


		DNA();
		DNA(vector <ofVec2f> newgenes);
		void setup(int length);
		DNA crossover(DNA partner);
		void mutate(float m);


};