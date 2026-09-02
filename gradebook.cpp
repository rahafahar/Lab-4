#include <iostream>
#include <iomanip>

using namespace std;

void getScores(int scores[], int size){

    cout << "\n\nPlease enter " << size << " scores. \n\n";

    for(int i = 0; i < size; i++){
        cout << "Number " << (i + 1) << ": ";
        int candidateScore = -1;
        cin >> candidateScore;
        while(candidateScore < 0 || candidateScore > 100){
            //redo
            cout << "Score must be between 0-100 ! Try again: " ;
            cin >> candidateScore;
            cout << endl;
        }
        scores[i] = candidateScore;
        cout << endl;
    }
}

void printScores(const int scores[], int size){
    cout << endl;
    for(int i = 0;i < size; i++){
        cout << scores[i] << endl;
    }
}

int getLowest(const int scores[], int size){

    int lowest = 100;
    for(int i = 0;i < size; i++){
      if(scores[i] < lowest){
        lowest = scores[i];
      }
    }

    return lowest;
   
}


double calculateAverage(const int scores[], int size){
    double sum = 0;
    for(int i = 0;i < size; i++){
      sum += scores[i];
      }
    

    sum -= getLowest(scores,size);
    
    return sum / (size - 1);
}

int main(){
    
    
    const int SIZE = 5;
    int scores[SIZE];
    cout << fixed << setprecision(2);

    //Call getScores to fill the array with user data.
    getScores(scores,SIZE);
    //Call printScores to display the scores the user entered.
    printScores(scores, SIZE);
    //Call calculateAverage and store the returned value in a variable.
    double average = calculateAverage(scores, SIZE);
    //Display the final calculated average, formatted to two decimal places.

    cout << "The scores you entered are: ";
    for(int i = 0; i < SIZE; i++){
        cout << scores[i] << " ";
    }    
    cout << "After dropping the lowest score, the average is: " << average << endl;



    return 0;
}
