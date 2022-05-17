#include "MoneyTree.h"
#include "LastSizeOp.h"

int main() {

	MoneyTree mTree;

	mTree.mainLoop();

	//Strategy *lastSizeOpStrat = new LastSizeOp();
	//lastSizeOpStrat->checkForBuy();
	//lastSizeOpStrat->checkForSell();
	//std::cout << lastSizeOpStrat->getCapRiskPercent() << std::endl;
	//std::cout << lastSizeOpStrat->getStopLoss() << std::endl;
	//delete lastSizeOpStrat;

	return 0;
}
