#include "E:\dev\of_v0.9.3_vs_release\apps\myApps\PathtoGene\src\Rocket.h"


Rocket::Rocket() {}

Rocket::Rocket(ofVec2f l, DNA dna_, int totalRockets) {
	position = l;
	r = 4;
	dna = dna_;
	finishTime = 0;
	recordDist = 10000;
	hitObstacle = false;
	hitTarget = false;
}

void Rocket::fitness() {
	if (recordDist < 1) recordDist = 1;
	fitnes = (1 / (finishTime*recordDist));
	fitnes = pow(fitnes, 4);
	if (hitObstacle) fitnes *= 0.1;
	if (hitTarget) fitnes *= 2;
}

void Rocket::run() {
	if (!hitObstacle && !hitTarget) {
		applyforce(dna.genes[geneCounter]);
		geneCounter = (geneCounter + 1) % dna.genes.size();
		update();

	}
}

void Rocket::checkTarget(Obstacle target) {

	float d = ofDist(position.x, position.y, target.position.x, target.position.y);
	if (d < recordDist) recordDist = d;

	if (target.contains(position) && !hitTarget) {
		hitTarget = true;
	}
	else if (!hitTarget) {
		finishTime++;
	}

}

void Rocket::obstacle(vector<ofPolyline> polylinestocheck, Rocket rocket) {

	for (int i = 0; i < polylinestocheck.size(); i++) {

		ofPolyline polyline = polylinestocheck[i];
		vector<ofVec3f> vertices = polyline.getVertices();
		for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
			ofVec2f linepoints = vertices[vertexIndex];

			hitObstacle = rocket.hit(linepoints, rocket.position);


		}
	}
}

bool Rocket::hit(ofVec2f line, ofVec2f rocketpoints) {

	float distance = ofDist(line.x, line.y, rocketpoints.x, rocketpoints.y);

	if (distance < 2)
		return true;
	else
		return false;

}


void Rocket::update() {
	velocity += acceleration;
	position += velocity;

	acceleration = acceleration * 0;
}
void Rocket::applyforce(ofVec2f f) {
	acceleration += f;

}

void Rocket::display() {


	ofSetColor(200, 120);
	ofFill();
	/*
	ofPushMatrix();
	ofTranslate(position.x, position.y);

	//ofRectMode(CENTER);
	ofSetColor(0);
	ofFill();
	ofRect(-r / 2, r * 2, r / 2, r);
	ofRect(r / 2, r * 2, r / 2, r);

	ofSetColor(175);
	ofBeginShape();
	ofVertex(0, -r * 2);
	ofVertex(-r, r * 2);
	ofVertex(r, r * 2);
	ofEndShape();

	ofPopMatrix();

	*/
	ofDrawCircle(position.x, position.y, 12);

}
float Rocket::getFitness() {
	return fitnes;
}

DNA Rocket::getDNA() {
	return dna;
}

bool Rocket::stopped() {
	return hitObstacle;
}