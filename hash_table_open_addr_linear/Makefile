obj = main.o Hash.o Utils.o

# 链接
main: $(obj)
	gcc -g -o main $(obj)
# 编译
main.o: main.c Hash.h
	gcc -g -c main.c Hash.h
Hash.o: Hash.c Hash.h Utils.h
	gcc -g -c Hash.c Hash.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
# 清理
.PHONY: clean
clean:
	-del $(obj) Hash.h.gch Utils.h.gch
