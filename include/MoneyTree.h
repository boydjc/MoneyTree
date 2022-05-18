#pragma once
#include <string>

#include "TDA.h"
#include "DbMan.h"
#include "LastSizeOp.h"

class MoneyTree {

	public:	
		MoneyTree();
		~MoneyTree();
		void mainLoop();
		

	private:
		void displayMenu();
		std::string getUserInput();
		void processMenuChoice(int userChoice);
		void printHistPrice();
		void printQuote();
		void printQuotes();
		void monitorMode(bool scrape=false);
		void scrapeMode(std::string ticker);
		void paperTrade();
		void paperTradeLoop(std::string ticker);

		TDA tda;
		DbMan dbMan;
		bool scrapeThreadStop = false;
		bool paperThreadStop = false;
		Strategy *userStrat;
		double money = 0.00;
		int stockShares = 0;
};
