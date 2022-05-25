#pragma once

#include "Strategy.h"

class CurrentTestStrat : public Strategy {
	public:
		CurrentTestStrat();
		~CurrentTestStrat();
		bool checkForBuy(Quote quote);
		bool checkForSell(Quote quote);

	private:
		float highestBuyPrice = 0.00;
		long lastTradeTime = 0;
		Quote lastQuote;
};
