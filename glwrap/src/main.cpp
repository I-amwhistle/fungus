#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>



namespace buffer {
    float vertexArr;
    float vertexObj;
    float elementObj;
}

namespace gl { // Capitalize function if it will get called externally

    GLFWwindow *window;

    namespace BufferType {
        const unsigned int VBO = GL_ARRAY_BUFFER;
        const unsigned int EBO = GL_ELEMENT_ARRAY_BUFFER;
    }

    void bufferCreate(unsigned int &object, unsigned int type) {glCreateBuffers(1, object);}
    void bufferBind(unsigned int target, unsigned int object) {glBindBuffer(target, object);}
    template<typename T>
    void bufferDataAssign(unsigned int target, T data) {glBufferData(target, sizeof(data), &data, GL_STATIC_DRAW);}

    void createVAO(unsigned int object) {glCreateVertexArrays(1, &object);}
    void bindVAO(unsigned int VAO) {glBindVertexArray(VAO);}

    void initGLFW() {
        std::cout << "Initializing GLFW ..." << std::endl; 
        if (!glfwInit()) {
            std::cerr << "Failed init GLFW" << std::endl;
            exit(0);
        }
        std::cout << "DONE" << std::endl;
    }

    void initGLEW() {
        std::cout << "Initializing GLEW ..." << std::endl; 
        if (!glewInit()) {
            std::cerr << "Failed init GLEW" << std::endl;
            exit(0);
        }
        std::cout << "DONE" << std::endl;
    }

    void initWindow(GLFWwindow *&win, unsigned int width, unsigned int height, const char* title) {
        std::cout << "Initializing GLFWwindow ..." << std::endl; 
        win = glfwCreateWindow(width, height, title, nullptr, nullptr);
        
        if (!win) {
            std::cerr << "Failed init Window" << std::endl;
            glfwTerminate();
            exit(0);
        }

        std::cout << "DONE" << std::endl;
    }

    void initContext(unsigned int versionMajor, unsigned int versionMinor) {

        initGLFW();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);

        initWindow(window, 800, 600, "Window");
        initGLEW();
        glfwMakeContextCurrent(window);

        std::cout << "Finished initializing context." << std::endl;

    }

    void recognizePlatform() {

        #ifdef __APPLE__
            std::cout << "i hate apple" << std::endl;
        #elif define(UNIX)
            std::cout << "linux or whatever unix is very good" << std::endl;
        #endif
        #ifdef WIN32
            std::cout << "i hate windows" << endl;
        #endif

    }

    void Init() {

        initContext(3, 3);

        unsigned int VBO;
        bufferCreate(VBO, BufferType::VBO);
        bufferBind(GL_ARRAY_BUFFER, VBO);
        bufferDataAssign(GL_ARRAY_BUFFER, )

        std::cout << "Finished Initialization." << std::endl;

    }


    void loop() {

        glfwPollEvents();
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);

    }

    void StartLoop() {

        std::cout << "Starting Loop." << std::endl; 
        std::cout << glfwWindowShouldClose(window) << std::endl;
        int frameCount = 0;
        while(!glfwWindowShouldClose(window)) {
            frameCount += 1;
            std::cout << "Running Loop: " << frameCount << "Frame" << std::endl;
            loop();
        }
    }


}

int main() {
    gl::Init();
    gl::StartLoop();
    return 0;
}