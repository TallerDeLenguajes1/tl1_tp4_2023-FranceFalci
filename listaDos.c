#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea
{
    int TareaID;       // Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} typedef Tarea;

struct Nodo
{
    Tarea *T;
    struct Nodo *siguiente;
};

typedef struct Nodo *Lista;

Lista crearLista();
Tarea *crearTarea(int id, int duracion, char descripcion[]);
struct Nodo *crearNodo(Tarea *t);
Lista insertarNodo(Lista *L , struct Nodo * nodoAInsertar);
void mostrarTarea(Tarea t) ;
void mostrarLista(Lista L);

int main(){

    Lista listaPendientes = crearLista();
    Tarea *uno = crearTarea(1, 2, "uno");
    // mostrarTarea(*uno);
    listaPendientes = insertarNodo(&listaPendientes, crearNodo(uno));

    mostrarLista(listaPendientes);

    return 0;
}

Lista crearLista(){
    return NULL;
}

Tarea *crearTarea(int id, int duracion, char descripcion[]){
    Tarea *nuevaTarea = (Tarea *)malloc(sizeof(Tarea));
    nuevaTarea->TareaID = id;
    nuevaTarea->Duracion = duracion;
    nuevaTarea->Descripcion = (char *)malloc((strlen(descripcion) + 1) * sizeof(char));
    strcpy(nuevaTarea->Descripcion, descripcion);
    return nuevaTarea;
}

struct Nodo *crearNodo(Tarea *t){
    struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->T = t;
    nuevoNodo->siguiente = NULL;
}

Lista insertarNodo(Lista *L, struct Nodo *nodoAInsertar){
     nodoAInsertar->siguiente = *L;
     *L = nodoAInsertar;

}

void mostrarTarea(Tarea t){
    printf("id: %d - desc: %s", t.TareaID , t.Descripcion);
}

void mostrarLista(Lista L){
    while (L != NULL)
    {
        mostrarTarea(*(L->T));
        L = L->siguiente;
    }
    
}