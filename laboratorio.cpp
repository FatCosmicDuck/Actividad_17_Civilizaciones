#include <fstream>
#include <algorithm>
#include "laboratorio.h"

Laboratorio::Laboratorio(){}

void Laboratorio::agregarComputadora(const Computadora &c)
{
    computadoras.push_back(c);
}

void Laboratorio::mostrar()
{
    cout << left;
    cout << setw(20) << "Sistema Operativo";
    cout << setw(16) << "Nombre Equipo";
    cout << setw(14) << "Memoria Ram";
    cout << setw(16) << "Tarjeta Grafica";
    cout << endl;

    for(size_t i = 0; i < computadoras.size(); i++){
        Computadora &c = computadoras[i];
        cout << c;
    }
}

void Laboratorio::respaldarTabla(){

    ofstream archivo("RespaldoTabla.txt");

    if(archivo.is_open()){

        archivo << left;
        archivo << setw(20) << "Sistema Operativo";
        archivo << setw(16) << "Nombre Equipo";
        archivo << setw(14) << "Memoria Ram";
        archivo << setw(16) << "Tarjeta Grafica";
        archivo << endl;

        for (size_t i = 0; i < computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo << c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar(){

    ofstream archivo("RespaldoDeComputadoras.txt");
    
    if(archivo.is_open()){

        for (size_t i = 0; i < computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo << c.getSistemaOperativo() << endl;
            archivo << c.getNombreEquipo() << endl;
            archivo << c.getMemoriaRam() << endl;
            archivo << c.getTarjetaGrafica() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar(){
    ifstream archivo("RespaldoDeComputadoras.txt");
    if(archivo.is_open()){
        string tempString;
        int tempInt;
        Computadora c;

        while(true){
            getline(archivo, tempString); //Sistema Operativo
            if(archivo.eof()){
                break;
            }
            c.setSistemaOperativo(tempString);

            getline(archivo, tempString); //Nombre Equipo
            c.setNombreEquipo(tempString);

            getline(archivo, tempString); //Memoria Ram
            tempInt = stoi(tempString);
            c.setMemoriaRam(tempInt);

            getline(archivo, tempString); //Tarjeta Grafica
            tempInt = stoi(tempString);               
            c.setTarjetaGrafica(tempInt);

            agregarComputadora(c);

        }
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t pos)
{
    computadoras.insert(computadoras.begin()+pos, c);
}

size_t Laboratorio::size()
{
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t n)
{
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}

Computadora* Laboratorio::buscar(const Computadora &c)
{
    //vector<Computadora>::iterator it
    //auto it
    vector<Computadora>::iterator it = find(computadoras.begin(), computadoras.end(), c);

    if(it == computadoras.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void Laboratorio::borrar_ultimo()
{
    if(computadoras.empty()){
                cout << "El vector esta vacio..." << endl;
            }
            else{
                computadoras.pop_back();
            }
}