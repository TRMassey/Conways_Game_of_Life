CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -03
LDFLAGS = -lboost_date_time

OBJS = assignment1.o Gameboard.o functions.o
SRCS = assignment1.cpp Gameboard.cpp functions.cpp
HEADERS = Gameboard.h functions.h

prog: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o prog

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -rf *.o prog

