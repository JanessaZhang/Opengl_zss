#ifndef TEXTUIRE_HEADER_H
#define TEXTUIRE_HEADER_H

#include "renderer.h"

class texture {
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char* m_LocalBuffer;  //纹理的本地存储
    int m_width, m_height, m_BPP;

public:
    texture(const std::string& path);
    ~texture();

    void Bind(unsigned int slot = 0)const ; //默认绑定到纹理卡槽0
    void Unbind()const ;

    inline int getwidth() const { return m_width; }
    inline int getheight() const { return m_height; }
    inline int getBPP() const { return m_BPP; }
};

#endif