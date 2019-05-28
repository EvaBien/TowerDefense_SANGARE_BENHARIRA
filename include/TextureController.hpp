#ifndef DEF_TEXTURECONTROLLER
#define DEF_TEXTURECONTROLLER

using namespace std;

bool isLoaded (SDL_Surface* image);

GLuint loadTexture(const char* filename);

void drawPicture(GLuint textureId, float x, float y); // AL

// void free_image(GLuint textureId, SDL_Surface* img); //CL
#endif
