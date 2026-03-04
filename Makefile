CXX := g++
CXXFLAGS := -std=c++17
SRC := src/cacheSim.cpp
BIN := cacheSim

.PHONY: all clean run

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(BIN)
	rm -f output/out output/.tmp_out