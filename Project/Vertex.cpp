#pragma once
class Vertex
{
public:
	float x;
	float y;
	float z;

	Vertex(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	~Vertex();
};

