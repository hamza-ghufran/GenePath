#pragma once

#include "ofMain.h"
#include "Rocket.h"
#include "Dna.h"
#include "Obstacle.h"

#include "Population.h"

//#include "Rocket.h"




class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofPolyline currentPolyline;
		bool leftMouseButtonPressed;
		ofVec2f lastPoint;
		float minDistance;

		vector<ofPolyline> polylines;
		vector<ofPolyline> polylinestocheck;

		Rocket rocket;
		DNA dna;
		Obstacle target;

		int lifetime;

		Population population;

		int lifecycle;
		int recordtime;

		vector<Obstacle> obstacle;


		
};
