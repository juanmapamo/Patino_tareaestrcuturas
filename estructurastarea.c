#include <stdio.h>
#include <string.h>

struct alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};
//En este apartado vamos a definir alumno y estudiantes.
int ingresarDatos(struct alumno *estudiante);
int mostrarDatos(struct alumno *estudiante);

