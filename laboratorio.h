#ifndef LABORATORIO_H_INCLUDED
#define LABORATORIO_H_INCLUDED

#include <iostream>
#include <vector>
#include "computadora.h"

using namespace std;

class Laboratorio
{
    private:
    vector<Computadora> computadoras;
    
    public:
    Laboratorio();
    void agregarComputadora(const Computadora &c);
    void mostrar();
    void respaldarTabla();
    void respaldar();
    void recuperar();

    void insertar(const Computadora &c, size_t pos);
    size_t size();
    void inicializar(const Computadora &c, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    Computadora* buscar(const Computadora &c);
    void borrar_ultimo();

    friend Laboratorio& operator<<(Laboratorio &l, const Computadora &c){
        l.agregarComputadora(c);
        return l;
    }
};

#endif //LABORATORIO_H_INCLUDED