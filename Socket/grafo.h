#ifndef GRAFO_H
#define GRAFO_H


#include <iostream>

using namespace std;
class Vertice;
/**
 * @brief The Arista class
 * La clase arista controla las rutas de los vertices
 */
class Arista{

public:
    int peso;
    Arista *sig;
    Vertice *ady;
};
/**
 * @brief The Vertice class
 * La cllase vertice son las llegadas y salidas de la arista
 */
class Vertice{
public:
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;
};



/**
 * @brief The Grafo class
 */

class Grafo {
    Vertice *h;
public:
    void Inicializa();
    bool Vacio();
    int Tamano();
    Vertice *GetVertice(string nombre);
    static void InsertarArista(Vertice *origen,Vertice *destino,int peso);
    void InsertaVertice(string nombre);
    void ListaAyacencia();
    void Dijkstra(string *origen,string *destino);
};

#endif // GRAFO_H
