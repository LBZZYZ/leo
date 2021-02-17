.PHONY:clean print

SRC := $(wildcard *.cpp) $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC)) $(patsubst %.cpp,%.o,$(SRC))
DES := $(filter %.o,$(OBJ))

$(TARGET):$(DES)
	$(CC) -o $(TARGET) $^ $(LDFLAGS)
	
$(DES):$(SRC)
	$(CC) $(CFLAGS) $^

print:
	@echo "$(SRC)"
	@echo "$(DES)"

clean:
	$(RM) $(OBJ)
	$(RM) $(TARGET)

install:
	-sudo cp $(TARGET) /usr/bin
distclean:
	-sudo rm /usr/bin/$(TARGET) -rf
