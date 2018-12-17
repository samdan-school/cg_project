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
	float x;
	float y;
	float z;

	Color() {
	};

	Color(string name, float x, float y, float z) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

// vector<Vertex> vertices;
// vector<Face> faces;
// vector<string> colors;
// vector<Color> colorInfo;

void read_verticies(string path1, vector<Vertex> &vertices, vector<Face> &faces, vector<string> &colors) {
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
			getline(file, b);
		}
	}
	file.close();
}

void read_colors(string path2, vector<Color> &colorInfo) {
	fstream file1(path2);
	if (!file1.is_open()) {
		std::cout << "NO!" << endl;
		return;
	}
	while (!file1.eof()) {
		string b;
		string c;
		string name;
		float x;
		float y;
		float z;
		file1 >> b;
		if (b == "newmtl") {
			file1 >> name; 
		} 
		if (b == "Kd") {
			file1 >> x >> y >> z;
			Color temp(name, x, y, z);
			std::cout << x << " " << y << " " << z << endl;
			colorInfo.push_back(temp);
		} 
	}
	file1.close();

	std::cout << colorInfo.size() << endl;
}

#endif // READ_FILE_H