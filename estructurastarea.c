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

int main(int argc, char const *argv[])
{
    int n;
    printf("Ingrese la cantidad de alumnos: ");
    fflush(stdout);
    scanf("%d", &n);

    struct alumno estudiantes[n];

    //En este apartado vamos a imprimir que opciones desea el usuario elegir.
    int opcion;
    do
    {
        printf("\n1. Ingresar datos de los alumnos\n");
        printf("2. Mostrar datos de los alumnos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        fflush(stdout);
        scanf("%d", &opcion);
        
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("\nIngrese los datos del alumno %d:\n", i + 1);
                ingresarDatos(&estudiantes[i]);
            }
            break;
        case 2:
            printf("\nDatos de los alumnos:\n");
            for (int i = 0; i < n; i++)
            {
                mostrarDatos(&estudiantes[i]);
            }
            break;
        case 3:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
            break;
        }
    } while (opcion != 3);

    return 0;
}

//Ahora vamos a configurar los tipos de datos que se nos ha pedido, para que
//el usuario pueda ingresar.
int ingresarDatos(struct alumno *estudiante)
{
    char buffer[100];

    printf("Matrícula: ");
    fflush(stdout);
    scanf("%d", &(estudiante->matricula));

    printf("Nombre: ");
    fflush(stdout);
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(estudiante->nombre, buffer, sizeof(estudiante->nombre));

    printf("Dirección: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(estudiante->direccion, buffer, sizeof(estudiante->direccion));

    printf("Carrera: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(estudiante->carrera, buffer, sizeof(estudiante->carrera));

    printf("Promedio: ");
    fflush(stdout);
    scanf("%f", &(estudiante->promedio));

    return 0;
}
