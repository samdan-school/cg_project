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

vector<Vertex> red_vertices;
vector<Face> red_faces;
vector<string> red_colors;
vector<Color> red_colorInfo;
vector<int> red_num;

vector<Vertex> black_vertices;
vector<Face> black_faces;
vector<string> black_colors;
vector<Color> black_colorInfo;
vector<int> black_num;

vector<Vertex> water_vertices;
vector<Face> water_faces;
vector<string> water_colors;
vector<Color> water_colorInfo;
vector<int> water_num;

unsigned int texture_zam;
unsigned int texture_els;
unsigned int texture_us;
unsigned int texture_grass;
unsigned int texture_walker;

float t = 0.0;
bool t_inc = true;
#endif // CONSTANT_CPP