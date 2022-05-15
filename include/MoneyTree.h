#pragma once
#include <string>

#include "TDA.h"
#include "DbMan.h"

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

		TDA tda;
		DbMan dbMan;
		bool scrapeThreadStop = false;

};
