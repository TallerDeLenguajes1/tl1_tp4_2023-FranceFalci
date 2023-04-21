// Considere la siguiente situación: En la misma distribuidora del práctico anterior ahora surgió
// la necesidad de llevar un control de las tareas realizadas por sus empleados. Usted forma
// parte del equipo de programación que se encargará de hacer el módulo en cuestión que a
// partir de ahora se llamará módulo ToDo:
// Tareas
// Cada empleado tiene un listado de tareas a realizar.
// Las estructuras de datos necesarias son las siguientes:
// 1. Desarrollar una interfaz por consola donde se solicite al usuario (es decir el
// empleado) cuantas tareas debe cargar.
// Tendrá que generar un arreglo de doble punteros dinámicamente del tipo Tarea
// con la cantidad de tareas solicitadas en el punto anterior.Recuerde inicializar
// los arreglos apuntando a NULL.
// 3.Desarrolle una interfaz de consola para cargar las tareas, ingresando su
// descripción y duración. Recuerde utilizar reserva de memoria dinámica para la
// carga de la descripción.
// 4.Una vez cargada todas las tareas. Irá listando de a una las tareas y
// preguntando si se realizó o no la misma. Si la respuesta es Si tiene que
// “mover” dicha tarea a otro arreglo denominado tareas realizadas que tendrá el
// mismo tamaño que el anterior. Una vez movida la tarea ese casillero del vector
// tiene que apuntar a null. Como se muestra en la gráfica a continuación.
// 5. Mostrar por pantalla todas las tareas realizadas y luego listar las tareas
// pendientes.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
}typedef Tarea;

int main(){

    int cantidadTareas,realizada;
    char *aux = malloc(sizeof(char)* 250);
    printf("Cuantas tareas desea carhar");
    scanf("%d", &cantidadTareas);
    fflush(stdin);
    Tarea **pTareas =  (Tarea**)malloc(sizeof(Tarea*) * cantidadTareas);
    Tarea **pTareasRealizadas =(Tarea**)malloc(sizeof(Tarea*) * cantidadTareas);

    //  Tarea **pTareas =  malloc(sizeof(Tarea*) * cantidadTareas);

    for (int i = 0; i < cantidadTareas; i++)
    {
        pTareas[i] = NULL;
        pTareasRealizadas = NULL;
    }

    for(int i = 0; i < cantidadTareas; i++){
        pTareas[i] =malloc(sizeof(Tarea));
        pTareas[i]->TareaID = i+1;
        printf("ingrese descripcion");
        gets(aux);
        fflush(stdin);
        pTareas[i]->Descripcion = malloc(sizeof(char) * strlen(aux)+1);
        strcpy(pTareas[i]->Descripcion, aux);
        printf("ingrese duracion de 10-100");
        scanf("%d",&pTareas[i]->Duracion);
        fflush(stdin);

    }

   
    for (int  i = 0; i<cantidadTareas ; i++)
    {
        printf(" realizo la tarea %d? (1=si  0=no)", pTareas[i]->TareaID);
        scanf("%d", &realizada);
        fflush(stdin);
        if(realizada == 1){
            // pTareas[i] = (Tarea *)malloc(sizeof(Tarea));
            // igualar directamente
            pTareasRealizadas[i] = pTareas[i];
            pTareas[i] =NULL;

        }
    }

    // for (int i = 0; i<cantidadTareas ; i++){
    //     if(pTareas[i] != NULL){
    //     printf("Tarea pendientes %s", pTareas[i]->Descripcion);

    //     } 
    // }



// otra forma
    // int i = 0 ;
    // while(pTareas[i] != NULL && i<cantidadTareas){
    //     printf(" realizo la tarea %d? (1=si  0=no)", pTareas[i]->TareaID);
    //     scanf("%d", &realizada);
    //     i++;
    // }
    

    

}