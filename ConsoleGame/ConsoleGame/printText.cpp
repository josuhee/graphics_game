#include "game.h"

GLuint base;
HDC hDC;

//해당 폰트의 리스트 만들기
GLvoid BuildFont(GLvoid)
{
    HFONT font; // <1>
    LPCWSTR fontName = L"Arial\0";
    base = glGenLists(96); // <2>
    font = CreateFont(-24, // <3-1>
        0,
        0,
        0,
        FW_BOLD, // <3-2>
        FALSE, // <3-3>
        FALSE, // <3-4>
        FALSE, // <3-5>
        ANSI_CHARSET, // <3-6>
        OUT_TT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY,
        FF_DONTCARE | DEFAULT_PITCH,
        fontName); // <3-6>

    SelectObject(hDC, font); // <4>
    wglUseFontBitmaps(hDC, 32, 96, base); // <5>
}

//생성된 리스트를 반환하는 함수
GLvoid KillFont(GLvoid)
{
    glDeleteLists(base, 96);
}

int InitFont(GLvoid)                      // All Setup For OpenGL Goes Here
{
    glShadeModel(GL_SMOOTH);                // Enable Smooth Shading
    // glClearColor(0.0f, 0.0f, 0.0f, 0.5f);           // Black Background
    // glClearDepth(1.0f);                 // Depth Buffer Setup
    // glEnable(GL_DEPTH_TEST);                // Enables Depth Testing
    // glDepthFunc(GL_LEQUAL);                 // The Type Of Depth Testing To Do
    // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations

    hDC = wglGetCurrentDC();            // 현재 openGL 윈도우의 hDC를 가져온다.

    BuildFont();       // Build The Font

    return TRUE;                        // Initialization Went OK
}


GLvoid glPrint(const char* text)
{
    glPushAttrib(GL_LIST_BIT);
    glListBase(base - 32);
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
    glPopAttrib();
}