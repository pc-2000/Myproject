srcfile= $(wildcard *.c)
objfile=$(patsubst %.c,%.so,$(srcfile))
all:$(objfile)

%.so:%.c
	gcc -fPIC -shared $^ -o  ../release/$@
