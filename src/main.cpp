#include "MoneyTree.h"
#include "DbMan.h"

int main() {

	DbMan dbMan;

	dbMan.createQuoteTable("AAPL");

	MoneyTree mTree;

	mTree.mainLoop();

	return 0;
}
