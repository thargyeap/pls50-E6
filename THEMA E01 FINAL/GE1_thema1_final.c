# include <stdio.h>

int main()
{
    double num1, num2;                              //������� ����������
    char praji;

    do {
    printf("\nDwse arithmo praji arithmo\n");              /* �������� ���������*/
    scanf ("%lf %c %lf", &num1, &praji, &num2);            /* �������� ��������� ��� ������ */

        if (praji == '/' && num2 ==0)                   /* ������� ��� �������� �� �� �����*/
        printf("PROSOCHI dieresi me 0 den orizete\n");  /*������ ������ ��� �������� �� �� ����� */

        if (praji !='+'& praji !='-' & praji !='*' & praji !='/')      /* ������� ������� �������  */
        printf("PROSOCHI Mi apodechtos telestis prajis\n");      /*������ ������� ��� �� �������� ������� */

       // ������� ��� ��������� ���� �������� ���������
    } while ((praji == '/' && num2 ==0 )|(praji !='+'& praji !='-' & praji !='*' & praji !='/') );

        if (praji == '+')                                       /* ������� ������ ��������� */
            printf("apotelesma= %f\n", num1+num2);               /*�������� ������������� ������ */
        if (praji == '-')                                        /* ������� ������ ��������� */
            printf("apotelesma= %f\n", num1-num2);               /*�������� ������������� ������ */
        if (praji == '*')                                       /* ������� ������ ���/����*/
            printf("apotelesma= %g\n", num1*num2);              /*�������� ������������� ������ */
        if (praji == '/')                                       /* ������� ������ ��������� */
            printf("apotelesma= %g\n", num1/num2);               /*�������� ������������� ������ */
           return 0;
    }
