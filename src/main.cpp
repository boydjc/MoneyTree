#include "MoneyTree.h"
#include "DbMan.h"

int main() {

	DbMan dbMan;

	dbMan.testDb();

	MoneyTree mTree;

	mTree.mainLoop();

	return 0;
}
