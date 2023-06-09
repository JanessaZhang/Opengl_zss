#include "shader.h"

#include <glad/glad.h>

shader::shader(const std::string& filepath) :
    m_filepath(filepath), m_RendererID(0) {
    shader_program_source source = parse_shader(filepath);
    m_RendererID = create_shader(source.vertex_source, source.fragment_source);
    std::cout << "init" << std::endl;
}

shader::~shader() {
    glDeleteProgram(m_RendererID);
}

void shader::Bind() {
    glUseProgram(m_RendererID);
}

void shader::Unbind() {
    glUseProgram(0);
}

int shader::GetUniformsLocation(const std::string& name) {
    if (m_uniform_color_location_cache.find(name) !=
        m_uniform_color_location_cache.end())
        return m_uniform_color_location_cache[name];
    int color_location = glGetUniformLocation(m_RendererID, name.c_str());
    if (color_location == -1)
        std::cout << "warning: uniform '" << name << "' doesn't exist!"
                  << std::endl;
    m_uniform_color_location_cache[name] = color_location;
    return color_location;
}

void shader::SetUniform1i(const std::string& name, int value) {
    glUniform1i(GetUniformsLocation(name), value);
}

void shader::SetUniform4f(const std::string& name, float v0, float v1, float v2,
                          float v3) {
    glUniform4f(GetUniformsLocation(name), v0, v1, v2, v3);
}

void shader::SetUniformMat4f(const std::string& name, const glm::mat4& mat4f) {
    glUniformMatrix4fv(GetUniformsLocation(name), 1,GL_FALSE,&mat4f[0][0]);
}

shader_program_source shader::parse_shader(const std::string& file_path) {
    enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

    std::ifstream stream(file_path);
    std::string line;
    std::stringstream ss[2];
    ShaderType shader_type = ShaderType::NONE;

    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                // set vertex mode
                shader_type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                // set fragment mode
                shader_type = ShaderType::FRAGMENT;

        } else {
            ss[(int)shader_type] << line << "\n";
        }
    }

    return {ss[0].str(), ss[1].str()};
}

// ����shader
unsigned int shader::compile_shader(unsigned int type,
                                    const std::string& source) {
    // �������ʹ���shader
    unsigned int id = glCreateShader(type);
    // ���shaderԴ��
    const char* src = source.c_str();
    // ��Դ�뵽shader��
    glShaderSource(id, 1, &src, nullptr);
    // ����shader
    glCompileShader(id);

    // TODO��error handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile "
                  << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "!"
                  << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

// ����shader
// shader��Դ�봫��ȥ��OPenGl����Դ�룬Ȼ������
unsigned int shader::create_shader(const std::string& vertex_shader,
                                   const std::string& fragment_shader) {
    // ����������program
    unsigned int program = glCreateProgram();
    // ���� �����������õ�shader
    unsigned int vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    unsigned int fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);
    // ���� ��shader �󶨵�������program  Ȼ������program
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}