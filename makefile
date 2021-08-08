all: indexer

indexer: arv_avl.o main.o
	gcc arv_avl.o main.o -lm -o indexer

arv_avl.o: arv_avl.c arv_avl.h
	gcc -c arv_avl.c

main.o: main.c arv_avl.h
	gcc -c main.c

clear:
	rm -rf *.o indexer


