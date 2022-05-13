#include <iostream>

#include "DbMan.h"

DbMan::DbMan() {
	std::cout << "Hello from DbMan!" << std::endl;
}

DbMan::~DbMan() {

}

void DbMan::testDb() {
	sqlite3 *db;
	int rc;

	rc = sqlite3_open("../test.db", &db);

	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}else {
		fprintf(stderr, "Opened database successfully\n");
	}	

	sqlite3_close(db);
}
