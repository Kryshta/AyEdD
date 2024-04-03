#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define crearNodo(x,y,z,w) (    \
            ((x) = malloc(y)) == NULL || \
            ((z) = malloc(w)) == NULL ?            \
                    free(x), 0 : 1 )


#define minimo(x,y) ((x) < (y) ? (x) : (y))

#define PATH_ARCH_CONFIG "./config.txt"

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,*der;
} tNodoArbol;

typedef tNodoArbol *tArbolBinBusq;

typedef tNodo *tLista;

typedef struct
{
    char nombre[31];
    unsigned turno;
} t_Jugador;

typedef struct
{
    unsigned rounds;
    unsigned timexround;
} t_Config;

typedef struct
{
    char letra;
    char palabra[31];
    char jugador[31];
}t_Respuesta;

/// GENERAR UNA LETRA ALEATORIA QUE NO SE REPITA Y GUARDAR LAS LETRAS

int isUsedLetter(char array[], int size, char key);
char generateRandomLetter(char usedLetters[], int numUsedLetters);


// Función para generar una letra aleatoria que no se repita en el mismo round
char generateRandomLetter(char usedLetters[], int numUsedLetters)
{
    char letter;
    do
    {
        letter = 'A' + rand() % 26;
    }
    while (isUsedLetter(usedLetters, numUsedLetters, letter));
    return letter;
}

// Función para verificar si un caracter está en un arreglo de caracteres
int isUsedLetter(char array[], int size, char key)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

// Función para mostrar el menú y obtener la opción del usuario
char showMenuAndGetOption() {
    char option;
    printf("\n[A] Jugar\n");
    printf("[B] Salir\n");
    printf("Ingrese su opcion: ");
    option = toupper(getch());
    printf("%c\n", option);
    return option;
}

/// INGRESAR CUALQUIER CANTIDAD DE JUGADORES Y DECIDIR UN ORDEN ALEATORIO DE TURNOS

void crearLista(tLista *p)
{
    *p = NULL;
}

int listaVacia(tLista *p)
{
    return *p == NULL;
}

int ponerAlComienzo(tLista *p, void *d, unsigned cantBytes)
{
    tNodo *nue;
    if(!crearNodo(nue,sizeof(tNodo), nue->info, cantBytes))
        return 0;

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int compararTurnos(const void* d1, const void* d2)
{
    t_Jugador* j1 = (t_Jugador*)d1;
    t_Jugador* j2 = (t_Jugador*)d2;

    return j1->turno - j2->turno;
}

int compararRespuesta(const void* d1, const void* d2)
{
    t_Respuesta* r1 = (t_Respuesta*)d1;
    t_Respuesta* r2 = (t_Respuesta*)d2;

    if(r1->letra == r2->letra)
        return strcmp(r1->jugador, r2->jugador);

    return r1->letra - r2->letra;
}

void ordenar(tLista* p, int(*comparar)(const void*, const void*))
{
    tLista* pri = p;

    if (*p == NULL)
        return;
    while((*p)->sig)
    {
        if(comparar((*p)->info, (*p)->sig->info) > 0)
        {
            tLista *q = pri;
            tNodo *aux = (*p)->sig;

            (*p)->sig = aux->sig;
            while (comparar((*q)->info, aux->info) < 0)
                q = &(*q)->sig;
            aux->sig = *q;
            *q = aux;
        }
        else
            p = &(*p)->sig;
    }
}

int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;

    if (aux == NULL)
        return 0;
    *p = aux->sig;
    memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

void mostrarJugador(const void* d)
{
    t_Jugador* jug = (t_Jugador*)d;
    printf("%d - Nombre: %s\n", jug->turno, jug->nombre);
}

void recorrerLista(tLista* p, void(*mostrar)(const void*))
{
    while (*p)
    {
        mostrar((*p)->info);
        p = &(*p)->sig;
    }
}

void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p = NULL;
}

int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,
                            int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;
    int         rc;

    if(*p)
    {
        if((rc = cmp(d, (*p)->info)) < 0)
            return insertarRecArbolBinBusq(&(*p)->izq, d, tam, cmp);            //ME PARO A LA IZQUIERDA HASTA QUE NO HAYA NODO E INSERTO
        if (rc > 0)
            return insertarRecArbolBinBusq(&(*p)->der, d, tam, cmp);            //ME PARO A LA DERECHA HASTA QUE NO HAYA NODO E INSERTO
        return 0;
    }
    if(!crearNodo(nue, sizeof(tNodoArbol), nue->info, tam))
        return 0;
    nue->tamInfo = tam;
    memcpy(nue->info, d, tam);
    nue->der = nue->izq = NULL;
    *p = nue;                                                //   !!METO LA DIRECCION DEL NODO DONDE ESTOY PARADO!!
    return 1;
}

// Función para verificar si un número ya existe en un array
int existe(int num, int array[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (array[i] == num)
        {
            return 1; // El número ya existe en el array
        }
    }
    return 0; // El número no existe en el array
}

int enterPlayerNames(tLista *listaJugadores)
{
    int cantJugadores = 0, i = 1, j = 0;
    int turno;
    t_Jugador jugador;
    tLista listaAux;
    char op = 'S';

    crearLista(&listaAux);

    while (op != 'N')
    {
        printf("Ingrese el nombre del jugador %d: ", i);
        fflush(stdin);
        gets(jugador.nombre);
        ponerAlComienzo(&listaAux, &jugador, sizeof(t_Jugador));
        cantJugadores++;

        printf("Desea ingresar otro jugador (S/N): ");
        scanf(" %c", &op);
        op = toupper(op);

        while(op != 'S' && op != 'N')
        {
            printf("Ingrese una opcion valida: ");
            fflush(stdin);
            scanf(" %c", &op);
            op = toupper(op);
        }
        i++;
    }
    system("cls");

    /// TODO ESTO PODRIA HACERSE EN UNA FUNCION APARTE
    int* turnos = malloc(cantJugadores);
    ///TODO: preguntar si pudo reservar memoria
    // Inicializar la semilla del generador de números aleatorios
    srand(time(NULL));

    // Generar números aleatorios sin repetición
    int asignados = cantJugadores;
    while (asignados)
    {
        turno = 1 + rand() % cantJugadores; // Generar un número aleatorio

        if (!existe(turno, turnos, i))
        {
            turnos[j] = turno;
            asignados--;
            j++;
        }
    }
    j = 0;
    while(!listaVacia(&listaAux))
    {
        sacarPrimeroLista(&listaAux, &jugador, sizeof(t_Jugador));
        jugador.turno = turnos[j];
        ponerAlComienzo(listaJugadores, &jugador, sizeof(t_Jugador));
        j++;
    }
    free(turnos);
    ordenar(listaJugadores, compararTurnos);
    printf("------- Orden de los Jugadores -------\n");
    recorrerLista(listaJugadores, mostrarJugador);
    return cantJugadores;
}

int getConfig(t_Config* conf)
{
    FILE *pf = fopen(PATH_ARCH_CONFIG, "rt");
    if(!pf)
    {
        printf("No se pudo obtener el archivo de configuracion.\n");
        return 0;
    }

    fscanf(pf, "Rounds: %d\n", &conf->rounds);
    fscanf(pf, "Tiempo por round: %d\n", &conf->timexround);

    return 1;
}

int play_game() /// ESTA VA A SER LA FUNCION PLAYGAME()
{
    srand(time(NULL));
    int roundNumber, roundLimit, roundDuration, cantJugadores;
    char* usedLetters;
    t_Config conf;
    t_Jugador jugador;
    tLista listaJugadores;
    tArbolBinBusq arbolRes;

    getConfig(&conf);
    crearLista(&listaJugadores);
    crearArbolBinBusq(&arbolRes);
    roundLimit = conf.rounds;
    usedLetters = malloc(roundLimit);
    cantJugadores = enterPlayerNames(&listaJugadores);
    roundDuration = conf.timexround * 1000;

    if(cantJugadores == 1)
    {
        system("cls");
        printf("\nDeben ser dos o mas jugadores.\n");
        return 0;
    }

    while(!listaVacia(&listaJugadores))
    {
        sacarPrimeroLista(&listaJugadores, &jugador, sizeof(t_Jugador));
        printf("\n------- Turno del Jugador %s -------\n", jugador.nombre);

        for(roundNumber = 1; roundNumber <= roundLimit; roundNumber++)
        {
            if(jugador.turno == 1)
            {
                char lastLetter = generateRandomLetter(usedLetters, roundNumber - 1);
                usedLetters[roundNumber - 1] = lastLetter;
                printf("\nRonda %d - Ingresa una palabra con la letra %c: ", roundNumber, lastLetter);
            }
            else
                printf("\nRonda %d - Ingresa una palabra con la letra %c: ", roundNumber, usedLetters[roundNumber - 1]);

            // Configurar el temporizador para la ronda
            clock_t start = clock();

            int keyIndex = 0;
            char word[100];
            int complete = 0;

            while ((clock() - start) < roundDuration)
            {
                if (_kbhit())
                {
                    char ch = _getch();
                    if (ch == '\r')   // Si el usuario presiona Enter
                    {
                        word[keyIndex] = '\0';
                        complete = 1;
                        break;
                    }
                    else if (ch == '\b')     // Si el usuario presiona Backspace
                    {
                        if (keyIndex > 0)
                        {
                            printf("\b \b"); // Borrar el último carácter en la consola
                            keyIndex--;
                        }
                    }
                    else if (keyIndex < sizeof(word) - 1)     // Agregar caracteres a la palabra
                    {
                        word[keyIndex++] = ch;
                        printf("%c", ch);
                    }
                }
            }
            if (!complete)
                printf("\nTiempo agotado! La ronda %d ha terminado.\n", roundNumber);
            else
                printf("\nPalabra ingresada: %s\n", word);

            t_Respuesta res;
            strcpy(res.jugador, jugador.nombre);
            res.letra = usedLetters[roundNumber - 1];
            strcpy(res.palabra, word);

            insertarRecArbolBinBusq(&arbolRes, word, strlen(word), compararRespuesta);
        }
        printf("\nHA FINALIZADO SU TURNO\n");
    }

    return 1;
}

int main()
{
    char option;

    do {
        option = showMenuAndGetOption();
        system("cls");

        switch (option) {
            case 'A':
                play_game();
                break;
            case 'B':
                printf("\nSaliendo del juego...\n");
                break;
            default:
                printf("\nOpcion no valida. Por favor, seleccione A o B.\n");
                break;
        }
    } while (option != 'B');
}
