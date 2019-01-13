CPPFLAGS += "-std=c++11"
objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

program: $(objects)
	clear
	g++ -o program $(objects)

.PHONY: clean run

clean:
	@rm program $(objects)

run::	program
run::
	@clear
	@./program
