#include <stdio.h>

	main()
	{
		int  num, decnum, binnum;  //дгкысг летабкгтым
        const int dieretis = 2;

        do {
        printf("Parakalo isagete thetiko arithmo:"); /* еисацыцг дедолемым*/
		while(scanf("%d",&num) != 1)
        {printf("Parakalo isagete thetiko arithmo:"); // диабасла дедолемым апо еисодо  йаи екевцос оти еисацоуле ломо аяихло
        while(getchar() != '\n');}
		(num < 0) ?  printf("Arnitikos mi apodektos isagete neo\n") :printf("Thetikos arithmos apodektos\n"); //екецвос хетийоу аяихлоу
         }while (num <0);
        decnum = num ;
        printf ("Dwsate ton arithmo: %d\n", decnum);
        printf ("\nAntistrofi Diadiki Anaparastasi tou arithmou:\n%d --->", decnum);

        //упокоцислос дуадийгс амапаяастасгс
        while (decnum >0)               //сумхгйг теялатислоу
        {
        binnum = decnum%dieretis ;      //упокоцислос упокоипоу диаияесгс
        decnum /= dieretis ;            //упокоцислос меоу аяихлоу
        printf ("%d",binnum);           //ейтупысг упокоипоу диаияесгс 1 ч 0 циа ломо г фуцо аяихло амтистоива
        }

         return 0;
	}

