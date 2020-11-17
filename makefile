src=ModuleA ModuleB
lpatha=/home/ubuntupc/file1111/Myproject/release/tool.so
lpathb=/home/ubuntupc/file1111/Myproject/release/outlook.so
all:$(src) a.out

$(src):ECHO
	make -C $@
ECHO:
	@echo $@

a.out:main.c
	gcc $^ -o ./release/$@  $(lpatha) $(lpathb)

