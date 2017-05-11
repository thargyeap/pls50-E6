# include <stdio.h>

int main()
{
    double num1, num2;                              //ояислос летабкгтым
    char praji;

    do {
    printf("\nDwse arithmo praji arithmo\n");              /* еисацыцг дедолемым*/
    scanf ("%lf %c %lf", &num1, &praji, &num2);            /* диабасла дедолемым апо еисодо */

        if (praji == '/' && num2 ==0)                   /* екецвос циа диаияесг ле то лгдем*/
        printf("PROSOCHI dieresi me 0 den orizete\n");  /*лгмула кахоус циа диаияесг ле то лгдем */

        if (praji !='+'& praji !='-' & praji !='*' & praji !='/')      /* екецвос текестг пяанеым  */
        printf("PROSOCHI Mi apodechtos telestis prajis\n");      /*лгмула екецвоу циа лг аподейто текестг */

       // екевцос йаи епистяожг стгм еисацыцг дедолемым
    } while ((praji == '/' && num2 ==0 )|(praji !='+'& praji !='-' & praji !='*' & praji !='/') );

        if (praji == '+')                                       /* екецвос пяангс пяосхесгс */
            printf("apotelesma= %f\n", num1+num2);               /*ейтупысг апотекеслатос пяангс */
        if (praji == '-')                                        /* екецвос пяангс ажаияесгс */
            printf("apotelesma= %f\n", num1-num2);               /*ейтупысг апотекеслатос пяангс */
        if (praji == '*')                                       /* екецвос пяангс пок/слоу*/
            printf("apotelesma= %g\n", num1*num2);              /*ейтупысг апотекеслатос пяангс */
        if (praji == '/')                                       /* екецвос пяангс диаияесгс */
            printf("apotelesma= %g\n", num1/num2);               /*ейтупысг апотекеслатос пяангс */
           return 0;
    }
