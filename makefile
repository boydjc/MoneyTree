build:
	g++ -o ./bin/main -lcurl -I./include/ -I../TDACPP/include/ ./src/* ../TDACPP/src/TDA.cpp
