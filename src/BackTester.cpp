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

	float startingCash = money;
	float currentCash = money;

	totalTrades = 0;
	unsuccessfulTrades = 0;
	successfulTrades = 0;
	totalSpent = 0;

	// this is pretty much the same as our live paper trade algo 
	// with the exception that we are passing in each quote from our
	// stored data
	for(int i=0; i<quoteData.size(); i++) {
		if(testStrat->checkForBuy(quoteData[i])) {
			float capitalToTrade = currentCash * testStrat->getCapRiskPercent();
			int tradeSize = capitalToTrade / quoteData[i].askPrice;

			if(tradeSize != 0 && currentCash > 0) {
				//std::cout << "BUY" << std::endl;
				stockShares += tradeSize;
				currentCash -= (quoteData[i].askPrice * tradeSize);
				totalSpent += (quoteData[i].askPrice * tradeSize);
			}
		}else if(testStrat->checkForSell(quoteData[i])) {	
			if(stockShares != 0) {
				//std::cout << "SELL" << std::endl;
				// check to see if we made a profit
				float potentialGain = stockShares * quoteData[i].bidPrice;
				if(totalSpent < potentialGain) {
					successfulTrades++;
				} else if(totalSpent > potentialGain) {
					unsuccessfulTrades++;
				}
				totalTrades++;
				currentCash += (stockShares * quoteData[i].bidPrice);
				stockShares = 0;
				totalSpent = 0;
			}
		}
	}

	float successRate = ((float) successfulTrades / (float) totalTrades) * 100;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Back Test Complete." << std::endl;
	std::cout << "Starting Capital: $" << startingCash << std::endl;
	std::cout << "Ending Capital: $" << currentCash << std::endl;
	std::cout << "Total Trades: " << totalTrades << std::endl;
	std::cout << "Successful Trades: " << successfulTrades << std::endl;
	std::cout << "Unsuccessful Trades: " << unsuccessfulTrades << std::endl;
	std::cout.precision(3);
	std::cout << "Success Rate: " << successRate << "%" << std::endl;
	std::cout << "---------------------------------------" << std::endl << std::endl;
}
