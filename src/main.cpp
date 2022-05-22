#include "MoneyTree.h"
#include "DbMan.h"
#include <iostream>

int main() {

	//MoneyTree mTree;

	//mTree.mainLoop();

	DbMan dbMan;

	dbMan.setQuoteData();

	std::vector<Quote> quoteData = dbMan.getQuoteData();

	std::cout << quoteData[0].symbol << std::endl;

	return 0;
}
