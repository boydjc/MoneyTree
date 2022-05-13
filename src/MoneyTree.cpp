#include <iostream>
#include <chrono> // for time
#include <thread> // for time

#include "MoneyTree.h"

MoneyTree::MoneyTree() {
	// constructor
}
	
MoneyTree::~MoneyTree() {
	// deconstructor
}

void MoneyTree::mainLoop() {
	displayMenu();
	std::string userInput = getUserInput();
	processMenuChoice(std::stoi(userInput));
}

void MoneyTree::displayMenu() {
	std::cout << "Please choose an option" << std::endl;
	std::cout << "1. Get Historical Price" << std:: endl;
	std::cout << "2. Get Quote " << std::endl;
	std::cout << "3. Get Quotes " << std::endl;
	std::cout << "4. Monitor Mode" << std::endl;
	std::cout << "5. Paper Mode" << std::endl;
}

std::string MoneyTree::getUserInput() {
	std::string userChoice;
	std::cout << ": ";
	getline(std::cin, userChoice);
	return userChoice;
}

void MoneyTree::processMenuChoice(int userChoice) {
	switch(userChoice) {
		case 1: 
			printHistPrice();
			break;
		case 2:
			printQuote();
			break;
		case 3:
			printQuotes();
			break;
		case 4:
			monitor();
			break;
		case 5:
			paperTrade();
			break;
		default:
			std::cout << "Sorry. That is an invalid choice." << std::endl;
			break;
	}
	mainLoop();
}

void MoneyTree::printHistPrice() {
	std::cout << "Enter a ticker" << std::endl;
	std::string ticker = getUserInput();
	std::vector<Candle> histPriceData = tda.getHistPrice(ticker);
	for(int i=0; i<5; i++) {
		std::cout << "Date: " << histPriceData[i].date << std::endl;
		std::cout << "Open: " << histPriceData[i].open << std::endl;
		std::cout << "High: " << histPriceData[i].high << std::endl;
		std::cout << "Low: " << histPriceData[i].low << std::endl;
		std::cout << "Close: " << histPriceData[i].close << std::endl;
		std::cout << "Volume: " << histPriceData[i].volume << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
}

void MoneyTree::printQuote() {
	std::cout << "Enter a ticker" << std::endl;
	std::string ticker = getUserInput();
	Quote quote = tda.getQuote(ticker);
	std::cout << "-----------------------------------------" << std::endl;

	std::cout << "Symbol: " << quote.symbol << std::endl;
	std::cout << "Last Price: " << quote.lastPrice << "\t";
	std::cout << "Bid Price: " << quote.bidPrice << "\t";
	std::cout << "Ask Price: " << quote.askPrice << std::endl;
	std::cout << "Last Size: " << quote.lastSize << "\t\t";	
	std::cout << "Bid Size: " << quote.bidSize << "\t\t";
	std::cout << "Ask Size: " << quote.askSize << std::endl << std::endl;
}

void MoneyTree::printQuotes() {
	std::cout << "Enter some tickers" << std::endl;
	std::string ticker = getUserInput();
	std::vector<Quote> quotes = tda.getQuotes(ticker);
	for(int i=0; i<quotes.size(); i++) {
		std::cout << "Symbol: " << quotes[i].symbol << std::endl;
		if(quotes[i].assetMainType != "FOREX") {
			std::cout << "Last Price: " << quotes[i].lastPrice << std::endl;
			std::cout << "Last Size: " << quotes[i].lastSize << std::endl;
			std::cout << "Bid Price: " << quotes[i].bidPrice << std::endl;
			std::cout << "Bid Size: " << quotes[i].bidSize << std::endl;
			std::cout << "Ask Price: " << quotes[i].bidPrice << std::endl;
			std::cout << "Ask Size: " << quotes[i].askSize << std::endl;
			std::cout << "Total Volume: " << quotes[i].totalVolume << std::endl;
			std::cout << "--------------------------------" << std::endl;
		} else {
			std::cout << "Last Price: " << quotes[i].lastPriceInDouble << std::endl;
			std::cout << "Last Size: " << quotes[i].lastSizeInLong << std::endl;
			std::cout << "Bid Price: " << quotes[i].bidPriceInDouble << std::endl;
			std::cout << "Bid Size: " << quotes[i].bidSizeInLong << std::endl;
			std::cout << "Ask Price: " << quotes[i].bidPriceInDouble << std::endl;
			std::cout << "Ask Size: " << quotes[i].askSizeInLong << std::endl;
			std::cout << "--------------------------------" << std::endl;
		}
	}
}

void MoneyTree::monitor() {
	std::cout << "Enter a ticker" << std::endl;
	std::string ticker = getUserInput();
	std::cout << "MONITOR MODE: Press CTRL+C to stop!" << std::endl;

	bool stop = false;
	
	Quote lastQuote;
	Quote currentQuote = tda.getQuote(ticker);

	std::this_thread::sleep_for(std::chrono::seconds(1));
	
	while(!(stop)) {
		currentQuote = tda.getQuote(ticker);

		std::cout << "-----------------------------------------" << std::endl;

		std::cout << "Symbol: " << currentQuote.symbol << std::endl;
		std::cout << "Last Price: " << currentQuote.lastPrice << "\t";
		std::cout << "Bid Price: " << currentQuote.bidPrice << "\t";
		std::cout << "Ask Price: " << currentQuote.askPrice << std::endl;
		std::cout << "Last Size: " << currentQuote.lastSize << "\t\t";	
		std::cout << "Bid Size: " << currentQuote.bidSize << "\t\t";
		std::cout << "Ask Size: " << currentQuote.askSize << std::endl << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));

	} 
}

void MoneyTree::paperTrade() {
	std::cout << "Paper Mode" << std::endl;
	std::cout << "Enter a ticker" << std::endl;
	std::string ticker = getUserInput();

	double money;
	std::string userInput;

	std::cout << "Enter starting amount" << std::endl;
	std::cout << ":";
		
	getline(std::cin, userInput);

	money = std::stof(userInput);

	int stockShares = 0;

	std::cout << "Money: $" << money << std::endl;
	if(stockShares != 0) {
		std::cout << "Shares of " << ticker << ": " << stockShares << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;

	bool stop = false;
	
	Quote lastQuote;
	Quote currQuote = tda.getQuote(ticker);

	float buyAsk;
	float stopLoss;

	int lastTradeSize = 0;

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	while(!(stop)) {
				
		try {
			currQuote = tda.getQuote(ticker);

			std::cout << "-----------------------------------------" << std::endl;

			std::cout << "Symbol: " << currQuote.symbol << std::endl;
			std::cout << "Last Price: " << currQuote.lastPrice << "\t";
			std::cout << "Bid Price: " << currQuote.bidPrice << "\t";
			std::cout << "Ask Price: " << currQuote.askPrice << std::endl;
			std::cout << "Last Size: " << currQuote.lastSize << "\t\t";	
			std::cout << "Bid Size: " << currQuote.bidSize << "\t\t";
			std::cout << "Ask Size: " << currQuote.askSize << std::endl << std::endl;
					
			// Play strategy
			// if we have an uptick with an increase in volume then we will buy
			// if we have some stock with we encounter a down tick then we will sell
			if(currQuote.bidPrice > lastQuote.bidPrice && currQuote.bidSize > currQuote.askSize) {

				float percentToRisk = 0.20;

				float capitalToTrade = money * percentToRisk;

				int tradeSize = capitalToTrade / currQuote.askPrice;
					
				if(tradeSize != 0) {
					std::cout << "Bought " << tradeSize << " shares of "  << ticker << std::endl;
					stockShares += tradeSize;
					money -= (currQuote.askPrice * tradeSize);
					buyAsk = currQuote.askPrice;
					stopLoss = buyAsk - (buyAsk * 0.003);
					lastTradeSize = tradeSize;
				}

			}else if((currQuote.bidPrice < lastQuote.bidPrice && stockShares != 0 && currQuote.bidPrice != 0 && currQuote.bidPrice > buyAsk) || 
					 (currQuote.bidPrice != 0 && currQuote.bidPrice <= stopLoss)) {
				// sell at the bid
				std::cout << "Sold all shares of " << ticker << std::endl << std::endl;
				money += (stockShares * currQuote.bidPrice);
				stockShares = 0;
				buyAsk = 0;
				stopLoss = 0;
			}

			std::cout << "\033[1;32mMoney: $" << money << "\033[0m" << std::endl;
			if(stockShares != 0) {
				std::cout << "\033[1;33mShares of " << ticker << ": " << stockShares << "\033[0m" << std::endl;
				std::cout << "\033[1;31mStop loss: " << stopLoss << "\033[0m" << std::endl;
			}

			lastQuote = currQuote;

			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		} catch(...){
			std::cout << "Error Getting New Quote" << std::endl;
		}
	}
}
