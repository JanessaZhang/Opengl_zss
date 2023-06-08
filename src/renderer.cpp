#include "renderer.h"
#include<iostream>

void GL_Clear_Error()
{
	while(glGetError()!=GL_NO_ERROR);
}

bool GLLogCall(const char* function,const char* file,int line){
	while(GLenum error = glGetError())
	{
		std::cout<<"[opengl error]  ( "<<error<<" )"<<function<<"  "<<file<<"  :"<<line<<std::endl;
		return false;
	}
	return true;
}