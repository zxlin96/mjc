cc = gcc
prom = main


LIB_PATH = $(ROOTDIR)./libs
INC = -I ./include -I ./src
src = $(shell find ./src -name "*.c")
obj = $(src:%.c=%.o)
LIBS = -L$(LIB_PATH) -lpthread -lcJSON -lpaho-mqtt3cs -lm
CFLAGS = -g -Wall
    
$(prom): $(obj)
	$(cc) -o $(prom) $(obj) $(CFLAGS) $(LIBS)

%.o: %.c
	$(cc) -c $< -o $@ $(CFLAGS) $(INC)

clean:
	rm -rf $(obj) $(prom)
