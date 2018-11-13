obj = main.o Heap.o Utils.o

# 链接
main: $(obj)
	gcc -g -o main $(obj)
# 编译
main.o: main.c Heap.h
	gcc -g -c main.c Heap.h
Heap.o: Heap.c Heap.h Utils.h
	gcc -g -c Heap.c Heap.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
# 清理
.PHONY: clean
clean:
	-del $(obj) Heap.h.gch Utils.h.gch
