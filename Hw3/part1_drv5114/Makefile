CC=g++
CFLAGS= -I. -O3 -mavx
DEPS = sd_thread.h
OBJ = sd_thread.o
LIB = lib_sd_thread.a

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB): $(OBJ)
	ar rcs $@ $(OBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) $(LIB)
