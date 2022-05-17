#include <iostream>
#include <typeinfo>
#include <string>


#include "DbMan.h"

DbMan::DbMan() {
}

DbMan::~DbMan() {

}

void DbMan::connect() {
	rc = sqlite3_open("../quote-data.db", &db);

	if(rc) {
		fprintf(stderr, "Could not connect to database: %s\n", sqlite3_errmsg(db));
	}
}

void DbMan::disconnect() {
	sqlite3_close(db);
}

int DbMan::quoteTableInsertionCallback(void *NotUsed, int argc, char **argv, char **azColName) {
	return 0;
}

void DbMan::insertToQuoteTable(Quote quote, std::string ticker) {
	std::string smt = "INSERT INTO " + ticker + " (SYMBOL,ASSET_MAIN_TYPE,"\
					  "ASSET_SUB_TYPE,ASSET_TYPE,EXCHANGE,EXCHANGE_NAME,DIV_DATE,"\
					  "SECURITY_STATUS,BID_ID,ASK_ID,DESCRIPTION,LAST_ID,PRODUCT,"\
					  "FUTURE_PRICE_FORMAT,FUTURE_TRADING_HOURS,FUTURE_EXPIRATION_DATE,"\
					  "CONTRACT_TYPE,"\
					  "DELIVERABLES,UV_EXPIRATION_TYPE,SETTLEMENT_TYPE,TRADING_HOURS,"\
					  "MARKET_MAKER,CUSIP,LAST_PRICE,OPEN_PRICE,HIGH_PRICE,LOW_PRICE,"\
					  "CLOSE_PRICE,BID_PRICE,NET_CHANGE,FIFTY_TWO_WEEK_HIGH,"\
					  "FIFTY_TWO_WEEK_LOW,PE_RATIO,DIV_AMOUNT,DIV_YIELD,FUTURE_PERCENT_CHANGE,"\
					  "MONEY_INTRINSIC_VALUE,MARK,TICK,FIFTY_WK_HIGH,FIFTY_WK_LOW,"\
					  "ASK_PRICE,VOLATILITY,FUTURE_SETTLEMENT_PRICE,STRIKE_PRICE,"\
					  "TIME_VALUE,DELTA,GAMMA,THETA,VEGA,RHO,THEORETICAL_OPTION_VALUE,"\
					  "UNDERLYING_PRICE,PERCENT_CHANGE,REGULAR_MARKET_LAST_PRICE,"\
					  "REGULAR_MARKET_NET_CHANGE,DIGITS,NAV,OPEN_INTEREST,FUTURE_MULTIPLIER,"\
					  "TICK_AMOUNT,TOTAL_VOLUME,BID_SIZE,ASK_SIZE,LAST_SIZE,MULTIPLIER,"\
					  "REGULAR_MARKET_LAST_SIZE,TRADE_TIME_IN_LONG,QUOTE_TIME_IN_LONG,"\
					  "BID_SIZE_IN_LONG,LAST_SIZE_IN_LONG,ASK_SIZE_IN_LONG,"\
					  "REGULAR_MARKET_TRADE_TIME_IN_LONG,BID_PRICE_IN_DOUBLE,"\
					  "ASK_PRICE_IN_DOUBLE,LAST_PRICE_IN_DOUBLE,HIGH_PRICE_IN_DOUBLE,"\
					  "LOW_PRICE_IN_DOUBLE,CLOSE_PRICE_IN_DOUBLE,OPEN_PRICE_IN_DOUBLE,"\
					  "NET_CHANGE_IN_DOUBLE,MONEY_INTRINSIC_VALUE_IN_DOUBLE,"\
					  "MARK_CHANGE_IN_DOUBLE,MARK_PERCENT_CHANGE_IN_DOUBLE,"\
					  "NET_PERCENT_CHANGE_IN_DOUBLE,REGULAR_MARKET_PERCENT_CHANGE_IN_DOUBLE,"\
					  "MULTIPLIER_IN_DOUBLE,STRIKE_PRICE_IN_DOUBLE,TIME_VALUE_IN_DOUBLE,"\
					  "DELTA_IN_DOUBLE,GAMMA_IN_DOUBLE,THETA_IN_DOUBLE,VEGA_IN_DOUBLE,"\
					  "RHO_IN_DOUBLE,CHANGE_IN_DOUBLE,FIFTY_TWO_WK_HIGH_IN_DOUBLE,"\
					  "FIFTY_TWO_WK_LOW_IN_DOUBLE) VALUES ('" + quote.symbol + "','" +
					  quote.assetMainType + "','" + quote.assetSubType + "','" + 
					  quote.assetType + "','" + quote.exchange + "','" +
					  quote.exchangeName + "','" + quote.divDate + "','" + quote.securityStatus + "','" +
					  quote.bidId + "','" + quote.askId + "','" + quote.description + "','" + 
					  quote.lastId + "','" + quote.product + "','" + quote.futurePriceFormat + "','" + 
					  quote.futureTradingHours + "','" +
					  quote.futureExpirationDate + "','" + quote.contractType + "','" + 
					  quote.deliverables + "','" + quote.uvExpirationType + "','" + quote.settlementType +
					  "','" + quote.tradingHours + "','" + quote.marketMaker + "','" +
					  quote.cusip + "'," + std::to_string(quote.lastPrice) + "," + std::to_string(quote.openPrice) + "," + 
					  std::to_string(quote.highPrice) + "," + std::to_string(quote.lowPrice) + "," + std::to_string(quote.closePrice) + "," + 
					  std::to_string(quote.bidPrice) + "," + std::to_string(quote.netChange) + "," + std::to_string(quote.fiftyTwoWeekHigh) + "," + 
					  std::to_string(quote.fiftyTwoWeekLow) + "," + std::to_string(quote.peRatio) + "," + std::to_string(quote.divAmount) + "," + 
					  std::to_string(quote.divYield) + "," + std::to_string(quote.futurePercentChange) + "," + std::to_string(quote.moneyIntrinsicValue) + "," +
					  std::to_string(quote.mark) + "," + std::to_string(quote.tick) + "," + std::to_string(quote.fiftyWkHigh) + "," + std::to_string(quote.fiftyWkLow) + "," + std::to_string(quote.askPrice) + "," + std::to_string(quote.volatility) + "," + std::to_string(quote.futureSettlementPrice) + "," +
					  std::to_string(quote.strikePrice) + "," + std::to_string(quote.timeValue) + "," + std::to_string(quote.delta) + "," + 
					  std::to_string(quote.gamma) + "," + std::to_string(quote.theta) + "," + std::to_string(quote.vega) + "," + 
					  std::to_string(quote.rho) + "," + std::to_string(quote.theoreticalOptionValue) + "," +
					  std::to_string(quote.underlyingPrice) + "," + std::to_string(quote.percentChange) + "," + std::to_string(quote.regularMarketLastPrice) + "," + 
					  std::to_string(quote.regularMarketNetChange) + "," + std::to_string(quote.digits) + "," + std::to_string(quote.nAV) + "," + 
					  std::to_string(quote.openInterest) + "," + std::to_string(quote.futureMultiplier) + "," + std::to_string(quote.tickAmount) + "," + 
					  std::to_string(quote.totalVolume) + "," + std::to_string(quote.bidSize) + "," + std::to_string(quote.askSize) + "," + 
					  std::to_string(quote.lastSize) + "," + std::to_string(quote.multiplier) + "," + 
					  std::to_string(quote.regularMarketLastSize) + "," + std::to_string(quote.tradeTimeInLong) + "," + 
					  std::to_string(quote.quoteTimeInLong) + "," + std::to_string(quote.bidSizeInLong) + "," + 
					  std::to_string(quote.lastSizeInLong) + "," + std::to_string(quote.askSizeInLong) + "," +
					  std::to_string(quote.regularMarketTradeTimeInLong) + "," + std::to_string(quote.bidPriceInDouble) + "," +
					  std::to_string(quote.askPriceInDouble) + "," + std::to_string(quote.lastPriceInDouble) + "," + 
					  std::to_string(quote.highPriceInDouble) + "," + std::to_string(quote.lowPriceInDouble) + "," + 
					  std::to_string(quote.closePriceInDouble) + "," + std::to_string(quote.openPriceInDouble) + "," + 
					  std::to_string(quote.netChangeInDouble) + "," + std::to_string(quote.moneyIntrinsicValueInDouble) + "," +
					  std::to_string(quote.markChangeInDouble) + "," + std::to_string(quote.markPercentChangeInDouble) + "," +
					  std::to_string(quote.netPercentChangeInDouble) + "," + std::to_string(quote.regularMarketPercentChangeInDouble) + "," +
					  std::to_string(quote.multiplierInDouble) + "," + std::to_string(quote.strikePriceInDouble) + "," + 
					  std::to_string(quote.timeValueInDouble) + "," + std::to_string(quote.deltaInDouble) + "," + 
					  std::to_string(quote.gammaInDouble) + "," + std::to_string(quote.thetaInDouble) + "," +
					  std::to_string(quote.vegaInDouble) + "," + std::to_string(quote.rhoInDouble) + "," + std::to_string(quote.changeInDouble) + "," +
					  std::to_string(quote.fiftyTwoWkHighInDouble) + "," + std::to_string(quote.fiftyTwoWkLowInDouble) + ");";
	
	connect();

	rc = sqlite3_exec(db, smt.c_str(), quoteTableInsertionCallback, 0, &zErrMsg);

	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} 

	disconnect();

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

		std::string smt = "CREATE TABLE " + ticker + "(ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
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
						  "TRADE_TIME_IN_LONG INTEGER NOT NULL, QUOTE_TIME_IN_LONG INTEGER NOT NULL,"\
					  	  "BID_SIZE_IN_LONG INTEGER NOT NULL, LAST_SIZE_IN_LONG INTEGER NOT NULL,"\
						  "ASK_SIZE_IN_LONG INTEGER NOT NULL, REGULAR_MARKET_TRADE_TIME_IN_LONG INTEGER NOT NULL,"\
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
