CC=g++
C=gcc
CFLAGS=-std=c++11 -Wall

PROGRAM  = ./program
BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
NCURSES_COMPILE_PARAMS = -static -D_GNU_SOURCE -D_DEFAULT_SOURCE -I ./libs/include/ -I ./libs/include/ncurses/ -L ./libs/lib/ -lncurses -ltinfo
# TEST_DIR = ./test

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
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/MainScreen.cpp -o ${BUILD_DIR}/MainScreen.o ${NCURSES_COMPILE_PARAMS}

# UI Manager
UIManager.o: ${INCLUDE_DIR}/views/UIManager.hpp ${SRC_DIR}/views/UIManager.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/views/UIManager.cpp -o ${BUILD_DIR}/UIManager.o ${NCURSES_COMPILE_PARAMS}


####################################################
#                                                  #
#                     MODELS                       #
#                                                  #
####################################################

# Mesa
CartaNaMesa.o: ${INCLUDE_DIR}/models/CartaNaMesa.hpp ${SRC_DIR}/models/CartaNaMesa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/CartaNaMesa.cpp -o ${BUILD_DIR}/CartaNaMesa.o

# Mesa
Mesa.o: ${INCLUDE_DIR}/models/Mesa.hpp ${SRC_DIR}/models/Mesa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Mesa.cpp -o ${BUILD_DIR}/Mesa.o

# Baralho
Baralho.o: ${INCLUDE_DIR}/models/Baralho.hpp ${SRC_DIR}/models/Baralho.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Baralho.cpp -o ${BUILD_DIR}/Baralho.o

# Carta
Carta.o: ${INCLUDE_DIR}/models/Carta.hpp ${SRC_DIR}/models/Carta.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Carta.cpp -o ${BUILD_DIR}/Carta.o

# Jogador
Jogador.o: ${INCLUDE_DIR}/models/Jogador.hpp ${SRC_DIR}/models/Jogador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Jogador.cpp -o ${BUILD_DIR}/Jogador.o
	

####################################################
#                                                  #
#                   CONTROLLERS                    #
#                                                  #
####################################################


# Carta
Bot.o: ${INCLUDE_DIR}/controllers/Bot.hpp ${SRC_DIR}/controllers/Bot.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/controllers/Bot.cpp -o ${BUILD_DIR}/Bot.o

# Carta
Humano.o: ${INCLUDE_DIR}/controllers/Humano.hpp ${SRC_DIR}/controllers/Humano.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/controllers/Humano.cpp -o ${BUILD_DIR}/Humano.o
	
# Rodada
Rodada.o: ${INCLUDE_DIR}/controllers/Rodada.hpp ${SRC_DIR}/controllers/Rodada.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/controllers/Rodada.cpp -o ${BUILD_DIR}/Rodada.o

# Partida
Partida.o: ${INCLUDE_DIR}/controllers/Partida.hpp ${SRC_DIR}/controllers/Partida.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/controllers/Partida.cpp -o ${BUILD_DIR}/Partida.o

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

# test
test.o: ${SRC_DIR}/teste.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/teste.cpp -o ${BUILD_DIR}/test/main.o ${NCURSES_COMPILE_PARAMS}
#test
test: test.o Exceptions.o MainScreen.o Partida.o Rodada.o Humano.o Mesa.o Baralho.o CartaNaMesa.o Carta.o Bot.o Jogador.o
	${CC} ${CFLAGS} ${SRC_DIR}/teste.cpp -o ${BUILD_DIR}/test/main ${BUILD_DIR}/*.o 
	${BUILD_DIR}/test/main 

# main
main.o: ${INCLUDE_DIR}/exceptions/Exception.hpp ${INCLUDE_DIR}/views/MainScreen.hpp ${PROGRAM}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${PROGRAM}/main.cpp -o ${BUILD_DIR}/program/main.o ${NCURSES_COMPILE_PARAMS}

# app
main: main.o Exceptions.o MainScreen.o Partida.o Rodada.o Humano.o Mesa.o Baralho.o CartaNaMesa.o Carta.o Bot.o Jogador.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/program/main ${BUILD_DIR}/*.o ${BUILD_DIR}/program/*.o ${NCURSES_COMPILE_PARAMS}
	${BUILD_DIR}/program/main 


# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it 
clean: 
	rm -rf ${BUILD_DIR}/*.o    

clean_windows:
	del /S "%dir%\build\*.o"    

run:
	./build/program/main

run_windows:
	./build/program/main.exe

cleantest: 
	rm -rf ${TEST_DIR}/*.o    

cleantest_windows:
	del /S "%dir%\test\*.o"  

runtest:
	./test/main

runtest_windows:
	./test/main.exe