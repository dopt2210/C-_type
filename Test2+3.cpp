#include<bits/stdc++.h>

using namespace std;

string guess; //Answer user inputs for question.
int total;  //Total score.

template <typename T>
T Score(T x){
    return x;
}

class Question
{
private:
    string Question_Text;
    string answer[4];
    string correct_answer;
    int Question_Score;
public:
    Question() {};
    void setValues(string, string, string, string, string, string, int);
    void askQuestion();
};

//Function called for question guidelines.
void Question::setValues(string text, string a,string b,string c,string d, string res, int scr){
    Question_Text = text;
    answer[0] = a;
    answer[1] = b;
    answer[2] = c;
    answer[3] = d;
    correct_answer = res;
    Question_Score = scr;
}

//Format for possible answers displayed when program executes.
void Question::askQuestion(){
    system("cls");
    cout << "\n"<< Question_Text << "\n";
    srand((unsigned int)time(NULL));
    map<int, bool> vis;
    int r;
    for(int i=0;i<4;i++){
        do{
            r = rand() % 4 ;
            }while(vis.find(r)!=vis.end());
            cout<<"\n"<< answer[r]<< "\n";
            vis[r]=true;
    }
    cout << "\n";
    //User enters their answer.
    cout << "Your answer ?: ";
    cin >> guess;

    if (guess == correct_answer)
    {
        cout << "\nCorrect!" << "\n";
        total = total + Question_Score;
        cout << "\nPress enter to continue.";
        cin.get();
        cin.ignore();
    }
    else
    {
        cout << "\nOops! Answer is: " << correct_answer << "." << "\n";
        cout << "\nPress enter to continue.";
        cin.get();
        cin.ignore();
    }
}

void beginQuizz(){
    //Program Title designed with an ASCII art generator
    cout << "( WELCOME TO THE MINI TEST)" << "\n";
    cout << "Press enter to start...\n";
    cin.get();

    //Ask if user wants to start quiz.
    string respond;
    cout << "Are you ready ?!?. (Yes/No)\n";
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

    //Display message created with ASCII art generator.
    if (total>50)
    {
        cout << "(YOU PASSED)" << "\n";
        cout << "\n";
        cin.get();
        cin.ignore();
        exit(0);
    }
    else
    {
        cout << "You failed... Sorry, better luck next time.\n";
        cout << "\n";
    }
    cin.get();
    cin.ignore();
    exit(0);
}

int main()
{
    beginQuizz();
    Question q[10];
    fstream f;
    f.open("CauHoi.txt", ios::in);

    for(int i=0;i<9;i++){
        string text,a,b,c,d,e;
        getline(f,text);
        getline(f,a);
        getline(f,b);
        getline(f,c);
        getline(f,d);
        getline(f,e);
        q[i].setValues(text,a,b,c,d,e,10);
    }
    f.close();

    srand((unsigned int)time(NULL));
    map<int, bool> vis;
    int rd;
    for(int i=0;i<9;i++){
        do{
            rd = rand() % 9 ;
            }while(vis.find(rd)!=vis.end());
            q[rd].askQuestion();
            vis[rd]=true;
    }

    result();
}


