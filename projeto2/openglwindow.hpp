#ifndef OPENGLWINDOW_HPP_
#define OPENGLWINDOW_HPP_

#include <vector>

#include "abcg.hpp"
#include "camera.hpp"
#include "model.hpp"


class OpenGLWindow : public abcg::OpenGLWindow {
 protected:
  void handleEvent(SDL_Event& ev) override;
  void initializeGL() override;
  void paintGL() override;
  void paintUI() override;
  void resizeGL(int width, int height) override;
  void terminateGL() override;

 private:  
  GLuint m_program{};

  int m_viewportWidth{};
  int m_viewportHeight{};

  Model m_bigHand;
  Model m_caveira;

  int m_trianglesToDraw{};

  Camera m_camera;
  float m_dollySpeed{0.0f};
  float m_truckSpeed{0.0f};
  float m_panSpeed{0.0f};

  std::vector<Vertex> m_vertices;
  std::vector<GLuint> m_indices;   

  void loadModelFromFile(std::string_view path);  
  void update();
};

#endif