# Executable Setup
TARGET := Game
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
INCLUDE_DIRS := -Iinclude -I../bld/_deps/sdl-src/include -I../bld/_deps/sdl_ttf-src -I../bld/_deps/sdl_mixer-src/include -I../bld/_deps/sdl_image-src/include -I../bld/_deps/tmxlite-src/tmxlite/include -I../include
CXXFLAGS := -std=c++14 -Wall $(INCLUDE_DIRS)

LINK_DIRS := -L../bld -L../bin -L../bld/_deps/sdl_image-build/ -L../bld/_deps/sdl_mixer-build/ -L../bld/_deps/sdl_ttf-build -L../bld/_deps/freetype-build
KRAKEN_LIB := -lKraken
SDL_LIB := -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
TMXLITE_LIB := -ltmxlite -lfreetype
ifeq ($(OS), Windows_NT)
  TMXLITE_LIB += -lz -lbz2 -lwinmm -lbrotlidec
endif
all: $(TARGET)

# Compile Executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LINK_DIRS) $(KRAKEN_LIB) $(SDL_LIB) $(TMXLITE_LIB)

# Build Object Files
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Object and Executable Files
clean:
	del $(subst /,\,$(TARGET)) $(subst /,\,$(OBJ))
