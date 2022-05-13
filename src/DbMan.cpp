#include <iostream>

#include "DbMan.h"

DbMan::DbMan() {
	std::cout << "Hello from DbMan!" << std::endl;
}

DbMan::~DbMan() {

}

void DbMan::connect() {
	rc = sqlite3_open("../test.db", &db);

	std::cout << rc << std::endl;

	if(!(rc)) {
		std::cout << "Successfully connected!" << std::endl;
	} else { 
		fprintf(stderr, "Could not connect to database: %s\n", sqlite3_errmsg(db));
	}
}

void DbMan::disconnect() {
	sqlite3_close(db);
}
