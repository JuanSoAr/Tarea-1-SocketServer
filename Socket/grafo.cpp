#include "grafo.h"
using namespace std;

/**
 * @brief Grafo::Inicializa
 * Inicializo mi grafo den nulo para evitar algun problema con los punteros
 */
void Grafo::Inicializa() {
    h = nullptr;
}
/**
 * @brief Grafo::Vacio
 * Revisa si mi grafo esta vacio o por lo contrario ya se creo algun vertice
 * @return
 * returna un booleano comparando a h con nullptr papra identificar si existe alguna arista
 *
 */
bool Grafo::Vacio() {
    return h == nullptr;
}

/**
* @brief Grafo::GetVertice
 * @param nombre el nombre del vertice que deseo obtener
 * @return el vertice solicicitado
 */
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
/**
 * @brief Grafo::InsertarArista Crea una arista desde dos vertices
 * @param origen veretice de origen
 * @param destino vertice destino
 * @param peso el peso que tiene llegar desde el vertice de origen al vertice destino
 */
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
/**
 * @brief Grafo::InsertaVertice
 * @param nombre se crea un nuevo vertice
 */
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
/**
 * @brief Grafo::ListaAyacencia
 * @return imprime en pantalla la rutas que existen entre un vertice
 */
void Grafo::ListaAyacencia() {
    Vertice *VerAux;
    Arista *ArisAux;
    string imprime;
    VerAux = h;
    while (VerAux != nullptr){
        imprime += VerAux->nombre +"-->";
        ArisAux = VerAux->ady;
        while (ArisAux != nullptr){
            imprime += ArisAux->ady->nombre;
            imprime += "-->";
            ArisAux = ArisAux->sig;
        }
        VerAux = VerAux->sig;
        imprime += "\n";

    }
    cout<<imprime<<endl;
}














