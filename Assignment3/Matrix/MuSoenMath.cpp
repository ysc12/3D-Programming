#include <iostream>
#include "MuSoenMath.h" // <- �Ʒ� �ڷᱸ�� ��� ����� �����Ұ�.

//vec3(float 3*1) -> 2������ǥ + ������ǥ

//mat3(float 3*3) -> 2���� ���

int main() {

	
	vec3 v;
	mat3 Translate, Rotate, Scale; //mac3 �̶�� Ŭ������ �ҷ��� �̵�, ȸ��, ũ�� �缱��
	Translate.setTranslate(3, 5);
	Rotate.setRotate(30);
	Scale.setScale(2, 2);
	vec3 p = v * Translate * Rotate * Scale;   // 3,5 �̵� | 30�� ȸ�� | 2�� Ȯ�� �����ؼ� ����
	cout << v << " -> " << p << endl;

	
}