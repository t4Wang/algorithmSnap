obj = main.o ShellSort.o Utils.o

# 链接
main: $(obj)
	gcc -g -o main $(obj)
# 编译
main.o: main.c ShellSort.h
	gcc -g -c main.c ShellSort.h
ShellSort.o: ShellSort.c ShellSort.h Utils.h
	gcc -g -c ShellSort.c ShellSort.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
# 清理
.PHONY: clean
clean:
	-del $(obj) ShellSort.h.gch Utils.h.gch
