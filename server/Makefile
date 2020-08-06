SUBDIR = ./src/net ./src/kernel ./src/threadpool ./src/mysql ./src

.PHONY:subdirs $(SUBDIR) clean
subdirs:$(SUBDIR)

$(SUBDIR):
	@+make -C $@
clean:
	@for i in $(SUBDIR);do (cd $$i && make clean) || exit "$$?";done
	rm ./lib/*
#	$(MAKE) -C $(SUBDIR) $@ clean
	
	
