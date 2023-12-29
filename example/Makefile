# C++ Compile and Link
CXX := x86_64-w64-mingw32-g++
CXXFLAGS := -std=c++14 -Wall -m64 -Iinclude -IC:/SDL2/include -I../include/tmxlite -I../include

# Executable Setup
TARGET := Game.exe
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
KRAKEN_LIB := -L../ -lKraken
SDL_LIB := -LC:/SDL2/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
TMXLITE_LIB := -L../lib -ltmxlite.dll
all: $(TARGET)

# Compile Executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(KRAKEN_LIB) $(SDL_LIB) $(TMXLITE_LIB)

# Build Object Files
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Object and Executable Files
clean:
	del $(subst /,\,$(TARGET)) $(subst /,\,$(OBJ))
