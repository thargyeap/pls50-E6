//*************************************************************
//*** ���50 "������� ������������� �� ������ ��� ���������" ***
//***                   ������� �02 - ���� 1                ***
//***                                                       ***
//***                   ��.���� 2016-17                     ***
//***                                                       ***
//*************************************************************
#include <stdio.h>  /* ���� printf(), fscanf(), fopen(), fclose() */
#include <stdlib.h> /* ���� exit() */
#include <string.h> /* ���� strcmp(), strlen() */
#define TRUE 1
#define FALSE 0


/* ����� ��������� ��� ������ ������ ��� ���������� */
typedef struct {
   char name[40];          /* �������, ����, ����� */
   unsigned short tel[10]; /* 10-����� �������� */
   unsigned int seat ;     /* ������� ����� */
} epivatis;



void initialize(epivatis bus[], char *license, int *seats);
void neos_epivatis(epivatis *new_passenger);
void apeleutherwsi_thesis(epivatis *old);
void anazitisi_epivati(epivatis bus[], int seats);
void emfanisi_thesewn(epivatis bus[], int seats);
void plithos_kenwn_thesewn(epivatis bus[], int seats);
void save_in_file(epivatis bus[], char license[], int seats);

/* ������ ��������� */
void main()
{

   epivatis bus[53];          /* ������� ������ */
   char license[8];           /* �������� �����������, 7 ��������-������� ��� �� '\0' */
   int seats;                 /* ������ ������ */
   unsigned int seat;         /* ������� ����� */

   int choice;                /* ������� ������ */

   initialize(bus,license, &seats); /* ������������ ���������� ��� �� bus.txt */

   choice = 1; /* ������ ���� ��� ������ ��� loop */
   while (choice != 0) { /* ����� �� �������� �����������  */
      printf("1. emfanish synolikoy plhthous kenwn thesewn kai twn arithmwn tous\n");
      printf("2. krathsh theshs me sygkekrimeno arithmo\n");
      printf("3. anazhthsh gia to an einai krathmenh thesh me sygkekrimeno onomatepwnymo, i tilefwno\n");
      printf("4. akyrwsh krathshs theshs me sygkekrimeno arithmo\n");
      printf("5. emfanish listas krathmenwn thesewn taksinomhmenhs kata arithmo\n");
      printf("0. termatismos\n");
      scanf("%d", &choice); /* �������� �������� ������ */
      switch(choice) {
        case 1:
           plithos_kenwn_thesewn(bus,seats);
           break;
        case 2:
           printf("dwse arithmo thesis\n");
           scanf("%d", &seat);
           if (seat<1 || seat>seats) /* ������� ��� ������� ����� ����� ����� */
              printf("arithmos thesis ektos oriwn\n");
           else
              neos_epivatis(&bus[seat-1]);
           break;
        case 3:
           anazitisi_epivati(bus, seats);
           break;
        case 4:
           printf("dwse arithmo thesis\n");
           scanf("%d", &seat);
           if (seat<1 || seat>seats) /* ������� ��� ������� ����� ����� ����� */
              printf("arithmos thesis ektos oriwn\n");
           else
              apeleutherwsi_thesis(&bus[seat-1]);
           break;
        case 5:
           emfanisi_thesewn(bus, seats);
           break;
        case 0:  /* ���� ��� bus.txt ���� ��� ����� */
           save_in_file(bus, license, seats);
           break;
        default:
           printf("akatallili epilogi\n");
      }
    }
}

/* �������� ��������� ��� ������� ��o struct ��� ��������� ��� �� new_passenger */
void neos_epivatis(epivatis *new_passenger) {
   char name[40];  /* ��� ��� �������� ��� �������������� */
   int i;

   if (new_passenger->name[0] == '\0') { /* �� � ���� ����� �������� */
      printf("dwse epwnymo epibati\n");
      scanf("%s",name); /* ������� ������� */
      name[strlen(name)+1]='\0'; /* ���� ��� ���������� ��� ���� ��������� */
      name[strlen(name)] = ' '; /* ���� ���� ��� ���� ��� ����� ���� ����������� */
      printf("dwse onoma epibati\n");
      scanf("%s",name+strlen(name)); /* ������� ��� �������� ����� ������� */
      strcpy(new_passenger->name, name);  /* ��������� ��� struct �� ������������� */
      printf("dwse tilefwno\n");
      for (i=0;i<10;i++)
          scanf("%1hu",&(new_passenger->tel[i])); /* ������� �������� ���-��� ����� */
      printf("thesi kratithike\n");
   } else
      printf("thesi kratimeni\n");
}

/* ������������ ����� */
void apeleutherwsi_thesis(epivatis *old) {
    if (old->name[0] != '\0') { /* �� ���� ��� ����� �������� */
        old->name[0] = '\0';  /* ������������ ��� */
        printf("thesi eleutherwthike\n");
    }
    else
        printf("thesi idi eleutheri\n");
}

/* ��������� ������� ����� ��������, � ��������� */
void anazitisi_epivati(epivatis bus[], int seats){
    int i, j, flag, flag1;
    char name[40]; /* ��� ��� �������� ��� �������������� */
    unsigned int tel[10]; /* ��� ��� �������� ��� ��������� */

    printf("Gia anazitisi me epwnymo, dwse 1, me tilefwno, dwse allo symbolo\n");
    scanf("%d", &i);
    if (i == 1) {
       printf("dwse eponymo epibati\n");
       scanf("%s",name); /* ������� ������� */
       name[strlen(name)+1]='\0'; /* ���� ��� ���������� ��� ���� ��������� */
       name[strlen(name)] = ' '; /* ���� ���� ��� ���� ��� ����� ���� ����������� */
       printf("dwse onoma epibati\n");
       scanf("%s",name+strlen(name)); /* ������� ��� �������� ����� ������� */
       flag = FALSE;
       for (i=0;i<seats;i++) /* ���� ���� ��� ������ ��� ��� ������� name */
           if (bus[i].name[0] != '\0' && strcmp(bus[i].name, name)==0) { /* �� ���� ��������� ��� ��� name */
               printf("%s %d\n",bus[i].name, bus[i].seat); /* ������ ��� ������� */
               flag = TRUE; /* ����� ����������� 1 ������� */
           }
       if (!flag)
            printf("De brethike\n");
    } else {
       printf("dwse tilefwno\n");
       for (i=0;i<10;i++)
           scanf("%1d",&tel[i]); /* ������� �������� ���-��� ����� */
       flag1 = TRUE; /* ��� ��� ���� ������� ������� */
       for (i=0;i<seats;i++) /* ���� ���� ��� ������ ��� �� ��� tel[] */
           if (bus[i].name[0] != '\0') {/* �� ���� ��������� */
               flag = TRUE; /* ���� �� �������� ����� ���� */
               for (j=0;j<10;j++) /* �������� ��� �� ����� ��� ���. */
                  if (bus[i].tel[j] != tel[j]) /* �� ��� ����� �������� */
                     flag = FALSE; /* �� �������� ��������� */
               if (flag) { /* �� �� �������� ����� ���� */
                   printf("%s %d\n",bus[i].name, bus[i].seat); /* ������ ��� ������� */
                   flag1 = FALSE; /* ����� ����������� 1 ������� */
               }
           }
        if (flag1) /* �� ��� ��� ���� ������� ������� */
            printf("De brethike\n");
     }
}

/* �������� ���� ����������� ���� ����, � ��/���� */
void emfanisi_thesewn(epivatis bus[], int seats) {
     int i, j;

     printf("kratimenes theseis\n");
     for (i=0;i<seats;i++)
         if (bus[i].name[0] != '\0') {/* �� ���� ��������� */
             printf("%s %d ",bus[i].name, bus[i].seat); /* ������ ��� */
             for (j=0;j<10;j++)
                printf("%1d",bus[i].tel[j]);
             printf("\n");
         }
     printf("\n");
}

/* ����������� ������� ����� ������ */
void plithos_kenwn_thesewn(epivatis bus[], int seats){
    int i;
    int count = 0;   /* ������������ ������� */

    for (i=0;i<seats;i++)
       if (bus[i].name[0] == '\0') count++; /* �� ���� ��������, ������ ������� */
    printf("plithos kenwn thesewn = %d apo %d\nEleutheres theseis:\n",count,seats);
    for (i=0;i<seats;i++)
       if (bus[i].name[0] == '\0') /* �� ���� �������� */
             printf("%d ",i+1); /* ������ ��� */
    printf("\n");
}

/* ������������ ���������� �� �������� ��� ������. ������������ � ������������� ������� ������ */
void initialize(epivatis bus[], char *license, int *seats) {
   char name[40];             /* ��� ��� �������� ��� �������������� */
   unsigned int seat;         /* ��� ��� �������� ��� ����� */

   int i;
   FILE* f_in;        /* ������� �� ������ */

   f_in = fopen("bus.txt", "r"); /* ������� ������� ��� �������� */
   if(f_in == NULL) /* �� ��������� ����������� ���� �� ������� */
   {
      printf("To arxeio bus.txt de mporese na anagnwstei\n");
      exit(1);      /* ������ ��� �� ��������� */
   }
   fscanf(f_in,"%s %d", license, seats); /* ������� �������� ��� ������ ������ */
   for (i=0;i<*seats;i++) { /* ������������ ������ ���������� */
      bus[i].name[0] = '\0';
      bus[i].seat = i+1;
   }
   fscanf(f_in,"\n"); /* ���������� ��� ������ ������� */
   while (!feof(f_in)) { /* ����� ������ ��� ������� */
      fscanf(f_in,"%s",name); /* ������� ������� */
      name[strlen(name)+1]='\0'; /* ���� ��� ���������� ��� ���� ��������� */
      name[strlen(name)] = ' '; /* ���� ���� ��� ���� ��� ����� ���� ����������� */
      fscanf(f_in,"%s",name+strlen(name)); /* ������� ��� �������� ����� ������� */
      fscanf(f_in,"%d", &seat); /* ������� �� ���� */
      bus[seat-1].seat=seat; /* ���������� ��� struct �� ���� */
      strcpy(bus[seat-1].name, name); /* ��������� ��� struct �� ������������� */
      for (i=0;i<10;i++)
         fscanf(f_in,"%1hu",&bus[seat-1].tel[i]); /* ������� �������� ���-��� ����� */
      fscanf(f_in,"\n");
   }
   fclose(f_in);    /* �������� ������� */
   printf("%s %d\n", license, *seats); /* �������� ��������� ��� ������� ������ */
}



/* ���������� ���������� �� ������ */
void save_in_file(epivatis bus[], char license[], int seats) {
   int i, j;
   FILE *f_out;        /* ������� �� ������ */

   f_out = fopen("bus.txt", "w"); /* ������� ������� ������ */
   if(f_out == NULL) /* se periptwsi problimatos kata to anoigma */
   {
      printf("To arxeio bus.txt de mporese na anagnwstei\n"); /* �� ��������� ����������� ���� �� ������� */
      exit(1);      /* ������ ��� �� ��������� */
   }
   fprintf(f_out,"%s %d\n", license, seats); /* �������� �������� ��� ������� ������ */
   for (i=0;i<seats;i++) { /* ��� ���� ��� ������ ��� ���������� */
      if (bus[i].name[0] != '\0') { /* �� ���� ��������� */
         fprintf(f_out,"%s",bus[i].name); /* ������ ��/���� */
         fprintf(f_out," %d ", bus[i].seat); /* ������ �� ���� */
         for (j=0;j<10;j++)
            fprintf(f_out,"%1hu",bus[i].tel[j]); /* ������ �������� ���-��� ����� */
         fprintf(f_out,"\n"); /* ������ ������ ������� */
       }
   }
   fclose(f_out);    /* �������� ������� */
}

