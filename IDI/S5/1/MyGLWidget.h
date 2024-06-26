// MyGLWidget.h
#include "BL2GLWidget.h"

#include "model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();


  protected:

    virtual void initializeGL();

    virtual void ini_escena();

    virtual void ini_camera();

    virtual void paintGL();

    virtual void modelTransformHomer();

    virtual void modelTransformTerra();

    virtual void projectTransform();

    virtual void viewTransform();

    virtual void keyPressEvent (QKeyEvent *event);

    virtual void creaBuffers();

    virtual void calcularCapsa_Homer();

    virtual void carregaShaders();

    GLuint projLoc;
    GLuint viewLoc;

    struct Figura {
      Model model;
      glm::vec3 minim;
      glm::vec3 maxim;
      glm::vec3 centre;
      glm::vec3 centreBase;
      float amplada;
      float profundidad;
      float altura;
      float escala;
      float angle; 
    };

    Figura homer;

    struct Escena {
      glm::vec3 centro;
      glm::vec3 maxim;
      glm::vec3 minim;
      float radio;
    };

    Escena escena;

    struct Camera {
      float FOV;
      float FOVInicial;
      float raw;
      float zNear;
      float zFar;
      glm::vec3 OBS;
      glm::vec3 VRP;
      glm::vec3 UP;
    };

    Camera cam3persona;


    GLuint VAO_Homer;
    GLuint VAO_Terra;

  private:
    int printOglError(const char file[], int line, const char func[]);

};
