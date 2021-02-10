#define dir var
export ROOT_DIR := ./
export INCLUDE_DIR := $(ROOT_DIR)/include
export LIB_DIR := $(ROOT_DIR)/lib
export SOURCE_DIR := $(ROOT_DIR)/src

SUB_DIRS += $(ROOT_DIR)/src/net
SUB_DIRS += $(ROOT_DIR)/src/kernel 
SUB_DIRS += $(ROOT_DIR)/src/threadpool 
SUB_DIRS += $(ROOT_DIR)/src/mysql 
SUB_DIRS += $(ROOT_DIR)/src 
SUB_DIRS += $(ROOT_DIR)/src/ccl-0.1.1


#define complite flags
export TARGET := server
export CC := gcc
export CXX := g++
export CFLAGS := -g -Wall -c $(INCLUDE_DIR)
export CPPFLAGS := -E -D
export LDFLAGS := -L../lib -L/usr/lib64/mysql -lnet -lkernel -lmysql -lthreadpool -lpthread -lmysqlclient -lccl
export RM := -rm -rf

.PHONY:subdirs
.PHONY:$(SUB_DIRS)
.PHONY:clean

subdirs:
	$(SUB_DIRS)

$(SUB_DIRS):
	@+make -C $@

clean:
	@for i in $(SUB_DIRS);do (cd $$i && make clean) || exit "$$?";done
	@rm -rf $(LIB_DIR)/*
	
	
