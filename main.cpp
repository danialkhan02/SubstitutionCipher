#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string user_message {};
    bool continue_program{true};

    //Ask user for desired message
    cout << "Please enter a message to encrypt:";
    getline(cin, user_message); //need to include all aspects of the sentence

    //encrypt the user input, using the C++ string object
    for(size_t index {0}; index < user_message.length(); index++){
        size_t position = alphabet.find(user_message.at(index));
        if(position != string::npos){
            user_message.at(index) = key.at(position);
        }
    }

    cout << "Congratulations, the following is your encrypted message:" << endl;
    cout << user_message << endl;


    bool incorrect_input{false};

    while(!incorrect_input){
        //Ask the user to enter y to decrypt, or to leave
        char user_decision;
        cout << "Would you like to decrypt your message? (Y/N):";
        cin >> user_decision;

        switch(user_decision){
            case 'Y':
            case 'y': {
                cout << "\nNice choice! Please wait a moment while we process your request" << endl;
                cout << "***************************************************************" << endl;
                for(size_t index {0}; index < user_message.length(); index++){
                    size_t position = key.find(user_message.at(index));
                    if(position != string::npos){
                        user_message.at(index) = alphabet.at(position);
                    }
                }

                cout << "Thanks for waiting!" << endl;
                cout << "We have processed your result, and conclude that the decrypted message is:" << endl;
                cout << user_message << endl;

                incorrect_input = true;
                break;
            }
            case 'N':
            case 'n':
                cout << "No problem! Make sure you take a note of your decrypted message before you exit!" << endl;
                continue_program = false;
                incorrect_input = true;
                break;
            default:
                cout << "Incorrect input, please try again..." << endl;
        }
    }

    return 0;
}
