#include <stdio.h>

	main()
	{
		int  num, decnum, binnum;  //������ ����������
        const int dieretis = 2;

        do {
        printf("Parakalo isagete thetiko arithmo:"); /* �������� ���������*/
		while(scanf("%d",&num) != 1)
        {printf("Parakalo isagete thetiko arithmo:"); // �������� ��������� ��� ������  ��� ������� ��� ��������� ���� ������
        while(getchar() != '\n');}
		(num < 0) ?  printf("Arnitikos mi apodektos isagete neo\n") :printf("Thetikos arithmos apodektos\n"); //������� ������� �������
         }while (num <0);
        decnum = num ;
        printf ("Dwsate ton arithmo: %d\n", decnum);
        printf ("\nAntistrofi Diadiki Anaparastasi tou arithmou:\n%d --->", decnum);

        //����������� �������� �������������
        while (decnum >0)               //������� �����������
        {
        binnum = decnum%dieretis ;      //����������� ��������� ���������
        decnum /= dieretis ;            //����������� ���� �������
        printf ("%d",binnum);           //�������� ��������� ��������� 1 � 0 ��� ���� � ���� ������ ����������
        }

         return 0;
	}

