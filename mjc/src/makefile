CC = gcc
PROM = main
DEPS = $(shell find $(IDIR) -name "*.h")
SRC = $(shell find ./ -name "*.c")
OBJ = $(src:%.c=%.o) 

IDIR = ../include
CFLAG = -I$(IDIR)

LDIR = ../libs
LIBS = -lcJSON -lm -lpaho-mqtt3cs -lpthread

$(PROM) : $(OBJ)
	$(CC) -o $(PROM) $(OBJ) $(LIBS)

$(PROM).o: $(SRC).c $(DEPS)
	$(CC) -c $< -o $@
clean:
	rm -rf $(OBJ) $(PROM)
