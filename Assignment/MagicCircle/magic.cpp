#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;
bool mRecomputeWorldTransform;


struct Vertex
{
    glm::vec3 pos;
    float r, g, b, a;
};

struct Transform
{
    glm::mat3 translate;
    glm::mat3 scale;
    glm::mat3 rotation;
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //ȭ�鿡 �׸� ������
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // ȭ�鿡 �׷��� ��

Transform transform;  //world ����� �� transform

//<����>////////�������� ���°�////////////////////////////////////////////////////////////




 //////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    //object������
     /// Star(������) ����
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].pos.x = -glm::sin(glm::radians(theta)) * 0.5f;
        star[i].pos.y = glm::cos(glm::radians(theta)) * 0.5f;
        star[i].pos.z = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;


        transformedStar[i] = star[i];

        i++;
    }

    // �� ����
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.x = -glm::sin(glm::radians((float)theta)) * 0.5;
        circle[theta].pos.y = glm::cos(glm::radians((float)theta)) * 0.5;
        circle[theta].pos.z = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }


    //Ʈ������ �ʱ�ȭ (�⺻�� ����)
    transform.translate = glm::mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.rotation = glm::mat3(
        glm::cos(glm::radians(0.0f)), -glm::sin(glm::radians(0.0f)), 0,
        glm::sin(glm::radians(0.0f)), glm::cos(glm::radians(0.0f)), 0,
        0, 0, 1
    );
    transform.scale = glm::mat3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );


}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
	
	float fGakdo = 0.f;
	float fScale = 1.f;
	float fMove = 0;
	
	bool bIncrease = true;
	bool bIncreaseMove = true;
	bool bIncreaseMoveY = true;
	while(!glfwWindowShouldClose(window))
	{
		
		fGakdo += 1;
		
		if(fScale > 1.4f)
		{
			bIncrease = false;
			fScale = 1.4f;
		}
		
		if(fScale <= 0.7f)
		{
			bIncrease = true;
			fScale = 0.7f;
		}

		if (bIncrease)
		{
			fScale += 0.01;	
		}
		else
		{
			fScale -= 0.01;

		}

		if (bIncreaseMove)
			fMove += 0.001f;
		else
			fMove -= 0.001f;

		

			
			
		
			
			

		

		transform.rotation = glm::mat3(
			glm::cos(glm::radians(fGakdo)), -glm::sin(glm::radians(fGakdo)), 0,
			glm::sin(glm::radians(fGakdo)), glm::cos(glm::radians(fGakdo)), 0,
			0, 0, 1
		);

		glm::vec3 move = glm::vec3(fMove, 0, 0);

		
		
		//		transform.scale *= 1.001;
		//Update����
		//<����>//////////////////////////////////////////////////////////////////////////////////

		//1. translate �� �����Ӵ� ���������� 0.001�� �������Ѽ� ��ü�� �̵��غ�����.
		//2. Rotation �� �����Ӵ� 1���� �������Ѽ� ��ü�� ȸ�����Ѻ�����.
		//3. Scale�� �ʴ� 0.01�� �ִ� 1.3����� �þ�ٰ� 0.7����� �پ�鵵�� ����ÿ� (�ݺ�)
		//   (1.3�� �̻��� �Ǹ� �پ��� 0.7�� ���ϰ� �Ǹ� �ٽ� �þ�� ����ÿ�)


		//////////////////////////////////////////////////////////////////////////////////////////

		for(int i = 0; i < 360; i++)
		{
			transformedCircle[i].pos = transform.translate * transform.rotation * transform.scale * fScale * circle[i].pos + move;
		}

		for(int i = 0; i < 5; i++)
		{
			transformedStar[i].pos = transform.translate * transform.rotation * transform.scale * fScale * star[i].pos + move;
		}



		//�� �ʱ�ȭ
		glClearColor(.0f, 0.0f, 0.0f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);

		//���β�
		glLineWidth(7.0f);
		//������ �׸���
		glBegin(GL_LINE_STRIP);

		int a = 0;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
		a = 3;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
		a = 1;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
		a = 4;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
		a = 2;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);

		a = 0;
		glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
		glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
		glEnd();

		//���׸���
		glBegin(GL_LINE_STRIP);
		for(int theta = 0; theta < 360; theta++)
		{
			glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
			glVertex3f(transformedCircle[theta].pos.x, transformedCircle[theta].pos.y, 0.0f);
		}

		


		glEnd();



		//ȭ�� ����
		glfwSwapBuffers(window);
		glfwPollEvents();

		//�����ð� ����
		renderDuration = chrono::system_clock::now() - startRenderTimePoint;
		startRenderTimePoint = chrono::system_clock::now();

		float fps = 1.0 / renderDuration.count();
		if(isFirstFrame == true)
		{
			isFirstFrame = false;
			continue;
		}
		if(renderDuration.count() < (1.0f / 60.0f))
			this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
		string fps_s = "FPS : " + to_string(fps);
		cout << fps_s << endl;

	}
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
}