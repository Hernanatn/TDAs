#ifndef LISTA_H
#define LISTA_H

#ifndef NODO_H
#include "nodo.h"
#endif

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
        return (raiz == nullptr)
    };

    int devolverLargo()
    {
        return largo;
    };

    void ordenarPorId();

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
            throw std::out_of_range("Se intentó acceder a la lista con un índice que excede su largo.")
        }

        Nodo<Tipo> * nodoBuscado = buscarNodo(indice);
        return *nodoBuscado;
    };

};


#endif