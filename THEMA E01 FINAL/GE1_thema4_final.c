#include <stdio.h>

int main()

{
    FILE *fp;

    int a,choice,c,i,j,left,right,first,sum;        // дгкысг летабкгтым пяоцяаллатос
    char bus[54], pinakida[8], answer;
    for (j=0; j<54; j++)                    // аявийопоигсеи пимайа
    bus[j]=0;

    fp = fopen ("bus.txt","r");             // амоицла аявеиоу йаи еисацыцг дедолемым
    fscanf(fp,"%s%d\n", &pinakida, &a);
    fclose (fp);

    if (a>53) {                                 // екецвос циа лецисто аяихло хесеым
    printf ("YPERARITHMO MAX 53 THESIS\n");
    return 0;
    }
    else if  (((a-5)%4)!=0) {                   // екецвос циа йатамолг хесеым 4вм+5
    printf ("LATHOS KATANOMI THESEON\n");
    return 0;
    }
    else {                          //сумевеиа отам ои пяогцоулемои екецвои епистяеьоум false
    printf("Ar. Kikloforias leoforiou '%s' Ar. Theseon: %d\n", pinakida,a);
    }

    do {
    printf  ("\nKENTRIKO MENOY\n");
    printf  ("1 KATANOMI ELEFTHERON THESEON\n");
    printf  ("2 KRATISI THESIS\n");
    printf  ("3 KRATISI THESIS STO PARATHIRO\n");
    printf  ("4 AKIROSI ARITHMOU THESIS\n");
    printf  ("5 ELENCHOS ARITHMOU THESIS\n");
    printf  ("6 KATANOMI KATELIMENON THESEON\n");
    printf  ("7 KATASTASI FORTOSIS\n");
    printf  ("0 EXODOS\n");
    printf  ("ESAGETAI EPILOGI:");
    while(scanf("%d",&choice) != 1)     // диабасла дедолемым апо еисодо  йаи екевцос оти еисацоуле ломо аяихло
    {printf("ESAGETAI EPILOGI:");
     while(getchar() != '\n');}
    // екецвос епикоцгс лемоу
    if (choice !=0 && choice!=1 && choice!=2 && choice!=3 && choice !=4 && choice!=5 && choice!=6 && choice!=7)  {
    printf ("MI APODECHTI EPILOGI\n");
    }
    if (choice ==0) {       //енодос
     printf ("\nBon Voyage Bus No %s\n", pinakida);
    }
    if ( choice ==1) {      //йатамолг екеухеяым хесеым
    printf("\nKATANOMI ELEFTHERON THESEON");
    sum=0;
    printf("\nDIATHESIMES THESIS STO LEOFORIO\n");
    for (j=1 ; j<=a ; j++ ) {
    if (bus[j]==0)
    printf("[%d]", j);
    sum += bus[j];
    }
    printf("\nSinolo eleftheron theseon : %d \n", (a-sum));
    }

    if (choice ==2) {       //уполемоу йяатгсг хесгс ле тгм емеяцеиа тым апаяаитгтым екецвым
    printf("\nYPOMENOY KRATISIS THESEON\n");
    printf("EISAGETAI 0 (MIDEN) GIA EPISTROFI STO KENTRIKO MENOY\n");
    do {
    printf ("Diloste arithmo Thesis -->");
    while(scanf("%d",&j) != 1)
    {printf("Diloste arithmo Thesis --> ");
     while(getchar() != '\n');}
    if (j>a) {
    printf ("Mi apodektos arithmos thesis\n");
    }
    else if (bus[j]==1 && j!=0) {
    printf ("\nH thesi me ar. %d einai Katelimeni epilexte alli thesi\n", j);
    }
    else
    bus[j] = 1;
    } while (j!=0);
    }

    if ( choice ==3) {      // упокоцислос йаи йатакгьг тгс пяытгс диахесилгс хесгс сто паяахуяо
    printf("\nYPOMENOY THESI STO PARATHIRO\n");
    left=a;
    for ( j = 1 ; j<=a; j+=4){
    if (bus[j]==0)
    left=(j<left) ? j: left;
    }
    right=a;
    for (j = 1 ; j<=(a-5); j+=4){
    if (bus[j+3]==0)
    right=((j+3)<right) ? (j+3): right;
    }
    first =(left<right) ? left: right;
    printf("\nProti thesi parathiro Ar.--> %d\n", first);
    printf("H thesi me Arithmo %d katalifthike\n", first, bus[first]=1);
    printf("=====================================\n");
    }

    if (choice ==4) {           //уполемоу айуяысг хесгс ле тгм емеяцеиа тым апаяаитгтым екецвым
    printf("\nAKIROSI THESIS\n");
    printf("EISAGETAI 0 (MIDEN) GIA EPISTROFI STO KENTRIKO MENOY\n");
    do {
    printf ("\nDiloste ar. thesis gia akirosi-->");
    while(scanf("%d",&j) != 1)
    {printf("Diloste ar. thesis gia akirosi--> ");
    while(getchar() != '\n');}
    if (j>a) {
    printf ("Mi apodektos arithmos thesis\n");
    }
    else if (bus[j]==1 && j!=0) {
    do {
    printf ("H thesi me ar. %d einai Katelimeni\n", j);
    printf("Thelete na akirosete ti thesi (Y/N)");
    scanf(" %c",&answer);
    ((answer =='Y') || (answer =='y')) ? printf("\nH thesi akirothike\n", bus[j]=0, answer='n') : printf("\nYPOMENOU: AKIROSI THESIS\n");
    } while (answer=='Y' || answer=='y');
    }
    else {
    printf("H thesi einai keni\n");}
    }while (j!=0);
    }

    if (choice ==5) {        //уполемоу амафгтгсг йяатглемгс хесгс ле тгм емеяцеиа тым апаяаитгтым екецвым
    printf("\nELENCHOS THESIS\n");
    printf("EISAGETAI 0 (MIDEN) GIA EPISTROFI STO KENTRIKO MENOY\n");
    do {
    printf ("\nDiloste ar. thesis gia elencho -->");
    while(scanf("%d",&j) != 1)
    {printf("Diloste ar. thesis gia elencho --> ");
     while(getchar() != '\n');}
    if (j>a) {
    printf ("Mi apodektos arithmos thesis\n");
    }
    else if (bus[j]==1 && j!=0) {
    printf ("H thesi me ar. %d einai Katelimeni\n", j);
    }
    else {
    printf("H thesi einai keni\n");}
    }while (j!=0);
    }

    if ( choice ==6) {       //йатамолг йатекеилемым хесеым
    printf("\nKATELIMENES THESIS STO LEOFORIO\n");
    sum=0;
    for (j=1 ; j<=a ; j++ ) {
    if (bus[j]==1)
    printf("[%d]", j);
    sum += bus[j];
    }
    printf("\nSinolo kateleimenon theseon : %d \n", sum);
    }

    if ( choice ==7) {      //елжамисг сведиаццяалатос хесеым ле вягсг - йаи *
    printf  ("\nKATASTASI FORTOSIS\n");
    printf("%s\n", pinakida);
    for (c =1 ; c <=a ; c++ ) {
    (bus[c]==0)? (bus[c]='-'): (bus[c]='*');
    }
    for ( c = 1 ; c <=(a-5); c+=4){
    printf("\n%c%c %c%c", bus[c], bus[c+1], bus[c+2], bus[c+3]);
    }
    if (c=a) {
    printf("\n%c%c%c%c%c\n", bus[c-4], bus[c-3], bus[c-2], bus[c-1], bus[c]);
    }
    for (c =1 ; c <=a ; c++ ) {
    (bus[c]=='-')? (bus[c]=0): (bus[c]=1);
    }
    }
    } while (choice!=0);


    // еццяажг се аявеио тгс текийгс йатастасгс тым хесеым тоу кеожыяеиоу
    fp=fopen("layout.txt","w");
    for (i =1 ; i <=a ; i++ ) {
    (bus[i]==0)? (bus[i]='-'): (bus[i]='*');
    }
    fprintf (fp,"%s\n", pinakida);
    for ( i = 1 ; i <=(a-5); i+=4){
    fprintf(fp,"\n%c%c %c%c", bus[i], bus[i+1], bus[i+2], bus[i+3]);
    }
    if (i=a) {
    fprintf(fp,"\n%c%c%c%c%c", bus[i-4], bus[i-3], bus[i-2], bus[i-1], bus[i]);
    }
    fclose (fp);

    return 0;
}
