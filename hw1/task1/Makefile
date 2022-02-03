CC=g++
CFLAGS= -O3 -mavx -std=c++11
DEPS = 
OBJ = benchmark_template.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

benchmark_template: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) benchmark_template
