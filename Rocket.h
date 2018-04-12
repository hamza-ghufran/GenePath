#pragma once
#include "Dna.h"
#include "Obstacle.h"


class Rocket {

public:
	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;

	float r;

	float recordDist;

	float fitnes;
	DNA dna;

	int geneCounter = 0;

	bool hitObstacle;
	bool hitTarget;
	int finishTime;



	//bool hitTarget = false;
	Rocket();
	Rocket(ofVec2f l, DNA dna_, int totalRockets);
	void fitness();
	void run();
	void checkTarget(Obstacle target);
	void applyforce(ofVec2f f);
	void update();
	void display();
	void set(ofVec2f l);
	bool hit(ofVec2f linepoints, ofVec2f p);
	void obstacle(vector<ofPolyline> polylinestocheck, Rocket rocket);
	float getFitness();
	DNA getDNA();
	bool stopped();
};