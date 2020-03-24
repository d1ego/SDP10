#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include <stdlib.h>

using namespace std;

int main() {
    SocketDatagrama  servidor = SocketDatagrama(6000);
    PaqueteDatagrama paqueteRecibido = PaqueteDatagrama(100);
    cout << "Esperando Respuesta:\n";
    while (1) {
        servidor.recibe(paqueteRecibido);
        cout << "Se recibio de IP: " <<paqueteRecibido.obtieneDireccion()<<endl;
        cout << "Usando el puerto: " <<paqueteRecibido.obtienePuerto()<<endl;
        servidor.envia(paqueteRecibido);
    }
    return 0;

}
