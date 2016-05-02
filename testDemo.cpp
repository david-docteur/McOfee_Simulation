#include "Simulation.h"

using namespace std;
using namespace McOfee;

int main()
{

	Simulation *s = new Simulation();
	s->start();
	s->getThreatsList();
	s->stop();

	Simulation *copy = new Simulation(*s);
	copy->start();
	copy->getThreatsList();

	*copy = *s;

	delete s;
	delete copy;

	return 0;
}
