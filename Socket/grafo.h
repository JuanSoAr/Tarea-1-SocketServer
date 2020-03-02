#ifndef GRAFO_H
#define GRAFO_H


#include <iostream>

using namespace std;

class Vertice;

class Arista{

public:
    int peso;
    Arista *sig;
    Vertice *ady;
};

class Vertice{
public:
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;
};


class Grafo {
    Vertice *h;
public:
    void Inicializa();
    bool Vacio();
    int Tamano();
    Vertice *GetVertice(string nombre);
    static void InsertarArista(Vertice *origen,Vertice *destino,int peso);
    void InsertaVertice(string nombre);
    string ListaAyacencia();
    void Dijkstra(Vertice *origen,Vertice *destino);
};


#endif // GRAFO_H
