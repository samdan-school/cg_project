#if !defined(READ_FILE_H)
#define READ_FILE_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Vertex {
public:
	float x;
	float y;
	float z;
	
	Vertex() {
	};

	Vertex(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vertex operator =(Vertex new_v) {
		this->x = new_v.x;
		this->y = new_v.y;
		this->z = new_v.z;
		return *this;

	}
};

class Face {
public:
	Vertex v[3];

	Face(Vertex x, Vertex y, Vertex z) {
		this->v[0] = x;
		this->v[1] = y;
		this->v[2] = z;
	}
};

class Color {
public:
	string name;
	float r;
	float g;
	float b;

	Color() {
	};

	Color(string name, float r, float g, float b) {
		this->name = name;
		this->r = r;
		this->g = g;
		this->b = b;
	}
};

// vector<Vertex> vertices;
// vector<Face> faces;
// vector<string> colors;
// vector<Color> colorInfo;

void read_verticies(string path1, vector<Vertex> &vertices, vector<Face> &faces, vector<string> &colors, vector<int> &face_number) {
	fstream file(path1);
	if (!file.is_open()) {
		std::cout << "NO!" << endl;
		return;
	}
	while (!file.eof()) {
		string b;
		char a;
		file >> a;
		if (a == 'v') {
			float x, y, z;
			file >> x >> y >> z;
			Vertex temp(x, y, z);

			vertices.push_back(temp);
		}
		else if (a == 'f') {
			int a1, a2, a3;
			file >> a1 >> a2 >> a3;
			Face temp(vertices[a1 - 1], vertices[a2 - 1], vertices[a3 - 1]);
			faces.push_back(temp);
		}
		else {
			if (a == 'u') {
				string c;
				string d;
				file >> c;
				file >> d;
				colors.push_back(d);
			}
			else{
				if(a == '#'){
					int c;
					file >> c;
					face_number.push_back(c);
					getline(file,b);
				} else {
					file >> b;
				}
			}
			
		}
	}
	file.close();
}

void read_colors(string path2, vector<Color> &colorInfo) {
	fstream file1(path2);
	if (!file1.is_open()) {
		return;
	}
	while (!file1.eof()) {
		string b;
		string c;
		string c_name;
		float x;
		float y;
		float z;
		file1 >> b;
		if (b == "newmtl") {
			file1 >> c_name;
			
			file1 >> c;
			while (1) { 
				if (c == "Kd") {
					file1 >> x >> y >> z;
					Color temp(c_name, x, y, z);
					colorInfo.push_back(temp);
					c_name.clear();
					break;
				}
				c.clear();
				file1 >> c;
			}
		} 
	}
	file1.close();
}


void ReduceToUnit(float *vector)
{
	float length;

	// Calculate the length of the vector
	length = float(sqrt((vector[0] * vector[0]) +
						 (vector[1] * vector[1]) +
						 (vector[2] * vector[2])));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if (length == 0.0f)
		length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}

void calcNormal(Face &face, float *out)
{
	float v1[3], v2[3];

	// Calculate two vectors from the three points
	v1[0] = face.v[0].x - face.v[1].x;
	v1[1] = face.v[0].y - face.v[1].y;
	v1[2] = face.v[0].z - face.v[1].z;

	v2[0] = face.v[1].x - face.v[2].x;
	v2[1] = face.v[1].y - face.v[2].y;
	v2[2] = face.v[1].z - face.v[2].z;

	out[0] = v1[1] * v2[2] - v1[2] * v2[1];
	out[1] = v1[2] * v2[0] - v1[0] * v2[2];
	out[2] = v1[0] * v2[1] - v1[1] * v2[0];

	// Normalize the vector (shorten length to one)
	ReduceToUnit(out);
}

#endif // READ_FILE_H