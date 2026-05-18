CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

SRC := src/system.cpp src/flow.cpp src/model.cpp
PRODUCT_BIN := bin/mySim
UNIT_TEST_BIN := bin/unit_tests
FUNCIONAL_TEST_BIN := bin/funcional_tests

.PHONY: all test unit funcional clean

all: $(PRODUCT_BIN) $(UNIT_TEST_BIN) $(FUNCIONAL_TEST_BIN)

$(PRODUCT_BIN): $(SRC) src/main.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) src/main.cpp -o $(PRODUCT_BIN)

$(UNIT_TEST_BIN): $(SRC) test/unit/main.cpp test/unit/unit_tests.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) test/unit/main.cpp test/unit/unit_tests.cpp -o $(UNIT_TEST_BIN)

$(FUNCIONAL_TEST_BIN): $(SRC) test/funcional/main.cpp test/funcional/funcional_tests.cpp
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) test/funcional/main.cpp test/funcional/funcional_tests.cpp -o $(FUNCIONAL_TEST_BIN)

test: unit funcional

unit: $(UNIT_TEST_BIN)
	./$(UNIT_TEST_BIN)

funcional: $(FUNCIONAL_TEST_BIN)
	./$(FUNCIONAL_TEST_BIN)

clean:
	rm -f $(PRODUCT_BIN) $(UNIT_TEST_BIN) $(FUNCIONAL_TEST_BIN)
