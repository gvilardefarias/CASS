arqui = ../rt_nonfinite.cpp \
../processamentoEMG.cpp \
../processamentoEMG_terminate.cpp \
../processamentoEMG_initialize.cpp \

run:
	g++ -c diff.cpp
	g++ -c mean.cpp
	g++ -c median.cpp
	g++ -c nullAssignment.cpp
	g++ -c rtGetInf.cpp
	g++ -c rtGetNaN.cpp
	g++ -c sign.cpp
	g++ -c sortIdx.cpp
	g++ -c std.cpp
	g++ -c sum.cpp
	g++ -c rt_nonfinite.cpp
	g++ -c processamentoEMG.cpp
	g++ -c -w Conect.cpp
	g++ -c processamentoEMG_terminate.cpp
	g++ -c processamentoEMG_initialize.cpp
	g++ -o saida *.o
	rm ./*.o
	./saida
#g++ -o saida main.o rt_nonfinite.o processamentoEMG_terminate.o processamentoEMG_initialize.o

