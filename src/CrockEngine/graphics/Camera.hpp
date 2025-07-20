#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

const float YAW             = -90.0f;
const float PITCH           =  0.0f;
const float SPEED           =  2.5f;
const float SENSITIVITY     =  0.1f;
const float ZOOM            =  45.0f;


class Camera
{
public:
    Camera();
    ~Camera();

    inline glm::vec3        GetPosition(){return m_position;}    
    inline glm::vec3        GetRight(){return m_right;}    
    inline glm::vec3        GetUp(){return m_up;}    
    inline glm::vec3        GetFront(){return m_front;}
    inline glm::mat4        GetViewMatrix(){return m_view;}
    inline glm::mat4        GetRotationMatrix(){return m_rotation;}

    void                    Move(glm::vec3 direction, float amount);
    void                    Move(glm::vec3 direction, float amount);
private:


private:

    glm::vec3               m_position;
    glm::vec3               m_right{1.0f, 0.0f, 0.0f};
    glm::vec3               m_up{0.0f, 1.0f, 0.0f};
    glm::vec3               m_front{0.0f, 0.0f, 1.0f};

    glm::mat4               m_view;
    glm::mat4               m_rotation;
};