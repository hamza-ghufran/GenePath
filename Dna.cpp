#include "Dna.h"

DNA::DNA() {
}
DNA::DNA(vector<ofVec2f>newgenes) {

	genes = newgenes;
}
DNA DNA::crossover(DNA partner) {

	vector<ofVec2f> child;
	//child.size() = genes.size();

	int crossover = int(ofRandom(genes.size()));

	for (int i = 0; i < genes.size(); i++) {
		if (i > crossover) child[i] = genes[i];
		else               child[i] = partner.genes[i];
	}
	DNA newgenes(child);
	return newgenes;

}

void DNA::mutate(float m) {
	for (int i = 0; i < genes.size(); i++) {
		if (ofRandom(1) < m) {
			float angle = ofRandom(TWO_PI);
			genes[i].set(cos(angle), sin(angle));
			genes[i] * (ofRandom(0, maxforce));

			if (i == 0) genes[i].normalize();
		}
	}
}

void DNA::setup(int length) {
	//genes.size = lifetime;
	ofVec2f v(0, 0);
	genes.assign(300, v);

	for (int i = 0; i < genes.size(); i++) {


		float angle = ofRandom(TWO_PI);

		genes[i].set(cos(angle), sin(angle));
		genes[i] *= (ofRandom(0, maxforce));
	}

	genes[0].normalize();
}