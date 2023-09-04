#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const map<char, string> MORSE_DICT = {
    {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."},    {'F', "..-."}, {'G', "--."},  {'H', "...."},
    {'I', ".."},   {'J', ".---"}, {'K', "-.-"},  {'L', ".-.."},
    {'M', "--"},   {'N', "-."},   {'O', "---"},  {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"},
    {'2', "..---"},{'3', "...--"},{'4', "....-"},{'5', "....."},
    {'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."}
};

map<string, char> REVERSE_DICT;

void initializeReverseDict() {
    for (auto const &pair : MORSE_DICT) {
        REVERSE_DICT[pair.second] = pair.first;
    }
}

string toUpperCase(string message) {
    transform(message.begin(), message.end(), message.begin(), ::toupper);
    return message;
}

string encryptMessage(const string &message) {
    string encryptedMessage;
    for (char c : message) {
        if (c != ' ') {
            encryptedMessage += MORSE_DICT.at(c);
            encryptedMessage += " ";
        } else {
            encryptedMessage += ' ';
        }
    }
    return encryptedMessage;
}

vector<string> split(const string &str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

string decryptMessage(const string &message) {
    string decryptedMessage;
    vector<string> morseTokens = split(message, ' ');
    for (const string &token : morseTokens) {
        if (REVERSE_DICT.count(token)) {
            decryptedMessage += REVERSE_DICT[token];
        }
    }
    return decryptedMessage;
}

int main() {
    initializeReverseDict();

    int choice;
    cout << "1 - encrypt | 2 - decrypt : ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Write your message: ";
        string message;
        getline(cin, message);
        message = toUpperCase(message);
        cout << encryptMessage(message) << endl;
    } else if (choice == 2) {
        cout << "Write your morse code: ";
        string morseCode;
        getline(cin, morseCode);
        morseCode = toUpperCase(morseCode);
        cout << decryptMessage(morseCode) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
