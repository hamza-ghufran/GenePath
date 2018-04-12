#pragma once

#include "ofMain.h"
class Obstacle {

public:

	ofVec2f position;
	Obstacle();
	Obstacle(int x, int y);

	void display();
	void place(int x_, int y_);
	bool contains(ofVec2f point);


};