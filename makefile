#target: dependencies
#	rule to build


# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time

OBJS=warMain.o warValidation.o game.o loadedDie.o die.o 
SRCS=warMain.cpp warValidation.cpp game.cpp loadedDie.cpp die.cpp
HEADERS=warValidation.hpp game.hpp loadedDie.hpp die.hpp

warMain: ${OBJS}
	${CXX} ${CXXFLAGS} -o warMain warMain.o warValidation.o game.o loadedDie.o die.o

warMain.o: warMain.cpp ${HEADERS}
	 ${CXX} ${CXXFLAGS} -c warMain.cpp

warValidation.o: warValidation.hpp
game.o: game.hpp
loadedDie.o: loadedDie.hpp
die.o: die.hpp

clean: ${OBJS}
	-rm *.o ${OBJS} warMain
