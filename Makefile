CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = raytracing_in_one_weekend/main.cpp
OUT = build/raytracer

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

render: all
	./$(OUT) > renders/latest.ppm
	convert renders/latest.ppm renders/latest.png

clean:
	rm -rf build
	rm -f renders/latest.ppm

