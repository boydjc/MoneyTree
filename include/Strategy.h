#pragma once

#include "TDA.h"

class Strategy {
	
	public:
		Strategy();
		~Strategy();
		virtual bool checkForSell(Quote quote);
		virtual bool checkForBuy(Quote quote);
		void setCapRiskPercent(float value);
		float getCapRiskPercent();
		float getStopLossPercent();
		float getStopLoss();

	protected:
		float capRiskPercent;
		float stopLossPercent;
		float stopLoss;
};
