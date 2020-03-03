
#include <socketserver.h>


SocketServer *server;
/**
 * @brief serverRun
 * @return
 * ESte es un hilo el cual me permite corre mi servidor y sus funciones
 */
void * serverRun(void *)
{
    try{
        server->run();
    }catch(string ex)
    {
        cout << ex;
    }

   pthread_exit(NULL);
}
/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
   server = new SocketServer;
   pthread_t hiloServer;
   pthread_create(&hiloServer,0,serverRun,NULL);
   pthread_detach(hiloServer);

   while (1) {//Envia mensaje al cliente
       string mensaje;
       cin >> mensaje;
       server->setMensaje(mensaje.c_str());
   }

   delete server;
   return 0;
}
