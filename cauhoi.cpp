#include<bits/stdc++.h>
#include"vector.cpp"

using namespace std;

#ifndef __cauhoi__cpp__
#define __cauhoi__cpp__

string guess;   //Answer user inputs for question.
int total;      //Total score.
int n;          //Total quiz

template <typename T>
T Score(T x){
    return x;
}

class Question{
private:
    string Question_Text;
    string answer[4];
    string correct_answer;
    int Question_Score;
public:
    Question() {};
    void setValues(string, string, string, string, string, string, int);
    void askQuestion();
    //void getValues(string, string, string, string, string, string, int, Vector<Question>);
    string getQuestion_Text();
    string getAnswers(int);
    string getCorrect_answer();
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

void Question::askQuestion(){
    system("cls");

    cout << "\n"<< getQuestion_Text() << "\n";
    srand((unsigned int)time(NULL));
    map<int, bool> vis;
    int r;
    for(int i=0;i<4;i++){
        do{
            r = rand() % 4 ;
            }while(vis.find(r)!=vis.end());
            cout<<"\n"<< getAnswers(r)<< "\n";
            vis[r]=true;
    }
    cout << "\n";
    //User enters their answer.
    cout << "Your answer ?: ";
    cin >> guess;

    if (guess == getCorrect_answer())
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

string Question::getQuestion_Text(){
    return Question_Text;
}

string Question::getCorrect_answer(){
    return correct_answer;
}

string Question::getAnswers(int i){
        return answer[i];
}
#endif
