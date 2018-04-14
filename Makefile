EXE = Life
MAINSRC = LifeSchedule
MODULESRC = Activity
HEADERS =
SRC = $(MAINSRC: %=%.cpp) $(MODULESRC: %=%.cpp)
OBJ = $(SRC: %.cpp=%.o)
COMPILEFLAGS = -Wall -Werror -g
COMPILER = g++ -c
COMPILE = $(COMPILER) $(COMPILEFLAGS)
LINKERFLAGS =
LINKER = g++ -o
LINK = $(LINKER) $(LINKERFLAGS)
REMOVE = rm -f

$(EXE): $(OBJ)
	$(LINK) $@ $^

$(OBJ): $(SRC) $(HEADERS)
	$(COMPILE) $(SRC)

run: $(EXE)
	echo "To Be Continued"

clean:
	$(REMOVE) $(OBJ)

spotless: clean
	$(REMOVE) $(EXE)

.PHONY: clean spotless run
