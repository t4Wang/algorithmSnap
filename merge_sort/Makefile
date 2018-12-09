obj = main.o MergeSort.o Utils.o

# 链接
main: $(obj)
	gcc -g -o main $(obj)
# 编译
main.o: main.c MergeSort.h
	gcc -g -c main.c MergeSort.h
MergeSort.o: MergeSort.c MergeSort.h Utils.h
	gcc -g -c MergeSort.c MergeSort.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
# 清理
.PHONY: clean
clean:
	-del $(obj) MergeSort.h.gch Utils.h.gch
