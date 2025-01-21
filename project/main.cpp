#include <iostream>
#include <chrono>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
using namespace std::chrono;
#define row 20
#define col 20
struct score{
    int movements=0;
    int countB=0;
    long int time=0;
};
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
    void menu();
    void space();
    
    string s="Welcome to the Spoon Man game";
    for (int i=0; i<30; ++i) {
        usleep(200000);
        cout<<s[i];
    }
    usleep(2000000);
    menu();
    return 0;
}
double point( score m, score cb, score t,const int wm,const int wt,const int wb)
{
    double s;
    s=1000/(1+(m.movements*wm)+(cb.countB*wb)+(t.time*wt));
    return s;
}
void space()
{
    for (int i=0; i<21; ++i) {
        cout<<endl;
    }
}
void spacemenu()
{
    for(int j=0;j<42;++j)
        cout<<endl;
}
int hardness()
{
    int ans;
    string k="\n\n1.easy\n2.medium\n3.Hard\n4.menu\n";
    for (int i=0; i<33; ++i) {
        usleep(100000);
        cout<<k[i];
    }
    cin>>ans;
    return ans;
}
void help()
{
    string i="\n\n\n\n\nHi\nIn this game if you want to survive,you just need to kill enemis with bombs and finally reach home.\n you can move with D:⮕ ,W:⬆ ,S:⬇ ,A:⬅ and press B button whenever you needed to demolish something.\n\nS:you\nE:your enemy\nXX:unbreakable wall\n= :breakable wall\nB!:bomb\n<>:home\n\n\nGame maker:Raha Pazoki\nId:4021226411";
    for (int k=0; k<328; ++k) {
        usleep(100000);
        cout<<i[k];
    }
    usleep(5000000);
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
    score m,t,cb;
    void menu();
    const int wm=1,wb=2,wt=1;
    char ground[row][col];
    int x=2,y=2;
    char ans;
    int count=0;
    int countB=0;
    auto start=high_resolution_clock::now();
    space();
    easyplayground(ground,x,y);
    while (x!=18||y!=17) {
        cout<<"EASY LEVEL\nmove...";
        cin>>ans;
        switch (ans) {
            case 'w':
                --x;
                space();
                ground[x][y]='S';
                easyplayground(ground,x,y);
                space();
                break;
            case 's':
                ++x;
                space();
                ground[x][y]='S';
                easyplayground(ground, x,y);
                space();
                break;
            case 'a':
                --y;
                space();
                ground[x][y]='S';
                easyplayground(ground,x,y);
                space();
                break;
            case 'd':
                ++y;
                space();
                ground[x][y]='S';
                easyplayground(ground,x,y);
                space();
                break;
            case 'b':
                space();
                easyB(ground,x,y);
                ++countB;
                space();
                break;
            case 'q':
                string k="Game over";
                for (int j=0; j<9; ++j) {
                    usleep(200000);
                    cout<<k[j];
                }
                sleep(2);
                spacemenu();
                menu();
                break;
        }
        ++count;
    }
    m.movements=count;
    cb.countB=countB;
    auto end=high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    t.time=duration.count();
    string s="\n\ncongrats...you win!\nyour point:";
    for (int i=0; i<34; ++i) {
        usleep(100000);
        cout<<s[i];
    }
    cout<<point(m,cb,t,wm,wt,wb)<<endl;
    
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
                if ((ran%50==0)){
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
                if ((ran%50==0)){
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
    score m,t,cb;
    void menu();
    const int wm=2,wb=2,wt=1;
    char ground[row][col];
    int x=2,y=2;
    char ans;
    int count=0;
    int countB=0;
    auto start=high_resolution_clock::now();
    space();
    mediumplayground(ground,x,y);
    while (x!=18||y!=17){
        cout<<"MEDIUM LEVEL\nmove...";
        cin>>ans;
        switch (ans) {
            case 'w':
                --x;
                space();
                ground[x][y]='S';
                mediumplayground(ground,x,y);
                space();
                break;
            case 's':
                ++x;
                space();
                ground[x][y]='S';
                mediumplayground(ground, x,y);
                space();
                break;
            case 'a':
                --y;
                space();
                ground[x][y]='S';
                mediumplayground(ground,x,y);
                space();
                break;
            case 'd':
                ++y;
                space();
                ground[x][y]='S';
                mediumplayground(ground,x,y);
                space();
                break;
            case 'b':
                space();
                mediumB(ground,x,y);
                ++countB;
                space();
                break;
            case 'q':
                string k="Game over";
                for (int j=0; j<8; ++j) {
                    usleep(200000);
                    cout<<k[j];
                }
                sleep(2);
                spacemenu();
                menu();
                break;
        }
        ++count;
    }
    m.movements=count;
    cb.countB=countB;
    auto end=high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    t.time=duration.count();
    string s="\n\ncongrats...you win!\nyour point:";
    for (int i=0; i<34; ++i) {
        usleep(100000);
        cout<<s[i];
    }
    cout<<point(m,cb,t,wm,wt,wb)<<endl;
}
void hardplayground ( char ground[row][col],int x,int y)
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
    score m,t,cb;
    void menu();
    const int wm=2,wb=3,wt=2;
    char ground[row][col];
    int x=2,y=2;
    char ans;
    int count=0;
    int countB=0;
    auto start=high_resolution_clock::now();
    space();
    hardplayground(ground,x,y);
    while (x!=18||y!=17){
        cout<<"HARD LEVEL\nmove...";
        cin>>ans;
        switch (ans) {
            case 'w':
                --x;
                space();
                ground[x][y]='S';
                hardplayground(ground,x,y);
                space();
                break;
            case 's':
                ++x;
                space();
                ground[x][y]='S';
                hardplayground(ground, x,y);
                space();
                break;
            case 'a':
                --y;
                space();
                ground[x][y]='S';
                hardplayground(ground,x,y);
                space();
                break;
            case 'd':
                ++y;
                space();
                ground[x][y]='S';
                hardplayground(ground,x,y);
                space();
                break;
            case 'b':
                space();
                hardB(ground,x,y);
                ++countB;
                space();
                break;
            case 'q':
                string k="Game over";
                for (int j=0; j<9; ++j) {
                    usleep(200000);
                    cout<<k[j];
                }
                sleep(1);
                spacemenu();
                menu();
                break;
        }
    }
    ++count;
    auto end=high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    t.time=duration.count();
    string s="\n\ncongrats...you win!\nyour point:";
    for (int i=0; i<34; ++i) {
        usleep(100000);
        cout<<s[i];
    }
    cout<<point(m, cb, t, wm, wt, wb);
}

void menu()
{
    int ans;
    string t="\n\n1.Start\n2.Hardness level\n3.Help\n4.Exit\n";
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
            spacemenu();
            switch (hardness()) {
                case 1:
                    spacemenu();
                    cout<<"\n\n1.start\n2.menu";
                    cin>>ans;
                    switch (ans) {
                        case 1:
                            easygame();
                            break;
                        case 2:
                            spacemenu();
                            menu();
                            break;
                        default:
                            cout<<"unknown";
                            spacemenu();
                            menu();
                            break;
                    }
                    break;
                case 2:
                    spacemenu();
                    cout<<"\n\n1.start\n2.menu";
                    cin>>ans;
                    switch (ans) {
                        case 1:
                            mediumgame();
                            break;
                        case 2:
                            spacemenu();
                            menu();
                            break;
                        default:
                            cout<<"unknown";
                            spacemenu();
                            menu();
                            break;
                    }
                    break;
                case 3:
                    spacemenu();
                    cout<<"\n\n1.start\n2.menu";
                    cin>>ans;
                    switch (ans) {
                        case 1:
                            hardgame();
                            break;
                        case 2:
                            spacemenu();
                            menu();
                            break;
                        default:
                            cout<<"unknown";
                            spacemenu();
                            menu();
                            break;
                    }
                    break;
                case 4:
                    spacemenu();
                    menu();
                    break;
                default:
                    cout<<"unknown";
                    spacemenu();
                    menu();
                    break;
            }
            break;
        case 3:
            spacemenu();
            help();
            spacemenu();
            menu();
            break;
        case 4:
            break;
        default:
            cout<<"unknown";
            spacemenu();
            menu();
            break;
    }
}
