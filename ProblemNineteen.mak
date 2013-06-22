#ProblemNineteen.mak
CC = gcc
WARNINGS = -Wall

all: ProblemNineteen.exe

ProblemNineteen.exe: ProblemNineteen.o
	$(CC) $(WARNINGS) ProblemNineteen.o -o ProblemNineteen.exe
	
ProblemNineteen.o: ProblemNineteen.c
	$(CC) -c ProblemNineteen.c
	
clean:
	rm -rf *o ProblemNineteen.exe