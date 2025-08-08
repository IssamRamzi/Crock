#include "Camera.hpp"
#include <iostream>

Camera::Camera(Window* window, vec3 position){
    m_position = position;
    m_window = window;
}

Camera::~Camera(){

}

mat4 Camera::CalculateMatrix(float nearPlane, float farPlane){
    mat4 view(1.0f);
    mat4 projection(1.0f);

    view = lookAt(m_position, m_position + m_orientation, m_up);
    projection = glm::perspective(m_fov, (float)m_window->GetWindowWidth() / (float)m_window->GetWindowHeight(), nearPlane, farPlane);

    return projection * view; // TOUJOURS PROJ * VIEW (3h de perdu a cause de ca)
}

void Camera::ProcessKeyboardInputs(){
    if(m_window->IsKeyPressed(GLFW_KEY_UP) || m_window->IsKeyPressed(GLFW_KEY_W)){
        m_position += m_speed * m_orientation;
    }
    if(m_window->IsKeyPressed(GLFW_KEY_DOWN) || m_window->IsKeyPressed(GLFW_KEY_S)){
        m_position += m_speed * -m_orientation;
    }
    if(m_window->IsKeyPressed(GLFW_KEY_D) || m_window->IsKeyPressed(GLFW_KEY_RIGHT)){
        m_position += m_speed * glm::vec3(1.0f, 0.0f, 0.0f);
    }
    if(m_window->IsKeyPressed(GLFW_KEY_A) || m_window->IsKeyPressed(GLFW_KEY_LEFT)){
        m_position += m_speed * -glm::vec3(1.0f, 0.0f, 0.0f);
    }
}

void Camera::ProcessMouseInputs(){

}   

void Camera::ProcessMouseScroll(){
}   


