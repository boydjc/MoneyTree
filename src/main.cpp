#include "MoneyTree.h"

int main() {

	MoneyTree mTree;

	mTree.mainLoop();

	//std::cout << "Please choose an option" << std::endl;
	//std::cout << "1. Get Historical Price" << std:: endl;
	//std::cout << "2. Get Quote " << std::endl;
	//std::cout << "3. Get Quotes " << std::endl;
	//std::cout << "4. Monitor Mode" << std::endl;
	//std::cout << "5. Paper Mode" << std::endl;

	//std::string userChoice;
	//std::cout << ": ";
	//getline(std::cin, userChoice);

	//if(userChoice == "1") {

	//	std::cout << "Enter a ticker: " << std::endl;
	
	//	std::string ticker;

	//	std::cout << ": ";
	//	getline(std::cin, ticker);

		// testing
	//	std::vector<Candle> histPriceData = testTda.getHistPrice(ticker);

	//	for(int i=0; i<5; i++) {
	//		std::cout << "Date: " << histPriceData[i].date << std::endl;
	//		std::cout << "Open: " << histPriceData[i].open << std::endl;
	//		std::cout << "High: " << histPriceData[i].high << std::endl;
	//		std::cout << "Low: " << histPriceData[i].low << std::endl;
	//		std::cout << "Close: " << histPriceData[i].close << std::endl;
	//		std::cout << "Volume: " << histPriceData[i].volume << std::endl;
	//		std::cout << "---------------------------------" << std::endl;
	//	}
	
	//} else if(userChoice == "2") {

	//	std::cout << "Enter a ticker: " << std::endl;
	
	//	std::string ticker;

	//	std::cout << ": ";
	//	getline(std::cin, ticker);


	//	Quote testQuote = testTda.getQuote(ticker);

	//	std::cout << "-----------------------------------------" << std::endl;

	//	std::cout << "Symbol: " << testQuote.symbol << std::endl;
	//	std::cout << "Last Price: " << testQuote.lastPrice << "\t";
	//	std::cout << "Bid Price: " << testQuote.bidPrice << "\t";
	//	std::cout << "Ask Price: " << testQuote.askPrice << std::endl;
	//	std::cout << "Last Size: " << testQuote.lastSize << "\t\t";	
	//	std::cout << "Bid Size: " << testQuote.bidSize << "\t\t";
	//	std::cout << "Ask Size: " << testQuote.askSize << std::endl << std::endl;


//	} else if(userChoice == "3") {

//		std::cout << "Enter some tickers: " << std::endl;
	
//		std::string tickers;

//		std::cout << ": ";
//		getline(std::cin, tickers);

//		std::vector<Quote> testQuotes = testTda.getQuotes(tickers);

//		for(int i=0; i<testQuotes.size(); i++) {
//			std::cout << "Symbol: " << testQuotes[i].symbol << std::endl;
//			if(testQuotes[i].assetMainType != "FOREX") {
//				std::cout << "Last Price: " << testQuotes[i].lastPrice << std::endl;
//				std::cout << "Last Size: " << testQuotes[i].lastSize << std::endl;
//				std::cout << "Bid Price: " << testQuotes[i].bidPrice << std::endl;
//				std::cout << "Bid Size: " << testQuotes[i].bidSize << std::endl;
//				std::cout << "Ask Price: " << testQuotes[i].bidPrice << std::endl;
//				std::cout << "Ask Size: " << testQuotes[i].askSize << std::endl;
//				std::cout << "Total Volume: " << testQuotes[i].totalVolume << std::endl;
//				std::cout << "--------------------------------" << std::endl;
//			} else {
//				std::cout << "Last Price: " << testQuotes[i].lastPriceInDouble << std::endl;
//				std::cout << "Last Size: " << testQuotes[i].lastSizeInLong << std::endl;
//				std::cout << "Bid Price: " << testQuotes[i].bidPriceInDouble << std::endl;
//				std::cout << "Bid Size: " << testQuotes[i].bidSizeInLong << std::endl;
//				std::cout << "Ask Price: " << testQuotes[i].bidPriceInDouble << std::endl;
//				std::cout << "Ask Size: " << testQuotes[i].askSizeInLong << std::endl;
//				std::cout << "--------------------------------" << std::endl;
//			}
//		}
//	} else if(userChoice == "4") {

//		std::cout << "Enter a ticker: " << std::endl;
//	
//		std::string ticker;
//
//		std::cout << ": ";
//		getline(std::cin, ticker);
//
//		std::cout << "MONITOR MODE: Press CTRL+C TO STOP" << std::endl;
//		
//		bool stop = false;
//	
//		Quote lastQuote;
//		Quote testQuote = testTda.getQuote(ticker);
//
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//	
//		while(!(stop)) {
//			testQuote = testTda.getQuote(ticker);
//
//			std::cout << "-----------------------------------------" << std::endl;
//
//			std::cout << "Symbol: " << testQuote.symbol << std::endl;
//			std::cout << "Last Price: " << testQuote.lastPrice << "\t";
//			std::cout << "Bid Price: " << testQuote.bidPrice << "\t";
//			std::cout << "Ask Price: " << testQuote.askPrice << std::endl;
//			std::cout << "Last Size: " << testQuote.lastSize << "\t\t";	
//			std::cout << "Bid Size: " << testQuote.bidSize << "\t\t";
//			std::cout << "Ask Size: " << testQuote.askSize << std::endl << std::endl;
//
//			std::ofstream outputFile("./outputFile.txt", std::ios::app);
//			
//			outputFile << "--------------------------------------------\n";
//			outputFile << "Symbol: " + testQuote.symbol + "\n";
//			outputFile << "Last Price: " + std::to_string(testQuote.lastPrice) + "\t";
//			outputFile << "Bid Price: " + std::to_string(testQuote.bidPrice) + "\t";
//			outputFile << "Ask Price: " + std::to_string(testQuote.askPrice) + "\n";
//			outputFile << "Last Size: " + std::to_string(testQuote.lastSize) + "\t\t";
//			outputFile << "Bid Size: " + std::to_string(testQuote.bidSize) + "\t\t";
//			outputFile << "Ask Size: " + std::to_string(testQuote.askSize) + "\n\n";
//
//			outputFile.close();
//
//			std::this_thread::sleep_for(std::chrono::milliseconds(500));
//
//		}
//		
//	}else if(userChoice == "5") {
//		std::cout << "Paper Mode" << std::endl;
//
//		std::cout << "Enter a ticker: " << std::endl;
//	
//		std::string ticker;
//
//		std::cout << ": ";
//		getline(std::cin, ticker);
//	
//		double money;
//		std::string userInput;
//
//		std::cout << "Enter starting amount" << std::endl;
//		std::cout << ":";
//		
//		getline(std::cin, userInput);
//
//		money = std::stof(userInput);
//
//		int stockShares = 0;
//
//		std::cout << "Money: $" << money << std::endl;
//		if(stockShares != 0) {
//			std::cout << "Shares of " << ticker << ": " << stockShares << std::endl;
//		}
//		std::cout << "-----------------------------------------" << std::endl;
//
//		bool stop = false;
//	
//		Quote lastQuote;
//		Quote testQuote = testTda.getQuote(ticker);
//
//		float buyAsk;
//		float stopLoss;
//
//		int lastTradeSize = 0;
//
//		std::this_thread::sleep_for(std::chrono::milliseconds(500));
//	
//		while(!(stop)) {
//				
//			try {
//				testQuote = testTda.getQuote(ticker);
//
//				std::cout << "-----------------------------------------" << std::endl;
//
//				std::cout << "Symbol: " << testQuote.symbol << std::endl;
//				std::cout << "Last Price: " << testQuote.lastPrice << "\t";
//				std::cout << "Bid Price: " << testQuote.bidPrice << "\t";
//				std::cout << "Ask Price: " << testQuote.askPrice << std::endl;
//				std::cout << "Last Size: " << testQuote.lastSize << "\t\t";	
//				std::cout << "Bid Size: " << testQuote.bidSize << "\t\t";
//				std::cout << "Ask Size: " << testQuote.askSize << std::endl << std::endl;
//					
//				// Play strategy
//				// if we have an uptick with an increase in volume then we will buy
//				// if we have some stock with we encounter a down tick then we will sell
//				if(testQuote.bidPrice > lastQuote.bidPrice && testQuote.bidSize > testQuote.askSize) {
//
//					float percentToRisk = 0.20;
//
//					float capitalToTrade = money * percentToRisk;
//
//					int tradeSize = capitalToTrade / testQuote.askPrice;
//					
//					if(tradeSize != 0) {
//						std::cout << "Bought " << tradeSize << " shares of "  << ticker << std::endl;
//						stockShares += tradeSize;
//						money -= (testQuote.askPrice * tradeSize);
//						buyAsk = testQuote.askPrice;
//						stopLoss = buyAsk - (buyAsk * 0.003);
//						lastTradeSize = tradeSize;
//					}
//
//				}else if((testQuote.bidPrice < lastQuote.bidPrice && stockShares != 0 && testQuote.bidPrice != 0 && testQuote.bidPrice > buyAsk) || 
//						 (testQuote.bidPrice != 0 && testQuote.bidPrice <= stopLoss)) {
//					// sell at the bid
//					std::cout << "Sold all shares of " << ticker << std::endl << std::endl;
//					money += (stockShares * testQuote.bidPrice);
//					stockShares = 0;
//					buyAsk = 0;
//					stopLoss = 0;
//				}
//
//				std::cout << "\033[1;32mMoney: $" << money << "\033[0m" << std::endl;
//				if(stockShares != 0) {
//					std::cout << "\033[1;33mShares of " << ticker << ": " << stockShares << "\033[0m" << std::endl;
//					std::cout << "\033[1;31mStop loss: " << stopLoss << "\033[0m" << std::endl;
//				}
//
//				lastQuote = testQuote;
//
//				std::this_thread::sleep_for(std::chrono::milliseconds(500));
//			} catch(...){
//				std::cout << "Error Getting New Quote" << std::endl;
//			}
//		}
//	}
	return 0;
}
