#include "TDA.h"
#include "Strategy.h"
#include "DbMan.h"

class BackTester {
	public:
		BackTester();
		~BackTester();
		void performBackTest(Strategy *testStrat);
		void setStartingCash(float amount);
	private:
		std::vector<Quote> quoteData;
		int successfulTrades = 0;
		int unsuccessfulTrades = 0;
		int stockShares;
		float money = 0.00;
		DbMan dbMan;
};
