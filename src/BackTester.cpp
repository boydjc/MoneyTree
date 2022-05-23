#include "BackTester.h"
#include <iostream>

BackTester::BackTester() {
	// constructor
}

BackTester::~BackTester() {
	// deconstructor
}

void BackTester::setStartingCash(float amount) {
	money = amount;
}

void BackTester::performBackTest(Strategy *testStrat) {
	dbMan.setQuoteData();
	quoteData = dbMan.getQuoteData();

	// this is pretty much the same as our live paper trade algo 
	// with the exception that we are passing in each quote from our
	// stored data
	for(int i=0; i<quoteData.size(); i++) {
		if(testStrat->checkForBuy(quoteData[i])) {
			float capitalToTrade = money * testStrat->getCapRiskPercent();
			int tradeSize = capitalToTrade / quoteData[i].askPrice;

			if(tradeSize != 0) {
				std::cout << "BUY" << std::endl;
				stockShares += tradeSize;
				money -= (quoteData[i].askPrice * tradeSize);
			}
		}else if(testStrat->checkForSell(quoteData[i])) {	
			if(stockShares != 0) {
				std::cout << "SELL" << std::endl;
				money += (stockShares * quoteData[i].bidPrice);
				stockShares = 0;
			}
		}
	}

}
