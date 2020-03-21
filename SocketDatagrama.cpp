#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
using namespace std;
SocketDatagrama::SocketDatagrama(int _puerto)
{
  s = socket(AF_INET, SOCK_DGRAM, 0);

  bzero((char *)&direccionForanea, sizeof(direccionForanea));
  bzero((char *)&direccionLocal, sizeof(direccionLocal));

  direccionLocal.sin_family = AF_INET;
  direccionLocal.sin_addr.s_addr = INADDR_ANY;

  if(puerto == 0)
    direccionLocal.sin_port = htons (puerto);
  else
    direccionLocal.sin_addr.sin_port = puerto;
}
SocketDatagrama::~SocketDatagrama()
{
  close(s);//cerrar socket
}
//Recibe un paquete tipo datagrama proveniente de este socket int recibe(PaqueteDatagrama & p);
//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p)
{
  return recvfrom(s,  (char *)&p.obtieneDatos(),p.obtieneLongitud() * sizeof(char),0,(struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}
int SocketDatagrama::envia(PaqueteDatagrama & p)
{
  direccionForanea.sin_family = AF_INET;
  direccionForanea.sin_addr.s_addr = inet_addr(p.obtienePuerto());
  direccionForanea.sin_port = htons(p.obtienePuerto())
  return sendto(s, (char *)&p.obtieneDatos(),p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));

}
