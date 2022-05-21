#include "MoneyTree.h"
#include "DbMan.h"

int main() {

	//MoneyTree mTree;

	//mTree.mainLoop();

	DbMan dbMan;

	dbMan.getTableNames();
	dbMan.getQuoteData();

	return 0;
}
