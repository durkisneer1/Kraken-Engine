
CXX := x86_64-w64-mingw32-g++
SRC_DIR := src
INCLUDE_DIR := include
SDL2_INCLUDE_DIR := C:/SDL2/include
SDL2_LIB_DIR := C:/SDL2/lib

CXXFLAGS := -std=c++17 -Wall -Werror -m64 -I$(INCLUDE_DIR) -I$(SDL2_INCLUDE_DIR)
TARGET := DurkGame.lib
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:.cpp=.o)
LIB := $(wildcard $(SDL2_LIB_DIR)/*.lib)

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^ $(LIB)

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del $(subst /,\,$(TARGET)) $(subst /,\,$(OBJ))
