CC=g++
CFLAGS= -O3 -mavx -std=c++11
DEPS = 
OBJ = hw1_task1_drv5114.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hw1_task1_drv5114: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) hw1_task1_drv5114
