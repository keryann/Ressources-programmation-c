CC = gcc
OBJ = TP4.o liste_ptr.o
PROG = prog
CFLAGS = -Wall -g

${PROG} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${PROG}
liste_ptr.o : liste_ptr.c
	${CC} ${CFLAGS} -c liste_ptr.c
TP4.o : tp4.c liste_ptr.h
	${CC} ${CFLAGS} -c TP4.c liste_ptr.h
	
#suppression des fichiers temporaires
clean :
	rm -i *.o
	rm -i *.gch
	
mrproper : clean
	rm -i prog*