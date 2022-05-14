#include <iostream>
#include <typeinfo>


#include "DbMan.h"

DbMan::DbMan() {
}

DbMan::~DbMan() {

}

void DbMan::connect() {
	rc = sqlite3_open("../test.db", &db);

	if(rc) {
		fprintf(stderr, "Could not connect to database: %s\n", sqlite3_errmsg(db));
	}
}

void DbMan::disconnect() {
	sqlite3_close(db);
}

int DbMan::quoteTableCreationCallback(void *NotUsed, int argc, char **argv, char **azColName) {
	for(int i=0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void DbMan::createQuoteTable(std::string ticker) {
	if(checkForQuoteTable(ticker)) {
		std::cout << "Cannot Create Table: Table Already Exists" << std::endl;
	} else {
		connect();

		std::string smt = "CREATE TABLE " + ticker + "(ID INT PRIMARY KEY NOT NULL,"\
						  "SYMBOL TEXT NOT NULL, ASSET_MAIN_TYPE TEXT NOT NULL,"\
						  "ASSET_SUB_TYPE TEXT NOT NULL, ASSET_TYPE TEXT NOT NULL,"\
						  "EXCHANGE TEXT NOT NULL, EXCHANGE_NAME TEXT NOT NULL,"\
						  "DIV_DATE TEXT NOT NULL, SECURITY_STATUS TEXT NOT NULL,"\
						  "BID_ID TEXT NOT NULL, ASK_ID TEXT NOT NULL,"\
						  "DESCRIPTION TEXT NOT NULL, LAST_ID TEXT NOT NULL,"\
						  "PRODUCT TEXT NOT NULL,"\
						  "FUTURE_PRICE_FORMAT TEXT NOT NULL, FUTURE_TRADING_HOURS TEXT NOT NULL,"\
						  "FUTURE_EXPIRATION_DATE TEXT NOT NULL, CONTRACT_TYPE TEXT NOT NULL,"\
						  "DELIVERABLES TEXT NOT NULL, UV_EXPIRATION_TYPE TEXT NOT NULL,"\
						  "SETTLEMENT_TYPE TEXT NOT NULL, TRADING_HOURS TEXT NOT NULL,"\
						  "MARKET_MAKER TEXT NOT NULL, CUSIP TEXT NOT NULL,"\
						  "LAST_PRICE REAL NOT NULL, OPEN_PRICE REAL NOT NULL,"\
						  "HIGH_PRICE REAL NOT NULL, LOW_PRICE REAL NOT NULL,"\
						  "CLOSE_PRICE REAL NOT NULL, BID_PRICE REAL NOT NULL,"\
						  "NET_CHANGE REAL NOT NULL, FIFTY_TWO_WEEK_HIGH REAL NOT NULL,"\
						  "FIFTY_TWO_WEEK_LOW REAL NOT NULL, PE_RATIO REAL NOT NULL,"\
						  "DIV_AMOUNT REAL NOT NULL, DIV_YIELD REAL NOT NULL,"\
						  "FUTURE_PERCENT_CHANGE REAL NOT NULL, MONEY_INTRINSIC_VALUE REAL NOT NULL,"\
						  "MARK REAL NOT NULL, TICK REAL NOT NULL,"\
						  "FIFTY_WK_HIGH REAL NOT NULL, FIFTY_WK_LOW,"\
						  "ASK_PRICE REAL NOT NULL, VOLATILITY REAL NOT NULL,"\
						  "FUTURE_SETTLEMENT_PRICE REAL NOT NULL, STRIKE_PRICE REAL NOT NULL,"\
						  "TIME_VALUE REAL NOT NULL, DELTA REAL NOT NULL,"\
						  "GAMMA REAL NOT NULL, THETA REAL NOT NULL,"\
						  "VEGA REAL NOT NULL, RHO REAL NOT NULL,"\
						  "THEORETICAL_OPTION_VALUE REAL NOT NULL, UNDERLYING_PRICE REAL NOT NULL,"\
						  "PERCENT_CHANGE REAL NOT NULL, REGULAR_MARKET_LAST_PRICE REAL NOT NULL,"\
						  "REGULAR_MARKET_NET_CHANGE REAL NOT NULL, DIGITS INTEGER NOT NULL,"\
						  "NAV INTEGER NOT NULL, OPEN_INTEREST INTEGER NOT NULL,"\
						  "FUTURE_MULTIPLIER INTEGER NOT NULL, TICK_AMOUNT INTEGER NOT NULL,"\
						  "TOTAL_VOLUME INTEGER NOT NULL, BID_SIZE INTEGER NOT NULL,"\
						  "ASK_SIZE INTEGER NOT NULL, LAST_SIZE INTEGER NOT NULL,"\
						  "MULTIPLIER INTEGER NOT NULL, REGULAR_MARKET_LAST_SIZE INTEGER NOT NULL,"\
						  "BID_PRICE_IN_DOUBLE REAL NOT NULL, ASK_PRICE_IN_DOUBLE REAL NOT NULL,"\
						  "LAST_PRICE_IN_DOUBLE REAL NOT NULL, HIGH_PRICE_IN_DOUBLE REAL NOT NULL,"\
						  "LOW_PRICE_IN_DOUBLE REAL NOT NULL, CLOSE_PRICE_IN_DOUBLE REAL NOT NULL,"\
						  "OPEN_PRICE_IN_DOUBLE REAL NOT NULL, NET_CHANGE_IN_DOUBLE REAL NOT NULL,"\
						  "MONEY_INTRINSIC_VALUE_IN_DOUBLE REAL NOT NULL, MARK_CHANGE_IN_DOUBLE REAL NOT NULL,"\
						  "MARK_PERCENT_CHANGE_IN_DOUBLE REAL NOT NULL, NET_PERCENT_CHANGE_IN_DOUBLE REAL NOT NULL,"\
						  "REGULAR_MARKET_PERCENT_CHANGE_IN_DOUBLE REAL NOT NULL, MULTIPLIER_IN_DOUBLE REAL NOT NULL,"\
						  "STRIKE_PRICE_IN_DOUBLE REAL NOT NULL, TIME_VALUE_IN_DOUBLE REAL NOT NULL,"\
						  "DELTA_IN_DOUBLE REAL NOT NULL, GAMMA_IN_DOUBLE REAL NOT NULL,"\
						  "THETA_IN_DOUBLE REAL NOT NULL, VEGA_IN_DOUBLE REAL NOT NULL,"\
						  "RHO_IN_DOUBLE REAL NOT NULL, CHANGE_IN_DOUBLE REAL NOT NULL,"\
						  "FIFTY_TWO_WK_HIGH_IN_DOUBLE REAL NOT NULL, FIFTY_TWO_WK_LOW_IN_DOUBLE REAL NOT NULL);";

		rc = sqlite3_exec(db, smt.c_str(), quoteTableCreationCallback, 0, &zErrMsg);

		if(rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Table created successfully\n");
		}

		disconnect();
	}

}

int DbMan::quoteTableCheckCallback(void *NotUsed, int argc, char **argv, char **azColName) {	
	if(*argv[0] == '1') {
		return 4; // sql abort code
	}
	return 0;
}	

bool DbMan::checkForQuoteTable(std::string ticker) {

	connect();

	std::string smt = "SELECT count(type) FROM sqlite_master WHERE type='table' AND\
				name='" + ticker + "';";

	rc = sqlite3_exec(db, smt.c_str(), quoteTableCheckCallback, 0, &zErrMsg);
	
	disconnect();

	if(rc == 4) {
		return true;
	} 

	return false;

}
