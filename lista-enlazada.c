// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// struct Tarea
// {
//     int TareaID;       // Numerado en ciclo iterativo
//     char *Descripcion; //
//     int Duracion;      // entre 10 – 100
// }typedef Tarea;

// struct Nodo
// {
//     Tarea *T;
//     struct Nodo *siguiente;
// };

// typedef struct Nodo *Lista;


// Lista crearLista();

// Tarea *crearTarea(int id , int duracion , char descripcion[]);

// struct Nodo * crearNodo(Tarea *tarea);
// Lista insertarNodo(Lista L, Tarea t);
// struct Nodo *quitarNodo(Lista *L, int id);
// void mostrarLista(Lista L);
// void enlistar(Lista A, Lista B, Lista C);
// void EliminarNodo(struct Nodo *nodo);



// int main()
// {
//     Lista ListaPendientes;
//     Lista ListaRealizadas;
//     Lista ListaEnProceso;


//     ListaPendientes = crearLista();
//     ListaRealizadas = crearLista();




//     // quitado = quitarNodo(&ListaPendientes, 2);
//     // ListaRealizadas = insertarNodo(ListaRealizadas, quitado->T);
//     // ------COMIENZO INTERFAZ---------

//     int seleccion = 0;
//     int idTarea;
  
//     // enlistar(ListaPendientes, ListaEnProceso, ListaRealizadas);

//     // while (seleccion != 3)
//     // {
//     //     printf("1.SELECCIONAR TAREA \n 2.AGREGAR TAREA \n 3.SALIR");
//     //     scanf("%d", &seleccion);
//     //     fflush(stdin);
//     //     if (seleccion == 1)
//     //     {
//     //         printf("Ingrese id a seleccionar");
//     //         scanf("%d", &idTarea);
//     //         fflush(stdin);
//     //         printf("1.MOVER A REALIZADAS 2.MOVER A ENPROCESO 3.ELIMINAR 4.SALIR");
//     //         scanf("%d", &seleccion);
//     //         fflush(stdin);

//     //         quitado = quitarNodo(&ListaPendientes, idTarea);

//     //         switch (seleccion)
//     //         {
//     //         case 1:
//     //             ListaRealizadas = insertarNodo(ListaRealizadas, quitado);
//     //             break;
//     //         case 2:
//     //             ListaEnProceso = insertarNodo(ListaEnProceso, quitado);
//     //             break;
//     //         case 3:
//     //             // EliminarNodo(quitado);
//     //             break;

//     //         default:
//     //             break;
//     //         }
//     //     }
//     // }

//     return 0;
// }

// void enlistar(Lista A , Lista B , Lista C){
//     puts("---PENDIENTES--- \n");
//     mostrarLista(A);
//     puts("---ENPROCESO--- \n");
//     mostrarLista(B);
//     puts("---REALIZADAS--- \n");
//     mostrarLista(C);
// }
// Lista crearLista(){
//     return NULL;
// }

// Tarea *crearTarea(int id, int duracion, char descripcion[]){
//     Tarea *aux;
//     aux = (Tarea*)malloc(sizeof(Tarea));
//     aux->TareaID = id;
//     aux->Duracion = duracion;
//     aux->Descripcion = (char *)malloc((strlen(descripcion) + 1) * sizeof(char));
//     strcpy(aux->Descripcion,descripcion);
//     return aux;

// }

// struct Nodo *crearNodo(Tarea *tarea){
//     struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
//     nuevo->T = tarea;
//     nuevo->siguiente = NULL;
//     return nuevo;
// }
// Lista insertarNodo(Lista L, Tarea t){
//         struct Nodo *nuevo;
//         nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
//         nuevo->T = t;
//         nuevo->siguiente = L;
//         L = nuevo;
//         return L;
// }

// struct Nodo * quitarNodo(Lista *L, int id){
//     Lista Aux = *L;
//     Lista AnteriorAux = *L;

//     while (Aux != NULL && Aux->T.TareaID != id)
//     {
//         AnteriorAux = Aux;
//         Aux = Aux->siguiente;
//     }
//     /// AUX -> null O AUX -> dir
//     if (Aux)
//     {
//     // Primero
//         if (Aux == *L)
//         {
//             *L= Aux->siguiente;
//         }
//         else
//         {
//             AnteriorAux->siguiente = Aux->siguiente;
//         }
//         // cualquier otro

//         Aux->siguiente = NULL;
//         }
//     return Aux;
// }

// void mostrarLista(Lista L){
//     while (L != NULL)
//     {
//         printf("id: %d , desc: %s  siguiente %p\n", L->T.TareaID, L->T.Descripcion, L->siguiente);
//         L = L->siguiente;
//     }
// }

// void EliminarNodo(struct Nodo *nodo)
// {
//     free(nodo);
// }