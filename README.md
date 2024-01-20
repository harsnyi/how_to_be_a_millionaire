# BMEVIEEAA00 Programozás alapjai házi feladat

A játék lényege, hogy a felhasználónak tegyen fel kérdéseket amikre 4 választási lehetősége van. Minden jól megválaszolt kérdéssel pontokat kap, a cél minél több pont összegyűjtése. Ha rosszul válaszol elveszti a kört, azonban ha legalább egy kérdésre jól válaszolt felkerülhet a dicsőséglistára.
## Futtatás
A játék konzolos felületen íródott, tehát elindításához elegendő a célmappában konzolos felületen a ./vegleges nevű parancsot futtatni. 

Miután a játékos elindította a játékot meg kell adnia nevét. Célszerű helyes nevet megadni, mert a megadott név alapján fog a játékos felkerülni a dicsőséglistára.

 ### Menü:

A név megadás után a játékos a menüben választhat a megadott opciók közül. Új játékot kezdhet, lekérheti a jelenlegi dicsőséglistát, vagy kiléphet a programból. A program egy számot vár ekkor a játékostól 1-től 3-ig.

### Új játék kezdése:

Miután a játékos az új játék kezdése opciót választotta, meg kell adnia a nehézségi szintet, amelyen kíván játszani. Ez a kérdések nehézségében fog megnyilvánulni, minél nehezebben játszik, annál fogósabb kérdésekre számíthat. Fontos még az is, hogy a végső pont kiszámítása a jól megválaszolt kérdések száma és a választott nehézség szorzata, tehát garantált, hogyha nehezebb nehézségi szintet választ, akkor több pontot lesz képes szerezni, feltéve ha sikerül több kérdést jól megválaszolnia. A program itt is egy számot vár a felhasználótól 1-től 3-ig.
 
### Játékmenet:

Miután a felhasználó választott nehézségi szintet megjelen számára az első kérdés, alatta a 4 választási lehetőséggel. Minden kérdésnél dönthet a játékos, hogy rögtön válaszol-e arra, vagy segítséget kér, ha maradt még segítségkérési lehetősége. Ezeket a lehetőségeket ki is írja a program a kérdések alatt a ’Felhasználható segítségek:’ után. A program tehát felteszi a kérdést, hogy kér-e segítséget a játékos? Itt egy ’I’ vagy ’N’ betűt vár. Ha N a bemenet, akkor válaszolnia kell a kérdésre a játékosnak.

### Ha segítséget kér a játékos:

Miután segítséget kért a játékos választania kell a fennmaradó segítségek közül. Itt is egy számot kér a program 1, vagy 2-őt. 

#### 1 – Felezés:
Ha a felhasználó ezt választja, akkor újra kiírja a játék a válaszokat, azonban csak kettőt, a helyes választ és még egyet mellé. Ezek után újra várja a válasz megadását. 
#### 2 – Közönség: 
Ha ezt választja a játékos, akkor a közönség szavazatainak eloszlását fogja látni a válaszokról és utána ugyanúgy várja tőle a játék a választ. Természetesen ha elfogytak a lehetőségek segítségkérésre a játék nem fogja feldobni azokat a játékosnak. Így mennek majd egymás után a kérdések, várva a választ a játékostól. Ha rosszul válaszolt, akkor utána a játék kiírja, hány kérdést sikerült eltalálnia.


### Modulok

- main.c
- fajlkezeles_lista.c
- menu.c
- jatekmenet.c

