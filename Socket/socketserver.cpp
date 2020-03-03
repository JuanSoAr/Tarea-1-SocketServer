#include "socketserver.h"

#include "grafo.h"
#include "socketserver.h"
#include "socketserver.h"

//Socket tomados  del video de Youtube pertneciente al canal de Kavin Marin, https://www.youtube.com/watch?v=0DdCOwSsFLY

Grafo *g = new Grafo();
/**
 * @brief SocketServer::SocketServer
 */
SocketServer::SocketServer()
{
}

/**
 * @brief SocketServer::crear_Socket
 * returna el descriptor y con esto crea el socket
 * @return
 */
bool SocketServer::crear_Socket()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0){
        return false;}
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}
/**
 * @brief SocketServer::ligar_kernel
 * LIga el socket con el sistema operativo
 * @return
 */
bool SocketServer::ligar_kernel()
{
    if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
        return false;

    listen(descriptor,5);
    return true;
}

/**
 * @brief SocketServer::run
 * Esta funcion esta escuchando y espearando a que se conecte con el cliente
 * se debe crear un hilo para que el progrma siga trabajando
 */
void SocketServer::run()
{
    if(!crear_Socket())
        throw string("Error al crear el socket");
    if(!ligar_kernel())
        throw string("Error al  ligar kernel");
    while (true) {
        cout << "Esperando nuevo cliente"<<endl;
        dataSocket data;
        socklen_t tam = sizeof(data.info);//Lena la estructa con nla informacion del cliente
        data.descriptor = accept(descriptor,(sockaddr*)&data.info,&tam);
        if(data.descriptor < 0)
            cout << "Error al acceptar al cliente"<<endl;
        else
        {
            clientes.push_back(data.descriptor);
            pthread_t hilo;
            pthread_create(&hilo,0,SocketServer::controladorCliente,(void *)&data);
            pthread_detach(hilo);
        }
    }
    close(descriptor);
}


/**
 * @brief SocketServer::controladorCliente
 * controla al cliente espera que recisa alguna infomracion del cliente
 * @param obj
 * @return
 */
void * SocketServer::controladorCliente(void *obj)
{
    dataSocket *data = (dataSocket*)obj;
    while (true) {
        string mensaje;
        while (1) {
            char buffer[10] = {0};//Lee el mesaje por partes
            int bytes = recv(data->descriptor,buffer,10,0);
            mensaje.append(buffer,bytes);
            if(bytes < 10){
                break;}
        }
        if(mensaje == "Crear grafo"){
            cout<<"Grafo creado :"<<endl;
            g->Inicializa();
            g->InsertaVertice("Madrid");
            g->InsertaVertice("Barcelona");
            g->InsertaVertice("Sevilla");
            g->InsertaVertice("Bilbao");
            g->InsertaVertice("Pamplona");
            g->InsertarArista(g->GetVertice("Madrid"),g->GetVertice("Barcelona"),100);
            g->InsertarArista(g->GetVertice("Sevilla"),g->GetVertice("Barcelona"),250);
            g->InsertarArista(g->GetVertice("Madrid"),g->GetVertice("Sevilla"),15);
            g->InsertarArista(g->GetVertice("Madrid"),g->GetVertice("Bilbao"),250);
            g->InsertarArista(g->GetVertice("Bilbao"),g->GetVertice("Barcelona"),100);
            g->InsertarArista(g->GetVertice("Sevilla"),g->GetVertice("Madrid"),150);
            g->ListaAyacencia();
        }

    }

    close(data->descriptor);
    pthread_exit(NULL);
}

/**
 * @brief SocketServer::setMensaje
 * @param msn
 * Controla en envio de mensajes a los clientes
 */
void SocketServer::setMensaje(const char *msn)
{
    for(unsigned int i = 0 ; i < clientes.size() ; i++)
        cout << "bytes enviados "<< send(clientes[i],msn,strlen(msn),0);
}
