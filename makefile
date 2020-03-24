main:  PaqueteDatagrama.o SocketDatagrama.o
	g++ cliente.cpp SocketDatagrama.o PaqueteDatagrama.o -o cliente
	g++ servidor.cpp SocketDatagrama.o PaqueteDatagrama.o -o servidor
SocketDatagrama.o:
	g++ -c SocketDatagrama.cpp
PaqueteDatagrama.o:
	g++ -c PaqueteDatagrama.cpp
clean:
	rm PaqueteDatagrama.o
	rm SocketDatagrama.o
	rm cliente
	rm servidor
