#include "IA.hpp"
#include "Personaje.hpp"
#include <cmath>
#include <iostream>

IA::IA(Personaje& yoRef, Personaje& enemigoRef) 
: 
yo(&yoRef), enemigo(&enemigoRef), distanciaRespectoJugador(0.0f)
{
    actualizarDistancia();
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void IA::setTiempoBotonMantenido(float t)
{
    tiempoBotonMantenido = t;
}

float IA::getDistanciaRespectoJugador()
{
    return distanciaRespectoJugador;
}

float IA::getRangoAtaque()
{
    return RANGO_ATAQUE;
}

float IA::getRangoMedio()
{
    return RANGO_MEDIO;
}

float IA::getTiempoBotonMantenido()
{
    return tiempoBotonMantenido;
}

void IA::actualizarDistancia()
{
    //Si no hay na pues que vas a calcular...
    if (!yo || !enemigo) 
    {
        return;
    }    

    // Aqui se calcula la distancia respecto al eje x (la y todavia no la tocamos)
    distanciaRespectoJugador = enemigo->getPosicion().x - yo->getPosicion().x;
}

void IA::soltarTodo()
{
    yo->detenerAccion(Accion::ARRIBA);
    yo->detenerAccion(Accion::ABAJO);
    yo->detenerAccion(Accion::IZQUIERDA);
    yo->detenerAccion(Accion::DERECHA);
    yo->detenerAccion(Accion::ATACAR);
}

void IA::bucleIA()
{
    //Si no hay na po no hay na, pon algo!
    if (!yo || !enemigo) 
    {
        return;
    }

    //Va contando cuanto le queda al boton para terminar;
    if(getTiempoBotonMantenido()>0)
    {
        float framesRestantes = getTiempoBotonMantenido();
        setTiempoBotonMantenido(framesRestantes--);
        return;
    }

    //Lo suelta.
    soltarTodo();
    //Actualiza la distancia
    actualizarDistancia();
    float distancia = getDistanciaRespectoJugador();
    //std::cerr << "La distancia es: " << distancia << "\n";

    bool isMirandoDerecha = yo->isMirandoDerecha();

    //Numero random que nos sirve para tomar decisiones
    int r = std::rand() % 100;
    /*Solo comprueba si esta cerca para atacar, si no esta cerca se acerca.
    Como la distancia puede ser positiva o negativa, usamos esto para saber si el personaje tiene que ir a la derecha o la izquierda
    El caso de atacar solo tenemos que calcular el valor absoluto de la distancia y si esa distancia es menor que la variable RANGO_ATAQUE 
    la IA ataca
    Si mira a la derecha y la distancia está por debajo de RANGO_MEDIO entonces se moverá.
    */
    if (std::abs(distancia) <= getRangoAtaque())
    {
        /*if(enemigo-> == Accion.ARRIBA)
        {
            Todo esto es por si el enemigo salta pues la IA salta y le suelta una leche
        }*/
        yo->realizarAccion(Accion::ATACAR); //Si estamos en el suelo le pega
    }
    else if (isMirandoDerecha && std::abs(distancia) <= getRangoMedio())
    {
        if(r<70)
        {
            yo->realizarAccion(Accion::DERECHA); //Se mueve a la derecha
            int tm = 3.0f * (std::rand() % 2) * 1.0f;
            setTiempoBotonMantenido(tm);
        }
        else
        {
            yo->realizarAccion(Accion::NADA);
            setTiempoBotonMantenido(1.0f);
        }
    }
    else
    {
        if(r<70)
        {
            yo->realizarAccion(Accion::IZQUIERDA); //Se mueve a la izquierda
            int tm = 3.0f * (std::rand() % 2) * 1.0f;
            setTiempoBotonMantenido(tm);
        }
        else
        {
            yo->realizarAccion(Accion::NADA);
            setTiempoBotonMantenido(1.0f);
        }
    }
}