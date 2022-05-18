#include <iostream>

#include "Strategy.h"

Strategy::Strategy() {
}

Strategy::~Strategy() {
	// deconstructor
}

bool Strategy::checkForBuy(Quote quot) {
	// virtual
	return false;
}

bool Strategy::checkForSell(Quote quote) {
	// virtual
	return false;
}

void Strategy::setCapRiskPercent(float value) {
	capRiskPercent = value;
}


float Strategy::getCapRiskPercent() {
	return capRiskPercent;
}

float Strategy::getStopLoss() {
	return stopLoss;
}

float Strategy::getStopLossPercent() {
	return stopLossPercent;
}

