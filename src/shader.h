#ifndef SHADER_HEADER_H
#define SHADER_HEADER_H


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

struct shader_program_source {
  std::string vertex_source;
  std::string fragment_source;
};

class shader {
 private:
  unsigned int m_RendererID;
  std::string m_filepath;
  std::unordered_map<std::string,int> m_uniform_color_location_cache;

  unsigned int GetUniformsLocation(const std::string& name);
  shader_program_source parse_shader(const std::string& file_path);
  unsigned int compile_shader(unsigned int type, const std::string& source);
  unsigned int create_shader(const std::string& vertex_shader,
                             const std::string& fragment_shader);

 public:
  shader(const std::string& filepath);
  ~shader();

  void Bind();
  void Unbind();
  // set uniforms
  void SetUniform4f(const std::string& name, float v0, float v1, float v2,
                   float v3);
};

#endif