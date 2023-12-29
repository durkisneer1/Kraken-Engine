# C++ Compile and Link
CXX := x86_64-w64-mingw32-g++
CXXFLAGS := -std=c++14 -Wall -m64 -Iinclude -IC:/SDL2/include -Iinclude/tmxlite

# Lib Setup
TARGET := Kraken.lib
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
all: $(TARGET)

# Compile Lib
$(TARGET): $(OBJ)
	ar rcs $@ $^

# Build Object Files
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Object and Lib Files
clean:
	del $(subst /,\,$(TARGET)) $(subst /,\,$(OBJ))
