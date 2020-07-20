#include <iostream>
#include <fstream>      //Files library
#include <cstdlib>      //For exit library
#include <algorithm>    //Libraries for transform if someone would use "A" instead of "a".
#include <string>       //

using namespace std;

//For reading the file;
string topic, nick;
string question[5];                             //Table of 5 elements with questions.
string ansA[5], ansB[5], ansC[5], ansD[5];      //Tables with answers (A,B,C,D), each of 5 elements for 5 questions.
string correct[5];                              //Table of 5 elements with correct answers.

//For answering the questions:
string answer;
int points=0;


int main()
{
    string line;        //variables for helping to create functions
    int line_nr=1;        //
    int question_nr=0;    //variable to help read the question data (see switch and if).

    fstream file;
    file.open("quiz.txt", ios::in);      //Opening the file quiz.txt

    if (file.good()==false)             //Checking if the file exists.
    {
        cout << "The file does not exist!";
        exit(0);
    }

    while(getline(file,line))
    {
        switch(line_nr)
        {
            case 1: topic=line;                      break;
            case 2: nick=line;                       break;
            case 3: question[question_nr]=line;      break;
            case 4: ansA[question_nr]=line;          break;
            case 5: ansB[question_nr]=line;          break;
            case 6: ansC[question_nr]=line;          break;
            case 7: ansD[question_nr]=line;          break;
            case 8: correct[question_nr]=line;       break;

            if(line_nr==8) {line_nr=2; question_nr++;}
            line_nr++;                                  //Incrementation of line number with each iteration.
        }
    }
    file.close();

    //We have successfully opened the file quiz.txt.
    //Now, we need to do the loop that will 5 times:
    // -> ask a question,
    // -> waits for answer  -> check if it is correct,
    // -> will give a point of correct.

    for(int i=0; i<=4; i++)
    {
        cout<<question[i]<<endl;
        cout<<"A. "<<ansA[i]<<endl;
        cout<<"B. "<<ansB[i]<<endl;
        cout<<"C. "<<ansC[i]<<endl;
        cout<<"D. "<<ansD[i]<<endl;

        cout<<"What is Your answer: ";
        cin >> answer;

        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);     //Transformation of the capital letters to lowercase.

        if(answer==correct[i])
        {
            cout<<"Good answer! You have a point!"<<endl;
            points++;
        }else cout<<"Wrong answer! No points for this. The correct answer is: "<<correct[i]<< endl;
    }

    cout <<endl<< "End of quiz! You have: " << points<<endl;

    return 0;
}
