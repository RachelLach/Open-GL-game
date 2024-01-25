
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace std;

void processInput(GLFWwindow*);

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void error_callback(int error, const char* msg) {
    cerr << " [" << error << "] " << msg << endl;
}

int main() {

   
    // Initialization ends here
    // ==================================================================
    // The Real Program starts here
    float red{};

    // ----- Create Vertex Array Object, which makes changing between VBOs easier -----
    unsigned int VAO1;
    glGenVertexArrays(1, &VAO1);
    glBindVertexArray(VAO1);

   
    // ----- Create Array Buffer on the GPU and copy our vertices to GPU -------
    float vertices[] {
       -0.75f, -0.75f, 0.0f,
        0.25f, -0.75f, 0.0f,
       -0.25f,  0.25f, 0.0f
    };

    unsigned int VBO1; // variable to store buffer id
    glGenBuffers(1, &VBO1); // ask open gl to create a buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO1); // tell gl to use this buffer
    glBufferData(GL_ARRAY_BUFFER, // copy our vertices to the buffer
        sizeof(vertices), vertices, GL_STATIC_DRAW);

    // ------ configure vertex attribute(s) (currently it's just one, the position) -----
    // so the vertex shader understands, where to find the input attributes, in this case position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    unsigned int VAO2;
    glGenVertexArrays(1, &VAO2);
    glBindVertexArray(VAO2);

    float vertices2[] {
        0.25f, -0.75f, 0.0f,
        0.75f, -0.75f, 0.0f,
        0.50f,  0.50f, 0.0f
    };

    unsigned int VBO2; // variable to store buffer id
    glGenBuffers(1, &VBO2); // ask open gl to create a buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO2); // tell gl to use this buffer
    glBufferData(GL_ARRAY_BUFFER, // copy our vertices to the buffer 
        sizeof(vertices2), vertices2, GL_STATIC_DRAW);

    // ------ configure vertex attribute(s) (currently it's just one, the position) -----
    // so the vertex shader understands, where to find the input attributes, in this case position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // ----- Compile the Vertex Shader on the GPU -------

    const char* vertexShaderSource{ "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0" };
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // ------ Compile the Fragment Shader on the GPU --------
    const char* orangefragmentShaderSource{ "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "} \0" };
    unsigned int orangefragmentShader;
    orangefragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(orangefragmentShader, 1, &orangefragmentShaderSource, NULL);
    glCompileShader(orangefragmentShader);

    // -------- Create Shader Program (Render Pipeline) ---------
    unsigned int orangeshaderProgram;
    orangeshaderProgram = glCreateProgram();
    glAttachShader(orangeshaderProgram, vertexShader);
    glAttachShader(orangeshaderProgram, orangefragmentShader);
    glLinkProgram(orangeshaderProgram);
    // clean up shaders after they've been linked into a program
    glDeleteShader(vertexShader);
    glDeleteShader(orangefragmentShader);

    //----------------new coloreeee
        
    const char* yellowfragmentShaderSource{ "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "} \0" };
    unsigned int yellowfragmentShader;
    yellowfragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(yellowfragmentShader, 1, &yellowfragmentShaderSource, NULL);
    glCompileShader(yellowfragmentShader);

    // -------- Create Shader Program (Render Pipeline) ---------
    unsigned int yellowshaderProgram;
    yellowshaderProgram = glCreateProgram();
    glAttachShader(yellowshaderProgram, vertexShader);
    glAttachShader(yellowshaderProgram, yellowfragmentShader);
    glLinkProgram(yellowshaderProgram);
    // clean up shaders after they've been linked into a program
    glDeleteShader(yellowfragmentShader);
    

    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!glfwWindowShouldClose(window))
    {
        // process input (e.g. close window on Esc)
        glfwPollEvents();
        processInput(window);
        red += 0.00001f;
        if (red > 1)
            red -= 1;

        // render (paint the current frame of the game)
        glClearColor(red, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(orangeshaderProgram);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(yellowshaderProgram);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        // present (send the current frame to the computer screen)
        glfwSwapBuffers(window); // ??
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
