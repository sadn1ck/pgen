CXX = g++
CXX_FLAGS = -std=c++17

SRC = src/*.cpp
INCLUDE := include/

BUILD = build
EXEC = pgen

all: clean build install

clean:
	@echo "-> Removing build files and copied binary"
	@rm -rf ./$(BUILD)
	@rm -f ~/.local/bin/$(EXEC)

build:
	@echo "-> Creating build directory"
	@mkdir -p $(BUILD)
	@echo "-> Building..."
	$(CXX) -I$(INCLUDE) $(SRC) $(CXX_FLAGS) -o ./$(BUILD)/$(EXEC)

install:
	@echo "-> Copying binary to ~/.local/bin"
	@cp ./$(BUILD)/$(EXEC) ~/.local/bin/
