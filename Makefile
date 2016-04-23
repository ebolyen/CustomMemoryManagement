CFLAGS := -g++ -Wall
CC := gcc
BUILDDIR = build

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

TARGET := bin/thing

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
