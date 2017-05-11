
#include <stdio.h>
#include <math.h>       // циа том упокоцисло тгс сумаятгсгс sqrt

// дгкысг енытеяийым сумаятгсеым циа упокоцисло тгс пеяилетяоу тым цеылетяийым свглатым
    float square (float a1);
    float rectangle (float a1, float b1);
    float triangle (float a1, float b1);
    float circle (float a1);

int main ()
{
    float a,b;
    int choice;
    do {
    printf ("\nEisagete mia apo tis parakato epiloges\n");  // то лемоу тым епикоцым

    printf ("0 EXODOS\n");
    printf ("1 TETRAGONO\n");
    printf ("2 PARALLILOGRAMMO\n");
    printf ("3 ORTHOGONIO TRIGONO\n");
    printf ("4 KYKLOS\n");
    printf ("Dwste epilogi:", choice);
    while(scanf("%d",&choice) != 1)       /* диабасла дедолемым апо еисодо  йаи екевцос оти еисацоуле ломо аяихло */
    {printf("Dwste epilogi:");
    while(getchar() != '\n');}

            // екевцос циа еисацыцг ояхгс тилгс сто лемоу
           if (choice !=0 && choice!=1 && choice!=2 && choice!=3 && choice!=4) {
            printf ("MI APODECHTI EPILOGI\n");
            }

           if (choice ==0) {
            printf ("\nBYE BYE");
           }
             // екевцос йаи упокоцислос пеяилетяоу циа йахе пеяиптысг цеылетяийоу свглатос
           if ( choice ==1) {
            printf ( "Dwste mikos plevras tetragonou (a): ");
            scanf   ("%f", &a);
            printf ("H perimetros tou tetragonou einai: %.3f\n", square(a));
           }
           if (choice ==2){
            printf ("Dwste mikos (a) kai platos (b) plevras parallilogramou\n(a keno b): ");
            scanf   ("%f %f", &a, &b);
            printf ("H perimetros tou parallilogramou einai: %.3f\n", rectangle(a,b));
            }
           if (choice ==3) {
            printf ("Dwste mikos ton dyo katheton plevron (a) kai (b) tou trigonou\n(a keno b): ");
            scanf   ("%f %f", &a, &b);
            printf ("H perimetros tou orthogoniou trigonou einai: %.3f\n", triangle(a,b));
           }
           if (choice ==4) {
            printf ("Dwste aktina kyklou (r): ");
            scanf   ("%f", &a);
            printf ("H perimetros tou kyklou einai: %.3f\n", circle(a));
          }
    }while (choice!=0);  // епистяожг сто лемоу епикоцым

    return 0 ;
}

 // ояислос енытеяийым сумаятгсеым циа упокоцисло тгс пеяилетяоу тым цеылетяийым свглатым
        float square (float a1) {
        float per;
        per =4*a1;
        return per;
        }

        float rectangle (float a1, float b1) {
        float per;
        per = 2*(a1+b1);
        return per;
        }

        float triangle (float a1, float b1) {
        // емаккайтийг епистяожг тилгс сумаятгсгс выяис вягсг епипкеом стахеяас per
        return (a1+b1+sqrt(a1*a1+b1*b1));
        }

        float circle (float a1) {
        const float pi =3.1415;
        float per;
        per =2*pi*a1;
        return per;
        }



