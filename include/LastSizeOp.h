#pragma once

#include "Strategy.h"

class LastSizeOp : public Strategy {
	
	public:
		LastSizeOp();
		~LastSizeOp();
		bool checkForBuy(Quote quote);
		bool checkForSell(Quote quote);
};
