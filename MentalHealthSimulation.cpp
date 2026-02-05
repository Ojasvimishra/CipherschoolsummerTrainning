#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

// ========== USER CLASS ==========
class User {
protected:
    string name;
    int age;
public:
    void inputUser() {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your age: ";
        while (!(cin >> age)) { // input validation for age
            cout << "Invalid input! Enter a number for age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
        
    }
    void displayUser() {
        cout << "\n------------------------------------------\n";
        cout << "User: " << name << " | Age: " << age << endl;
        cout << "------------------------------------------\n";
    }
    string getName() { return name; }
};

// ========== MOOD TRACKER ==========
class MoodTracker {
private:
    string mood;
public:
    void setMood(string m) { mood = m; }
    string getMood() { return mood; }
    void displayMood() { cout << "Your current mood is: " << mood << endl; }
};

// ========== QUOTE MANAGER ==========
class QuoteManager {
    vector<string> quotes;
public:
  QuoteManager() {
    quotes = {
        "Keep going, you are doing great!",
        "Breathe. You are stronger than you think.",
        "Your feelings are valid — take care of yourself.",
        "Small steps every day make a big difference.",
        "Positivity is a superpower!",
        "You don't have to be perfect to be amazing.",
        "Rest. Recharge. Restart. You got this!"
    };
}

    void showRandomQuote() {
        static bool seeded = false;
        if (!seeded) {
            srand(time(0)); // seed once
            seeded = true;
        }
        int i = rand() % quotes.size();
        cout << "Quote of the Day: \"" << quotes[i] << "\"\n";
    }
};

// ========== ACTIVITY SUGGESTER ==========
class ActivitySuggester {
public:
    virtual void suggestActivity(string mood) {
        cout << "\nMindful Suggestion:\n";
        if (mood == "sad") {
            cout << "Activity: Write down three things you’re grateful for.\n";
            cout << "Music: Play some soft instrumental tunes.\n";
            cout << "Challenge: Compliment yourself.\n";
        }
        else if (mood == "stressed") {
            cout << "Activity: Take a slow walk outside and focus on breathing.\n";
            cout << "Music: Lo-fi Chill or Nature Sounds.\n";
            cout << "Challenge: Disconnect from phone for 30 minutes.\n";
        }
        else if (mood == "tired") {
            cout << "Activity: Close eyes and take 10 deep breaths.\n";
            cout << "Music: Calm rain or ocean sounds.\n";
            cout << "Challenge: Sleep 30 minutes earlier.\n";
        }
        else if (mood == "happy") {
            cout << "Activity: Capture the moment in a journal.\n";
            cout << "Music: Dance to your favorite upbeat song.\n";
            cout << "Challenge: Text a friend something positive.\n";
        }
        else {
            cout << "Activity: Try meditation or drink a warm cup of tea.\n";
            cout << "Music: Relaxing acoustic tracks.\n";
            cout << "Challenge: Smile at someone today.\n";
        }
    }
    virtual ~ActivitySuggester() {}
};

// ========== EXERCISE CLASS ==========
class Exercise : public ActivitySuggester {
public:
    void suggestActivity(string mood) override {
        cout << "\nWellness Exercise:\n";
        if (mood == "sad")
            cout << "Take a 10-min walk in sunlight.\n Write 3 positive affirmations.\n"
                 "Listen to your favorite uplifting song.\n Draw or doodle something that makes you smile.\n"
                 "Call or message a supportive friend.\n Read a short inspiring story or quote.\n"
                 "Try a simple breathing exercise: inhale deeply, hold, exhale slowly.\n";
            
        else if (mood == "stressed")
            cout << "• Box breathing (Inhale 4s, Hold 4s, Exhale 4s, Hold 4s).\n• Stretch arms and neck.\n"
                 "• Take a 5-minute walk.\n";
        else if (mood == "tired")
            cout << "• Light yoga for 5 minutes.\n• Drink water and stretch.\n"
                 "• Do a quick 2-minute meditation.\n"
                 "• Avoid screens for 30 minutes.\n";
        else if (mood == "happy")
            cout << "• Do 10 jumping jacks.\n• Share your energy with others.\n"
                 "• Dance to your favorite song.\n"
                 "• Try a new fun activity.\n";
        else
            cout << "• Practice slow breathing and journaling.\n"
                 "• Take a short walk outside.\n"
                 "• Do light stretching.\n";
    }
};

// ========== DATA LOGGER ==========
class DataLogger {
public:
    void saveMood(string name, string mood) {
        ofstream file("mood_log.txt", ios::app);
        if (!file) { cout << "Error opening file!\n"; return; }
        time_t now = time(0);
        char* dt = ctime(&now);
        file << "User: " << name << " | Mood: " << mood << " | " << dt;
        file.close();
    }
    void showLogs() {
        ifstream file("mood_log.txt");
        if (!file) { cout << "No mood history found.\n"; return; }
        string line;
        cout << "\nMood History:\n";
        while (getline(file, line)) cout << line;
        file.close();
    }
};

// ========== MENU ==========
void displayMenu() {
    cout << "\nMAIN MENU\n";
    cout << "1. Update Mood\n";
    cout << "2. Show Motivational Quote\n";
    cout << "3. Get Mindful Activity Suggestion\n";
    cout << "4. Get Wellness Exercise Suggestion\n";
    cout << "5. View Mood History\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// ========== MAIN FUNCTION ==========
int main() {
    cout << "Welcome to the Mental Health Simulator\n";

    User user;
    user.inputUser();
    user.displayUser();

    MoodTracker tracker;
    QuoteManager quoteManager;
    Exercise exercise;
    DataLogger logger;
    ActivitySuggester activity;

    string mood;
    int choice;
    bool running = true;

    while (running) {
        displayMenu();

        // Input validation for choice
        while (!(cin >> choice)) {
            cout << "Invalid input! Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

        switch (choice) {
            case 1:
                cout << "Enter your mood (happy/sad/stressed/tired): ";
                getline(cin, mood);
                tracker.setMood(mood);
                tracker.displayMood();
                logger.saveMood(user.getName(), mood);
                cout << "Mood updated successfully!\n";
                break;
            case 2:
                quoteManager.showRandomQuote();
                break;
            case 3:
                activity.suggestActivity(tracker.getMood());
                break;
            case 4:
                exercise.suggestActivity(tracker.getMood());
                break;
            case 5:
                logger.showLogs();
                break;
            case 6:
                running = false;
                cout << "Thank you for using the Mental Health Simulator!\n";
                break;
            default:
                cout << "Invalid choice. Please try again!\n";
        }
    }

    return 0;
}
