#include "ofApp.h"

void ofApp::setup(){
	

	ofSetWindowShape(640,480);
	ofSetWindowPosition(300,200);
	minDistance = 10;
	leftMouseButtonPressed = false;
	ofSetFrameRate(5);
	
	lifetime = 300;
	lifecycle = 0;
	recordtime = lifetime;

	target = Obstacle(0, 0);
	float mutationrate = 0.01;
	ofVec2f startposition(ofGetWidth() / 2, ofGetHeight() + 100 / 2);


	population = Population(startposition, mutationrate, 50);

	
}

//--------------------------------------------------------------
void ofApp::update(){


	if (leftMouseButtonPressed==true) {

		ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

		if (lastPoint.distance(mousePos) >= minDistance) {

			currentPolyline.curveTo(mousePos);
			lastPoint = mousePos;

		}

	}
	

	if (lifecycle < lifetime) {
		//cout << lifecycle << " :::: ";
		population.live(target);

		if ((population.targetreached()) && (lifecycle < recordtime)) {
			recordtime = lifecycle;
		}
		lifecycle++;
	}
	

	else
	{
		lifecycle = 0;
		//cout << "lifecycle set to 0";
		population.fitness();
		population.selection();
		population.reproduction();
	}


	

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(125);
	ofSetColor(0);
	
	for (int i = 0; i < polylines.size(); i++) {
		ofPolyline polyline = polylines[i];
		polyline.draw();
		vector <ofVec3f> vertices = polyline.getVertices();
	
		for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
			ofVec3f vertex = vertices[vertexIndex];
			ofDrawCircle(vertex, 2.5);	
		}

	}

	target.display();
	if (lifecycle < lifetime) {
		population.display();
		
	}





	
	//if(rocket.hitObstacle!=true)
	//rocket.display();

	ofSetColor(0, 0, 0);
	currentPolyline.draw();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	

		
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	

	if (button == OF_MOUSE_BUTTON_1) {

		leftMouseButtonPressed = true;
		currentPolyline.curveTo(x, y);
		currentPolyline.curveTo(x, y);
		lastPoint.set(x, y);
	}


	if (button == OF_MOUSE_BUTTON_3) {

		target.place(x, y);

	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	
		leftMouseButtonPressed = false;
		currentPolyline.curveTo(x, y);
		polylinestocheck.push_back(currentPolyline);
		currentPolyline.simplify(0.90);
		polylines.push_back(currentPolyline);
		
		currentPolyline.clear();

	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
