CC=gcc
CXX=g++
INCLUDE=-I../../include -I/usr/include/mysql/
CFLAGS= -g -Wall -c $(INCLUDE)
CPPFLAGS=-E -D
CXXFLAGS=
RM=-rm -rf
.PHONY:clean print

SRC=$(wildcard *.cpp) $(wildcard *.c)
RDES=$(patsubst %.c,%.o,$(SRC)) $(patsubst %.cpp,%.o,$(SRC))
DES=$(filter %.o,$(RDES))
LIB=libmysql.a

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
