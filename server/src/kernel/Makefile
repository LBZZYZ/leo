.PHONY:clean print

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(SRC))
LIB=libkernel.a

$(LIB):$(OBJ)
	$(AR) rcs $@ $^
	mv $@ ../../lib

$(OBJ):$(SRC)
	$(CC) $(CFLAGS) $^

print:
	@echo "$(SRC)"
	@echo "$(OBJ)"
clean:
	$(RM) *.o

install:
	-sudo cp $(TARGET) /usr/bin
distclean:
	-sudo rm /usr/bin/$(TARGET) -rf
