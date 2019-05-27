#ifndef DEF_TEXTURECONTROLLER
#define DEF_TEXTURECONTROLLER

using namespace std;

bool isLoaded (SDL_Surface* image);

void loadTexture(const char* filename);

void drawTexture(GLuint textureId, float x, float y); // AL

void free_image(GLuint textureId, SDL_Surface* img); //CL
#endif


//LoadTexture // DrawPicture
