CXX = g++
CXXFLAGS = -std=c++11 -Wall 

# List of source files (replace these with your actual source files)
SRCS = caesar_cipher.cpp 
# Derive the names of object files from source files
OBJS = $(SRCS:.cpp=.o)

# Derive the names of executables from source files
EXECS = $(SRCS:.cpp=)

# Default target, will be executed when you just type 'make' in the terminal
all: $(EXECS)

# Rule to compile object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link the object files into the executable
%: %.o
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up intermediate object files and executables
clean:
	rm -f $(OBJS) $(EXECS)

.PHONY: all clean

