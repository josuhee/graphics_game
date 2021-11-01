#include "game.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

GLuint  texID[5];
int width, height;

static unsigned char* LoadMeshFromFile(const char* texFile)
{
    GLuint texture;
    glGenTextures(1, &texture);
    FILE* fp = NULL;
    if (fopen_s(&fp, texFile, "rb")) {
        printf("ERROR : No %s. \n fail to bind %d\n", texFile, texture);
        exit(1);
        //return (unsigned char*)false;
    }
    int channel;
    unsigned char* image = stbi_load_from_file(fp, &width, &height, &channel, 4);
    fclose(fp);
    return image;
}

static void init_image_util(char* filename, int n)
{
    unsigned char* bitmap;
    bitmap = LoadMeshFromFile(filename);
    glBindTexture(GL_TEXTURE_2D, texID[n]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
    glBindTexture(GL_TEXTURE_2D, 0);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    free(bitmap);
}

void init_image(void)
{
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texID[0]);
    init_image_util((char*)"image/block.png", 0);
    
}

void draw_img(int n, t_point_f p1, t_point_f p2)
{
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texID[n]);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);      glVertex2f(p1.x, p1.y);
    glTexCoord2d(0.0, 1.0);      glVertex2f(p1.x, p2.y);
    glTexCoord2d(1.0, 1.0);      glVertex2f(p2.x, p2.y);
    glTexCoord2d(1.0, 0.0);      glVertex2f(p2.x, p1.y);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}