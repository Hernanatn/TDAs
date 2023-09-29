#ifndef LISTA_H
#define LISTA_H

#ifndef NODO_H
#include "nodo.h"
#endif

#include <iostream>
#include <stdexcept>

template<typename Tipo>
class Lista
{
    private:
    int largo;
    Nodo<Tipo> * raiz;

    public:
    Lista() noexcept
    : Lista{0,nullptr} 
    {};

    explicit Lista(Nodo<Tipo> * nuevoNodo)
    {
        this->raiz = nuevoNodo;
        this->largo = nuevoNodo->devolverLargo();
    };

    void agregarNodo(Nodo<Tipo> * nuevoNodo);
    void insertarNodo(Nodo<Tipo> * nuevoNodo, int indice);
    void eliminarNodo(int indice);
    Nodo<Tipo> * extraerNodo(int indice);
    Nodo<Tipo> * buscarNodo(int indice);

    bool estaVacia()
    {
        return (raiz == nullptr);
    };

    int devolverLargo()
    {
        return this->largo;
    };

    void ordenar()
    {
        if (this->estaVacia())
        {   
            std::cout<<"Intentó ordenar una lista vacía.\n";
            //#pragma message(": warning<lista vacía> Intentó ordenar una lista vacía.")
            return;
        }
        else if (!raiz->esComparable())
        {
            std::cout<<"Intentó llamar ordenar() sobre una lista de tipos que no implementan métodos ni operadores de comparación. Esta llamada no hizo nada. Es probable que no exista una noción razonable de 'orden' para los tipos subyacentes a la lista, por lo que tratar de ordenarla resulta igualmente irrazonable.\n";
            //#pragma message(": warning<tipo no es ordenable> Intentó llamar ordenar() sobre una lista de tipos que no implementan métodos ni operadores de comparación. Esta llamada no hizo nada. Es probable que no exista una noción razonable de 'orden' para los tipos subyacentes a la lista, por lo que tratar de ordenarla resulta igualmente irrazonable.");
            return;
        }

        // [HACER] Implementar ordenamiento por mezcla.
        return;
    };

    ~Lista()
    {
        if(!estaVacia())
        {
            raiz->~Nodo();
        }
    };


    Nodo<Tipo>& operator[](int indice)
    {
        if (indice > this->largo)
        {
            throw std::out_of_range("Se intentó acceder a la lista con un índice que excede su largo.");
        }

        Nodo<Tipo> * nodoBuscado = buscarNodo(indice);
        return *nodoBuscado;
    };

};


#endif