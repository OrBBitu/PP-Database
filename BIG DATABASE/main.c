#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum tip_produs
{magazine=0, video_game, album, cinematography};

enum genre1
{action=0, adventure, horror, drama};

enum genre2
{classical=0, rock, folk, pop};

struct MAGAZINE  /// STRUCTURA PENTRU REVISTE
{
    unsigned int year;
    unsigned int month:4;
};
struct GAME /// STRUCTURA PENTRU JOCURI VIDEO
{
    unsigned int year;
    enum genre1 g;
};

struct SONGS /// STRUCTURA PENTRU ALBUME
{
    char band[50];
    unsigned int track_nr;
    enum genre2 s;
};

struct MOVIE /// STRUCTURA PENTRU FILME
{
    char nume_regizor[20];
    unsigned int minute;
    enum genre1 m;
};

typedef struct Produs /// STRUCTURA CU UNIUNE PENTRU PRODUS OARECARE
{
    int id;
    char title[50];
    unsigned int price;
    enum tip_produs type;
    union info
    {
     struct MAGAZINE mag;
     struct MOVIE mov;
     struct GAME gam;
     struct SONGS alb;
    }obj[100];
};

struct Produs produs[100]; /// VECTOR DE STOCARE PENTRU PRODUSE

typedef struct Oferta /// STRUCTURA PENTRU OFERTE
{
    int id_oferta;
    char title1[50];
    char title2[50];
    unsigned int price;
};

struct Oferta oferta[100]; /// VECTOR DE STOCARE PENTRU OFERTE

void afis_produse(int id) /// AFISEAZA UN PRODUS DUPA ID
{
    switch(produs[id-1].type)
    {
    case 0 :
        {
            fflush(stdin);
            printf("ID-ul produsului este %d.\n", id);
            printf("Numele revistei este %s.\n", produs[id-1].title);
            printf("Revista a fost lansata in anul %d, luna %d.\n", produs[id-1].obj[id-1].mag.year, produs[id-1].obj[id-1].mag.month);
            printf("Pretul revistei este de %d lei.\n", produs[id-1].price);
            break;
        }
    case 1 :
        {
            fflush(stdin);
            printf("ID-ul produsului este %d.\n", id);
            printf("Numele jocului este %s.\n", produs[id-1].title);
            printf("Jocul a fost lansat in anul %d.\n", produs[id-1].obj[id-1].gam.year);
            printf("Pretul jocului este de %d lei.\n", produs[id-1].price);
            switch(produs[id-1].obj[id-1].gam.g)
            {
            case 0 :
                {
                    printf("Genul jocului este ACTIUNE.\n");
                    break;
                }
            case 1 :
                {
                    printf("Genul jocului este AVENTURA.\n");
                    break;
                }
            case 2 :
                {
                    printf("Genul jocului este HORROR.\n");
                    break;
                }
            case 3 :
                {
                    printf("Genul jocului este DRAMA.\n");
                    break;
                }
            }
            break;
        }
    case 2 :
                {
                    fflush(stdin);
                    printf("ID-ul produsului este %d.\n", id);
                    printf("Numele albumului este %s si este al trupei %s.\n",produs[id-1].title, produs[id-1].obj[id-1].alb.band);
                    printf("Albumul are un numar total de %d melodii si costa %d LEI.\n", produs[id-1].obj[id-1].alb.track_nr, produs[id-1].price);
                    switch(produs[id-1].obj[id-1].alb.s)
            {
            case 0 :
                {
                    printf("Genul albumului este MUZICA CLASICA.\n");
                    break;
                }
            case 1 :
                {
                    printf("Genul albumului este ROCK.\n");
                    break;
                }
            case 2 :
                {
                    printf("Genul albumului este FOLK.\n");
                    break;
                }
            case 3 :
                {
                    printf("Genul albumului este POP.\n");
                    break;
                }
            }
            break;
                }

    case 3 :
                {
                    fflush(stdin);
                    printf("ID-ul produsului este %d.\n", id);
                    printf("Numele filmului este %s, fiind regizat de %s.\n",produs[id-1].title, produs[id-1].obj[id-1].mov.nume_regizor);
                    printf("Filmul are un numar total de %d minute, iar pretul sau este de %d LEI.\n", produs[id-1].obj[id-1].mov.minute, produs[id-1].price);
                    switch(produs[id-1].obj[id-1].mov.m)
            {
            case 0 :
                {
                    printf("Genul filmului este ACTIUNE.\n");
                    break;
                }
            case 1 :
                {
                    printf("Genul filmului este AVENTURA.\n");
                    break;
                }
            case 2 :
                {
                    printf("Genul filmului este HORROR.\n");
                    break;
                }
            case 3 :
                {
                    printf("Genul filmului este DRAMA.\n");
                    break;
                }
            }
            break;
                }
}
printf("\n\n");
}

void insert_produs(int i) /// INSEREAZA UN PRODUS IN VECTORUL DE PRODUSE
{
    int x;
    int OK;
    int id=0;
    printf("Ce produs doriti sa inregistrati?\n\n");
    printf("------------------------------\n");
    printf("1 ---> REVISTA\n");
    printf("2 ---> JOC VIDEO\n");
    printf("3 ---> ALBUM\n");
    printf("4 ---> FILM\n");
    printf("------------------------------\n");
    do{
    OK=1;
    scanf("%d", &x);
    printf("\n");
    if(x<1 || x>4)
    {
        OK=0;
        printf("Ati ales gresit. Incercati din nou.\n");
    }
    }while(OK!=1);
    switch(x-1)
    {
        case 0 :
               {
               int aux;
               produs[i].type=0;
               printf("Ce titlu are revista?\n");
               scanf("%50s", produs[i].title);
               printf("Ce pret are revista?\n");
               scanf("%d", &aux);
               produs[i].price=aux;
               printf("In ce an a fost publicata revista?\n");
               int OK;
               do{
               OK=1;
               scanf("%d", &aux);
               if(aux>2017 || aux<1900)
               {
                   OK=0;
                   printf("Anul ales este incorect. Incercati din nou.\n");
               }
               }while(OK!=1);
               produs[i].obj[i].mag.year=aux;
               printf("In ce luna a anului respectiv?\n");
               do{
               OK=1;
               scanf("%d", &aux);
               if(aux>12 || aux<1)
               {
                   OK=0;
                   printf("Luna aleasa este incorecta. Incercati din nou.\n");
               }
               }while(OK!=1);
               produs[i].obj[i].mag.month=aux;
               produs[i].id=id+1;
               printf("\n\n");
               break;
               }

        case 1 :
               {
               int aux;
               produs[i].type=1;
               printf("Ce titlu are jocul video?\n");
               scanf("%50s", produs[i].title);
               printf("Ce pret are jocul video?\n");
               scanf("%d", &aux);
               produs[i].price=aux;
               printf("In ce an s-a lansat jocul video?\n");
               int OK;
               do{
               OK=1;
               scanf("%d", &aux);
               if(aux>2017 || aux<1900)
               {
                   OK=0;
                   printf("Anul ales este incorect. Incercati din nou.\n");
               }
               }while(OK!=1);
               produs[i].obj[i].gam.year=aux;
               printf("Ce gen este jocul video?\n");
               do{
               OK=1;
               printf("------------------------------\n");
               printf("1 ---> ACTIUNE\n");
               printf("2 ---> AVENTURA\n");
               printf("3 ---> HORROR\n");
               printf("------------------------------\n");
               scanf("%d", &aux);
               if(aux<1 || aux>3)
               {
                   OK=0;
                   printf("Ati ales gresit. Incercati din nou.\n");
               }
               }while(OK!=1);
               switch(aux-1)
               {
                   case 0 : produs[i].obj[i].gam.g=0;
                          break;
                   case 1 : produs[i].obj[i].gam.g=1;
                          break;
                   case 2 : produs[i].obj[i].gam.g=2;
                          break;
               }
               produs[i].id=id+1;
               printf("\n\n");
               break;
               }
        case 2 :

            {int aux;
            produs[i].type=2;
            printf("Ce titlu are albumul?\n");
            scanf("%50s", produs[i].title);
            printf("Carei trupa apartine albumul?\n");
            scanf("%50s", produs[i].obj[i].alb.band);
            printf("Ce pret are albumul?\n");
            scanf("%d", &aux);
            produs[i].price=aux;
            printf("Cate piese are albumul?\n");
            scanf("%d", &aux);
            produs[i].obj[i].alb.track_nr=aux;
            printf("Ce gen de muzica este albumul?\n");
            do{
            printf("------------------------------\n");
            printf("1 ---> CLASICA\n");
            printf("2 ---> ROCK\n");
            printf("3 ---> FOLK\n");
            printf("4 ---> POP\n");
            printf("------------------------------\n");
            scanf("%d", &aux);
            if(aux<1 || aux>4)
            {
                OK=0;
                printf("Ati ales gresit. Incercati din nou.\n");
            }
            }while(OK!=1);
            switch(aux-1)
               {
                   case 0 :
                          {produs[i].obj[i].alb.s=0;
                          break;
                          }
                   case 1 :
                          {produs[i].obj[i].alb.s=1;
                          break;
                          }
                   case 2 :
                          {produs[i].obj[i].alb.s=2;
                          break;
                          }
                   case 3 :
                          {produs[i].obj[i].alb.s=3;
                          break;
                          }
               }
            produs[i].id=id+1;
            printf("\n\n");
            break;
            }
        case 3 :
            {
            int aux, OK;
            produs[i].type=3;
            printf("Cum se numeste filmul?\n");
            scanf("%50s", produs[i].title);
            printf("Cum il cheama pe regizorul filmului?\n");
            scanf("%50s", produs[i].obj[i].mov.nume_regizor);
            printf("Cat costa filmul?\n");
            scanf("%d", &aux);
            produs[i].price=aux;
            printf("Cate minute are filmul?");
            scanf("%d", &aux);
            produs[i].obj[i].mov.minute=aux;
            printf("Ce gen este filmul?\n");
            do{
            OK=1;
            printf("------------------------------\n");
            printf("1 ---> ACTIUNE\n");
            printf("2 ---> AVENTURA\n");
            printf("3 ---> HORROR\n");
            printf("4 ---> DRAMA\n");
            printf("------------------------------\n");
            scanf("%d", &aux);
            if(aux<1 || aux >4)
            {
                OK=0;
                printf("Ati ales gresit. Incercati din nou.\n");
            }
            }while(OK!=1);
            switch(aux-1)
               {
                   case 0 :
                       {produs[i].obj[i].mov.m=0;
                          break;
                       }
                   case 1 :
                       {produs[i].obj[i].mov.m=1;
                          break;
                       }
                   case 2 :
                       {produs[i].obj[i].mov.m=2;
                          break;
                       }
                   case 3 :
                       {produs[i].obj[i].mov.m=3;
                          break;
                       }
               }
            produs[i].id=id+1;
            printf("\n\n");
            break;
            }
}

}


void insert_oferta(int i, int id1, int id2) /// INSEREAZA O OFERTA IN VECTORUL DE OFERTE
{
   strcpy(oferta[i].title1, produs[id1-1].title);
   strcpy(oferta[i].title2, produs[id2-1].title);

   printf("Oferta facuta cu produsul de ID %d --- %s si produsul de ID %d --- %s.\n", id1, oferta[i].title1, id2, oferta[i].title2);

   unsigned int p1;
   unsigned int p2;
   p1=pret(id1);
   p2=pret(id2);
   unsigned int p_final=p1+p2;
   oferta[i].price=p_final;
   discount(&(oferta[i].price));

   oferta[i].id_oferta=i+1;
   printf("\n\n");
}

int pret(id) /// RETURNEAZA PRETUL UNUI PRODUS DUPA ID
{
    return produs[id-1].price;
}

int discount(int *pret) /// FUNCTIE PENTRU DISCOUNT. PRETUL SE SCHIMBA LA IESIREA DIN FUNCTIE
{
    printf("Pretul initial este de %d LEI.\n", *pret);
    printf("Ce procent promotional doriti sa aplicati?\n");
    int procent;
    scanf("%d", &procent);
    int p=100-procent;
    *pret=(p * (*pret))/100;
    printf("Noul pret este de %d LEI.", *pret);
    return *pret;
}

int majorare(int *pret) /// FUNCTIE PENTRU MAJORARE. PRETUL SE SCHIMBA LA IESIREA DIN FUNCTIE
{
    printf("Pretul initial este de %d LEI.\n", *pret);
    printf("Ce procent de majorare doriti sa aplicati?\n");
    int procent;
    scanf("%d", &procent);
    int p=(procent * (*pret))/100;
    *pret=(*pret)+p;
    printf("Noul pret este de %d LEI.", *pret);
    return *pret;
}

void ordonare_alf(struct Produs *point, int nr_produse) /// ORDONARE ALFABETICA A PRODUSELOR.
{
    unsigned short i;
    for (i = 0 ; i < nr_produse ; i++)
    {
        struct Produs x = produs[i];
        short j;
        for (j = i - 1 ; j >= 0 && strcmp( produs[j].title , x.title ) > 0 ; j--)
            produs[j + 1] = produs[j];
        j++;
        produs[j] = x;
    }
    printf("Numele in ordine alfabetica sunt :\n");
    for(i=0;i<nr_produse;i++)
    {

     printf("%s \n",produs[i].title);
    }
}

void ordonare_pret_cresc(struct Produs *point, int nr_produse) /// ORDONARE CRESCATOARE A PRETURILOR PRODUSELOR
{
    unsigned short i;
    for (i = 0 ; i < nr_produse ; i++)
    {
        struct Produs x = produs[i];
        short j;
        for (j = i - 1 ; j >= 0 && produs[j].price > x.price ; j--)
            produs[j + 1] = produs[j];
        j++;
        produs[j] = x;
    }
    printf("Produsele ordonate crescator dupa pret sunt :\n");
    for(i=0;i<nr_produse;i++)
    {
        printf("%s --- %d LEI\n", produs[i].title, produs[i].price);
    }
}

int compare_title(const void *a, const void *b) /// FUNCTIE DE COMPARARE PENTRU QSORT
{
    struct Produs *ia = (struct Produs *)a;
    struct Produs *ib = (struct Produs *)b;
    return strcmp(ia->title, ib->title);
}

int main()
{

    struct Produs *point;
    int i, n;
    printf("Cate produse doriti sa introduceti in sistem?\n");
    scanf("%d", &n);
    printf("\n");
    for(i=0;i<n;i++)
        insert_produs(i);
    int optiune;
    do{
    printf("Ce operatii doriti sa efectuati?\n");
    printf("-------------------------------------\n");
    printf("1 -----> AFISAREA TUTUROR PRODUSELOR\n");
    printf("2 -----> AFISAREA UNUI PRODUS (se va cere ID-ul)\n");
    printf("3 -----> APLICAREA UNUI DISCOUNT (se va cere ID-ul)\n");
    printf("4 -----> APLICAREA UNEI MAJORARI (se va cere ID-ul)\n");
    printf("5 -----> ORDONARE DUPA NUME (QSORT) + AFISARE\n");
    printf("6 -----> ORDONARE DUPA NUME + AFISARE\n");
    printf("7 -----> ORDONARE DUPA PRET + AFISARE\n");
    printf("8 -----> FACETI O OFERTA\n");
    printf("9 -----> IESIRE\n");
    printf("-------------------------------------\n");

    scanf("%d", &optiune);
    switch(optiune)
    {
  case 1 :
    {
        for(i=1;i<=n;i++)
        {

            afis_produse(i);
            printf("\n");
        }
        break;
    }
  case 2 :
    {
        int id;
        printf("Introduceti ID-ul.\n");
        scanf("%d", &id);

        afis_produse(id);
        break;
    }
  case 3 :
    {
        int id;
        int x;
        int p_final;
        printf("Introduceti ID-ul.\n");
        scanf("%d", &id);
        x=pret(id);
        p_final=discount(&x);
        produs[id-1].price=p_final;
        break;
    }
  case 4 :
    {
        int id;
        int x;
        int p_final;
        printf("Introduceti ID-ul.\n");
        scanf("%d", &id);
        x=pret(id);
        p_final=majorare(&x);
        produs[id-1].price=p_final;
        break;
    }
  case 5 :
    {

        qsort(produs, n, sizeof(struct Produs), compare_title);
        printf("Produsele ordonate alfabetic dupa quickSort : \n");
        for(i=0;i<n;i++)
            {
                printf("%d.%s\n", i+1, produs[i].title);
            }
        break;
    }
  case 6 :
    {

        ordonare_alf(point, n);
        break;
    }

  case 7 :
    {

        ordonare_pret_cresc(point, n);
        break;
    }
  case 8 :
    {
        printf("Cate oferte doriti sa creati?\n");
        int nr;
        scanf("%d", &nr);
        for(i=0;i<nr;i++)
        {

            printf("Introduceti ID-urile celor doua produse.\n");
            int id1, id2;
            scanf("%d", &id1);
            scanf("%d", &id2);
            insert_oferta(i, id1, id2);
        }
        break;
    }
    }
    }while(optiune!=9);

    return 0;
}







