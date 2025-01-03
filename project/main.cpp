#include <iostream>
#include <chrono>
#include <cstdlib>
#include <time.h>
using namespace std;
using namespace std::chrono;
#define row 20
#define col 20
int main()
{
    int hardness();
    void easylevel();
    void mediumlevel();
    void hardlevel();
    void help();
    int ans;
    cout<<"Welcome to the Spoon Man game";
    cout<<"\n\n1.Start"<<"\n2.Hardness level"<<"\n3.Help"<<"\n4.Exit";
    cin>>ans;
    switch (ans) {
        case 1:
            easylevel();
            break;
        case 2:
            hardness();
            if (hardness()==2){
                cout<<"\n\n1.Start"<<"\n2.Hardness level"<<"\n3.Help"<<"\n4.Exit";
                cin>>ans;
                switch (ans) {
                    case 1:
                        mediumlevel();
                        break;
                    case 2:
                        hardness();
                    case 3:
                        help();
                    default:
                        break;
                }
            }
            else if (hardness()==3){
                cout<<"\n\n1.Start"<<"\n2.Hardness level"<<"\n3.Help"<<"\n4.Exit";
                cin>>ans;
                switch (ans) {
                    case 1:
                        hardlevel();
                        break;
                    case 2:
                        hardness();
                    case 3:
                        help();
                    default:
                        break;
                }
            }
            else{
                cout<<"\n\n1.Start"<<"\n2.Hardness level"<<"\n3.Help"<<"\n4.Exit";
                cin>>ans;
                switch (ans) {
                    case 1:
                        easylevel();
                        break;
                    case 2:
                        hardness();
                    case 3:
                        help();
                    default:
                        break;
                }
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
    cout<<"1.easy"<<"\n2.medium"<<"\n3.Hard";
    cin>>ans;
    return ans;
}
void help()
{
    cout<<"Hi\n"<<"In this game if do you want to survive you just will need to kill the enemis with bombs "<<"\n you can move with ⮕,⬆,⬇,⬅"<<"\nor"<<"A,W,S,D"<<"\n\n\nGame maker:Raha Pazoki"<<"\nId:"<<"4021226411";
}
void easylevel ()
{
    auto start=high_resolution_clock::now();
    srand(time_t(0));
    char graound[row][col];
    int ran;
    
    srand(time_t(0));

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (i == 1 || i == row - 1 || j == 1 || j == col - 1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"xx";
            }
            else if (i==18&&j==17){
                cout<<"<>";
        }
        else {
            ran=(rand()%20);
            if ((ran%100==0)){
                graound[i][j]='E';
                cout<<graound[i][j]<<" ";}
            else if(ran%15==0){
                graound[i][j]='=';
                cout<<graound[i][j]<<" ";}
            else
                cout<<"  ";
            }
        }
        cout << endl;
    }
    auto end= high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    cout<<"Time:"<<duration.count()<<endl;
}
void mediumlevel ()
{
    auto start=high_resolution_clock::now();
    srand(time_t(0));
    char graound[row][col];
    int ran;
    
    srand(time_t(0));

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (i==1||i==row-1||j==1||j==col-1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"xx";
            }
            else if (i==18&&j==17){
                cout<<"<>";
        }
        else {
            ran=(rand()%20);
            if ((ran%80==0)){
                graound[i][j]='E';
                cout<<graound[i][j]<<" ";}
            else if(ran%7==0){
                graound[i][j]='=';
                cout<<graound[i][j]<<" ";}
            else
                cout<<"  ";
            }
        }
        cout << endl;
    }
    auto end= high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    cout<<"Time:"<<duration.count()<<endl;
}
void hardlevel()
{
    auto start=high_resolution_clock::now();
    srand(time_t(0));
    char graound[row][col];
    int ran;
    
    srand(time_t(0));

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (i == 1 || i == row - 1 || j == 1 || j == col - 1) {
                cout<<" *";
            }
            else if (i!=1&&i%2==1&& j%2==1) {
                cout<<"xx";
            }
            else if (i==18&&j==17){
                cout<<"<>";
        }
        else {
            ran=(rand()%20);
            if ((ran%8==0)){
                graound[i][j]='E';
                cout<<graound[i][j]<<" ";}
            else if(ran%3==0){
                graound[i][j]='=';
                cout<<graound[i][j]<<" ";}
            else
                cout<<"  ";
            }
        }
        cout << endl;
    }
    auto end= high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    cout<<"Time:"<<duration.count()<<endl;
}

