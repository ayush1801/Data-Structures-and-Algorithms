compRecMS: mainrec.o merge.o mergerec.o
	gcc mainrec.o mergerec.o merge.o -o recursiveMerge

compIterMS: mainiter.o merge.o mergeitr.o
	gcc mainiter.o mergeitr.o merge.o -o iterativeMerge 

runRecMS : compRecMS
	./recursiveMerge

runIterMS : compIterMS
	./iterativeMerge

mainrec.o : mainrec.c
	gcc -c mainrec.c

mainiter.o : mainiter.c
	gcc -c mainiter.c

mergerec.o : mergerec.c merge.h
	gcc -c mergerec.c

mergeitr.o : mergeitr.c merge.h
	gcc -c mergeitr.c

merge.o : merge.c
	gcc -c merge.c

comparer.o : compare.c
	gcc -c compare.c

compare : compare.o merge.o mergerec.o mergeitr.o
	gcc compare.o mergerec.o mergeitr.o merge.o -o compareMerge
	./compareMerge
