CC=clang++

all: main.cpp
	$(CC) -o powerpend main.cpp

.PHONY: install
install: powerpend
	mkdir /opt/powerpend
	cp powerpend /opt/powerpend/
	ln /opt/powerpend/powerpend /usr/local/bin/


.PHONY: uninstall
	uninstall:
	rm -f /usr/local/bin
	rm -rf /opt/powerpend/

release: all
	tar cvfz powerpend.tar.gz powerpend
	mv powerpend.tar.gz ../release/

