obj = main.o HeapSort.o Utils.o

# 链接
main: $(obj)
	gcc -g -o main $(obj)
# 编译
main.o: main.c HeapSort.h
	gcc -g -c main.c HeapSort.h
HeapSort.o: HeapSort.c HeapSort.h Utils.h
	gcc -g -c HeapSort.c HeapSort.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
# 清理
.PHONY: clean
clean:
	-del $(obj) HeapSort.h.gch Utils.h.gch
