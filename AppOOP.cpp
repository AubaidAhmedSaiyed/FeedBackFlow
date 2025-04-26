#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

class User{

    private:

        string filename;
        string feedback;

    public:

    // to view all logged feedback
    void viewFeedback() {
        ifstream file("feedback.txt");
        if (!file) {
            cout << "Could not open the feedback file.\n";
            return;
        }

        cout << "\nAll Feedback:\n";
        while (getline(file, feedback)) {
            cout << feedback << endl;
        }

        file.close();
    }
    // Function to log feedback to a file
    void logFeedback() {
        ofstream file("feedback.txt");
        if (!file) {
            cout << "Could not open the file to log feedback.\n";
            return;
        }

        string feedback;
        cout << "Enter feedback to log: ";
        cin.ignore();
        getline(cin, feedback);

        file << feedback << endl;
        cout << "Feedback logged successfully.\n";

        file.close();
    }

    
};

class PM{

    private:


        string pmFeedback;
        float rating;
        string feature;

    public:
   

   // to prioritize features based on impact vs effort
    void prioritizeFeatures() {
        int impact, effort;

        cout << "Enter 3 features with their impact (1-10) and effort (1-10) scores:\n";

        for (int i = 0; i < 3; i++) {
            cout << "Feature " << i + 1 << " name: ";
            cin >> feature;
            cout << "Impact score (1-10): ";
            cin >> impact;
            cout << "Effort score (1-10): ";
            cin >> effort;

            // Calculate and display priority
            float priority = (float)impact / effort;
            cout << "Feature: " << feature << ", Priority Score: " << priority << endl;
        }
    }

    
    // PM decision-making based on ratings
    void pmDecision() {

        float rating;
        cout << "Enter average rating (1-5): ";
        cin >> rating;

        if (rating < 3) {
            cout << "\nImprove performance and UI : Arrange Meeting With  The Team \n";
        } else {
            cout << "\nContinue gathering feedback \n";
        }


    }
    // Function to log feedback to a file
    void logFeedback(User u) {
        ofstream file("feedback.txt");
        if (!file) {
            cout << "Could not open the file to log feedback.\n";
            return;
        }
        cout << "Enter feedback to log: ";
        cin.ignore();
        getline(cin, pmFeedback);

        file << pmFeedback << endl;
        cout << "Feedback logged successfully.\n";

        file.close();
    }

};


class analyzeFeedback {

    private:

        string file1;
    

    public:

    void painPointAnalysisk() { // function to analyze pain points from feedback file



    
        cout << "Enter the feedback file name (e.g., feedback.txt): ";
        cin >> file1;
    
        ifstream file(file1);
        if (!file) {
            cout << "Could not open the file.\n";
            return;
        }

        string line;
        vector<string> words; // Vector to store words

        while (getline(file, line)) {
        
            stringstream ss(line); // Create a stringstream from the line
            string word;

            // Split the line into words using stringstream
            while (ss >> word) {
                words.push_back(word); // Store each word in the vector
            }
        }


        // Iterate over each string in the vector
        for (int i = 0; i < words.size(); ++i) {
            // Convert each character of the current string to lowercase
            for (int j = 0; j < words[i].length(); ++j) {
                words[i][j] = tolower(words[i][j]);  // Convert each character
            }
        }
        int slowCount = 0, crashCount = 0, paymentCount = 0;
        for(string word: words){
            
            if (word == "slow") {
                slowCount++;
            }
            else if (word == "payment issue" || word == "issue payment") {
                paymentCount++;
        
            } else if (word =="crash") {
            crashCount++;;
            }
        
        }

        cout << "\nPain point analysis:\n";
        cout << "Slow: " << slowCount << endl;
        cout << "Crash: " << crashCount << endl;
        cout << "Payment: " << paymentCount << endl;

        file.close();
    }

    void sentimentDetection(){
        cout << "Enter the feedback file name (e.g., feedback.txt): ";
        cin >> file1;
    
        ifstream file(file1);
        if (!file) {
            cout << "Could not open the file.\n";
            return;
        }

        string line;
        vector<string> words;

        while (getline(file, line)) {
        
            stringstream ss(line);
            string word;

            while (ss >> word) {
                words.push_back(word); 
            }
        }


        
        for (int i = 0; i < words.size(); ++i) {
           
            for (int j = 0; j < words[i].length(); ++j) {
                words[i][j] = tolower(words[i][j]);  // Convert each character
            }
        }



        int pcount = 0, ncount = 0, mcount =0;
        for(string word: words){
            
            if (word == "good" || word == "very good" || word == "excellent" || word == "nice") {
                pcount++;
            }
            else if (word == "bad" || word == "very bad" || word == "very poor" || word == "poor") {
                ncount++;
        
            } else {
            mcount++;;
            }
        
        }


        cout << "\nSentiment Detection : ";
        if(pcount>ncount){
            cout<<"Mostly Positive\n\n";

        }else if(ncount<ncount){
            cout<<"Mostly Negative\n\n";

        }else{
            cout<<"Neutral - Positive And Negatives Are Equal\n\n";
        }


    }

    void PriorityDetection(){

        cout << "Enter the feedback file name (e.g., feedback.txt): ";
        cin >> file1;
    
        ifstream file(file1);
        if (!file) {
            cout << "Could not open the file.\n";
            return;
        }

        vector<string> words; 

        string line;
        int count = 0;
        while(getline(file,line)){
            stringstream ss(line); 
            string word;

            while (ss >> word) {
                words.push_back(word); 
            }
            

            for(string word: words){
            
                if (word == "important" || word == "immediately" || word == "urgent" || word == "high priority") {
                    cout<<"Priority Detection :: "<< line;
                    count++;
                }
                

            }
        }
        if(count == 0 ){
            cout<<"No High Priority Feedback Detected ";
        }

    }
};



int main() {

    int choice;
    int mode;
    do{
        // Mode selection (User or Product Manager)
        cout<<"\n\n***************** FeedBack Analyzer *********************\n\n";
        cout << "\n\nSelect Mode:\n";
        cout << "1. User Mode\n";
        cout << "2. Product Manager Mode\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mode;
        User u;
        if (mode == 1) {
            
            do{
                cout << "\nUser Mode:\n";
                cout << "1. Give feedback\n";
                cout << "2. View all feedback\n";
                cout << "3. Back To Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        u.logFeedback();  // Log feedback to file
                        break;
                    case 2:
                        u.viewFeedback();  // View all feedback from file
                        break;
                   
                }
            }while(choice != 3);

        } else if (mode == 2) {
            PM pm;
            analyzeFeedback a;
            do{
                cout << "\nProduct Manager Mode:\n";
                cout << "1. Analyze feedback\n";
                cout << "2. Make PM decision based on rating\n";
                cout << "3. Log feedback\n";
                cout << "4. Prioritize features\n";
                cout << "5. Back To Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice) {
                    case 1:

                        int ch;
                        cout<<"\n1.Pain Point Analysis\n";
                        cout<<"2.Sentiment Detection of Feedback\n";
                        cout<<"3.Priority Detection\n\n";
                        cout<<"Enter Your choice :: [1| 2 | 3] :: ";
                        cin>>ch;

                        if(ch == 1){
                            a.painPointAnalysisk();
                        } else if(ch == 2){
                            a.sentimentDetection();
                        }
                        else{
                            a.PriorityDetection();
                        }
                    

                        break;
                    case 2:
                        pm.pmDecision();  // Make PM decision based on rating
                        break;
                    case 3:
                        pm.logFeedback(u);  // Log feedback to file
                        break;
                    case 4:
                        pm.prioritizeFeatures();  // Prioritize features based on impact vs effort
                        break;
                }
            }while(choice!= 5);
        }
    }while(mode != 3);

    return 0;
}
