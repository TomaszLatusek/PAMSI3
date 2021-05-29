CPPFLAGS=-c -g -pedantic -std=c++17
OBJS=main.o Board.o AI.o Game.o
EXEC=open

__start__: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJS)
	g++ -o $(EXEC) $(OBJS)

main.o: main.cpp Board.hh
	g++ ${CPPFLAGS} -o main.o main.cpp

Board.o: Board.cpp Board.hh
	g++ ${CPPFLAGS} -o Board.o Board.cpp

AI.o: AI.cpp AI.hh
	g++ ${CPPFLAGS} -o AI.o AI.cpp

Game.o: Game.cpp Game.hh
	g++ ${CPPFLAGS} -o Game.o Game.cpp

clear:
	rm $(EXEC) $(OBJS)
