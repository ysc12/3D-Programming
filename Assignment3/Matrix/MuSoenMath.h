#pragma once
#include <iostream>
#define _USE_MATH_DEFINES // 수학 관련 매크로 정의
#include <math.h> // 수학 관련 라이브러리

using namespace std;

class mat3; 

class vec3
{
	double v[3]; // 매트릭스 연산으로 처리하기 위해 3개로 선언함 
public:
	vec3(double v1 = 0, double v2 = 0, double v3 = 1)
	{
		v[0] = v1; v[1] = v2; v[2] = v3;
	};
	vec3 operator*(const mat3& m) const; // 벡터와 매트릭스 연산한 함수 호출
	friend ostream& operator<<(ostream& os, const vec3& v) {
		os << "(" << v.v[0] << "," << v.v[1] << "," << v.v[2] << ")";
		return os;
	};
};

class mat3 ////mat3 이라는 클래스 선언
{
	friend class vec3; // vec3라는 클래스에 접근 가능 하도록 friend 선언함
	double m[3][3]; //  이동이 포함되서 3X3 2차원 배열 선언함
public:
	mat3() { setIdentity(); };
	void setIdentity() { // identity 행렬 설정하는 함수
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) m[i][j] = 1;
				else m[i][j] = 0;
			}
		}
	}
	void setTranslate(double tx, double ty) { // 이동 설정하는 함수
		setIdentity(); // 행렬 설정하는 함수 호출함
		m[2][0] = tx;
		m[2][1] = ty;
	}
	void setRotate(double angle) { // 회전 설정하는 함수
		double rad = angle * M_PI / 180;
		setIdentity(); // 행렬 설정하는 함수 호출함
		m[0][0] = cos(rad);
		m[0][1] = sin(rad);
		m[1][0] = -sin(rad);
		m[1][1] = cos(rad);
	}
	void setScale(double sx, double sy) { // 크기 설정하는 함수
		setIdentity(); // 행렬 설정하는 함수 호출함
		m[0][0] = sx;
		m[1][1] = sy;
	}
};

inline vec3 vec3::operator*(const mat3& m) const // vec3 함수를 오버로딩함 벡터와 매트릭스 연산하고, 벡터를 리턴함
{
	vec3 t;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			t.v[i] += this->v[j] * m.m[j][i];
		}
	}
	return t;
}
