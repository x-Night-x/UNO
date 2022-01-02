/*
-----------------------------------------------------------------------------------------------
Card Structure in UNO

Total number of cards = 108 [(10 x 4) + (9 x 4) + (6 x 4) + 4 + 4]
Cards in 1 suit = 25
No of 0 in each suit = 1
Numbers in each suit = 19 [(0 to 9) + (1 to 9)]
Powers in each suit = 3 x 2
No of suits = 4
No of Wild = 4
No of Wild draw 4 = 4
------------------------------------------------------------------------------------------------
Card Structure to computer

Colors
Identified by rows number
0 or 4 = red
1 or 5 = yellow
2 or 6 = green
3 or 7 = blue

Numbers and powers
Identified by column number
0 to 9 = same as column numbers
10 = skip
11 = reverse
12 = draw 2
13 = {row number 0 to 3 = normal wild,
      row number 4 to 7 = draw 4 wild}
-------------------------------------------------------------------------------------------------
Card Structure to user

Colors
Identified by first letter of string
R = red
Y = yellow
G = green
B = blue

Numbers and powers
Identified by second letter of string
0 to 9 = the number itself
S = skip
R = reverse
T = draw two

Wilds
WC = normal wild
WF = wild draw four
-------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class start
{
    public:
void slow()
{
    for(int i=0; i<=100000000; i++);
}
void uno_d()
{
cout<<"\n\n";
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@####@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#########################*      @@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##########################  @@.  ...   @@  @@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@###########################  @ ............... @  @@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@####################   &@@@ . @@ .....  @@@@@ ...... @ @@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@#################### @@@.....# @@@ .... @@@@@@@@##@ .....@ &\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@###########(     ### @####@.....@@@ .... @ ###  @####@ .... @ \n";slow();
cout<<"@@@@@@@@@@@@@@@########   @@@  ... @,   @##@#@.....@@ .... @ ###### @@##@.....@ \n";slow();
cout<<"@@@@@@@@@@@@@#####  @@  .. @@........  @ @##@@/.....@@.....// ###### @@@@.....@ \n";slow();
cout<<"@@@@@@@@@@   ### &@##@ .... @@........... @@@@@ .....@ ..... @  ###, @@@..... @ \n";slow();
cout<<"@@@@  @@@  @  ##  @##@@ .... @@....., ....... @@ .... @@ ...... #@@@  ...... @ @\n";slow();
cout<<"@  @@@,.....@ /##  @%#@@ .... @@.....@@@& ....... .... @@@ ............... @ @@@\n";slow();
cout<<"@ @@@@@ .....@ ###  @@@@@..... @@.....@@@@@@ .......... @@@@@@   ...  *@@@  @@@@\n";slow();
cout<<"@@ @@@@@ .....@ ### #@@@@@..... @......@@@@@@@@@ ....... @@@@@@@@@@@@@@  @@@@@@@\n";slow();
cout<<"@@@ @@@@@ .... @ ### @@@@@@.....@@ .....@ @@@@@@@@@@ .  @@@          @@@@@@@@@@@\n";slow();
cout<<"@@@@ @###@ .... @ ### @@@@@ .... @@ .....@ #  @@@@@@@@@@  ########%@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@ @#@@@ .....@& ## @@@ .....@@@@ .... @ ####  #   ##########@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@  @#@@@ ......    ........@@@@@@@@@@@ ###################@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@  @@@@@@ ............. @   @@@@   ,##################@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@ @@@@@@@@@     @@@@@  ### ######################@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@  @@@@@@@@@@@@%  ########################&@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@       (########################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@#################%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"\n\nUNO - Multiplayer card game presented by:\n";slow();
cout<<"ANANDITA"<<endl;slow();
cout<<"SHIVANG"<<endl;slow();
cout<<"AASTHA"<<endl;slow();
cout<<"PIYUSH"<<endl;slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
}
};

//Card Info
typedef struct CardId
{
    int rowNo;
    int colNo;
}Id;
vector<int> col{0,1,2,3,4,5,6,7,8,9,10,11,12,13};
vector<int> row{0,1,2,3,4,5,6,7};
int cnup = 0;
int cnf = 0;

int Deck[8][14]= {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0}};

void updateRow()
{
    for(int i=0; i<row.size(); i++)
    {
        int flag=0;
        for(int j = 0; j<col.size(); j++)
        {
            if(Deck[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int k=0; k<row.size(); k++)
            {
                if(row[k]==i)
                {
                    int temp= row[k];
                    row[k]= row[row.size()-1];
                    row[row.size()-1]= temp;
                }
            }
            row.pop_back();
        }
    }
}
void updateColumn()
{
    for(int i=0; i<col.size(); i++)
    {
        int flag=0;
        for(int j = 0; j<row.size(); j++)
        {
            if(Deck[j][i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int k=0; k<col.size(); k++)
            {
                if(col[k]==i)
                {
                    int temp= col[k];
                    col[k]= col[col.size()-1];
                    col[col.size()-1]= temp;
                }
            }
            col.pop_back();
        }
    }
}
void checkdeck()
{
    if(cnf == 108)
    {
        cout<<"The deck is empty. It's a draw."<<endl;
        exit(0);
    }
}
Id random()
{
    srand(time(0));
    Id card;
    cnup++;
    if(cnup>7)
    {
        updateRow();
        updateColumn();
        cnup=0;
    }
    int r = rand()%row.size();
    int c = rand()%col.size();
    card.rowNo= row[r];
    card.colNo= col[c];
    return card;
}

Id getCard()
{
    Id card=random();

    while(Deck[card.rowNo][card.colNo])
    {
        card=random();
    }
    cnf++;
    checkdeck();
    Deck[card.rowNo][card.colNo]=1;

    return card;
}


//Player Info
//For cards in the player's hands we have used a linked list structure

class hand
{
public:
    int rowNo;
    int colNo;
    hand* next;
};


class Player : public hand
{
public:
    string name;
    hand* head=NULL;
public:
    void addCard()
    {

        Id newCard = getCard();
        hand* newC=new hand();

        newC->rowNo=newCard.rowNo;
        newC->colNo=newCard.colNo;
        newC->next=NULL;
        if(head==NULL)
        {
            head=newC;
            return;
        }
        hand* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newC;

    }
    void delCard(int rno, int cno)
    {
        hand* temp=head;
        hand* prev=new hand();
        while(temp!=NULL)
        {
            if(cno==13)
            {
                if((temp->rowNo==rno||temp->rowNo==(rno+1)||temp->rowNo==(rno+2)||temp->rowNo==(rno+3)) && temp->colNo==cno)
                {
                    if(temp==head)
                    {
                        head = head->next;
                    }
                    if(temp->next==NULL)
                    {
                        prev->next=NULL;
                    }
                    prev->next=temp->next;
                    break;
                }
            }
            else
            {
                if((temp->rowNo==rno||temp->rowNo==(rno+4)) && temp->colNo==cno)
                {
                    if(temp==head)
                    {
                        head = head->next;
                    }
                    if(temp->next==NULL)
                    {
                        prev->next=NULL;
                    }
                    prev->next=temp->next;
                    break;
                }
            }
            prev=temp;
            temp=temp->next;
        }

    }
    int inlinked(int rno, int cno)
    {
        hand* temp = head;
        while(temp!= NULL)
        {
            if((temp->rowNo==rno||temp->rowNo==(rno+4)) && temp->colNo == cno)
            {
                return 1;
            }
            if(cno == 13 && (temp->rowNo==rno||temp->rowNo==(rno+1)||temp->rowNo==(rno+2)||temp->rowNo==(rno+3)) && temp->colNo==cno)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
};



void displayCard(int r, int c)
{
     if(c==13)
    {
        cout<<"W";
        if(r<=3)
            cout<<"C";
        else
            cout<<"F";
        cout<<"\t";
        return;
    }
    if(r==0||r==4)
        cout<<"R";
    if(r==1||r==5)
        cout<<"Y";
    if(r==2||r==6)
        cout<<"G";
    if(r==3||r==7)
        cout<<"B";
    if(c<=9)
        cout<<c;
    if(c==10)
        cout<<"S";
    if(c==11)
        cout<<"R";
    if(c==12)
        cout<<"T";
    cout<<"\t";
}
int getRow(string card)
{
    char ch=card[0];
    if(ch=='R')
        return 0;
    if(ch=='Y')
        return 1;
    if(ch=='G')
        return 2;
    if(ch=='B')
        return 3;
    if(ch=='W')
    {
        if(card[1]=='C')
            return 0;
        if(card[1]=='F')
            return 4;
    }
    return -1;
}
int getCol(string card)
{
    char ch=card[1];
    if(ch=='S')
        return 10;
    if(ch=='R')
        return 11;
    if(ch=='T')
        return 12;
    if(ch=='F'||ch=='C')
        return 13;
    int num= (int)ch-48;
    return num;
}
bool checkCard(int r, int c, string s)
{
    int r1=getRow(s);
    int c1=getCol(s);
    if(c1==13)
    {
        return true;
    }
    else
    {
        if((r==r1||r==(r1+4)) || c==c1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
void displayHand(hand* head1)
{
    hand* temp;
    temp=head1;
    do
    {
        displayCard(temp->rowNo,temp->colNo);
        temp=temp->next;
    }
    while(temp!=NULL);
    return;
}

int main()
{
    cout<<"UNO - Multiplayer Card Game"<<endl;
    start u;
    u.uno_d();
    system("cls");
    cout<<"UNO - Multiplayer Card Game"<<endl;
    int n;
    do{
    cout<<"Enter number of players between 2 to 4"<<endl;
    cin>>n;
    if(n<=1 || n>=5)
        cout<<"Invalid number of players.\nEnter number of players again.\n";
    }
    while(n<=1 || n>=5);
    string p[n+1];
    for(int i=1; i<=n; i++)
    {
        cout<<"Enter name of Player: "<<i<<endl;
        cin>>p[i];
    }
    cout<<"Its time for some UNO!!"<<endl;
    cout<<"Loading..."<<endl;
    Player* players = new Player[n+1];
    for(int i=1; i<=n; i++)
    {
        cout<<p[i]<<"'s cards generating..."<<endl;
        players[i].name = p[i];

        for(int j=1; j<=7; j++)
        {
            players[i].addCard();
        }

    }
    int rot=1;
    cout<<"Game Loaded"<<endl;
    Id TopCard = getCard();
    while(TopCard.colNo==13)
    {
        Deck[TopCard.rowNo][TopCard.colNo]=0;
        TopCard = getCard();
    }
    string colour;
    int prev;
    int fla;
    string cardPlayed;
    while(rot>=(-n) || rot<=n)
    {
        prev=rot;
        cout<<"\n\n\n"<<p[abs(rot)]<<"'s chance"<<endl;


        cout<<"Last Played card is : ";
        displayCard(TopCard.rowNo,TopCard.colNo);
        if(!colour.empty())
        {
            cout<<endl<<"Color switched to "<<colour;
            TopCard.rowNo=getRow(colour);
            colour="";
        }
        cout<<endl<<"Your hand is :\n";




        displayHand(players[abs(rot)].head);



        char choice;
        choose_move:
        cout<<endl<<"What you wanna do \nDraw Card(enter D)/Play Card(P)"<<endl;
        fflush(stdin);
        cin>>choice;
            fflush(stdin);
            if(choice=='P')
            {
                    cout<<"Enter your card:"<<endl;

                    cin>>cardPlayed;
                    if(players[abs(rot)].inlinked(getRow(cardPlayed),getCol(cardPlayed)))
                    {
                            if(checkCard(TopCard.rowNo,TopCard.colNo,cardPlayed))
                            {
                                TopCard.rowNo=getRow(cardPlayed);
                                TopCard.colNo=getCol(cardPlayed);
                                players[abs(rot)].delCard(getRow(cardPlayed),getCol(cardPlayed));
                            }
                            else
                            {
                                cout<<endl<<"Invalid Card. Play again.\n";
                                goto choose_move;
                            }
                    }
                    else
                    {
                            cout<<"You don't have this card. Choose again.\n";
                            goto choose_move;
                    }
                }
            else if(choice=='D')
            {
                players[abs(rot)].addCard();
                cout<<"One Card added"<<endl;
                displayHand(players[abs(rot)].head);
            }
            else
            {
                cout<<endl<<"Invalid choice. Choose again.";
                goto choose_move;
            }

        if(players[abs(rot)].head==NULL)
        {
            cout<<"Good Game!"<<players[abs(rot)].name<<" wins!!"<<endl;
            cout<<"Game Ended.";
            break;
        }
        //Updation of rot

        if(cardPlayed.compare("WF")==0 && choice != 'D')
        {
            if(rot==n)
            {
                players[1].addCard();
                players[1].addCard();
                players[1].addCard();
                players[1].addCard();
            }
            else if(rot==-1)
            {
                players[n].addCard();
                players[n].addCard();
                players[n].addCard();
                players[n].addCard();
            }
            else
            {
                players[abs(rot+1)].addCard();
                players[abs(rot+1)].addCard();
                players[abs(rot+1)].addCard();
                players[abs(rot+1)].addCard();
            }
            cout<<"Which color do you want to be played - R,Y,G,B ?"<<endl;
            cin>>colour;
            rot+=2;
        }
        else if(cardPlayed.compare("WC")==0 && choice != 'D')
        {
            cout<<"Which color do you want to be played - R,Y,G,B?"<<endl;
            cin>>colour;
            rot++;
        }
        else if(cardPlayed[1]=='T' && choice != 'D')
        {
            if(rot==n)
            {
                players[1].addCard();
                players[1].addCard();
            }
            else if(rot==-1)
            {
                players[n].addCard();
                players[n].addCard();
            }
            else
            {
                players[abs(rot+1)].addCard();
                players[abs(rot+1)].addCard();
            }
            rot+=2;
        }
        else if(cardPlayed[1]=='S' && choice != 'D')
        {
            rot+=2;
        }
        else if(cardPlayed[1]=='R' && choice != 'D')
        {
            rot=-rot;
            rot++;
        }
        else
        {
            rot++;
        }
        if(prev<0)
        {
            if(rot==0)
            {
                rot=-n;
            }
            if(rot==1)
            {
                rot=-n+1;
            }
        }
        else if(prev>0)
        {
            if(rot==n+1)
                rot=1;
            if(rot==n+2)
                rot=2;
            if(rot==0)
                rot=-n;
        }
    }
    return 0;
}
//Thank You
