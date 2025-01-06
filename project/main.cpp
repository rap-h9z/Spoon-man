#include <iostream>
#include <chrono>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
using namespace std::chrono;
#define row 20
#define col 20
int main()
{
    int hardness();
    void easyplayground(char ground[row][col],int x,int y);
    void mediumplayground(char ground[row][col],int x,int y);
    void hardplayground( char ground[row][col],int x,int y);
    void help();
    void easyB(char ground[row][col],int x,int y);
    void mediumB(char ground[row][col],int x,int y);
    void hardB(char ground[row][col],int x,int y);
    void easygame();
    void mediumgame();
    void hardgame();
    int ans;
    
    string s="Welcome to the Spoon Man game";
    for (int i=0; i<30; ++i) {
        usleep(200000);
        cout<<s[i];
    }
    usleep(2000000);
    string t="\n\n1.Start\n2.Hardness level\n3.Help\n4.Exit";
    for (int j=0; j<41; ++j) {
        usleep(100000);
        cout<<t[j];
    }
    cin>>ans;
    switch (ans) {
        case 1:
            easygame();
            break;
        case 2:
            switch (hardness()) {
                case 1:
                    cout<<"\n\n\n\n\n\n\n\n\n\n1.Start\n2.back";
                    cin>>ans;
                    switch (ans) {
                        case 1:
                            easygame();
                            break;
                        default:
                            hardness();
                            break;
                    }
                    break;                case 2:
                    cout<<"\n\n\n\n\n\n\n\n\n\n1.Start\n2.back";
                    cin>>ans;
                    switch (ans) {
                        case 1:
                            mediumgame();
                            break;
                        default:
                            hardness();
                            break;
                    }
                    break;
                case 3:
                    cout<<"\n\n1.Start\n2.back";
                    cin>>ans;
                    switch (ans) {
                        case 1:
                            hardgame();
                            break;
                        default:
                            hardness();
                            break;
                    }
                default:
                    cout<<"\n\n1.Start\n2.Hardness level\n3.Help\n4.Exit";
                    cin>>ans;
                    switch (ans) {
                        case 1:
                            easygame();
                            break;
                        case 2:
                            hardness();
                        case 3:
                            help();
                        default:
                            break;
                    }
                    break;
            }
            break;
        case 3:
            help();
            break;
        default:
            break;
    }
}
int hardness()
{
    int ans;
    cout<<"\n\n1.easy"<<"\n2.medium"<<"\n3.Hard"<<"\n4.back";
    cin>>ans;
    return ans;
}
void help()
{
    string i="Hi\nIn this game if you want to survive,you just need to kill enemis with bombs\n you can move with D:⮕ ,W:⬆ ,S:⬇ ,A:⬅\n\nS:you\nE:your enemy\nXX:unbreakable wall\n= :breakable wall\nB!:bomb\n\n\nGame maker:Raha Pazoki\nId:4021226411";
    for (int k=0; k<230; ++k) {
        usleep(200000);
        cout<<i[k];
    }
}
void easyplayground (char ground[row][col],int x,int y)
{
    ground[x][y] = 'S';
    int ran;
    srand(time_t(0));
    for (int i=1; i<row; i++) {
        for (int j=1; j<col; j++) {
            if (i==1||i==row-1||j==1||j==col-1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"xx";
            }
            else if (i==18&&j==17){
                cout<<"<>";
            }
            else if (i==x&&j==y)
                cout<<" "<<ground[x][y];
            else {
                ran=(rand()%20);
                if ((ran%100==0)){
                    ground[i][j]='E';
                    cout<<ground[i][j]<<" ";}
                else if(ran%15==0){
                    ground[i][j]='=';
                    cout<<ground[i][j]<<" ";}
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void easyB(char ground[row][col],int x,int y)
{
    ground[x][y] = 'S';
    int ran;
    srand(time_t(0));
    for (int i=1; i<row; i++) {
        for (int j=1; j<col; j++) {
            if (i==1||i==row-1||j==1||j==col-1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"XX";
            }
            else if (i==18&&j==17){
                cout<<"<>";
            }
            else if (i==x&&j==y){
                cout<<" "<<ground[x][y];
                ++j;
                ground[i][j]='B';
                cout<<"  "<<ground[i][j];
                ++j;
                ground[i][j]='!';
                cout<<ground[i][j];
            }
            else {
                ran=(rand()%20);
                if ((ran%100==0)){
                    ground[i][j]='E';
                    cout<<ground[i][j]<<" ";}
                else if(ran%15==0){
                    ground[i][j]='=';
                    cout<<ground[i][j]<<" ";}
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void easygame()
{
    auto start=high_resolution_clock::now();
    long int T;
    char ground[row][col];
    int x=2,y=2;
    char ans;
    int count=0;
    easyplayground(ground,x,y);
        cout<<"Go..."<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cin>>ans;
        switch (ans) {
            case 'w':
                --x;
                ground[x][y]='S';
                easyplayground(ground,x,y);
                break;
            case 's':
                ++x;
                ground[x][y]='S';
                easyplayground(ground, x,y);
                break;
            case 'a':
                --y;
                ground[x][y]='S';
                easyplayground(ground,x,y);
                break;
            case 'd':
                ++y;
                ground[x][y]='S';
                easyplayground(ground,x,y);
                break;
            case 'b':
                easyB(ground,x,y);
                break;
            case 'q':
                return;
        }
    ++count;
    auto end=high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    T=duration.count();
    cout<<T;
    
}
void mediumplayground (char ground[row][col],int x,int y)
{
    ground[x][y] = 'S';
    int ran;
    srand(time_t(0));
    for (int i=1; i<row; i++) {
        for (int j=1; j<col; j++) {
            if (i==1||i==row-1||j==1||j==col-1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"xx";
            }
            else if (i==18&&j==17){
                cout<<"<>";
            }
            else if (i==x&&j==y)
                cout<<" "<<ground[x][y];
            else {
                ran=(rand()%20);
                if ((ran%80==0)){
                    ground[i][j]='E';
                    cout<<ground[i][j]<<" ";}
                else if(ran%7==0){
                    ground[i][j]='=';
                    cout<<ground[i][j]<<" ";}
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void mediumB (char ground[row][col],int x,int y)
{
    ground[x][y] = 'S';
    int ran;
    srand(time_t(0));
    for (int i=1; i<row; i++) {
        for (int j=1; j<col; j++) {
            if (i==1||i==row-1||j==1||j==col-1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"XX";
            }
            else if (i==18&&j==17){
                cout<<"<>";
            }
            else if (i==x&&j==y){
                cout<<" "<<ground[x][y];
                ++j;
                ground[i][j]='B';
                cout<<"  "<<ground[i][j];
                ++j;
                ground[i][j]='!';
                cout<<ground[i][j];
            }
            else {
                ran=(rand()%20);
                if ((ran%80==0)){
                    ground[i][j]='E';
                    cout<<ground[i][j]<<" ";}
                else if(ran%7==0){
                    ground[i][j]='=';
                    cout<<ground[i][j]<<" ";}
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void mediumgame()
{
    auto start=high_resolution_clock::now();
    long int T;
    char ground[row][col];
    int x=2,y=2;
    char ans;
    int count=0;
    mediumplayground(ground,x,y);
        cout<<"Go..."<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cin>>ans;
        switch (ans) {
            case 'w':
                --x;
                ground[x][y]='S';
                mediumplayground(ground,x,y);
                break;
            case 's':
                ++x;
                ground[x][y]='S';
                mediumplayground(ground, x,y);
                break;
            case 'a':
                --y;
                ground[x][y]='S';
                mediumplayground(ground,x,y);
                break;
            case 'd':
                ++y;
                ground[x][y]='S';
                mediumplayground(ground,x,y);
                break;
            case 'b':
                mediumB(ground,x,y);
                break;
            case 'q':
                return;
        }
    ++count;
    auto end=high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    T=duration.count();
    cout<<T;
    
}void hardplayground ( char ground[row][col],int x,int y)
{
    ground[x][y] = 'S';
    int ran;
    srand(time_t(0));
    for (int i=1; i<row; i++) {
        for (int j=1; j<col; j++) {
            if (i==1||i==row-1||j==1||j==col-1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"xx";
            }
            else if (i==18&&j==17){
                cout<<"<>";
            }
            else if (i==x&&j==y)
                cout<<" "<<ground[x][y];
            else {
                ran=(rand()%20);
                if ((ran%8==0)){
                    ground[i][j]='E';
                    cout<<ground[i][j]<<" ";}
                else if(ran%3==0){
                    ground[i][j]='=';
                    cout<<ground[i][j]<<" ";}
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void hardB( char ground[row][col],int x,int y)
{
    ground[x][y] = 'S';
    int ran;
    srand(time_t(0));
    for (int i=1; i<row; i++) {
        for (int j=1; j<col; j++) {
            if (i==1||i==row-1||j==1||j==col-1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"XX";
            }
            else if (i==18&&j==17){
                cout<<"<>";
            }
            else if (i==x&&j==y){
                cout<<" "<<ground[x][y];
                ++j;
                ground[i][j]='B';
                cout<<"  "<<ground[i][j];
                ++j;
                ground[i][j]='!';
                cout<<ground[i][j];
            }
            else {
                ran=(rand()%20);
                if ((ran%8==0)){
                    ground[i][j]='E';
                    cout<<ground[i][j]<<" ";}
                else if(ran%3==0){
                    ground[i][j]='=';
                    cout<<ground[i][j]<<" ";}
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void hardgame()
{
    auto start=high_resolution_clock::now();
    long int T;
    char ground[row][col];
    int x=2,y=2;
    char ans;
    int count=0;
    hardplayground(ground,x,y);
        cout<<"Go..."<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cin>>ans;
        switch (ans) {
            case 'w':
                --x;
                ground[x][y]='S';
                hardplayground(ground,x,y);
                break;
            case 's':
                ++x;
                ground[x][y]='S';
                hardplayground(ground, x,y);
                break;
            case 'a':
                --y;
                ground[x][y]='S';
                hardplayground(ground,x,y);
                break;
            case 'd':
                ++y;
                ground[x][y]='S';
                hardplayground(ground,x,y);
                break;
            case 'b':
                hardB(ground,x,y);
                break;
            case 'q':
                return;
        }
    ++count;
    auto end=high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    T=duration.count();
    cout<<T;
    
}
