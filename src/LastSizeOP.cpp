#include "LastSizeOp.h"
#include <iostream>

LastSizeOp::LastSizeOp() {
	std::cout << "Hello from LastSizeOp Strategy" << std::endl;
	stopLoss = 0.20;
	capRiskPercent = 100.10;
}

LastSizeOp::~LastSizeOp() {
	// deconstructor
}

bool LastSizeOp::checkForBuy() {
	std::cout << "Checking for Buy signal on LastSizeOp" << std::endl;
	return true;
}

bool LastSizeOp::checkForSell() {
	std::cout << "Checking for sell signal on LastSizeOp" << std::endl;
	return true;
}	
