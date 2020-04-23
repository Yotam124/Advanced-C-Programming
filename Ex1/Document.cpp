#include <iostream>
#include <vector>
#include "Document.h"

using namespace std;

Document::Document() {
    vec.push_back("");
    index = 0;
}

void Document::line_n(int lineNumber) {
    string newStr = to_string(lineNumber) + "\t" + vec[lineNumber];
    cout << newStr << endl;
    index = lineNumber;
}

void Document::precent_p() {
    for (int i=1 ; i<vec.size() ; i++){
        cout << vec[i] << endl;
    }
}

void Document::a() {
    string line;
    while (getline(cin,line)) {
        index++;
        if (line == (".")){
            break;
        }
        vec.insert(begin(vec)+index,line);
    }
    
}

void Document::i() {
    index--;
    a();
    index++;
    
}

void Document::c() {
    string line;
    vec.erase(begin(vec)+index);
    while (getline(cin,line)) {
        index++;
        if (line == (".")){
            break;
        }
        vec.insert(begin(vec)+index-1,line);
    }
}

void Document::line_d(int lineNumber) {
    vec.erase(begin(vec)+lineNumber);
}

void Document::search_text_forward(string txt) {
    for (int i=index ; i<vec.size() ; i++){
        size_t pos = vec[i].find(txt);
        if (pos != string::npos){
            cout << vec[i] << endl;
            index = i;
            return;
        }
    }
}

void Document::search_text_backward(string txt) {
    for (int i=0 ; i<index ; i++){
        size_t pos = vec[i].find(txt);
        if (pos != string::npos){
            cout << vec[i] << endl;
            index = i;
            return;
        }
    }
}

void Document::s_old_to_new(string txt) {
    vector<string> words;
    for (int i=2, k=2 ; i<txt.length() ; i++) {
        if (txt[i] == '/') {
            string temp = txt.substr(k,i-k);
            k = i+1;
            words.push_back(temp);
        }
    }
    
    string oldWord = words[0];
    string newWord = words[1];

    vec[index].replace(vec[index].find(oldWord), oldWord.size(), newWord);
}

void Document::append_lines_j(string txt) {

    vector<string> rows;
    for (int i=0, k=0 ; i<txt.length() ; i++) {
        if (txt[i] == ',' || txt[i] == 'j') {
            string temp = txt.substr(k,i-k);
            k = i+1;
            rows.push_back(temp);
        }
    }
    int firstRow = stoi(rows[0]);
    int secondRow = stoi(rows[1]);

    vec[firstRow] += vec[secondRow];
    vec.erase(begin(vec)+secondRow);
    index = firstRow;
}

