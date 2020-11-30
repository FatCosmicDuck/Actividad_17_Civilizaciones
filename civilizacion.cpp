#include "civilizacion.h"

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const string &nombre, int &ubicacionEnX, int ubicacionEnY, float puntuacion)
{
    this->nombre = nombre;
    this->ubicacionEnX = ubicacionEnX;
    this->ubicacionEnY = ubicacionEnY;
    this->puntuacion = puntuacion;
}

void Civilizacion::setnombre(const string &c)
{
    nombre = c;
}

void Civilizacion::setUbicacionEnX(const int &c)
{
    ubicacionEnX = c;
}

void Civilizacion::setUbicacionEnY(const int &c)
{
    ubicacionEnY = c;
}

void Civilizacion::setPuntuacion(const float &c)
{
    puntuacion = c;
}

string Civilizacion::getNombre()
{
    return nombre;
}

int Civilizacion::getUbicacionEnX()
{
    return ubicacionEnX;
}

int Civilizacion::getUbicacionEnY() 
{
    return ubicacionEnY;
}

float Civilizacion::getPuntuacion()
{
    return puntuacion;
}
