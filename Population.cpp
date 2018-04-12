#include "Population.h"


Population::Population() {}

Population::Population(ofVec2f position,float m, int populationsize) {

	mutationrate = m;
	generations = 0;
	ofVec2f v(0, 0);
	Rocket temprockets;
	population.assign(populationsize, temprockets);
	DNA dna;
	

	for (int i = 0; i < population.size(); i++) {
 	    
		dna.setup(300);		
		Rocket assignrockets(position, dna, population.size());
		population[i] = assignrockets;
	}

}

void Population::live(Obstacle target) {

	for (int i = 0; i < population.size(); i++) {

		population[i].checkTarget(target);
		population[i].run();

	}
}

bool Population::targetreached() {

	for (int i = 0; i < population.size(); i++) {

		if (population[i].hitTarget == true)
			return true;

		else
			return false;
	}
	return false;

}

void Population::fitness() {

	for (int i = 0; i < population.size(); i++)
		population[i].fitness();

}

void Population::selection() {
	matingpool.clear();

	float maxFitness = maxfitness();
	for (int i = 0; i < population.size(); i++) {
		float fitnessNormal = ofMap(population[i].getFitness(), 0, maxFitness, 0, 1);

		//cout<< "rocket fit   " << fitnessNormal;
	     int n = (fitnessNormal * 100);  // Arbitrary multiplier
	   //	cout << "after 100 " << n;

		for (int j = 0; j < 2; j++) {
			matingpool.push_back(population[i]);
		}	
	}


}

void Population::reproduction() {

	for (int i = 0; i < population.size(); i++) {

		int m = int(ofRandom(matingpool.size()));
		int d = int(ofRandom(matingpool.size()));

		Rocket mom = matingpool.at(m);
		Rocket dad = matingpool.at(d);

		DNA momgenes = mom.getDNA();
		DNA dadgenes = dad.getDNA();

		DNA child = momgenes.crossover(dadgenes);

		child.mutate(mutationrate);

		ofVec2f position(ofGetWidth() / 2, ofGetHeight() + 20);
	
		population[i] = Rocket(position, child, population.size());
	}

	generations++;
}

int Population::getgenerations() {
	return generations;
}

void Population::display() {

	for (int i = 0; i < population.size(); i++) {
		population[i].display();


	}

}

float Population::maxfitness() {
	float record = 0;
	for (int i = 0; i < population.size(); i++) {
		if (population[i].getFitness() > record) {
			record = population[i].getFitness();
		}
	}
	return record;
}
