all: main.o

main.o: disciplina.o pessoas.o
	gcc main.c modulo_disciplina.o modulo_pessoas.o -o main

disciplina.o: 
	gcc -c modulo_disciplina.c 

pessoas.o:
	gcc -c modulo_pessoas.c modulo_disciplina.o 

rm: 
	rm *.o