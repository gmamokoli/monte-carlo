CXX = g++
CXXFLAGS = -O2 -fopenmp -std=c++17
TARGET = montecarlo_pi

all: $(TARGET)

$(TARGET): src/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
