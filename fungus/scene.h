#include <cstring>
#include <raylib.h>
#include <iostream>
#include <pugixml.hpp>
#include <vector>

#ifndef SCENE

namespace fg {
    class Sprite {
        public:
            int x;
            int y;
            Texture texture;
    };
}

class Scene {


    pugi::xml_document doc;
    std::string spriteString = "sprite";
    pugi::xml_node sceneRoot;

    Texture texturesRegistery[1000];
    std::vector<fg::Sprite> spritesLoaded;   
    public:
        Scene(std::string scenePath) {
            
            pugi::xml_parse_result result = doc.load_file(scenePath.c_str());
            sceneRoot = doc.first_child();

            InitWindow(800, 600, "fungus example");
            SetTraceLogLevel(0);

            int i = 0;

            for (pugi::xml_node node = sceneRoot.first_child(); node; node = node.next_sibling()) {
                if (strcmp(node.name(), "sprite ")) {
                    Texture newTexture = LoadTexture(node.attribute("src").as_string());
                    i += 1;
                }
               std::cout << "asdfasdfasdf" << std::endl; 
            }

        }
        void Render() {

            while (!WindowShouldClose())
            {
                BeginDrawing();

                for (pugi::xml_node node = sceneRoot.first_child(); node; node = node.next_sibling()) {
                    int i = 0;
                    //std::cout << i << std::endl;
                    if (strcmp(node.name(), "sprite ")) {
                        DrawTexture(texturesRegistery[i], 100, 100, RAYWHITE);
                        i += 1;
                    }
                    //std::cout << "render running properly" << std::endl;
                } 
                

                EndDrawing();
            }



            Texture texturesRegistery;

        }

};

#endif