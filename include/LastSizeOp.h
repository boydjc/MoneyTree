#pragma once

#include "Strategy.h"

class LastSizeOp : public Strategy {
	
	public:
		LastSizeOp();
		~LastSizeOp();
		bool checkForBuy(Quote quote);
		bool checkForSell(Quote quote);

	private:
		float highestBuyPrice = 0.00;
		long lastTradeTime = 0;
};
