#pragma once

#include <sqlite3.h>
#include "TDA.h"


class DbMan {

	public:
		DbMan();
		~DbMan();
		void connect();
		void disconnect();
		bool checkForQuoteTable(std::string ticker);
		void createQuoteTable(std::string ticker);
		void insertToQuoteTable(Quote quote, std::string ticker);

	private:
		static int quoteTableCheckCallback(void *NotUsed, int argc, char **argv, char **azColName);
		static int quoteTableCreationCallback(void *NotUsed, int argc, char **argv, char **azColName);
		static int quoteTableInsertionCallback(void *NotUsed, int argc, char **argv, char **azColName);

		sqlite3 *db;
		int rc;
		char *zErrMsg = 0;

};
