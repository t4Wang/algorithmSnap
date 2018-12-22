obj = main.o DisjSet.o Utils.o

# 链接
main: $(obj)
	gcc -g -o main $(obj)
# 编译
main.o: main.c DisjSet.h
	gcc -g -c main.c DisjSet.h
DisjSet.o: DisjSet.c DisjSet.h Utils.h
	gcc -g -c DisjSet.c DisjSet.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
# 清理
.PHONY: clean
clean:
	-del $(obj) DisjSet.h.gch Utils.h.gch
