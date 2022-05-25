#include "CurrentTestStrat.h"
#include <iostream>

CurrentTestStrat::CurrentTestStrat() {
	stopLossPercent = 0.0005;
	capRiskPercent = 0.20;
}

CurrentTestStrat::~CurrentTestStrat() {
	// deconstructor
}

bool CurrentTestStrat::checkForBuy(Quote quote) {

	if(quote.lastPrice >= lastQuote.lastPrice && lastQuote.lastPrice != 0 && quote.tradeTimeInLong > lastTradeTime) {
		if(quote.askPrice > highestBuyPrice) {
			highestBuyPrice = quote.askPrice;
			stopLoss = quote.askPrice - (quote.askPrice * stopLossPercent);
		}
		lastTradeTime = quote.tradeTimeInLong;
		lastQuote = quote;
		return true;
	}
	lastQuote = quote;
	return false;
}

bool CurrentTestStrat::checkForSell(Quote quote) {

	if(quote.lastPrice != 0.00 || quote.askPrice != 0.00 || quote.bidPrice != 0.00) { 
		if((quote.lastPrice < lastQuote.lastPrice && quote.bidPrice > highestBuyPrice) || quote.bidPrice <= stopLoss)  {
			lastQuote = quote;
			return true;
		}
	}
	lastQuote = quote;
	return false;
}	
