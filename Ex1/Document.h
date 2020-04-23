#include <iostream>
#include<vector>
#pragma once

class Document {

    std::vector<std::string> vec; 
    int index;

public:
    Document();
    void line_n(int lineNumber);
    void precent_p();
    void a();
    void i();
    void c();
    void line_d(int lineNumber);
    void search_text_forward(std::string text);
    void search_text_backward(std::string text);
    void s_old_to_new(std::string text);
    void append_lines_j(std::string text);
    
};
