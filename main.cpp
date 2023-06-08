#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "src/indexbuffer.h"
#include "src/renderer.h"
#include "src/shader.h"
#include "src/texture.h"
#include "src/vertexarray.h"
#include "src/vertexbuffer.h"
#include "src/vertexbufferlayout.h"
int main() {
    // glfw init
    if (!glfwInit()) {
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //创建window
    GLFWwindow* window =
        glfwCreateWindow(1000, 1000, "first window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    //指定上下文
    glfwMakeContextCurrent(window);
    //设置频率
    glfwSwapInterval(1);

    // glad init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    {
        // 数据 索引
        float positions[] = {-0.5f,
                             -0.5f,
                             0.0,
                             0.0,
                             0.5f,
                             -0.5f,
                             1.0,
                             0.0,
                             0.5f,
                             0.5f,
                             1.0,
                             1.0,
                             -0.5f,
                             0.5f,
                             0.0,
                             1.0};
		// float positions[] = {-0.5f,
        //                      -0.5f,
        //                      0.5f,
        //                      -0.5f,
        //                      0.5f,
        //                      0.5f,
        //                      -0.5f,
        //                      0.5f};
        unsigned int indices[] = {0, 1, 2, 2, 3, 0};

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

        vertexarray va;
        vertexbuffer vb(positions, sizeof(float) * 4 * 4);
        vertexbufferlayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
	    
        va.AddBuffer(vb, layout);
        indexbuffer ib(indices, 6);

        shader mshader("res/shader/basic.shader");
        mshader.Bind();
        mshader.SetUniform4f("u_color", 0.2, 0.3, 0.5, 1.0);

        texture mtexture("res/shader/1.png");
        mtexture.Bind();
        mshader.SetUniform1i("u_Texture", 0);

        va.Unbind();
        mshader.Unbind();
        vb.unbind();
        ib.unbind();

        renderer mrenderer;

        //动态颜色
        float r = 0.1, increment = 0.05;

        // loop
        while (!glfwWindowShouldClose(window)) {
            // 清除buffer 并设置背景颜色
            mrenderer.Clear();

            // 进行绘制
            mshader.Bind();
            mshader.SetUniform4f("u_color", r, 0.3, 0.5, 1.0);
            if (r < 0.0)
                increment = 0.05;
            if (r > 1.0)
                increment = -0.05;
            r += increment;

            //有索引缓冲区
            mrenderer.Draw(va, ib, mshader);

            // 交换buffer，进行显示
            glfwSwapBuffers(window);
            // 分发事件
            glfwPollEvents();
        }
    }
    //终止窗口
    glfwTerminate();
    return 0;
}