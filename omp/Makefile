# GCC compiler
CC=g++

# compilation flags (none)
LDFLAGS=-fopenmp

# source file
SOURCE=./square_sum_omp.cpp

# binary name
EXEC=square_sum_omp.exe

all:
	$(CC) $(LDFLAGS) $(SOURCE) -o $(EXEC)
	@echo -e "----- COMPILATION DONE -----"

clean:
	rm -r $(EXEC)