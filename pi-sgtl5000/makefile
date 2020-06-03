OBJs := $(patsubst %.cpp, %.o, $(wildcard *.cpp)) 
DEPs := $(OBJs:%.o=%.d)
BIN  := example
CC  = g++
CFLAGS += --std=gnu++18 -Wall -Werror -O2
LDFLAGS += -lm
MAKEFLAGS += -j4

.PHONY: all
all: example

example:	$(OBJs) -lbcm2835 

.PHONY: clean
clean:
	@rm -fv example $(OBJs) $(DEPs) *.o

