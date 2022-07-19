#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "debugmalloc.h"

typedef struct Kerdes{
    char* sor;
    struct Kerdes *kov;
}Kerdes;

Kerdes *letrehoz(Kerdes *eleje,char* beolvasott_sor){
    
    Kerdes *uj = (Kerdes*)malloc(sizeof(Kerdes));
    uj->kov = eleje;
    uj->sor = (char*)malloc(sizeof(char)*strlen(beolvasott_sor)+1);
    strcpy(uj->sor,beolvasott_sor);
    return uj;
    
};
void felszabadit(Kerdes *kerdesek){
    while(kerdesek != NULL){
        Kerdes *kov = kerdesek->kov;
        free(kerdesek->sor);
        free(kerdesek);
        kerdesek = kov;
    }
}

Kerdes *beolvas(int valasztott_nehezseg){
    
    Kerdes *kerdesek = NULL;
    FILE *fp;
    fp = fopen("loim.csv","r");
    if(fp == NULL){
        perror("A kerdesek megnyitasa sikertelen volt! Kerem ellenorizze hogy a megfelelo helyen talalhato-e!");
        return NULL;
    }
    int szam=0;
    char sor[255]; 
    printf("%d",valasztott_nehezseg);
    while (fgets(sor, sizeof(sor), fp)) {
        if(valasztott_nehezseg == 1){
            if((sor[0]-48 == 1 || sor[0]-48 == 2 || sor[0]-48 == 3 || sor[0]-48 == 4 || sor[0]-48 == 5) && sor[1] == ';'){
                kerdesek = letrehoz(kerdesek,sor);}
        }   
        if(valasztott_nehezseg == 2){
            if(((sor[0]-48 == 6 || sor[0]-48 == 7 || sor[0]-48 == 8 || sor[0]-48 == 9) && sor[1] == ';') || (sor[0]-48 == 1) && sor[2] == ';'){
                kerdesek = letrehoz(kerdesek,sor);}
            
        }    
        if(valasztott_nehezseg == 3){
            if(((sor[0]-48 == 1 && sor[1]-48 == 1) || (sor[0]-48 == 1 && sor[1]-48 == 2) || (sor[0]-48 == 1 && sor[1]-48 == 3) || (sor[0]-48 == 1 && sor[1]-48 == 4) || (sor[0]-48 == 1 && sor[1]-48 == 5)) && sor[2] == ';'){
                kerdesek = letrehoz(kerdesek,sor);}       
        }
    }
    fclose(fp);    
    return kerdesek;
    
}
void fajlba_iras(char* nev,int nehezseg,int megvalaszolt){

    FILE *fp;
    fp = fopen("dicsoseg_lista.txt","a");
    if(fp == NULL){
        perror("A celfajl letrehozasa, vagy bovitese sikertelen volt!");
        return;
    }
    fprintf(fp,"%d_pont  - %s\n",(nehezseg*300*megvalaszolt),nev);
    fclose(fp);
}
void rekordok_rendez(int* t,int n){
    int i =0;
    while(i<n){
        if(i == 0 || t[i-1] >= t[i]){
            i++;
        }else{
            int temp = t[i];
            t[i] = t[i-1];
            t[i-1] = temp;
            i--;
        }
    }
}
int dicsoseg_lista(){
    FILE *fp;
    Kerdes *eleje = NULL;
    fp = fopen("dicsoseg_lista.txt","r");
    if(fp == NULL){
        perror("A dicsoseglista beolvasasa sikertelen volt! Ellenorizze, hogy letezik-e es hogy megfelelo helyen talalhato!");
        return 0;
    }
    char sor[255];
    int rekordok_szama = 0;
    while(fgets(sor,sizeof(sor),fp)){
        rekordok_szama++;
    }
    fclose(fp);
    if(rekordok_szama < 1){
        printf("Jelenleg nincsenek adatok a dicsoseglistaban\n\n");
        return 0;
    }
    return rekordok_szama;
    

}
void kiir(int rekordok_szama){
    int *rekordok = (int*)malloc(sizeof(int)*rekordok_szama);
    FILE *fp;
    Kerdes *eleje = NULL;
    fp = fopen("dicsoseg_lista.txt","r");
    if(fp == NULL){
        perror("A dicsoseglista beolvasasa sikertelen volt! Ellenorizze, hogy letezik-e es hogy megfelelo helyen talalhato!");
        return;
    }
    char sor[255];
    int i = 0;
    while(fgets(sor,sizeof(sor),fp)){
        eleje = letrehoz(eleje,sor);
        int temp = 0;
        sscanf(sor,"%d_%*s",&temp);
        rekordok[i] = temp;
        i++;
    }
    rekordok_rendez(rekordok,rekordok_szama);
    int hossz = 0;
    if(rekordok_szama > 9){
        hossz = 10;

    }else{
        hossz = rekordok_szama;
    }
    printf("Jelenlegi ranglista:\n\n");
    Kerdes *mozgo;
    for(int i =0;i<hossz;++i){
        for(mozgo = eleje;mozgo!= NULL;mozgo = mozgo->kov){
            int tmp;
            sscanf(mozgo->sor,"%d_%*s",&tmp);
            if(tmp == rekordok[i]){
                printf("%d - hely: %s",i+1,mozgo->sor);
                break;
            }
        }
    }
    fclose(fp);
    printf("\n");
    felszabadit(eleje);
    free(rekordok);

}

