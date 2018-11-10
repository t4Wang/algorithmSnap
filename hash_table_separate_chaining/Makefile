# 链接
main: main.o Hash.o Utils.o
	gcc -g -o main main.o Hash.o Utils.o
# 编译
main.o: main.c Hash.h
	gcc -g -c main.c Hash.h
Hash.o: Hash.c Hash.h Utils.h
	gcc -g -c Hash.c Hash.h
Utils.o: Utils.c Utils.h
	gcc -g -c Utils.c Utils.h
