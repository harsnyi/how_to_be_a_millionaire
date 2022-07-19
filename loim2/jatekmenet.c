#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fajlkezeles_lista.h"
#include <ctype.h>
#include <time.h>
#include "debugmalloc.h"


void nev_felszabadit(char* nev){
    free(nev);
}
char* nev_bekeres(){
    char t_nev[255];
    printf("Kerem adja meg a nevet:");
    scanf("%s",t_nev);
    char *nev = (char*)malloc((strlen(t_nev)+1)*sizeof(char));
    strcpy(nev,t_nev);
    return nev;
}
int valasztas(){
    int ciklus = 1;
    int szint;
    printf("\nAz alabbiak kozul valassz nehezsegi szintet:\n");
    printf("1 - Konnyu\n");
    printf("2 - Kozepes\n");
    printf("3 - Nehez\n");
    while(ciklus){
        printf("?");scanf(" %d",&szint);
    
        if(szint > 3 || szint < 1){
            printf("\nKerem a megadott intervallumbol valasszon!\n");
        }
        else{ciklus = 0;}
    }
    return szint;
}

int random_kerdes_szam(int kerdesek_szumma){
    int random_kerdes_sorszama=0;
    random_kerdes_sorszama = rand()%kerdesek_szumma;
    return random_kerdes_sorszama;
}
int kerdes_kiir(char* sor){
    int i,j;
    printf("\n");
    for(i=0;sor[i] != ';';++i);
    for(j = i+1;sor[j] != ';';++j){
        printf("%c",sor[j]);
    }printf("\n");
    return j;
}
int valaszok_kiir(char* sor,int folytatas){
    int k;
    int i,j,x;
    for(i=folytatas+1;sor[i] != ';';++i);
    for(j=i+1;sor[j] != ';';++j);
    for(x=j+1;sor[x] != ';';++x);
    char valasz_betuk[4] = "ABCD";
    int valaszok[4] = {folytatas+1,i+1,j+1,x+1};
    
    for(int i =0;i<4;++i){
        k = valaszok[i];
        printf("%c - ",valasz_betuk[i]);
        while(sor[k] != ';'){
            printf("%c",sor[k]);
            k++;
        }printf("\n");
    }
    return k;
}
char valaszadas(){
    char valasz;
    int ciklus = 1;
    
    printf("Kerem adja meg valaszat:\n");
    while(ciklus){
        
        printf("?");scanf(" %c",&valasz);
        valasz = toupper(valasz);
        int helyes = (valasz == 'A' || valasz == 'B' || valasz == 'C' || valasz == 'D');
        if(!helyes){
            printf("Kerem helyes erteket adjon meg!");
            break;
        }
        else{
            ciklus = 0;
        }
    }    
    return valasz;
}
int helyes_valasz(char* sor,int folytatas,char valasz){
    if(sor[folytatas+1] == valasz){
        return 1;
    }
    return 0;
}
void segitsegek(int felezes,int kozonseg){
    
    printf("\nFelhasznalhato segitsegek:\t\t");
    !felezes ? printf("1 - Felezes\t\t") : printf("");;
    !kozonseg? printf("2 - Kozonseg") : printf("");;
    printf("\n");
}
void helyes_kiir(int helyes_valasz,int* valaszok,char helyes,char* sor){
    int kezdete = valaszok[helyes_valasz];
    printf("%c - ",helyes);
    for(int z=kezdete;sor[z] != ';';++z){
        printf("%c",sor[z]);
    }printf("\n");
}
void helyes_melle_masik_kiir(int *valaszok,char* valasz_betuk,char* sor,char helyes){
    
    int random_valasz = 0;
    while(random_valasz == helyes){
        random_valasz = rand()%3;
    }
    int kezdete = valaszok[random_valasz];
    printf("%c - ",valasz_betuk[random_valasz]);
    for(int z=kezdete;sor[z] != ';';++z){
            printf("%c",sor[z]);
        }printf("\n");
}
void kerdes_felezes(char* sor,int seged,int valasz_helye){
    char helyes = sor[valasz_helye+1];
    int helyes_valasz = 0;
    int i,j,x;
    for(i=seged+1;sor[i] != ';';++i);
    for(j=i+1;sor[j] != ';';++j);
    for(x=j+1;sor[x] != ';';++x);
    char valasz_betuk[4] = "ABCD";
    int valaszok[4] = {seged+1,i+1,j+1,x+1};
    int sorrend = rand()%2;    
    while(valasz_betuk[helyes_valasz] != helyes){
        helyes_valasz++;
    }
    if(sorrend == 1){
        helyes_kiir(helyes_valasz,valaszok,helyes,sor);
        helyes_melle_masik_kiir(valaszok,valasz_betuk,sor,helyes);
    }
    if(sorrend == 0){
        helyes_melle_masik_kiir(valaszok,valasz_betuk,sor,helyes);
        helyes_kiir(helyes_valasz,valaszok,helyes,sor);
    }
}
void szavazat_stat(int szavazat){
    for (int i = 0; i < szavazat/2; i++){
        printf("+");
    }
}
void kerdes_kozonseg(char* sor,int valasz_helye){
    char helyes = sor[valasz_helye+1];
    char valaszok[] = "ABCD";
    int szavazasok[4] = {0};
    double sum;
    while(sum != 100){
        szavazasok[0] = rand()%100;
        szavazasok[1] = rand()%100;
        szavazasok[2] = rand()%100;
        szavazasok[3] = rand()%100;
        sum = (szavazasok[0]+szavazasok[1]+szavazasok[2]+szavazasok[3]);

    }int max = 0;
    for(int i =0;i<4;++i){
        if(max < szavazasok[i]){
            max = szavazasok[i];
        }
    }
    int max_helye=0;
    while(szavazasok[max_helye] != max){
        max_helye++;
    }
    int helyes_index = 0;
    while(valaszok[helyes_index] != helyes){
        helyes_index++;
    }
    int temp = szavazasok[max_helye];
    szavazasok[max_helye] = szavazasok[helyes_index];
    szavazasok[helyes_index] = temp;

    int i=0;
    printf("\n");
    while(valaszok[i] != '\0'){
        printf("%c - ",valaszok[i]);szavazat_stat(szavazasok[i]);printf(" - %d%%\n",szavazasok[i]);
        i++;
    }
}

void segitseg_keres(char* sor,int *felezes,int *kozonseg,int seged,int valasz_helye){
    char keres;
    int ciklus;
    printf("Szeretne segitseget kerni? (I - Igen) (N - Nem)\n");
    while(ciklus){
        printf("?");scanf(" %c",&keres);
        keres = toupper(keres);
        printf("\n");
        int szub_ciklus = 1;
        char valasztas;
        switch (keres){
        case 'I':
            printf("Kerem valasszon a lehetseges opciok kozul:\n");
            while(szub_ciklus){
                printf("?");scanf(" %c",&valasztas);
                switch (valasztas){
                case '1':
                    if(*felezes == 0){
                        kerdes_felezes(sor,seged,valasz_helye);
                        *felezes = 1;
                        szub_ciklus = 0;
                    }
                    else{printf("A fent marado lehetosegek kozul valassz!\n");break;}
                    break;
                case '2':
                    if(*kozonseg == 0){
                        kerdes_kozonseg(sor,valasz_helye);
                        *kozonseg = 1;
                        szub_ciklus = 0;
                    }
                    else{printf("A fent marado lehetosegek kozul valassz!\n");break;}
                default:
                    printf("Kerem helyes erteket valasszon!");
                    break;
                }
            }
            ciklus = 0;
            break;
        
        case 'N':
            ciklus = 0;
            break;
        default:
            printf("Kerem helyes erteket adjon meg");
            break;
        }
    }
}
int jatek_menet(int nehezseg){
    
    Kerdes *lista = beolvas(nehezseg);
    Kerdes *mozgo;
    int kerdesek_ossz=0;
    int random_kerdesek[15] = {0};
    for(mozgo = lista;mozgo != NULL;mozgo = mozgo->kov){
        kerdesek_ossz++;
    }
    for(int i =0;i<15;++i){
        random_kerdesek[i] = random_kerdes_szam(kerdesek_ossz);
        for(int j =0;j<i;++j){
            if(random_kerdesek[j] == random_kerdesek[i]){
                random_kerdesek[j] = random_kerdes_szam(kerdesek_ossz);
            }
        }
    }
    int helyes_valaszok=0;
    int iter=0;
    int ciklus = 1;
    int kerdes_szam = 0;
    int felezes = 0;
    int kozonseg = 0;
    while(ciklus || kerdes_szam == 15){
        for(mozgo = lista;mozgo != NULL;mozgo = mozgo->kov){
            iter++;
            if(iter == random_kerdesek[kerdes_szam]){
                int seged = kerdes_kiir(mozgo->sor);
                int seged2 = valaszok_kiir(mozgo->sor,seged);
                if(!felezes || !kozonseg){
                    segitsegek(felezes,kozonseg);
                    segitseg_keres(mozgo->sor,&felezes,&kozonseg,seged,seged2);
                }
                char valasz = valaszadas();
                if(helyes_valasz(mozgo->sor,seged2,valasz)){
                    helyes_valaszok++;
                }
                else{ciklus = 0;}
            }       
        }
        iter = 0;
        mozgo = lista;
        kerdes_szam++;
    }

    felszabadit(lista);
    return helyes_valaszok;
}