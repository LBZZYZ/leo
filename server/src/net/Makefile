INCLUDE=-I../../include -I/usr/local/mysql/include

.PHONY:clean print

SRC=$(wildcard *.c)
DES=$(patsubst %.c,%.o,$(SRC))
LIB=libnet.a

$(LIB):$(DES)
	$(AR) rcs $@ $^
	mv $@ ../../lib

$(DES):$(SRC)
	$(CC) -std=c99 $(CFLAGS) $^

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
