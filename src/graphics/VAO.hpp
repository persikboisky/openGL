#ifndef GRAPHICS_VAO_HPP_
#define GRAPHICS_VAO_HPP_

#include <vector>

struct vao
{
    static int nVertex;
    static unsigned int create(const std::vector<float>& data);
    //static unsigned int create(float data[]);
    static void bind(unsigned int  id);
    static void DrawArrays(unsigned int mode, int first, unsigned int count);
    static void deBind();
    static void Delete(unsigned int id);
};

#endif // GRAPHICS_VAO_HPP_