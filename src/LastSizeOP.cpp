#include "LastSizeOp.h"
#include <iostream>

LastSizeOp::LastSizeOp() {
	stopLossPercent = 0.0005;
	capRiskPercent = 0.20;
}

LastSizeOp::~LastSizeOp() {
	// deconstructor
}

bool LastSizeOp::checkForBuy(Quote quote) {
	// Check the last size against the bid and ask size
	// if the last size is greater than the ask size but not 
	// greater than the bid size then we will buy
	if(quote.lastSize >= quote.bidSize && quote.lastSize < quote.askSize && quote.tradeTimeInLong > lastTradeTime) {
		if(quote.askPrice > highestBuyPrice) {
			highestBuyPrice = quote.askPrice;
			stopLoss = quote.askPrice - (quote.askPrice * stopLossPercent);
		}
		lastTradeTime = quote.tradeTimeInLong;
		return true;
	}
	return false;
}

bool LastSizeOp::checkForSell(Quote quote) {
	// Check the last size against the bid and ask size
	// if the last size is greater than the bid size but not
	// greater than the ask size AND the bid is larger than our highest
	// buy ask
	if(quote.lastPrice != 0.00 || quote.askPrice != 0.00 || quote.bidPrice != 0.00) { 
		if((quote.lastSize < quote.bidSize && quote.lastSize >= quote.askSize && 
		quote.bidPrice > highestBuyPrice) || quote.bidPrice <= stopLoss)  {
			return true;
		}
	}
	return false;
}	
