CC=g++
CFLAGS= -O3 -pthread -fopenmp
DEPS =
OBJ = main.o calcSd.o
EXEC = sd_test
LIB = _sd_thread
LIB_DIR = abc123_threadSd

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
