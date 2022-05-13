#include "MoneyTree.h"
#include "DbMan.h"

int main() {

	DbMan dbMan;

	dbMan.connect();

	dbMan.disconnect();

	MoneyTree mTree;

	mTree.mainLoop();

	return 0;
}
