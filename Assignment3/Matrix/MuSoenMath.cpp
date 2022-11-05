#include <iostream>
#include "MuSoenMath.h" // <- 아래 자료구조 모두 여기다 구현할것.

//vec3(float 3*1) -> 2차원좌표 + 동차좌표

//mat3(float 3*3) -> 2차원 행렬

int main() {

	
	vec3 v;
	mat3 Translate, Rotate, Scale; //mac3 이라는 클래스를 불러와 이동, 회전, 크기 재선언
	Translate.setTranslate(3, 5);
	Rotate.setRotate(30);
	Scale.setScale(2, 2);
	vec3 p = v * Translate * Rotate * Scale;   // 3,5 이동 | 30도 회전 | 2배 확대 설정해서 곱함
	cout << v << " -> " << p << endl;

	
}