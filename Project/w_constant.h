#if !defined(CONSTANT_CPP)
#define CONSTANT_CPP

#include <vector>
using namespace std;

#include "ReadFile.h"

vector<Vertex> residence_vertices;
vector<Face> residence_faces;
vector<string> residence_colors;
vector<Color> residence_colorInfo;
vector<int> residence_num;

vector<Vertex> home_vertices;
vector<Face> home_faces;
vector<string> home_colors;
vector<Color> home_colorInfo;
vector<int> home_num;

unsigned int texture_zam;
unsigned int texture_els;
unsigned int texture_us;
unsigned int texture_grass;
unsigned int texture_walker;
#endif // CONSTANT_CPP