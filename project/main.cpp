#include <iostream>
#include <chrono>
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
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                cout << "* ";
            } else if (i % 2 == 1 && j % 2 == 1) {
                cout << "|XX|";
            } else if ((i==10 && j==11) || (i==8 && j==17)||(i==18 && j==12)) {
                cout << "EE";
            } else if((i==10&&j==10)||(i==10&&j==9)||(i==9&&j==12)||(i==8&&j==18)||(i==7&&j==16)||(i==7&&j==16)||(i==7&&j==18)){
                cout << "|_-|";
            }
            else if((i==row-2&&j==col-2))
                cout<<"|<>|";
            else
                cout<<"  ";
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
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                cout << "* ";
            } else if (i % 2 == 1 && j % 2 == 1) {
                cout << "|XX|";
            } else if ((i==10 && j==11) || (i==8 && j==17)||(i==18 && j==12)||(i==16&&j==5)||(i==6&&j==11)||(i==13&&j==12)) {
                cout << "EE";
            } else if((i==10&&j==10)||(i==10&&j==9)||(i==9&&j==12)||(i==8&&j==18)||(i==7&&j==16)||(i==7&&j==16)||(i==7&&j==18)||(i==16&&j==3)||(i==16&&j==7)||(i==13&&j==11)||(i==12&&j==11)||(i==12&&j==9)){
                cout << "|_-|";
            }
            else if((i==row-2&&j==col-2))
                cout<<"|<>|";
            else
                cout<<"  ";
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
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                cout << "* ";
            } else if (i % 2 == 1 && j % 2 == 1) {
                cout << "|XX|";
            } else if ((i==10 && j==11) || (i==8 && j==17)||(i==18 && j==12)||(i==16&&j==5)||(i==6&&j==11)||(i==13&&j==12)||(i==7&&j==10)||(i==3&&j==12)||(i==5&&j==4)||(i==15&&j==18)) {
                cout << "EE";
            } else if((i==10&&j==10)||(i==10&&j==9)||(i==9&&j==12)||(i==8&&j==18)||(i==7&&j==16)||(i==7&&j==16)||(i==7&&j==18)||(i==16&&j==3)||(i==16&&j==7)||(i==13&&j==11)||(i==12&&j==11)||(i==12&&j==9)||(i==3&&j==14)||(i==3&&j==16)||(i==5&&j==6)||(i==5&&j==2)||(i==5&&j==8)||(i==15&&j==16)||(i==15&&j==4)||(i==15&&j==10)){
                cout << "|_-|";
            }
            else if((i==row-2&&j==col-2))
                cout<<"|<>|";
            else
                cout<<"  ";
        }
        cout << endl;
    }
    auto end= high_resolution_clock::now();
    auto duration= duration_cast<seconds>(end-start);
    cout<<"Time:"<<duration.count()<<endl;
}

