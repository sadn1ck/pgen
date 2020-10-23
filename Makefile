CXX = g++
CXX_FLAGS = -std=c++17

SRC = src/*.cpp
BUILD = bin
EXEC = pgen

all: clean build install

clean:
	rm -rf ./$(BUILD)
	rm ~/.local/bin/$(EXEC)

install:
	cp ./$(BUILD)/$(EXEC) ~/.local/bin/

build:
	mkdir $(BUILD)
	$(CXX) $(SRC) $(CXX_FLAGS) -o ./$(BUILD)/$(EXEC)