//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 3                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



/////////////////////////////domes//////////////////////////////

/*
Domh pou antistoixei sta dedomena enos paixth
*/
typedef struct
{
    char  name[17]; //onoma
    unsigned  short score; //vathmologia
    char id; //monadiko anagnwristiko
} Player;


/*
Domh pou antistoixei sta dedomena mias kartas
*/
typedef struct
{
    char color; //xrwma
    char shape; //sxhma
    char number; //arithmos
    char texture; //yfh
    char isUsed;  // 'y': exei xrhsimopoihthei sto plegma 'n': den exei xrhsimopoihthei
    int isChosen;  //1: exei epilegei apo ton paixth se auto ton gyro
                   //0: den exei epilegei se ayto ton gyro
} Card;
////////////////////////////////////////////////////////////////


///////////////dhlwseis synarthsewn/////////////////////////////
/*
Sunarthsh poy elegxei ean oi epilegmenes kartes apoteloyn SET
max_x: megisto plhthos grammwn toy plegmatos
max_y: megisto plhthos sthlwn toy plegmatos
visCards: oi kartes poy fainontai sto plegma
*/
int areChosenCardsSet(int max_x,int max_y,Card visCards[max_x][max_y]);
/*
me dedomenes tis syntetagmenes x kai y toy plegmatos oi opoies dinontai eswterika epilegei
thn antistoixh karta kai epistrefei enan deikth pros ayth
max_x: megisto plhthos grammwn toy plegmatos
max_y: megisto plhthos sthlwn toy plegmatos
visCards: oi kartes poy fainontai sto plegma
*/
Card * ChooseCard(int max_x,int max_y,Card visCards[max_x][max_y]);
/*
Elegxei ean oi treis kartes einai SET
Orismata: Oi kartes A, B C
epistrefei: 1 ean einai SET
            0 ean den einai SET
*/
int isSet( Card A,Card B,Card C);

/*
Typwnei sthn othonh vohthitiko mynhma
*/
void help();

/*
Typwnei mia karta se [] an den einai epilegmenh kai se {} an einai
*/
void printCard(Card crd);

/*
thetei mh-epilegmenes oles tis kartes toy plegmatos
max_x: h megisth diastash twn grammwn tou plegmatos
max_y: h megisth diastash twn sthlwn tou plegmatos
*/
void UnCheckChosenCards(int max_x,int max_y,Card visCards[max_x][max_y]);

/*
Enarksh toy paixnidioy
*/
void PlaySet(Card *AllCards,int max_x,int max_y,Card visCards[max_x][max_y],Player players[3]);

/*
Epilegei alles kartes apo tis 81 pithanes. Anakateyei tis kartes toy plegmatis
*/
void shuffleCards(int max_x,int max_y,Card *Cards,Card visCards[max_x][max_y]);

/*
Typwnei tis kartes toy plegmatos. Eswterika xrhsimopoiei thn synathsh printCard
*/
void PrintVisibleCards(int max_x,int max_y,Card visCards[max_x][max_y]);

/*
Arxikopoihse ton pinaka me oles tis pithanes kartes
*/
void initCards(Card *Cards);

/*
Provalei tis plhrofories enos paixth
*/
void showPlayer( Player );

/*
Provalei toys steps prwtous paixtes poy einai apothikeumenoi ston pinaka players
*/
void showAllPlayers( Player * players,int steps);

/*
Mia oloklhrh kinhsh enos paixth
*/
void Move(int max_x,int max_y,Card visCards[max_x][max_y],Player * AP,Card *AllCards);

/*
epistrefei enan akeraio metaksy Min kai Max pou dhlwnei ton epilegmenh karta
*/
int getNextCard(int min,int max);
////////////////////////////////////////////////////////////////


/////////////////////////MAIN///////////////////////////////////
int main()
{
    //orismos diastasewn plegmatos
    int max_x=3;
    int max_y=4;
    //arxikopoihsh tyxaiwn arit
    srand(time(NULL));
    Card visCards[max_x][max_y]; //orismos plegmatos
    Card AllCards[81];   //orismos pinaka me oles tis pithanes kartes


    Player players[3];   //orismos pinaka paixtwn

    /*Arxikopoihsh prokathiorismenvn paixtwn*/
    strcpy( players[0].name,"Marina Andreou");
    players[0].score=0;
    players[0].id='a';

    strcpy( players[1].name,"Kostas Grammenos");
    players[1].id='g';
    players[1].score=0;

    strcpy( players[2].name,"Maria Perdika");
    players[2].id='p';
    players[2].score=0;

    //klhsh synarthshs arxikopoihshs olwn twn kartwn. Gemisma pinaka AllCards
    initCards(AllCards);

    //Enarksh paixnidiou
    PlaySet(AllCards,max_x,max_y,visCards,players);
    return 0;
}
////////////////////////////////////////////////////////////////


///////////////////YLOPOIHSEIS SYNARTHSEWN//////////////////////
void PlaySet(Card *AllCards,int max_x,int max_y,Card visCards[max_x][max_y],Player players[3])
{
    Player *AP;// o energos paixths


    showAllPlayers( players,3);
    shuffleCards(max_x,max_y,AllCards,visCards);
    char answer;
    while(1) //perimene ep apeiro
    {
        help();

        PrintVisibleCards(max_x,max_y,visCards);


        scanf(" %c",&answer);
        printf("[%c]\n",answer);
        switch(answer) //diavase eisodo xrhsth
        {
        case 'a':

            printf("epilejate ton paixth 1\n");
            AP=&players[0];
            Move(max_x,max_y,visCards,AP,AllCards);

            break;
        case 'g':

            printf("epilejate ton paixth 2\n");
            AP=&players[1];
            Move(max_x,max_y,visCards,AP,AllCards);
            break;
        case 'p':

            printf("epilejate ton paixth 3\n");
            AP=&players[2];
            Move(max_x,max_y,visCards,AP,AllCards);
            break;
        case '0': //eksodos
            showAllPlayers( players,3);
            return;
        default: //provale tous paixtes , anakatepse tis kartes kai provale to neo plegma
            showAllPlayers( players,3);
            shuffleCards(max_x,max_y,AllCards,visCards);
            PrintVisibleCards(max_x,max_y,visCards);
            break;

        }

    }



}

void Move(int max_x,int max_y,Card visCards[max_x][max_y],Player * AP,Card *AllCards)
{
    //elegxei ean oi epilegmenes kartes einai set
    if( areChosenCardsSet(max_x,max_y,visCards))
    {
        // an nai... auksanei to score +2
        AP->score+=2;
        //.. anakateuei kartes
        shuffleCards(max_x,max_y,AllCards,visCards);
    }
    else
    {
        //an oxi...
        if(AP->score>0)
        {
            //meiwnei to score kata 1
            AP->score--;
        }
        else
        {
            //mexri to elaxisto 0
            AP->score=0;
        }
        //oi kartes den anakateuontai alla oi epilegmenes apepilegontai
        UnCheckChosenCards(max_x,max_y,visCards);
    }
    //ean kapoios paixths sygentwsei 10 pontous...
    if( AP->score>=10)
    {
        //termatise
        printf("o nikhths einai o/h %s\n",AP->name);
        return;

    }
    showPlayer(*AP);
}

Card * ChooseCard(int max_x,int max_y,Card visCards[max_x][max_y])
{
    int x,y;

    //epilogh grammhs
    printf("Epilexte grammh[0,%d]:\n",max_x-1);
    scanf(" %d",&x);

    //elegxos orthothtas
    while(x<0 || x>=max_x)
    {
        x=-1;
        printf("MH EPITREPTH EISODOS\nH grammh prepei na vrisketai sta oria [0,%d]:\nEPILEXTE KSANA:",max_x-1);
        scanf(" %d",&x);
    }

    //epilogh sthlhs
    printf("Epilexte sthlh[0,%d]:\n",max_y-1);
    scanf(" %d",&y);
    //elegxos orthothtas
    while(y<0 || y>=max_y)
    {
        y=-1;
        printf("MH EPITREPTH EISODOS\nH grammh prepei na vrisketai sta oria [0,%d]:\nEPILEXTE KSANA:",max_y-1);
        scanf(" %d",&y);
    }
    //epilogh kartas sthn thesi x,y kai epistrofh deikth pros auth thn thesh
    return  &visCards[x][y];
}

int isSet( Card A,Card B,Card C)
{
    //Gia kathe idiothta elegxe oti eite oles oi kartes exoyn thn idia timh ;h oles oi kartes exoyn diaforetikh
    //elegxe to xrwma:
    int color_res= (A.color==B.color && B.color==C.color) || (A.color!=B.color && B.color!=C.color&& A.color!=C.color);
    //elegxe ton arithmo:
    int number_res= (A.number==B.number && B.number==C.number) || (A.number!=B.number && B.number!=C.number&& A.number!=C.number);
    //elegxe to sxhma:
    int shape_res= (A.shape==B.shape && B.shape==C.shape) || (A.shape!=B.shape && B.shape!=C.shape&& A.shape!=C.shape);
    //elegxe thn yfh:
    int texture_res= (A.texture==B.texture && B.texture==C.texture) || (A.texture!=B.texture && B.texture!=C.texture&& A.texture!=C.texture);
    //an kathe epimerous idiothta einai true tote to synolo twn kartwn einai SET
    return color_res&&number_res&&shape_res&&texture_res;
}

int areChosenCardsSet(int max_x,int max_y,Card visCards[max_x][max_y])
{
    Card  *A;
    Card  *B;
    Card  *C;

    A=  ChooseCard(max_x,max_y,visCards);
    A->isChosen=1; //h karta exei epilexthei na summetasxei sto set

    /*printf("H prwth karta poy epilexate einai h :");
    printCard(*A);
    printf("\n");*/
    PrintVisibleCards(max_x,max_y,visCards);
    do
    {
        B=  ChooseCard(max_x,max_y,visCards);
    }
    while(B->isChosen); //oso h karta den exei hdh epilexthei...
    B->isChosen=1;//these thn ws epilegmenh kai synexise
    /*
        printf("H deyterh karta poy epilexate einai h :");
        printCard(*B);
        printf("\n");
      */

    PrintVisibleCards(max_x,max_y,visCards);

    do
    {
        C=  ChooseCard(max_x,max_y,visCards);
    }
    while(C->isChosen);//oso h karta den exei hdh epilexthei...
    C->isChosen=1;//these thn ws epilegmenh kai synexise

    /*    printf("H trith karta poy epilexate einai h :");
        printCard(*C);
        printf("\n");
    */

    PrintVisibleCards(max_x,max_y,visCards);
    int res= isSet( *A,*B,*C);//elegxe ean oi kartes einai set

    printf("Epilexate tis kartes:");
    printCard(*A);
    printCard(*B);
    printCard(*C);
    printf("\n");
    if(res>0)
    {
        printf("Oi kartes aytes einai SET\n");
    }
    else
    {
        printf("Oi kartes aytes den einai SET\n");
    }


    return res;
}

void help()
{
    //emfanise vohthteia
    printf("*****************ODHGIES:*****************\n");
    printf("EPILEXTE: \n-eite paixth me vash to id tou\n-eite 0 gia exodo\n-eite otidhpote allo gia provolh neas kartelas.\n");
    printf("*****************ODHGIES:*****************\n");
}

void PrintVisibleCards(int max_x,int max_y,Card visCards[max_x][max_y])
{
    int i,j;
    //ektypwse kathe karta poy fainetai
    for(i=0; i<max_x; i++)
    {
        for(j=0; j<max_y; j++)
        {
            printCard(visCards[i][j]);
        }
        printf("\n");
    }

}

void showAllPlayers( Player *list_of_players,int steps)
{
    //typwse ta stoixeia olwn twn paixtwn
    printf("PROVOLH PAIXTWN\n");
    int i;
    for( i= 0 ; i<steps; i++)
    {
        showPlayer(list_of_players[i]);//+i*sizeof(Player));
    }
}


void showPlayer(Player p)
{
    //typwse ta stoixeia toy paixth
    printf("[%c] %s, score:%d\n",p.id,p.name,p.score);
}


void initCards(Card *Cards)
{
    printf("ARXOKOPOIHSH KARTWN\n");
    //χρώμα ϵ{r,g,b} 	με r: κόκκινο, g: πράσινο ,b: μπλε
    //σχήμα ϵ {c,t,r} 	με c: κύκλος, t: τρίγωνο, r: ρόμβος
    //αριθμός ϵ{1,2,3}
    //υφή ϵ {b,h,e}	με b: πλήρες, h: γραμμοσκιασμένο, e: κενό-μόνο περίγραμμα

    char color_values[3]= {'r','g','b'};
    char shape_values[3]= {'c','t','r'};
    char number_values[3]= {'1','2','3'};
    char texture_values[3]= {'b','h','e'};
    int i,j,z,k;
    int index=0;

    //dhmiourghse kathe pithano synduasmo kartwn kai apothikeyse ton ston pinaka Cards
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            for(z=0; z<3; z++)
            {
                for(k=0; k<3; k++)
                {
                    Cards[index].color=color_values[i];
                    Cards[index].shape=shape_values[j];
                    Cards[index].number=number_values[z];
                    Cards[index].texture=texture_values[k];
                    Cards[index].isUsed='n';//arxika oi kartes den einai xrhsimopoihmenes
                    Cards[index].isChosen=0;//kai oute exoyn epilexthei apo kapoio paixth
                    index++;
                }
            }
        }
    }


}

void shuffleCards(int max_x,int max_y,Card *Cards,Card visCards[max_x][max_y])
{
    printf("ANAKATEMA KARTWN\n");
    int rand_i=0;
    int so_far=0;
    int x,y;
    int total_cells_num=max_x*max_y;
    int index=0;
    //these oles tis kartes
    //...axrhsimopoihtes isUsed='n'
    //...kai mh epilegmenes isChosen=0;
    for(index=0; index<max_x*max_y; index++)
    {

        Cards[index].isUsed='n';
        Cards[index].isChosen=0;
    }

    //epelekse 12 apo tis 81 kartes tyxaia
    while(so_far<total_cells_num)
    {
        rand_i=getNextCard(0,81);
        //  printf("%d %c\n",rand_i,Cards[rand_i].isUsed);

        // ... pou omws den einai Used
        if(Cards[rand_i].isUsed=='n')
        {
            x=(int)so_far/max_y;
            y=so_far-x*max_y;
            visCards[x][y]=Cards[rand_i];
            //molis thn epilekseis these thn ws used
            Cards[rand_i].isUsed='y';

            //  printf("[%d][%d]",x,y);printCard(Cards[rand_i]);
            //  printf("%d\n",so_far);
            so_far++;
        }

    }


}

void UnCheckChosenCards(int max_x,int max_y,Card visCards[max_x][max_y])
{
    int i,j;
    //diatrexoyme ton pinaka me tis kartes poy fainontai... (visCards)...
    for(i=0; i<max_x; i++)
    {
        for(j=0; j<max_y; j++)
        {
            //...kai tis thetoume se katastash mh epilegmenes
            visCards[i][j].isChosen=0;
        }
        //printf("\n");
    }
}


void printCard(Card crd)
{
    //ean h karta einai epilegmenh tote emfanizontai {} gyro ths anti twn []
    if(crd.isChosen)
        printf("{%c,%c,%c,%c}",crd.color,crd.shape,crd.number,crd.texture);
    else
        printf("[%c,%c,%c,%c]",crd.color,crd.shape,crd.number,crd.texture);

}

int getNextCard(int min,int max){
     max-=min;
    return (rand()%max)+min;
}

