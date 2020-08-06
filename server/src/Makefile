TARGET=server
CC=gcc
CXX=g++
INCLUDE=-I../include -I/usr/local/mysql/include
CFLAGS= -g -Wall -c $(INCLUDE)
CPPFLAGS=-E -D
CXXFLAGS=
LDFLAGS=-lpthread -lcrypto -lmysqlclient -llibmysql.so -L../lib -L/usr/lib/mysql
RM=-rm -rf
.PHONY:clean print

SRC=$(wildcard *.cpp) $(wildcard *.c)
RDES=$(patsubst %.c,%.o,$(SRC)) $(patsubst %.cpp,%.o,$(SRC))
DES=$(filter %.o,$(RDES))

$(TARGET):$(DES)
	g++ -o $(TARGET) $^ -L../lib -L/usr/local/mysql/lib \
	-lnet -lkernel -lmysql -lthreadpool -lpthread -lmysqlclient
$(DES):$(SRC)
	$(CXX) $(CFLAGS) $^

print:
	@echo "$(SRC)"
	@echo "$(DES)"

clean:
	$(RM) *.o
	$(RM) $(TARGET)

install:
	-sudo cp $(TARGET) /usr/bin
distclean:
	-sudo rm /usr/bin/$(TARGET) -rf
