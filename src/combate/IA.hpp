#pragma once

#include <SFML/Graphics.hpp>
class Personaje;

class IA
{
private:
    //yo -------> yo
    Personaje* yo;
    //el bicho que tengo que matar
    Personaje* enemigo;
    //Tiempo que la IA mantiene un boton
    float tiempoBotonMantenido = 0.0f;
    //cuanta distancia me saca el bicho que tengo que matar
    float distanciaRespectoJugador;
    //Esto es el rango en el que puede atacar... Le pega al bicho que tengo que matar
    const float RANGO_ATAQUE = 50.0f;
    const float RANGO_MEDIO = 500.0f;
    //Pienso que hay que meter un rango lejos...
public:
    //El obrero o como se diga (constructor)
    IA(Personaje& yo,Personaje& enemigo);
    //Cambiar el tiempo de boton mantenido
    void setTiempoBotonMantenido(float t);
    //Para tener la distancia que me saca el bicho que tengo que matar
    float getDistanciaRespectoJugador();
    //Conseguir el valor de rango ataque
    float getRangoAtaque();
    //Conseguir el valor de rango medio
    float getRangoMedio();
    //Conseguir el valor del boton mantenido
    float getTiempoBotonMantenido();
    //Para actualizar la distancia respecto al bicho
    void actualizarDistancia();
    //Suelta todas las teclas, porque se queda pillao si no
    void soltarTodo();
    //Mi cerebro
    void bucleIA();
};