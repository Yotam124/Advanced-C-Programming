#include <iostream>
#include "Editor.h"

using namespace std;

Editor::Editor() {
    Document();
    flag = true;
}

void Editor::loop() {
    string line;

    while (getline(cin, line) && flag == true) {
        // type of command -> go to line n and print: line number + tab + text.
        // function -> doc.line_n
        if (line[line.length()-1] == 'n'){
            for (int i=0 ; i<line.length()-1 ; i++){
                if (!(isdigit(line[i]))){
                    break;
                }
            }
            int lineNumber = stoi(line.substr(0,line.length()-1));
            doc.line_n(lineNumber);
        }
        // type of command -> print the document.
        // function -> doc.precent_p
        else if (line == "%p") {
            doc.precent_p();
        }
        // type of command -> add lines after the current line (index) untill '.'.
        // function -> doc.a
        else if (line == "a") {
            doc.a();
        }
        // type of command -> add lines before the current line (index) untill '.'.
        // function -> doc.i
        else if (line == "i") {
            doc.i();
        }
        // type of command -> replace the current line with one or more lines untill '.'.
        // function -> doc.c
        else if (line == "c") {
            doc.c();
        }
        // type of command -> erase line number n.
        // function -> doc.line_d
        else if (line[line.length()-1] == 'd') {
            for (int i=0 ; i<line.length()-1 ; i++){
                if (!(isdigit(line[i]))){
                    break;
                }
            }
            int lineNumber = stoi(line.substr(0,line.length()-1));
            doc.line_d(lineNumber);
        }
        // type of command -> search the word in the text after the current line.
        // function -> doc.search_text_fortward
        else if (line[0] == '/') {
            doc.search_text_forward(line.substr(1));
        }
        // type of command -> search the word in the text before the current line.
        // function -> doc.search_text_backward
        else if (line[0] == '?') {
            doc.search_text_backward(line.substr(1));
        }
        // type of command -> swap old word with new word in the current line.
        // function -> doc.s_old_to_new.
        else if (line[0] == 's' && line[1] == '/') {
            doc.s_old_to_new(line);
        }
        // type of command -> connect two line into one.
        // function -> doc.append_lines_j
        else if (line[line.length()-1] == 'j') {
            for (int i=0 ; i<line.length()-1 ; i++){
                if (line[i] != ',') {
                    if (!(isdigit(line[i]))){
                        break;
                    }
                }
            }
            doc.append_lines_j(line);
        }
        // type of command -> quit editor
        // function -> none
        else if (line == "Q"){
            flag = false;
        }
        else {
            cout << "invalid input" << endl;
        }
    }
}
