CC=g++
CFLAGS= -O3 -fopenmp
DEPS =
OBJ = hw4_part2_test.o 
EXEC = hw4_part2_test
LIB = _hw4_part2
LIB_DIR = abc123_hw2_part2

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -I. -I./$(LIB_DIR)

$(EXEC): $(OBJ)
	module load gcc; \
	cd $(LIB_DIR) && $(MAKE);
	module load gcc; \
	$(CC) -o $@ $^ $(CFLAGS) -L./$(LIB_DIR)/ -l$(LIB) -L.

.PHONY: clean
clean:
	cd $(LIB_DIR) && $(MAKE) clean
	rm -f $(OBJ) $(EXEC)
