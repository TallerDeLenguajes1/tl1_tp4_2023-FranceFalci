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
    Tarea T;
    struct Nodo *siguiente;
};

typedef struct Nodo *Lista;

Lista crearLista();
Tarea crearTarea(int id, int duracion, char descripcion[]);
struct Nodo *crearNodo(Tarea t);
struct Nodo *quitarNodo(Lista *L, int id);
void insertarNodo(Lista *L , struct Nodo * nodoAInsertar);
void mostrarTarea(Tarea t) ;
void mostrarLista(Lista L);

int main(){

    Lista listaPendientes, listaRealizadas;
    listaPendientes = crearLista();
    listaRealizadas = crearLista();
    struct nodo *nodoQuitado;

    Tarea uno = crearTarea(1, 2, "uno");
    Tarea dos = crearTarea(2, 2, "dos");
    
    // mostrarTarea(uno);
    insertarNodo(&listaPendientes, crearNodo(uno));
    insertarNodo(&listaPendientes, crearNodo(dos));
    insertarNodo(&listaPendientes, crearNodo(crearTarea(3, 2, "tres")));
    
    nodoQuitado = quitarNodo(&listaPendientes, 2);
    insertarNodo(&listaRealizadas, nodoQuitado);
    puts("----PendienteS---");
    mostrarLista(listaPendientes);
    puts("----Realizadas---");
    mostrarLista(listaRealizadas);




    return 0;
}

Lista crearLista(){
    return NULL;
}

Tarea crearTarea(int id, int duracion, char descripcion[]){
    Tarea nuevaTarea; //(Tarea *)malloc(sizeof(Tarea));
    nuevaTarea.TareaID = id;
    nuevaTarea.Duracion = duracion;
    nuevaTarea.Descripcion = (char *)malloc((strlen(descripcion) + 1) * sizeof(char));
    strcpy(nuevaTarea.Descripcion, descripcion);
    return nuevaTarea;
}

struct Nodo *crearNodo(Tarea t){
    struct Nodo *nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->T = t;
    nuevoNodo->siguiente = NULL;
}

struct Nodo *quitarNodo(Lista *L, int id){
    Lista aux = *L;
    Lista auxAnterior = *L;

    while (aux != NULL && aux->T.TareaID != id)
    {
        auxAnterior = aux;
        aux = aux->siguiente;
    }

    if(aux){
        if(aux == *L){
            *L = aux->siguiente;
        }else{
            auxAnterior->siguiente= aux->siguiente;
        }

        aux->siguiente = NULL;
    }
    return aux;
}

void insertarNodo(Lista *L, struct Nodo *nodoAInsertar){
     nodoAInsertar->siguiente = *L;
     *L = nodoAInsertar;

}

void mostrarTarea(Tarea t){
    printf("id: %d - desc: %s", t.TareaID,t.Descripcion);
}

void mostrarLista(Lista L){
    while (L != NULL)
    {
        printf("id: %d - desc: %s - siguiente %p \n ", L->T.TareaID , L->T.Descripcion, L->siguiente);
        L = L->siguiente;
    }
    
}