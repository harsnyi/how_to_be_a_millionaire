#include <stdio.h>
#include "fajlkezeles_lista.h"
#include "jatekmenet.h"
#include <stdlib.h>




void menu(){

    int nehezseg;
    int opcio = 0;
    int ciklus=1;
    int helyes_valaszok=0;
    int rekordok_szama = 0;
    

    char *nev = nev_bekeres();
    printf("\nKerem valasszon a lehetosegek kozul!\n");
    while(ciklus==1){
    
        printf("1 - Uj jatek kezdese\n");
        printf("2 - Dicsoseglista lekerdezese\n");
        printf("3 - Kilepes\n");
        printf("?");scanf(" %d",&opcio);
        switch (opcio)
        {
        case 1:
            
            nehezseg = valasztas();
            helyes_valaszok = jatek_menet(nehezseg);
            printf("\nHelyesen megvalaszolt kerdesek: %d\n",helyes_valaszok);
            if(helyes_valaszok > 0){
                printf("Szep volt %s !\n",nev);
                fajlba_iras(nev,nehezseg,helyes_valaszok);
            }
            nehezseg = 0;
            helyes_valaszok = 0;
            break;
        case 2:
            rekordok_szama = dicsoseg_lista();
            if(rekordok_szama > 0){kiir(rekordok_szama);}

            break;
        
        case 3:
            
            nev_felszabadit(nev);
            printf("Viszlat");
            ciklus = 0;
            break;

        default:
            printf("\nKerem a lehetseges opciok kozul valasszon!\n");
            break;
        }
    }
}