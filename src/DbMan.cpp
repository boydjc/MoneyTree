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

void DbMan::createQuoteTable(std::string ticker) {
	if(checkForQuoteTable(ticker)) {
		std::cout << "Cannot Create Table: Table Already Exists" << std::endl;
	} else {
		std::cout << "Table can be created!" << std::endl;
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

	std::cout << rc << std::endl;

	if(rc == 4) {
		return true;
	} 

	return false;

}
