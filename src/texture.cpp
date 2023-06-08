#include "texture.h"

#include "vendor/stb_image/stb_image.h"

texture::texture(const std::string& path) :
    m_FilePath(path), m_LocalBuffer(nullptr), m_width(0), m_height(0),
    m_BPP(0) {
    //加载图像
    stbi_set_flip_vertically_on_load(1);  //上下翻转图片
    m_LocalBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);

    glGenTextures(1, &m_RendererID);  //创建纹理buffer
    glBindTexture(GL_TEXTURE_2D,
                  m_RendererID);  //绑定buffer m_RendererID就是绑定的纹理
    //设置纹理参数 (必须)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // 传送数据给opengl
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA8,
                 m_width,
                 m_height,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 m_LocalBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (m_LocalBuffer)
        stbi_image_free(m_LocalBuffer);
}

texture::~texture() {
    glDeleteTextures(1, &m_RendererID);
}

void texture::Bind(unsigned int slot )const  //默认绑定到纹理卡槽0
{
    //指定纹理卡槽
	glActiveTexture(GL_TEXTURE0+slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

}
void texture::Unbind()const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
