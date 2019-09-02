#include <iostream>
#include <fstream>

using namespace std;

string minify(string text){
    for (int i = 0; i < text.length(); i++)
    {
        /*if (text[i] == '\t' && text[i+1] == '\t'|| text[i] == '\n')
        {
            text[i] = '\b';
        }   

        else if(text[i+1])*/

        // check it it's tab and if it's not the file's end mark, then backspace and add a space

        if (text[i] == '\t' && text[i+1] != '\0')
        {
            text[i] = '\b';
            text[i] = ' ';  
        } 

        /*else if (text[i] == '\t' && text[i+1] == '\0')
        {
            text[i] = '\b';
        } */

        // needs to check the case: if it's tab + space?
        else if ((text[i] == '\t' && text[i+1] == '\0'))
        {
            text[i] = ' ';
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
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line = minify(line);
        cout << line;
    }

    return 0;
}

