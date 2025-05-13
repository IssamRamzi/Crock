// //
// // Created by issbe on 12/05/2025.
// //

// #include "iostream"
// #include "graphics/Window.hpp"


// int main() {
//     Window window("Crock Engine", 600, 600);
//     glClearColor(0.1, 0.1f, 0.3f, 1.0);

//     float data[9] = {
//         -0.5, -0.5, 0.0,
//         -0.5, 0.5, 0,
//         0.5, 0.5, 0
//     };
//     GLuint vbo;
//     glGenBuffers(1,&vbo);
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), data, GL_STATIC_DRAW);
//     glVertexAttribPointer(0, GL_FLOAT, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

//     while (!window.closed()) {

//         window.update();

//         glDrawArrays(GL_TRIANGLES, 0, 3);

//         window.clear();
//     }


//     return 0;
// }