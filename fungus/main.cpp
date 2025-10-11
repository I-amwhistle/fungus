#include <iostream>
#include <fstream>
#include <pugixml.hpp>
#include <raylib.h>

#include "scene.h"

std::string getFileContent(std::string path) {

    std::fstream file(path);
    std::string currentString;
    std::string content;

    while (std::getline(file, currentString)) {
        content += currentString;
        content.push_back('\n');
    }

    return content;
}

int main()
{

    std::cout << "Hello Wold" << std::endl;

    Scene scene = Scene("../file");

    scene.Render();

    return 0;
}