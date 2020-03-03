#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H


#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>


using namespace std;
/**
 * @brief The dataSocket struct
 */
struct dataSocket{
    int descriptor;
    sockaddr_in info;
};
/**
 * @brief The SocketServer class
 * Manejo de los sockets
 */
class SocketServer
{
public:
    SocketServer();
    void run();
    void setMensaje(const char *msn);
private:
    int descriptor;//Variable que devuelve el sistema operativo al crear un nuevo Socket
    sockaddr_in info;//informacion sobre el tipo de socket y tipo de infomracion
    bool crear_Socket();
    bool ligar_kernel();//Liga el socket con el sistema operativo
    static void * controladorCliente(void *obj);
    vector<int> clientes;
};
#endif // SOCKETSERVER_H
