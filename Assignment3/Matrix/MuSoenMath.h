#pragma once
#include <iostream>
#define _USE_MATH_DEFINES // ���� ���� ��ũ�� ����
#include <math.h> // ���� ���� ���̺귯��

using namespace std;

class mat3; 

class vec3
{
	double v[3]; // ��Ʈ���� �������� ó���ϱ� ���� 3���� ������ 
public:
	vec3(double v1 = 0, double v2 = 0, double v3 = 1)
	{
		v[0] = v1; v[1] = v2; v[2] = v3;
	};
	vec3 operator*(const mat3& m) const; // ���Ϳ� ��Ʈ���� ������ �Լ� ȣ��
	friend ostream& operator<<(ostream& os, const vec3& v) {
		os << "(" << v.v[0] << "," << v.v[1] << "," << v.v[2] << ")";
		return os;
	};
};

class mat3 ////mat3 �̶�� Ŭ���� ����
{
	friend class vec3; // vec3��� Ŭ������ ���� ���� �ϵ��� friend ������
	double m[3][3]; //  �̵��� ���ԵǼ� 3X3 2���� �迭 ������
public:
	mat3() { setIdentity(); };
	void setIdentity() { // identity ��� �����ϴ� �Լ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) m[i][j] = 1;
				else m[i][j] = 0;
			}
		}
	}
	void setTranslate(double tx, double ty) { // �̵� �����ϴ� �Լ�
		setIdentity(); // ��� �����ϴ� �Լ� ȣ����
		m[2][0] = tx;
		m[2][1] = ty;
	}
	void setRotate(double angle) { // ȸ�� �����ϴ� �Լ�
		double rad = angle * M_PI / 180;
		setIdentity(); // ��� �����ϴ� �Լ� ȣ����
		m[0][0] = cos(rad);
		m[0][1] = sin(rad);
		m[1][0] = -sin(rad);
		m[1][1] = cos(rad);
	}
	void setScale(double sx, double sy) { // ũ�� �����ϴ� �Լ�
		setIdentity(); // ��� �����ϴ� �Լ� ȣ����
		m[0][0] = sx;
		m[1][1] = sy;
	}
};

inline vec3 vec3::operator*(const mat3& m) const // vec3 �Լ��� �����ε��� ���Ϳ� ��Ʈ���� �����ϰ�, ���͸� ������
{
	vec3 t;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			t.v[i] += this->v[j] * m.m[j][i];
		}
	}
	return t;
}
