#include <iostream>
#include "Document.h"
#pragma once

class Editor {
    Document doc;
public:
    Editor();
    void loop();
    bool flag;
    int index; //current line index
};