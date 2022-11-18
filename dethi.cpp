#include<bits/stdc++.h>
#include"cauhoi.cpp"
#include"vector.cpp"

using namespace std;

Question q[10];

void beginQuizz(){

    cout << "( WELCOME TO THE MINI TEST)" << "\n";
    cout << "Press enter to start...\n";
    cin.get();

    //Ask if user wants to start quiz.
    string respond;
    cout << "Are you ready ?!?. (Yes/No)\n\n";
    cin >> respond;

    //If user says yes, the quiz begins.
    if (respond == "Yes" || respond == "yes")
    {
        cout << "\nOkay, Good luck!\n";
        cout << "\nPress enter to continue.";
        cin.get();
        cin.ignore();
    }
    else
    {
        cout << "Goodbye!\n";
        cin.ignore();
        cin.get();
        exit(0);
    }
}

void result(){
    system("cls");
    cout << "\nYour Total Score is " << Score<int>(total) <<" point !";
    cout << "\n";

    if (total>(n/2))
    {
        cout << "(YOU PASSED)" << "\n";
        cin.get();
        cin.ignore();
        exit(0);
    }
    else
    {
        cout << "You failed... Sorry, better luck next time.\n";
    }
    cin.get();
    cin.ignore();
    exit(0);
}

void crVec(Vector<Question>& newVec, int n){
    fstream f;
    f.open("CauHoi.txt", ios::in);

    for(int i=0;i<n;i++){
        string text,a,b,c,d,e;
        getline(f,text);
        getline(f,a);
        getline(f,b);
        getline(f,c);
        getline(f,d);
        getline(f,e);
        q[i].setValues(text,a,b,c,d,e,10);
        newVec.push_back(q[i]);
    }
    f.close();
}

void shVec(Vector<Question>& newVec, int n){
    int vecSize=newVec.size();
    srand((unsigned int)time(NULL));
    map<int, bool> vis;
    int rd;
    if(vecSize<n) exit(1);
    else vecSize=n;
    for(int i=0; i<vecSize; i++){
        do{
            rd = rand() % n ;
            }while(vis.find(rd)!=vis.end());
            q[rd].askQuestion();
            vis[rd]=true;
    }
}

int main()
{
    Vector<Question> newVec;
    beginQuizz();
    system("cls");
    cout<< "Chose numbers of questions (<=9) : ";cin>>n;
    crVec(newVec, n);
    shVec(newVec, n);
    result();
}
