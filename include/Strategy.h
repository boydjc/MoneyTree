#pragma once

class Strategy {
	
	public:
		Strategy();
		~Strategy();
		virtual bool checkForSell();
		virtual bool checkForBuy();
		void setCapRiskPercent(float value);
		void setStopLoss(float value);
		float getCapRiskPercent();
		float getStopLoss();

	protected:
		float capRiskPercent;
		float stopLoss;
};
