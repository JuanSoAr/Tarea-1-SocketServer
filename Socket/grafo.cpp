#include "grafo.h"
using namespace std;

void Grafo::Inicializa() {
    h = nullptr;
}

bool Grafo::Vacio() {
    return h == nullptr;
}

int Grafo::Tamano(){
    int cont = 0;
    Vertice *aux;
    aux = h;
    while(aux != nullptr){
        cont +=1;
        aux = aux->sig;
    }
    return cont;
}

Vertice *Grafo::GetVertice(string nombre) {
    Vertice *aux;
    aux = h;
    while (aux != nullptr){
        if(aux->nombre == nombre){
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

void Grafo::InsertarArista(Vertice *origen, Vertice *destino, int peso) {
    auto *nueva = new Arista;
    nueva->peso = peso;
    nueva->sig = nullptr ;
    nueva->ady = nullptr;

    Arista *aux;

    aux = origen->ady;
    if(aux == nullptr){
        origen->ady = nueva;
        nueva->ady = destino;
    }
    else{
        while (aux->sig != nullptr){
            aux = aux->sig;
        }
        aux->sig = nueva;
        nueva->ady = destino;
    }
}

void Grafo::InsertaVertice(string nombre) {
    auto *nuevo = new Vertice;
    nuevo->nombre = nombre;
    nuevo->sig = nullptr;
    nuevo->ady = nullptr;
    if(Vacio()){
        h = nuevo;
    } else{
        Vertice *aux = h;
        while (aux->sig != nullptr){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

}

string Grafo::ListaAyacencia() {
    Vertice *VerAux;
    Arista *ArisAux;
    string imprime;
    VerAux = h;
    while (VerAux != nullptr){
        imprime += VerAux->nombre +"--->";
        ArisAux = VerAux->ady;
        while (ArisAux != nullptr){
            imprime += ArisAux->ady->nombre + "--->";
            ArisAux = ArisAux->sig;
        }
        VerAux = VerAux->sig;
        imprime += "\n";

    }
    return imprime;}
