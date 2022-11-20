#include <chrono> // �ð����� ���̺귯��
#include <thread> // �۾� �Ҵ� ���̺귯��
#include <string> // ���ڿ��� �ٷ�� �ִ� ���̺귯��
#include <iostream> // ǥ�� ����� ���̺귯��
#include <GLFW/glfw3.h> // opengl ���̺귯��
#include <math.h> //���� ���̺귯��



#pragma comment(lib, "OpenGL32") // opengl32�� ��ũ�����ش�.

using namespace std; // �̰� ����ϸ� ����Ҷ� std �Ⱥٿ��� �ȴ�.

chrono::system_clock::time_point startRenderTimePoint; // �ð� ������ ��Ÿ����.
chrono::duration<double> renderDuration; // ���� �ٸ� �ð� ��ȯ�� �� ����Ѵ�.

GLFWwindow* window; //glfw ������ ����

bool isFirstFrame; // frame �� ��Ÿ���� ���� bool �� ���








void Init(); // �ʱ�ȭ
void Update(); //���Ӱ� �ٽ��ϱ�
void Release(); //�����ϱ�

static void error_callback(int error, const char* description); //������ �μ��� �Ѱ��ش�.
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); // Ű ���� �μ��� �Ѱ��ش�

int main(void); // ���� �Լ� ȣ��


void Init()//�ʱ�ȭ �Լ�
{
	glfwSetErrorCallback(error_callback); // ������ ȣ���Ѵ�.
	if (!glfwInit()) //glfw �ʱ�ȭ 
		exit(EXIT_FAILURE); // ������ â�� ������.
	window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL); // ������ â �ػ� 
	if (!window) // �����찡 ���̸� ������ �����̸� ���̴�. 
	{
		glfwTerminate(); //glfw ��Ÿ�� ȣ��
		exit(EXIT_FAILURE); // ������â ������
	}

	glfwMakeContextCurrent(window); // �ѹ��� �ϳ��� �����忡���� ������·� ���� �� �ִ�.
	glfwSetKeyCallback(window, key_callback); // Ű�� �����Ѵ�.


	glEnable(GL_BLEND); //����
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSwapInterval(1); // ���� ���� �۵����� �ʰ� �ϱ�

	startRenderTimePoint = chrono::system_clock::now(); //���� �ð� ��Ÿ����


	





}
// �� �׸��� �Լ�
void star(float x_shift, float y_shift, float star_radius) {
	// PI��
	float DEGINRAD = 3.14159 / 180;
	
	glBegin(GL_LINE_STRIP); // �� ���� �׸���
	glColor3f(1.0, 0.0, 0.0); // ���� ������
	// cos sin ���� pi���� ���ϸ� ������� ����
	glVertex2f(cos(18 * DEGINRAD) * star_radius + x_shift, sin(18 * DEGINRAD) * star_radius + y_shift);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(cos((18 + 72 + 72) * DEGINRAD) * star_radius + x_shift, sin((18 + 72 + 72) * DEGINRAD) * star_radius + y_shift);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(cos((18 + 72 + 72 + 72 + 72) * DEGINRAD) * star_radius + x_shift, sin((18 + 72 + 72 + 72 + 72) * DEGINRAD) * star_radius + y_shift);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(cos((18 + 72) * DEGINRAD) * star_radius + x_shift, sin((18 + 72) * DEGINRAD) * star_radius + y_shift);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(cos((18 + 72 + 72 + 72) * DEGINRAD) * star_radius + x_shift, sin((18 + 72 + 72 + 72) * DEGINRAD) * star_radius + y_shift);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(cos((18) * DEGINRAD) * star_radius + x_shift, sin((18) * DEGINRAD) * star_radius + y_shift);
	glColor3f(1.0, 0.0, 0.0);
	glEnd(); //������
}
//���� �Լ�
void Release()
{
	glfwDestroyWindow(window); // ������â ����
	glfwTerminate(); // ������
}
//���Ӱ� �ٽ� �ϱ�
void Update()
{

	//while�� �ȿ��� ������â�� �׸��� ȭ�鿡 ����Ѵ�.
	while (!glfwWindowShouldClose(window))
	{

	





		



		



		//		transform.scale *= 1.001;
		//Update����
		//<����>//////////////////////////////////////////////////////////////////////////////////

		//1. translate �� �����Ӵ� ���������� 0.001�� �������Ѽ� ��ü�� �̵��غ�����.
		//2. Rotation �� �����Ӵ� 1���� �������Ѽ� ��ü�� ȸ�����Ѻ�����.
		//3. Scale�� �ʴ� 0.01�� �ִ� 1.3����� �þ�ٰ� 0.7����� �پ�鵵�� ����ÿ� (�ݺ�)
		//   (1.3�� �̻��� �Ǹ� �پ��� 0.7�� ���ϰ� �Ǹ� �ٽ� �þ�� ����ÿ�)


		//////////////////////////////////////////////////////////////////////////////////////////

		



		//�� �ʱ�ȭ
		glClearColor(.0f, 0.0f, 0.0f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);

		//���β�
		glLineWidth(7.0f);
		
		// ������
		float radius = 0.6;

		// PI��
		float DEGINRAD = 3.14159 / 180;
		
		
		//x��
		float x_left = 0.01;
		//y��
		float y_left = 0.11;

		//���׸���
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 1.0f); //����
		
		//�� �׸����� ȸ�����Ѿ� �ذ����� for������ cos�� sin�� ���� radius ���� ���ϰ� x,y�� ���� ���Ѵ�.
		for (int i = 0; i <= 360; i++) {
			float degInRad = i * DEGINRAD;
			glVertex2f(cos(degInRad) * radius + x_left, sin(degInRad) * radius + y_left);
			
		}
		

		//����� �׸��� �Լ� 
		star(0.01, 0.1, 0.6);

		// ������
		glEnd();
		



		



		//ȭ�� ����
		glfwSwapBuffers(window);
		glfwPollEvents();

		//�����ð� ����
		renderDuration = chrono::system_clock::now() - startRenderTimePoint;
		startRenderTimePoint = chrono::system_clock::now();

		float fps = 1.0 / renderDuration.count(); // fps �� �� �ð� ��ȯ ī��Ʈ�� ������.
		if (isFirstFrame == true) 
		{
			isFirstFrame = false;
			continue; 
		}
		// �ð���ȯ ī��Ʈ�� 1.0 / 60.0 ���� ������ �ð��� ����ؼ� string���� ��ȯ�� �� FPS���� ����Ѵ�.
		if (renderDuration.count() < (1.0f / 60.0f))
			this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
		string fps_s = "FPS : " + to_string(fps);
		cout << fps_s << endl;

	}
}
// ���� üũ�ϴ� �Լ��̴�.
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

// Ű ���� �ٸ� �μ��� �Ѱ��ִ� �Լ�
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
// ���� �߿��� �����Լ�
int main(void) 
{
	Init(); //�ʱ�ȭ �Լ� ȣ��
	Update(); //�����ϱ� �Լ� ȣ��
	Release(); // �����ϱ� �Լ� ȣ��

	// ������ â�� ������.
	exit(EXIT_SUCCESS); 
}