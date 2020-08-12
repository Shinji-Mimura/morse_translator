#include<map>
#include<string>
#include<string.h> 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

        map<char,string> MS_DICT = {
        {'A',".-"}, {'B',"-..."},
        {'C',"-.-."}, {'D',"-.."},
        {'E',"."}, {'F',"..-."},
        {'G',"--."}, {'H',"...."},
        {'I',".."}, {'J',".---"},
        {'K',"-.-"}, {'L',".-.."},
        {'M',"--"}, {'N',"-."},
        {'O',"---"}, {'P',".--."},
        {'Q',"--."}, {'R',".-."},
        {'S',"..."}, {'T',"-"},
        {'U',"..-"}, {'V',"...-"},
        {'W',".--"}, {'X',"-..-"},
        {'Y',"-.--"}, {'Z',"--.."},
        {'0',"-----"}, {'1',".----"},
        {'2',"..---"}, {'3',"...--"},
        {'4',"....-"}, {'5',"....."},
        {'6',"-...."}, {'7',"--..."},
        {'8',"---.."}, {'9',"----."}
    };

string up(string message){

    for_each(message.begin(), message.end(), [](char & c){
        c = toupper(c);
    });

    return message;
    
}

string encrypta(string message){
    message = up(message);
    string cypher = "";
    int tam = message.length();
    for (int i = 0; i <= tam; i++)
    {   
        char aux = message[i];
        if (aux != ' ')
        {
            cypher += MS_DICT[aux];
            cypher += " ";
        }
        else {
            cypher += ' ';
        }
        
    }

    return cypher;
}

vector<string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

string decrypta(string message){
    message = up(message);
    string decrypt_message = "";
    vector<string> arr_message = split(message, " ");
    int tam = arr_message.size();
    
    for (int i = 0; i <= tam; i++)
    {
        for (map<char,string>::iterator it=MS_DICT.begin(); it!=MS_DICT.end(); it++) 
        {
            if (arr_message[i] == it->second)
            {
                decrypt_message += it->first;
                
            }
            

        }
    }
    
    return decrypt_message;

   
    
}

int main(int argc, char const *argv[])
{
    int op;
    cout << "1 - encrypt | 2 - decrypt : ";
    cin >> op;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 

    if (op == 1)
    {
        cout << "Write your message: ";
        char your_message[100]={0};
        cin.getline(your_message,100);
        cout << encrypta(your_message) << endl;
    }
    
    else if (op == 2){
        cout << "Write your morse code: ";
        char your_message[100]={0};
        cin.getline(your_message,100);
        cout << decrypta(your_message) << endl;
    }

    else
    {
        cout << "Invalid!" << endl;
    }
    


    return 0;
}


