#include <iostream>
#include <fstream>

using namespace std;

string minify(string text){
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ' || text[i] == '\t' || (text[i] == '\n'))
        {
            text[i] = '\b';
        }   
    }
    return text;
}

int main(){
    string line;
    ifstream myfile;
    myfile.open("t.rtf");

    if(!myfile.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }
    
    while(getline(myfile, line)) {
        line = space2underscore(line);
        std::cout << line << std::endl;
    }

    return 0;
}

