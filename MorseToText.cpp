#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<unordered_map>
#include<cctype>

std::unordered_map<char, std::string> textToMorseMap = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},
    {'D', "-.."},   {'E', "."},     {'F', "..-."},
    {'G', "--."},   {'H', "...."},  {'I', ".."},
    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},    {'N', "-."},    {'O', "---"},
    {'P', ".--."},  {'Q', "--.-"},  {'R', ".-."},
    {'S', "..."},   {'T', "-"},     {'U', "..-"},
    {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},  {'Z', "--.."},

    {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}
};
std::unordered_map<std::string, char> MorseToTextMap;
std::vector<std::string> history;

void buildReverseMorse(){
    for (auto pair : textToMorseMap)
    {
    MorseToTextMap[pair.second] = pair.first;
    }
}

void loadHistory(){
    std::ifstream file("history.txy");

    if(!file.is_open()){
        return;
    }

    std::string line;

    while(getline(file, line)){
        history.push_back(line);
    }

    file.close();

}
void saveHistory(){
    std::ofstream file("history.txt");
    for(auto item :history){
        file << item << std::endl;
    }
    file.close();

    std::cout<<"\n History saved successfully\n";
}

void convertTextToMorse(){
    std::string text;

    std::cout<< "\n Enter Text";

    getline(std::cin, text);
    std::string result = "";
    for(char c : text){
        c = toupper(c);

        if(c == ' '){
            result += "/ ";
        }
        else if(textToMorseMap.count(c)){
            result += textToMorseMap[c] + " ";
        }
    }
    std::cout<<"\n Morse Code: \n";
    std::cout<< result <<std::endl;

    history.push_back("TEXT->MORSE : " + text + " => " + result);
}
void convertMorseToText(){
    std:: string code;

    std::cout<<"\n Enter MorseCode";
    getline(std::cin, code);

    std::stringstream ss(code);
    std::string symbol;
    std::string result = "";

    while(ss >> symbol){
        if(symbol == "/"){
            result += " ";
        }
        else if( MorseToTextMap.count(symbol)){
            result+=  MorseToTextMap[symbol];
        }
    }
    std::cout<<"\n Decode Morse Code";
    std::cout<< result <<std::endl;

    history.push_back("MORSE-> TEXT: " + code + "=>"+result);
}

void showHistory(){
    if(history.empty()){
        std::cout<<"\n Translations Found.\n";
        return;
    }
    for(int i = 0; i<history.size();i++){
        std::cout<< i + 1<<". "<<history[i]<<std::endl;
    }
}

void displayMenu() {

    std::cout << "\n MORSE CODE TRANSLATOR";
    std::cout << "\n1. Text to Morse";
    std::cout << "\n2. Morse to Text";
    std::cout << "\n3. View History";
    std::cout << "\n4. Save History";
    std::cout << "\n5. Exit";
    std::cout << "\nEnter your choice: ";
}

int main(){
    buildReverseMorse();
    loadHistory;
    int choice;

    do{
        displayMenu();
        std::cin>>choice;
        std::cin.ignore();

        switch(choice){
            case 1:
                convertTextToMorse();
                break;
            case 2:
                convertMorseToText();
                break;
            case 3:
                showHistory();
                break;
            case 4:
                saveHistory();
                break;
            case 5:
                saveHistory();
                std::cout<<"\nThank u for using Morse Code Translator\n";
                break;
            default:
                std::cout<<"\nInvalid Choice.Try again\n";
        }
    }while(choice != 5);

    return 0;
}




