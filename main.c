/************************************************************************/
/*Program jest kalkulatorem w notacji odwrotnej do Polskiej (sufiksowej)*/
/*        Pozwala na wywołanie 4 podstawowych działań na liczbach       */
/*      Są to: +,-,/,*, gdzie / - to dzielenie i * - to mnożenie        */
/*        Program jest dodatkowo wyposażony w funkcje pomocnicze        */
/*                                                                      */
/*   P - odpowiada za usunięcie ostatnio wpisanej liczby                */
/*   c - odpowiada za usunięcie wszystkich wpisanych liczb              */
/*   d - odpowiada za duplikowanie wpisywanej/ostatnio wpisanej liczby  */
/*   f - odpowiada za wypisanie wszystkich dotychczas podanych liczb    */
/*   p - odpowiada za wypisanie ostatnio podanej liczby                 */
/*   r - odpowiada za zamianę miescami ostatnio podanych 2 liczb        */
/*   q - pozwala wyłączyć program                                       */
/************************************************************************/

#include"stos.h"
int main()
{
  t_stos *stos;
  char oper=' ';

  int dana, arg1, arg2;
  inicjuj(&stos);
  while(oper!='q'){
  oper = getc(stdin);                 /*pobiera znak z wejścia*/
  if(isdigit(oper)){                    /*jeżeli znak jest cyfrą*/
  ungetc(oper,stdin);                   /*zwraca cyfrę*/
  scanf("%d",&dana );                   /*odczytuje cyfrę*/
  push(&stos, &dana);                   /*dodaje cyfrę na stos*/
  }else if(oper=='\n' || oper==' '){} /*jeżeli znakiem jest znak nowej lini albo biały znak, rób nic*/
  else{
    switch(oper){

        case'+':                         /*jeżeli znakiem jest +*/
    {
      char tmp=getc(stdin);              /*pobierz znak i zapamiętaj go*/
      if(isdigit(tmp)){                   /*jeżeli znak to cyfra*/
      ungetc(tmp,stdin);                   /*zwróć cyfrę*/
      scanf("%d", &arg1);                  /*odczyaj cyfrę*/
      push(&stos, &arg1);                   /*i daj cyfrę na stos*/
      }                    /*warunek pozwalający na zapis np. +48 jako 48 */
      else{ungetc(tmp,stdin);                   /*jeżeli po znaku plus nie ma liczby to zwróć pobrany znak*/
    if(!empty(&stos)){                   /*i sprawdź czy stos ma co najmniej 2 argumenty*/
      arg1=pop(&stos, &arg1);             /*jeżeli ma to zrób operację dodawania*/
      if(!empty(&stos)){
	arg2=pop(&stos, &arg2);
  dana=(arg1+arg2);
	push(&stos, &dana);
  printf("wynik: %d\n", dana);    /*!!!!!!!!!!!!!!!!!!!!!!*/
      }
      else{
	printf("Za mało\n");
	  push(&stos, &arg1);
	  }
    }else
      printf("Brak danych\n");
    }
    }
    
    break;


    case'-':            /*jeżeli znakiem jest - */
    {
      char tmp=getc(stdin);             /*sprawdź czy po minusie jest liczba*/
      if(isdigit(tmp)){            /*jeśli tak, to zapisz na stosie liczbę z minusem*/
      ungetc(tmp,stdin);
      scanf("%d", &arg1);
      dana=-arg1;
      push(&stos, &dana);
      }
      else{ungetc(tmp,stdin);            /*jeżeli nie, to */
    if(!empty(&stos)){                    /*sprawdź czy stos ma conajmniej 2 argumenty*/
      arg1=pop(&stos, &arg1);             /*jeżeli ma to zrób operację odejmowania*/
      if(!empty(&stos)){
	arg2=pop(&stos, &arg2);
  dana=(arg2-arg1);
	push(&stos, &dana);
  printf("wynik: %d\n", dana);    /*!!!!!!!!!!!!!!!!!!!!!!*/
      }
      else{
	printf("Za mało\n");
	  push(&stos, &arg1);
	  }
    }else
      printf("Brak danych\n");
    }
    }
    break;


    case'*':                      /*jeżeli znakiem jest * */
    {
      if(!empty(&stos)){              /*sprawdź czy stos ma conajmniej 2 argumenty*/      
      arg1=pop(&stos, &dana);       /*jeżeli ma to zrób operację mnożenia*/
      if(!empty(&stos)){
	arg2=pop(&stos, &dana);
  dana=(arg1*arg2);
	push(&stos, &dana);
  printf("wynik: %d\n", dana);    /*!!!!!!!!!!!!!!!!!!!!!!*/
      }
      else{
	printf("Za mało\n");
	  push(&stos, &arg1);
	  }
    }else
      printf("Brak danych\n");
    }
    break;


case'/':                      /*jeżeli znakiem jest / */
    {
      if(!empty(&stos)){              /*sprawdź czy stos ma conajmniej 2 argumenty*/ 
      arg1=pop(&stos, &dana);             /*jeżeli ma to zrób operację dzielenia*/
      if(!empty(&stos)){
	arg2=pop(&stos, &dana);
  dana=(arg2/arg1);
	push(&stos, &dana);
  printf("wynik: %d\n", dana);    /*!!!!!!!!!!!!!!!!!!!!!!*/
      }
      else{
	printf("Za mało\n");
	  push(&stos, &arg1);
	  }
    }else
      printf("Brak danych\n");
    }
    break;

    case'd':                    /*jeżeli znakiem jest d */
    {
      if(!empty(&stos)){        /*i stos nie jest pusty*/
        pop(&stos, &dana);       /*duplikuj liczbę na górze stosu*/
        push(&stos, &dana);
        push(&stos, &dana);
        printf("Duplikuję %d \n", dana);    /*!!!!!!!!!!!!!!!!!!!!!!*/
      }else{
        printf("Brak danych\n");
      }
    }
    break;

    case'r':                  /*jeżeli znakiem jest r */
    {
       if(!empty(&stos)){              /*sprawdź czy stos ma conajmniej 2 argumenty*/ 
      arg1=pop(&stos, &dana);             /*jeżeli tak, to zamień 2 górne elementy miejscami*/
      if(!empty(&stos)){
	arg2=pop(&stos, &dana);
	push(&stos, &arg1);
  push(&stos, &arg2);
  printf("zamieniłem %d z %d\n",arg1, arg2);     /*!!!!!!!!!!!!!!!!!!!!!!*/
      }
      else{
	printf("Za mało\n");
	  push(&stos, &arg1);
	  }
    }else
      printf("Brak danych\n");
    }
    break;
    
    case'p':               /*jeżeli znakiem jest p */
    {printf("----\n");
      print1(&stos);      /*wypisz liczbę na szczycie stosu*/
      printf("----\n");                    
    }                     /*jeżeli stos jest pusty to nic nie zostanie zrobione*/
    break;

    case'c':            /*jeżeli znakiem jest c */
    {
      while(!empty(&stos)){     /*i stos nie jest pusty*/
        pop(&stos, &dana);      /*wyciągaj ze stosu elementy (usuwa je)*/
      }
    }
    break;

    case'P':
    {
      if(!empty(&stos)){
      arg1=pop(&stos, &dana);         /*wyciągaj ze stosu górny element (usuwa go)*/
      printf("Usunąłem %d\n", arg1);    /*!!!!!!!!!!!!!!!!!!!!!!*/
      }
    }
    break;

    case'f':       /*jeżeli znakiem jest f */
    {
      printf("-------\n"); 
    print(&stos);     /*wypisz wszystkie elementy stosu*/
    printf("-------\n");
    }
    break;

    case'q':{}
    
    default:
      printf("%c - Niepoprawna komenda\n", oper);  
    }
   
  }
  }

  while(!empty(&stos)){     /*odpowiada za czyszczenie pamięci*/
        pop(&stos, &arg1); 
      }

  return (0);
}




/*Sprawozdanie: Radomyr Tkachenko Kalkulator RPN 29.01.2023
1. Sprawdzanie poprawności programu przy wpisywaniu liczb.
  Program wykonuje instrukcję push, liczby z + i z - są wpisywane do stosu
  Program działa poprawnie

2. Sprawdzanie poprawności programu przy wpisywaniu znaku lub liter niezgodnych
    z specyfikacją.
  Przy wpisaniu nieodpowiedniego znaku, jest wyświetlany komunikat "nieznana komenda".
  Program działa poprawnie.

3. Sprawdzanie poprawności programu przy wpisywaniu znaku P.
  Program wykonuje instrukcję pop i wypisuje komunikat (usunąłem %d liczbę), 
  jeżeli na stosie jest liczba, jeżeli liczby nie ma, program nie wypisuje żadnego komunikatu.
  Program działa poprawnie.

4. Sprawdzanie poprawności programu przy wpisywaniu znaku c.
  Program wykonuje instrukcję pop aż stos będzie pusty, jeżeli na stosie jest liczba,
  jeżeli liczby nie ma, program nie wypisuje żadnego komunikatu.
  Program działa poprawnie.

5. Sprawdzanie poprawności programu przy wpisywaniu znaku d.
  Program wykonuje instrukcję pop, push, push, jeżeli na stosie jest liczba,
  jeżeli liczby nie ma, program wypisuje komunikat - Brak danych.
  Program działa poprawnie.

6. Sprawdzanie poprawności programu przy wpisywaniu znaku r.
  Program wykonuje instrukcję pop, pop, push, push, jeżeli na stosie są 2 liczby,
  jeżeli liczb nie ma, program wypisuje komunikat - Brak danych, lub - Za mało.
  Program działa poprawnie.

7. Sprawdzanie poprawności programu przy wpisywaniu znaku f.
  Program przebiega przez cały stos wskaźnikiem, jeżeli na stosie są liczby,
  to je wypisuje, jeżeli liczby nie ma, program wypisuje ozdobne puste nawiasy.
  Program działa poprawnie.

8. Sprawdzanie poprawności programu przy wpisywaniu znaku p.
  Program sprawdza pierwszy element stosu wskaźnikiem, jeżeli na stosie jest liczba,
  to ją wypisuje, jeżeli liczby nie ma, program wypisuje ozdobne puste nawiasy.
  Program działa poprawnie.

9. Sprawdzanie poprawności programu przy wpisywaniu znaku q.
  Program wykonuje instrukcję return 0.
  Program działa poprawnie.

10. Sprawdzanie poprawności programu przy wpisywaniu znaku /.
  Program wykonuje instrukcję pop, pop, push, gdzie push umieszcza liczbę po dzieleniu
  jeżeli na stosie są 2 liczby, jeżeli liczb nie ma, program wypisuje komunikat - Brak danych, lub - Za mało.
  Program działa poprawnie.

11. Sprawdzanie poprawności programu przy wpisywaniu znaku *.
  Program wykonuje instrukcję pop, pop, push, gdzie push umieszcza liczbę po wymnożeniu
  jeżeli na stosie są 2 liczby, jeżeli liczb nie ma, program wypisuje komunikat - Brak danych, lub - Za mało.
  Program działa poprawnie.

12. Sprawdzanie poprawności programu przy wpisywaniu znaku +.
  Program wykonuje instrukcję pop, pop, push, gdzie push umieszcza liczbę po dodaniu
  jeżeli na stosie są 2 liczby, jeżeli liczb nie ma, program wypisuje komunikat - Brak danych, lub - Za mało.
  Program działa poprawnie.

13. Sprawdzanie poprawności programu przy wpisywaniu znaku -.
  Program wykonuje instrukcję pop, pop, push, gdzie push umieszcza liczbę po odjęciu
  jeżeli na stosie są 2 liczby, jeżeli liczb nie ma, program wypisuje komunikat - Brak danych, lub - Za mało.
  Program działa poprawnie.

14. Sprawdzanie poprawności programu przy wpisywaniu kombinacji znaków i liczb.
  Przy kombinacjach liczb i znaków, program wykonuje kolejno polecenia.
  Np. przy wpisaniu "4d * 2 / 3 r" wykona się duplikacja 4, potem wymnożeniu 4*4,
  nstępnie podzielenie przez 2 i zamiana miejscami z 3.
  Program działa poprawnie.

UWAGA: Jedyną potencjalną wadą programu mogą być komunikaty, których może być za dużo,
ewentualnie mogą być nie jednorodne, w takim sensie, że przy usuwaniu jednego elementu
wyświetlany jest komunikat o udanym usunięciu lub brak komunikatu, a przy usunięciu
całego stosu nie są wypisywane żadne komunikaty.
*/