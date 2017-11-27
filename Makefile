EXE = life
MAINSRC = LifeSchedule
MODULESRC = Activity
HEADERS = args
SRC = $(MAINSRC:%=%.cpp) $(MODULESRC:%=%.cpp)
OBJ = $(SRC:%.cpp=%.o)
COMPILEFLAGS = -Wall -Werror -g -std=c++11
COMPILER = g++ -c
COMPILE = $(COMPILER) $(COMPILEFLAGS)
LINKERFLAGS =
LINKER = g++ -o
LINK = $(LINKER) $(LINKERFLAGS)
REMOVE = rm -f

$(EXE): $(OBJ)
	$(LINK) $@ $<

$(OBJ): $(SRC) $(HEADERS)
	$(COMPILE) $<

run: $(EXE)
	echo "To Be Continued"

HELP.md: $(EXE)
	@ echo
	@ $(EXE) -h > $@
	@ cat $@

ci: spotless
	git add -A :/
	git commit -av
	git push
	git log --oneline --graph --all

clean:
	$(REMOVE) $(OBJ)

spotless: clean
	$(REMOVE) $(EXE)

.PHONY: clean spotless run ci
