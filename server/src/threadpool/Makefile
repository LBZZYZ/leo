.PHONY:clean print

SRC=$(wildcard *.c)
DES=$(patsubst %.c,%.o,$(SRC))
LIB=libthreadpool.a

$(LIB):$(DES)
	$(AR) rcs $@ $^
	mv $@ ../../lib


$(DES):$(SRC)
	$(CC) $(CFLAGS) $^

print:
	@echo "$(SRC)"
	@echo "$(DES)"

clean:
	$(RM) *.o

install:
	-sudo cp $(TARGET) /usr/bin
distclean:
	-sudo rm /usr/bin/$(TARGET) -rf
#-------------------------------------------------------
