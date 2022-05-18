#include "LastSizeOp.h"
#include <iostream>

LastSizeOp::LastSizeOp() {
	std::cout << "Hello from LastSizeOp Strategy" << std::endl;
	stopLoss = 0.20;
	capRiskPercent = 0.20;
}

LastSizeOp::~LastSizeOp() {
	// deconstructor
}

bool LastSizeOp::checkForBuy(Quote quote) {
	// Check the last size against the bid and ask size
	// if the last size is greater than the ask size but not 
	// greater than the bid size then we will buy
	if(quote.lastSize >= quote.bidSize && quote.lastSize < quote.askSize) {
		return true;
	}
	return false;
}

bool LastSizeOp::checkForSell(Quote quote) {
	// Check the last size against the bid and ask size
	// if the last size is greater than the bid size but not
	// greater than the ask size then we will sell all of our shares
	if(quote.lastSize < quote.bidSize && quote.lastSize >= quote.askSize) {
		return true;
	}
	return false;
}	
