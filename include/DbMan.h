#pragma once

#include <sqlite3.h>

class DbMan {

	public:
		DbMan();
		~DbMan();
		void connect();
		void disconnect();

	private:
		sqlite3 *db;
		int rc;
		char *zErrMsg = 0;

};
