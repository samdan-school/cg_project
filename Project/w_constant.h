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

vector<Vertex> tree1_vertices;
vector<Face> tree1_faces;
vector<string> tree1_colors;
vector<Color> tree1_colorInfo;
vector<int> tree1_num;

vector<Vertex> shark_vertices;
vector<Face> shark_faces;
vector<string> shark_colors;
vector<Color> shark_colorInfo;
vector<int> shark_num;

vector<Vertex> boat_vertices;
vector<Face> boat_faces;
vector<string> boat_colors;
vector<Color> boat_colorInfo;
vector<int> boat_num;

unsigned int texture_zam;
unsigned int texture_els;
unsigned int texture_us;
unsigned int texture_grass;
unsigned int texture_walker;
unsigned int texture_black;

float t = 0.0;
bool t_inc = true;

float scale_factor = float(1.0 / 5);
const float red_car_init_position = -300;
float red_car_position = red_car_init_position;
float red_car_speed = 13;

const float black_car_init_position = -30;
float black_car_position = black_car_init_position;
float black_car_speed = 20;

const float road_start = -1000;
const float road_end = 1000;
#endif // CONSTANT_CPP