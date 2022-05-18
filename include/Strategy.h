#pragma once

#include "TDA.h"

class Strategy {
	
	public:
		Strategy();
		~Strategy();
		virtual bool checkForSell(Quote quote);
		virtual bool checkForBuy(Quote quote);
		void setCapRiskPercent(float value);
		void setStopLoss(float value);
		float getCapRiskPercent();
		float getStopLoss();

	protected:
		float capRiskPercent;
		float stopLoss;
};
