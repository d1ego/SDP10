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

int main(int argc, char* argv[]) {
    char num[2];

    num[0] = 2;
    num[1] = 5; /*rellena el mensaje */

		SocketDatagrama cliente = SocketDatagrama(6666);
		PaqueteDatagrama paquete = PaqueteDatagrama(num, sizeof(num), argv[1], 6000);
    cliente.envia(paquete);
		cliente.recibe(paquete);
		cout << "Enviado"<<endl;
		cout << paquete.obtieneDireccion()<<endl;
		cout << paquete.obtienePuerto()<<endl;
    return 0;
}
