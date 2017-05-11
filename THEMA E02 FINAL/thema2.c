//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 2                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************
#include <stdio.h>  /* λόγω printf(), fscanf(), fopen(), fclose() */
#include <stdlib.h> /* λόγω exit() */
#include <string.h> /* λόγω strcmp(), strlen() */
#define TRUE 1
#define FALSE 0
/* μακροεντολή για εναλλαγή δύο στοιχείων */
#define SwapVals(x,y,tmp) {tmp=x;x=y;y=tmp;}

/* τύπος στοιχείων του πίνακα θέσεων του λεωφορείου */
typedef struct {
   char name[40];          /* επώνυμο, κενό, όνομα */
   unsigned short tel[10]; /* 10-ψήφιο τηλέφωνο */
   unsigned int seat ;     /* αριθμός θέσης */
} epivatis;

/* τύπος στοιχείων συνδεδεμένης λίστας */
typedef struct thesi {
   epivatis stoixeia;  /* δεδομένα κόμβου */
   struct thesi *next; /* δείκτης προς επόμενο κόμβο */
} THESI;

/* πρωτότυπα συναρτήσεων */
void bubblesort_by_name(epivatis bus[], int seats);
void bubblesort_by_seat(epivatis bus[], int seats);
epivatis *initialize(char *license, int *seats);
void neos_epivatis(epivatis *new_passenger);
void apeleutherwsi_thesis(epivatis *old);
void anazitisi_epivati(epivatis bus[], int seats);
void emfanisi_thesewn(epivatis bus[], int seats, int sort_by_name);
void plithos_kenwn_thesewn(epivatis bus[], int seats);
void save_in_file(epivatis bus[], char license[], int seats);

/* κυρίως πρόγραμμα */
void main()
{

   epivatis *bus;             /* πίνακασ θέσεων */
   char license[8];           /* πινακίδα κυκλοφορίας, 7 γράμματα-αριθμοί και το '\0' */
   int seats;                 /* πλήθος θέσεων */
   unsigned int seat;         /* επιλογή θέσης */

   int choice, choice1;       /* επιλογή χρήστη */

   bus = initialize(license, &seats); /* αρχικοποίηση λεωφορείου από το bus.txt */

   choice = 1; /* αρχική τιμή για είσοδο στο loop */
   while (choice != 0) { /* μέχρι να επιλεγεί τερματισμός  */
      printf("1. emfanish synolikoy plhthous kenwn thesewn kai twn arithmwn tous\n");
      printf("2. krathsh theshs me sygkekrimeno arithmo\n");
      printf("3. anazhthsh gia to an einai krathmenh thesh me sygkekrimeno onomatepwnymo, i tilefwno\n");
      printf("4. akyrwsh krathshs theshs me sygkekrimeno arithmo\n");
      printf("5. emfanish listas krathmenwn thesewn taksinomhmenhs kata arithmo, i onomatepwnymo\n");
      printf("0. termatismos\n");
      scanf("%d", &choice); /* ανάγνωση επιλογής χρήστη */
      switch(choice) {
        case 1:
           plithos_kenwn_thesewn(bus,seats);
           break;
        case 2:
           printf("dwse arithmo thesis\n");
           scanf("%d", &seat);
           if (seat<1 || seat>seats) /* έλεγχος ότι αριθμός θέσης εντός ορίων */
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
           if (seat<1 || seat>seats) /* έλεγχος ότι αριθμός θέσης εντός ορίων */
              printf("arithmos thesis ektos oriwn\n");
           else
              apeleutherwsi_thesis(&bus[seat-1]);
           break;
        case 5:
           printf("dwse 1 gia tajinomisi kata onomatepwnymo, 0 gia tajinomisi kata thesi\n");
           scanf("%d", &choice1); /* ανάγνωση επιλογής χρήστη */
           emfanisi_thesewn(bus, seats, choice1);
           break;
        case 0:  /* σώσε στο bus.txt πριν την έξοδο */
           save_in_file(bus, license, seats);
           break;
        default:
           printf("akatallili epilogi\n");
      }
    }
}

/* εισαγωγή στοιχείων νέο επιβάτη στo struct που δείχνεται από το new_passenger */
void neos_epivatis(epivatis *new_passenger) {
   char name[40];  /* για την ανάγνωση του ονοματεπώνυμου */
   int i;

   if (new_passenger->name[0] == '\0') { /* αν η θέση είναι ελεύθερη */
      printf("dwse epwnymo epibati\n");
      scanf("%s",name); /* διάβασε επώνυμο */
      name[strlen(name)+1]='\0'; /* βάλε τον τερματισμό μια θέση δεξιότερα */
      name[strlen(name)] = ' '; /* βάλε κενό στη θέση του μέχρι τώρα τερματισμού */
      printf("dwse onoma epibati\n");
      scanf("%s",name+strlen(name)); /* διάβασε και πρόσθεσε όνομα επιβάτη */
      strcpy(new_passenger->name, name);  /* αντέγραψε στο struct το ονοματεπώνυμο */
      printf("dwse tilefwno\n");
      for (i=0;i<10;i++)
          scanf("%1hu",&(new_passenger->tel[i])); /* διάβασε τηλέφωνο ένα-ένα ψηφίο */
      printf("thesi kratithike\n");
    } else
          printf("thesi kratimeni\n");
}

/* απελευθέρωση θέσης */
void apeleutherwsi_thesis(epivatis *old) {
    if (old->name[0] != '\0') { /* αν θέση δεν είναι ελεύθερη */
        old->name[0] = '\0';  /* απελευθέρωσέ την */
        printf("thesi eleutherwthike\n");
    }
    else
        printf("thesi idi eleutheri\n");
}

/* αναζήτηση επιβάτη βάσει επωνύμου, ή τηλεφώνου */
void anazitisi_epivati(epivatis bus[], int seats){
    int i, j, flag, flag1;
    char name[40]; /* για την ανάγνωση του ονοματεπώνυμου */
    unsigned int tel[10]; /* για την ανάγνωση του τηλεφώνου */

    printf("Gia anazitisi me epwnymo, dwse 1, me tilefwno, dwse allo symbolo\n");
    scanf("%d", &i);
    if (i == 1) {
       printf("dwse eponymo epibati\n");
       scanf("%s",name); /* διάβασε επώνυμο */
       name[strlen(name)+1]='\0'; /* βάλε τον τερματισμό μια θέση δεξιότερα */
       name[strlen(name)] = ' '; /* βάλε κενό στη θέση του μέχρι τώρα τερματισμού */
       printf("dwse onoma epibati\n");
       scanf("%s",name+strlen(name)); /* διάβασε και πρόσθεσε όνομα επιβάτη */
       flag = FALSE;
       for (i=0;i<seats;i++) /* ψάξε όλες τις θέσεις για τον επιβάτη name */
           if (bus[i].name[0] != '\0' && strcmp(bus[i].name, name)==0) { /* αν θέση κρατημένη για τον name */
               printf("%s %d\n",bus[i].name, bus[i].seat); /* τύπωσε τον επιβάτη */
               flag = TRUE; /* βρήκα τουλάχιστον 1 επιβάτη */
           }
       if (!flag)
            printf("De brethike\n");
    } else {
       printf("dwse tilefwno\n");
       for (i=0;i<10;i++)
           scanf("%1d",&tel[i]); /* διάβασε τηλέφωνο ένα-ένα ψηφίο */
       flag1 = TRUE; /* δεν έχω βρει κανέναν επιβάτη */
       for (i=0;i<seats;i++) /* ψάξε όλες τις θέσεις για το τηλ tel[] */
           if (bus[i].name[0] != '\0') {/* αν θέση κρατημένη */
               flag = TRUE; /* έστω τα τηλέφωνα είναι ίδια */
               for (j=0;j<10;j++) /* σύγκρινε όλα τα ψηφία του τηλ. */
                  if (bus[i].tel[j] != tel[j]) /* αν ένα ψηφίο διαφέρει */
                     flag = FALSE; /* τα τηλέφωνα διαφέρουν */
               if (flag) { /* αν τα τηλέφωνα είναι ίδια */
                   printf("%s %d\n",bus[i].name, bus[i].seat); /* τύπωσε τον επιβάτη */
                   flag1 = FALSE; /* βρήκα τουλάχιστον 1 επιβάτη */
               }
           }
        if (flag1) /* Αν δεν έχω βρει κανέναν επιβάτη */
            printf("De brethike\n");
     }
}

/* εμφάνιση θέση ταξινομένων κατά θέση, ή ον/νυμο */
void emfanisi_thesewn(epivatis bus[], int seats, int sort_by_name) {
     int i, j;

     if (sort_by_name) /* αν ο χρήστης ζήτησε λίστα κατά ον/νυμο */
         bubblesort_by_name(bus, seats); /* ταξινόμηση φυσαλίδας κατά ον/νυμο */
     printf("kratimenes theseis\n");
     for (i=0;i<seats;i++)
         if (bus[i].name[0] != '\0') {/* αν θέση κρατημένη */
             printf("%s %d ",bus[i].name, bus[i].seat); /* τύπωσέ την */
             for (j=0;j<10;j++)
                printf("%1d",bus[i].tel[j]);
             printf("\n");
         }
     printf("\n");
     if (sort_by_name) /* αν ο χρήστης ζήτησε λίστα κατά ον/νυμο */
         bubblesort_by_seat(bus, seats); /* επαναταξινόμηση φυσαλίδας κατά θέση */
}

/* υπολογισμός πλήθους κενών θέσεων */
void plithos_kenwn_thesewn(epivatis bus[], int seats){
    int i;
    int count = 0;   /* αρχικοποίηση μετρητή */

    for (i=0;i<seats;i++)
       if (bus[i].name[0] == '\0') count++; /* αν θέση ελεύθερη, αύξησε μετρητή */
    printf("plithos kenwn thesewn = %d apo %d\nEleutheres theseis:\n",count,seats);
    for (i=0;i<seats;i++)
       if (bus[i].name[0] == '\0') /* αν θέση ελεύθερη */
             printf("%d ",i+1); /* τύπωσέ την */
    printf("\n");
}

/* Αρχικοποίηση λεωφορείου με ανάγνωση από αρχείο. Επιστρέφεται ο δημιουργηθείς πίνακας θέσεων */
epivatis *initialize(char *license, int *seats) {
   epivatis *bus;             /* προσωρινός δείκτης πίνακα θέσεων */
   char name[40];             /* για την ανάγνωση του ονοματεπώνυμου */
   unsigned int seat;         /* για την ανάγνωση της θέσης */

   int i;
   FILE* f_in;        /* δείκτης σε αρχειο */

   f_in = fopen("bus.txt", "r"); /* άνοιγμα αρχείου για ανάγνωση */
   if(f_in == NULL) /* σε περίπτωση προβλήματος κατά το άνοιγμα */
   {
      printf("To arxeio bus.txt de mporese na anagnwstei\n");
      exit(1);      /* έξοδος από το πρόγραμμα */
   }
   fscanf(f_in,"%s %d", license, seats); /* διάβασε πινακίδα και πληθος θέσεων */
   bus = (epivatis *)malloc(*seats * sizeof(epivatis)); /* εκχώρησε μνήμη για πίνακα θέσεων */
   if (bus == NULL) {  /* αν απέτυχε η εκχώρηση μνήμης */
      printf("memory allocation error\n");
      exit(1);        /* έξοδος από το πρόγραμμα */
   }
   for (i=0;i<*seats;i++) { /* αρχικοποίηση θέσεων λεωφορείου */
      bus[i].name[0] = '\0';
      bus[i].seat = i+1;
   }
   fscanf(f_in,"\n"); /* προσπέρασε την αλλαγή γραμμής */
   while (!feof(f_in)) { /* μέχρι τέλους του αρχείου */
      fscanf(f_in,"%s",name); /* διάβασε επώνυμο */
      name[strlen(name)+1]='\0'; /* βάλε τον τερματισμό μια θέση δεξιότερα */
      name[strlen(name)] = ' '; /* βάλε κενό στη θέση του μέχρι τώρα τερματισμού */
      fscanf(f_in,"%s",name+strlen(name)); /* διάβασε και πρόσθεσε όνομα επιβάτη */
      fscanf(f_in,"%d", &seat); /* διάβασε τη θέση */
      bus[seat-1].seat=seat; /* καταχώρησε στο struct τη θέση */
      strcpy(bus[seat-1].name, name); /* αντέγραψε στο struct το ονοματεπώνυμο */
      for (i=0;i<10;i++)
         fscanf(f_in,"%1hu",&bus[seat-1].tel[i]); /* διάβασε τηλέφωνο ένα-ένα ψηφίο */
      fscanf(f_in,"\n");
   }
   fclose(f_in);    /* κλείσιμο αρχείου */
   printf("%s %d\n", license, *seats); /* εκτύπωση πινακίδας και πλήθους θέσεων */
   return(bus); /* επέστρεψε το δείκτη προς τον πίνακα θέσεων */
}



/* αναδρομική εισαγωγή στο τέλος συνδεδεμένης λίστας */
THESI *insert(THESI *h, epivatis e)  {
   THESI * temp;

   if (h == NULL) { /* αν φτάσαμε στο τέλος της λίστας */
      temp = (THESI *) malloc(sizeof(THESI)); /* εκχώρησε μνήμη για τον νέο κόμβο */
      if (temp == NULL) { /* αν συμβεί λάθος μνήμης */
         fprintf(stderr,"ERROR OF MEMORY ALLOCATION\n");
         exit(1); /* έξοδος από το πρόγραμμα */
      }
      temp->stoixeia = e; /* αποθήκευσε τα δεδομένα στον κόμβο */
      temp->next = h;     /* επόμενος κόμβος το κενό */
      return(temp);       /* επέστρεψε δείκτη προς τον νέο κόμβο */
   } else {    /* αν δε φτάσαμε στο τέλος της λίστας */
      h->next =insert(h->next, e); /* κάλεσε αναδρομικά για τον επόμενο κόμβο της λίστας */
      return(h);          /* επέστρεψε δείκτη προς τρέχοντα κόμβο */
   }
}



/* αποθήκευση λεωφορείου σε αρχείο */
void save_in_file(epivatis bus[], char license[], int seats) {
   int i, j;
   FILE *f_out;        /* δείκτης σε αρχειο */
   THESI *head;        /* κεφαλή συνδεδεμένης λίστας */


   head = NULL;        /* αρχικοποίηση συνδεδεμένης λίστας */

   bubblesort_by_name(bus, seats); /* ταξινόμησε κατά ον/νυμο */
   for (i=0;i<seats;i++)
       if (bus[i].name[0] != '\0') { /* αν μια θέση είναι κρατημένη */
         head=insert(head, bus[i]); /* εισηγαγέ την στο τέλος της συνδ. λίστας */
   }
   f_out = fopen("bus.txt", "w"); /* άνοιγμα αρχείου εξόδου */
   if(f_out == NULL) /* se periptwsi problimatos kata to anoigma */
   {
       printf("To arxeio bus.txt de mporese na anagnwstei\n"); /* σε περίπτωση προβλήματος κατά το άνοιγμα */
       exit(1);      /* έξοδος από το πρόγραμμα */
   }
   fprintf(f_out,"%s %d\n", license, seats); /* εκτύπωση πινακίδα και πλήθους θέσεων */
   while (head != NULL) { /* για όλα τα στοιχεία της συνδ. λίστας */
       fprintf(f_out,"%s %d ",head->stoixeia.name, head->stoixeia.seat); /* τύπωσε ον/νυμο και θέση */
       for (j=0;j<10;j++)
            fprintf(f_out,"%1d",head->stoixeia.tel[j]); /* τύπωσε ένα-ένα τα ψηφία του τηλ. */
       fprintf(f_out,"\n");  /* τύπωσε αλλαγή γραμμής */
       head = head->next; /* πήγαινε στο επόμενο κόμβο της συνδ. λίστας */
   }
   fclose(f_out);    /* κλείσιμο αρχείου */

}

/* ταξινόμηση φυσαλίδας κατά ον/νυμο */
void bubblesort_by_name(epivatis bus[], int seats) {
  epivatis x;
  int i, r =seats;
  int at_least_one_swap = 1;

  /* ενώ στο προηγούμ. πέρασμα έγινε 1 τουλάχιστον εναλλαγή */
  while (at_least_one_swap) {
    at_least_one_swap = 0;
    for (i = 0; i < r-1; i ++)
      if (strcmp(bus[i].name,bus[i+1].name) > 0) {  /* αν τα γειτονικά στοιχεία */
                                /* δεν τηρούν τη διάταξη ...*/
         SwapVals(bus[i],bus[i+1],x); /* ενάλλαξε τη θέση τους    */
         at_least_one_swap = 1;  /* και ετοιμάσου για άλλο...*/
      }                         /* ένα πέρασμα              */
    r --;        /* το δεξί άκρο περιέχει το σωστό στοιχείο */
  }
}

/* ταξινόμηση φυσαλίδας κατά θέση */
void bubblesort_by_seat(epivatis bus[], int seats) {
  epivatis x;
  int i, r =seats;
  int at_least_one_swap = 1;

  /* ενώ στο προηγούμ. πέρασμα έγινε 1 τουλάχιστον εναλλαγή */
  while (at_least_one_swap) {
    at_least_one_swap = 0;
    for (i = 0; i < r-1; i ++)
      if (bus[i].seat > bus[i+1].seat) {  /* αν τα γειτονικά στοιχεία */
                                /* δεν τηρούν τη διάταξη ...*/
         SwapVals(bus[i],bus[i+1],x); /* ενάλλαξε τη θέση τους    */
         at_least_one_swap = 1;  /* και ετοιμάσου για άλλο...*/
      }                         /* ένα πέρασμα              */
    r --;        /* το δεξί άκρο περιέχει το σωστό στοιχείο */
  }
}
