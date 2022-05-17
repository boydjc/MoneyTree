#include <iostream>

#include "Strategy.h"

Strategy::Strategy() {
}

Strategy::~Strategy() {
	// deconstructor
}

bool Strategy::checkForBuy() {
	// virtual
	return false;
}

bool Strategy::checkForSell() {
	// virtual
	return false;
}

void Strategy::setCapRiskPercent(float value) {
	capRiskPercent = value;
}

void Strategy::setStopLoss(float value) {
	stopLoss = value;
}

float Strategy::getStopLoss() {
	return stopLoss;
}

float Strategy::getCapRiskPercent() {
	return capRiskPercent;
}

