#ifndef RENDERER_HEADER_H
#define RENDERER_HEADER_H

#include <glad/glad.h>

#define ASSERT(x) if(!(x) __debugbreak());
#define GLCall(x) GLClearError();\
    x;\
	ASSERT(GLLogCall(#x,__FILE,__LINE__))

void GL_Clear_Error();
bool GLLogCall(const char* function,const char* file,int line);
	
#endif