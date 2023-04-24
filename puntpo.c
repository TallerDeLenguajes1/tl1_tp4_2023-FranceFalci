#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAMA 200

struct Tarea
{
    int tareaID; // Numerado en ciclo iterativo
    char *descripcion;
    int duracion; // entre 10 – 100
} typedef tarea;

void inicializarTareas(int cantidad, tarea **tareas);
void agregarTareas(int cantidad, tarea **pTareasPendientes);
void realizarTareas(int cantidad, tarea **pTareasPendientes, tarea **pTareasRealizadas);
void mostrarPendientes(int cantidad, tarea **pTareasPendientes);
void mostrarRealizadas(int cantidad, tarea **pTareasRealizadas);
void buscarTareasId(int cantidad, tarea **tareas, int idBuscado);
void buscarTareasClave(int cantidad, tarea **tareas , char *palabra);

    int main()
{
    srand(time(NULL));
    int canttareas;
    char aux[TAMA];
    printf("Cuanta cantidad de tareas desea realizar?");
    scanf("%d", &canttareas);
    fflush(stdin);
    tarea **pTareasPendientes = (tarea **)malloc(sizeof(tarea) * canttareas);
    tarea **pTareasRealizadas = (tarea **)malloc(sizeof(tarea) * canttareas);

    inicializarTareas(canttareas, pTareasPendientes);
    inicializarTareas(canttareas, pTareasRealizadas);
    
    agregarTareas(canttareas, pTareasPendientes);

    // realizarTareas(canttareas,pTareasPendientes,pTareasRealizadas);
    // mostrarPendientes(canttareas,pTareasPendientes);
    // mostrarRealizadas(canttareas,pTareasRealizadas);
    // buscarTareasId(canttareas, pTareasPendientes, 1);
    buscarTareasClave(canttareas, pTareasPendientes,"dos");

        return 0;
}

void inicializarTareas(int cantidad, tarea **tareas)
{
    for (int i = 0; i < cantidad; i++)
    {
        tareas[i] = NULL;
        
    }
}

void agregarTareas(int cantidad, tarea **pTareasPendientes)
{
    char aux[TAMA];
    for (int i = 0; i < cantidad; i++)
    {
        pTareasPendientes[i] = malloc(sizeof(tarea));
        pTareasPendientes[i]->tareaID = i + 1;
        printf("Ingrese la descripcion de la tarea\n");
        scanf("%c", &aux);
        fflush(stdin);
        pTareasPendientes[i]->descripcion = malloc(sizeof(aux + 1));
        strcpy(pTareasPendientes[i]->descripcion, aux);
        pTareasPendientes[i]->duracion = 10 + rand() % 90;
    }
}

void realizarTareas(int cantidad, tarea **pTareasPendientes, tarea **pTareasRealizadas)

{
    int realizado;
    for (int i = 0; i < cantidad; i++)
    {
        printf("Realizo la tarea (1:Verdadero 0:Falso):%d\n", pTareasPendientes[i]->tareaID);
        scanf("%d", &realizado);
        fflush(stdin);
        if (realizado == 1)
        {
            pTareasRealizadas[i] = pTareasPendientes[i];
            pTareasPendientes[i] = NULL;
        }
    }
}

void mostrarPendientes(int cantidad, tarea **pTareasPendientes){
    printf("Tareas pendientes\n");
    for (int i = 0; i < cantidad; i++)
    {
        if (pTareasPendientes[i] != NULL)
        {
            printf("ID: %d\n", pTareasPendientes[i]->tareaID);
        }
    }
}

void mostrarRealizadas(int cantidad, tarea **pTareasRealizadas){
    printf("Tareas realizadas\n");
    for (int i = 0; i < cantidad; i++)
    {
        if (pTareasRealizadas[i] != NULL)
        {
            printf("ID: %d\n", pTareasRealizadas[i]->tareaID);
        }
    }
}

void buscarTareasId(int cantidad, tarea **tareas, int idBuscado){
    for (int i = 0; i < cantidad; i++)
    {
        if(tareas[i]->tareaID == idBuscado){
            printf("descripcion: %s \n", tareas[i]->descripcion);
            printf("duracion %d", tareas[i]->duracion);
        }
    }
    
}

void buscarTareasClave(int cantidad, tarea **tareas, char *palabra)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nDescripcion de la tarea: %s", tareas[i]->descripcion);

        if (strstr(tareas[i]->descripcion, palabra))
        {
            printf("\n------TAREA CON PALABRA CLAVE %s ENCONTRADA------\n", palabra);
            printf("ID: %d", tareas[i]->tareaID);
            printf("\nDescripcion: %s", tareas[i]->descripcion);
            printf("\nDuracion: %d", tareas[i]->duracion);
        }
    }
}