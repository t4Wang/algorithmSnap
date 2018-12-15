obj = main.o QuickSort.o Utils.o

# 链接
main: $(obj)
	gcc -g -o main $(obj)
# 编译
main.o: main.c QuickSort.h
	gcc -g -c main.c QuickSort.h
QuickSort.o: QuickSort.c QuickSort.h Utils.h
	gcc -g -c QuickSort.c QuickSort.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
# 清理
.PHONY: clean
clean:
	-del $(obj) QuickSort.h.gch Utils.h.gch
