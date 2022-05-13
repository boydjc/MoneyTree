build:
	g++ -o ./bin/main -lcurl -lsqlite3 -I./include/ -I../TDACPP/include/ ./src/* ../TDACPP/src/TDA.cpp
