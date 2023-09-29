#ifndef NODO_H
#define NODO_H


template<typename Tipo>
class Nodo
{
    private:
    Tipo * dato;
    Nodo * siguiente;
    bool comparable;

    public:

    Nodo() = delete;

    explicit Nodo(Tipo * nuevoDato) noexcept
    {
        this->dato = nuevoDato;
        this->siguiente = nullptr;
    };

    Nodo * cambiarSiguiente(Nodo * nuevoSiguiente)
    {
        this->siguiente = nuevoSiguiente;
    };

    Tipo * cambiarDato(Tipo * nuevoDato)
    {
        Tipo * viejo = this->dato;
        this->dato = nuevoDato;
        return viejo;
    };

    Tipo * devolverDato()
    {
        return this->dato;
    };

    Nodo * devolverSiguiente()
    {
        return this->siguiente;
    };
    
    int devolverLargo()
    {
        int largo = 1;
        Nodo * esteNodo = this;
        while(esteNodo->devolverSiguiente() != nullptr)
        {
            esteNodo = esteNodo->devolverSiguiente();
            largo++;
        }
        return largo;
    };

    bool esComparable()
    {
        return comparable;
    };

    ~Nodo()
    {
        if (this->siguiente != nullptr)
        {
            this->siguiente->~Nodo();
        }
        delete dato;
    };
};

#endif