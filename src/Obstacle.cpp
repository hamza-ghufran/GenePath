
#include "Obstacle.h"


Obstacle::Obstacle(int x, int y) {
	position.set(x, y);


}
Obstacle::Obstacle() {


}


void Obstacle::place(int x_, int y_) {

	position.set(x_, y_);

}

void Obstacle::display() {

	ofSetColor(0);
	ofFill();
	ofDrawEllipse(position.x, position.y, 15, 10);

}
bool Obstacle::contains(ofVec2f point) {

	if (point.x > position.x && point.x <position.x + 15 && point.y> position.y && point.y < position.y + 10)
		return true;

	else return false;



}
