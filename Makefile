CC=g++
C=gcc
CFLAGS=-std=c++11 -Wall

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: main

####################################################
#                                                  #
#                       DAOS                       #
#                                                  #
####################################################


####################################################
#                                                  #
#                     VIEWS                        #
#                                                  #
####################################################

# Main Screen
MainScreen.o: ${INCLUDE_DIR}/views/MainScreen.hpp ${SRC_DIR}/views/MainScreen.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/MainScreen.cpp -o ${BUILD_DIR}/MainScreen.o


####################################################
#                                                  #
#                     MODELS                       #
#                                                  #
####################################################

# Carta
Carta.o: ${INCLUDE_DIR}/models/Carta.hpp ${SRC_DIR}/models/Carta.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Carta.cpp -o ${BUILD_DIR}/Carta.o


####################################################
#                                                  #
#                  	EXCEPTIONS                     #
#                                                  #
####################################################

# General Exceptions
Exceptions.o: ${INCLUDE_DIR}/exceptions/Exception.hpp ${SRC_DIR}/exceptions/Exception.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/exceptions/Exception.cpp -o ${BUILD_DIR}/Exceptions.o
	
####################################################
#                                                  #
#                       APP                        #
#                                                  #
####################################################

# main
main.o: ${INCLUDE_DIR}/exceptions/Exception.hpp ${INCLUDE_DIR}/views/MainScreen.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# app
main: Exceptions.o MainScreen.o main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/main ${BUILD_DIR}/*.o


# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean_linux:
	rm -rf ${BUILD_DIR}/*.o 

clean_windows:
	del /S "%dir%\build\*.o"

run:
	./build/main.exe
