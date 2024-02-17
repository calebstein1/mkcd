ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

mkcd :
	cc -o mkcd mkcd.c

install:
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 755 mkcd $(DESTDIR)$(PREFIX)/bin/
	@echo ""
	@echo "***Make sure you add the following line to your .bashrc or .zshrc***"
	@echo "\talias mkcd=exec mkcd"

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/mkcd

clean:
	rm -f mkcd
