#include<iostream>
#include<stdlib.h>
using namespace std;
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='x';
int row,column;
bool draw=false;
void function1()

{
    system("CLS");
    cout<<"\t\t Tic Toc Game\n";
    cout<<"player X[]\n";
    cout<<"player Y[]\n\n";


    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"  "<<endl;
    cout<<"\t\t-----|-----|-----"<<endl;;
    cout<<"\t\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"  "<<endl;
    cout<<"\t\t-----|-----|-----"<<endl;
    cout<<"\t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"  "<<endl;
    cout<<"\t\t     |     |     "<<endl;
}
void playerturn()
{
    int choice;
    if(turn=='x')
    {
        cout<<"\n\tplayer1[x] turn!";
    }
    if(turn=='y')
    {
        cout<<"\n\tplayer2[y] turn!";
    }
     cin>>choice;
     switch(choice){
 case 1:row=0;column=0;break;
 case 2:row=0;column=1;break;
 case 3:row=0;column=2;break;
 case 4:row=1;column=0;break;
 case 5:row=1;column=1;break;
 case 6:row=1;column=2;break;
 case 7:row=2;column=0;break;
 case 8:row=2;column=1;break;
 case 9:row=2;column=2;break;

 default:
    cout<<"Invalid choice"<<endl;
}
if(turn=='x'&&a[row][column]!='x'&&a[row][column]!='y')
{
    a[row][column]='x';
    turn='y';
}
else if(turn=='y'&&a[row][column]!='x'&&a[row][column]!='y')
{
    a[row][column]='y';
    turn='x';
}
else{
    cout<<"Box already filed\nPlease try again\n\n";
    playerturn();
}
function1();

}
bool gameover()
{
    for(int i=0;i<3;i++)
        if(a[i][0]==a[i][1]&&a[i][0]==a[i][2]||a[0][i]==a[1][i]&&a[0][i]==a[2][i])
        {
            return false;
        }
        if(a[0][0]==a[1][1]&&a[0][0]==a[2][2]||a[0][2]==a[1][1]&&a[0][0]==a[2][0])
            return false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!='x'&&a[i][j]!='y')
            {
                return true;
            }
        }
    }
    draw=true;
    return false;
}
int main()
{
    while(gameover())
            {
    function1();
    playerturn();
    gameover();
    }
    if(turn=='x' && draw==false)
    {
        cout<<"player 2 win the game";
    }
    if(turn=='y' && draw==false)
    {
        cout<<"player 1 win the game";
    }
    else
        cout<<"Game Draw";
}
