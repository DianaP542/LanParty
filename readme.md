# LanParty- tema anul 1 semestrul 2
  > Facultatea de Automatica si Calculatoare prin LSAC organizează in fiecare semestru un LAN Party la care participă toți studenții care vor sa își testeze abilitățile la un anumit joc. Se dorește realizarea unei soluții software(program executabil) ce poate automatiza acest proces.
  >
  Cerintele si restrictiile de rulare se gasesc [aici](https://ocw.cs.pub.ro/courses/sda-ab/tema1)

  ## Functionare
  - Codul mai intai deschide cele 3 fisiere care vor fi folosite in program: c.in apartine fisierului cerinte, d.in fisierului date si out.out fisierului printare.
  - Se citeste vectorul cerinta din c.in si apoi, in functie de input ul dat, se citeste lista de echipe in "addAtBegining". Aceasta este functia data din curs dar modificata sa introduca input ul unei liste ca si valoarea nodului.
  - Functia teamInfo citeste numarul de elevi din echipa si, folosind un aux, ia 50 de caractere pe care le desparte in cuvinte si le readauga in lista, dupa care citeste datele fiecarui student in fisierul studentInfo.
  - Daca se cere doar cerinta 1, atunci se printeaza lista.
  - In cerinta 2, se creeaza un nou camp pentru structura Team unde se stocheaza punctajul per total al echipei care se calculeaza intr-o functie separata numita teamPointCount.
Functia nTeams gaseste numarul n, cea mai mare putere de 2, mai mica decat numarul de echipe si dupa asta apeleaza de teamNr-n ori functia wosrtTeam. Functia gaseste echipa cu punctajul minim si o sterge intr o alta functie.
  - In cerinta 3, se creeaza meciurile in functia Matches, care creeaza o coada si 2 stive,pune toate echipele in coada, gaseste castigatorul rundei intr-o alta functie, sterge pierzatori, reumple coada cu castigatori si repeta, salvand in acelasi timp echipele din top 8.

  ## Completari
  &emsp; La momentul predarii tema a rulat doar primele cerinte. Vor fi create/postate completari cu rezolvarea intregii teme atunci cand voi avea posibilitatea. 
