pro2.exe: pro2.o Agenda.o Historico.o Organigrama.o 
	g++ -o pro2.exe pro2.o Agenda.o Historico.o Organigrama.o 

pro2.o: pro2.cpp Organigrama.hpp Agenda.hpp
	g++ -c pro2.cpp -D_GLIBCXX_DEBUG

Agenda.o: Agenda.hpp Agenda.cpp
	g++ -c Agenda.cpp -D_GLIBCXX_DEBUG

Historico.o: Historico.cpp
	g++ -c Historico.cpp -D_GLIBCXX_DEBUG

Organigrama.o: Organigrama.hpp Organigrama.cpp Agenda.hpp
	g++ -c Organigrama.cpp -D_GLIBCXX_DEBUG

empaquetar: Organigrama.hpp Organigrama.cpp Agenda.hpp Agenda.cpp
	zip ENTREGA_NOMES_AQUEST.zip Organigrama.hpp Organigrama.cpp Agenda.hpp Agenda.cpp

#
# Esta última opción sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe

