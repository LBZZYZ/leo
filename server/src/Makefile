INCLUDE=-I../include -I/usr/local/mysql/include

.PHONY:clean print

SRC=$(wildcard *.cpp) $(wildcard *.c)
RDES=$(patsubst %.c,%.o,$(SRC)) $(patsubst %.cpp,%.o,$(SRC))
DES=$(filter %.o,$(RDES))

$(TARGET):$(DES)
	gcc -o $(TARGET) $^ $(LDFLAGS)
$(DES):$(SRC)
	$(CC) $(CFLAGS) $^

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
