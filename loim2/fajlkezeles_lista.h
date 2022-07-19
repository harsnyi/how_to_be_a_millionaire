#ifndef FAJLKEZELES_LISTA_H_INCLUDED
#define FAJLKEZELES_LISTA_H_INCLUDED
 
typedef struct Kerdes
{
    char* sor;
    struct Kerdes *kov;
}Kerdes;

Kerdes *beolvas(int valasztott_nehezseg);
void felszabadit(Kerdes *kerdesek);
void fajlba_iras(char* nev,int nehezseg,int megvalaszolt);
int dicsoseg_lista();
void kiir(int rekordok);


#endif