CC=gcc
CXX=g++
INCLUDE=-I../../include -I/usr/local/mysql/include
#编译时选项
CFLAGS= -g -Wall -c $(INCLUDE)
#预处理命令
CPPFLAGS=-E -D
#C++编译时选项
CXXFLAGS=
#库选项
LDFLAGS=-lpthread -lcrypto -lmysqlclient -llibmysql.so -L../lib -L/usr/lib/mysql
#删除命令
RM=-rm -rf
.PHONY:clean print

SRC=$(wildcard *.c)
DES=$(patsubst %.c,%.o,$(SRC))
LIB=libnet.a

$(LIB):$(DES)
	$(AR) rcs $@ $^
	mv $@ ../../lib

$(DES):$(SRC)
	$(CXX) $(CFLAGS) $^

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
