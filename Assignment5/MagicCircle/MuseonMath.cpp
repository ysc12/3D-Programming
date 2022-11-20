#include <chrono> // 시간관련 라이브러리
#include <thread> // 작업 할당 라이브러리
#include <string> // 문자열을 다룰수 있는 라이브러리
#include <iostream> // 표준 입출력 라이브러리
#include <GLFW/glfw3.h> // opengl 라이브러리
#include <math.h> //수학 라이브러리



#pragma comment(lib, "OpenGL32") // opengl32를 링크시켜준다.

using namespace std; // 이걸 사용하면 출력할때 std 안붙여도 된다.

chrono::system_clock::time_point startRenderTimePoint; // 시간 간격을 나타낸다.
chrono::duration<double> renderDuration; // 서로 다른 시간 변환할 때 사용한다.

GLFWwindow* window; //glfw 윈도우 선언

bool isFirstFrame; // frame 값 나타내기 위해 bool 값 사용








void Init(); // 초기화
void Update(); //새롭게 다시하기
void Release(); //해제하기

static void error_callback(int error, const char* description); //에러를 인수로 넘겨준다.
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); // 키 값을 인수로 넘겨준다

int main(void); // 메인 함수 호출


void Init()//초기화 함수
{
	glfwSetErrorCallback(error_callback); // 에러를 호출한다.
	if (!glfwInit()) //glfw 초기화 
		exit(EXIT_FAILURE); // 윈도우 창을 나간다.
	window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL); // 윈도우 창 해상도 
	if (!window) // 윈도우가 참이면 거짓을 거짓이면 참이다. 
	{
		glfwTerminate(); //glfw 런타임 호출
		exit(EXIT_FAILURE); // 윈도우창 나가기
	}

	glfwMakeContextCurrent(window); // 한번의 하나의 쓰레드에서만 현재상태로 만들 수 있다.
	glfwSetKeyCallback(window, key_callback); // 키를 설정한다.


	glEnable(GL_BLEND); //섞기
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSwapInterval(1); // 나를 위해 작동하지 않게 하기

	startRenderTimePoint = chrono::system_clock::now(); //현재 시간 나타내기


	





}
// 별 그리는 함수
void star(float x_shift, float y_shift, float star_radius) {
	// PI값
	float DEGINRAD = 3.14159 / 180;
	
	glBegin(GL_LINE_STRIP); // 선 직접 그리기
	glColor3f(1.0, 0.0, 0.0); // 색상 빨간색
	// cos sin 값과 pi값을 곱하면 별모양이 나옴
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
	glEnd(); //마무리
}
//해제 함수
void Release()
{
	glfwDestroyWindow(window); // 윈도우창 삭제
	glfwTerminate(); // 끝내기
}
//새롭게 다시 하기
void Update()
{

	//while문 안에서 윈도우창에 그린걸 화면에 출력한다.
	while (!glfwWindowShouldClose(window))
	{

	





		



		



		//		transform.scale *= 1.001;
		//Update로직
		//<문제>//////////////////////////////////////////////////////////////////////////////////

		//1. translate 를 프레임당 오른쪽으로 0.001씩 누적시켜서 물체를 이동해보세요.
		//2. Rotation 을 프레임당 1도씩 누적시켜서 물체를 회전시켜보세요.
		//3. Scale은 초당 0.01씩 최대 1.3배까지 늘어났다가 0.7배까지 줄어들도록 만드시오 (반복)
		//   (1.3배 이상이 되면 줄어들고 0.7배 이하가 되면 다시 늘어나게 만드시오)


		//////////////////////////////////////////////////////////////////////////////////////////

		



		//색 초기화
		glClearColor(.0f, 0.0f, 0.0f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);

		//선두께
		glLineWidth(7.0f);
		
		// 반지름
		float radius = 0.6;

		// PI값
		float DEGINRAD = 3.14159 / 180;
		
		
		//x값
		float x_left = 0.01;
		//y값
		float y_left = 0.11;

		//원그리기
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 1.0f); //색상
		
		//원 그릴려면 회전시켜야 해가지고 for문으로 cos과 sin에 각각 radius 값을 곱하고 x,y에 값을 더한다.
		for (int i = 0; i <= 360; i++) {
			float degInRad = i * DEGINRAD;
			glVertex2f(cos(degInRad) * radius + x_left, sin(degInRad) * radius + y_left);
			
		}
		

		//별모양 그리는 함수 
		star(0.01, 0.1, 0.6);

		// 끝내기
		glEnd();
		



		



		//화면 스왑
		glfwSwapBuffers(window);
		glfwPollEvents();

		//렌더시간 측정
		renderDuration = chrono::system_clock::now() - startRenderTimePoint;
		startRenderTimePoint = chrono::system_clock::now();

		float fps = 1.0 / renderDuration.count(); // fps 값 을 시간 변환 카운트로 나눈다.
		if (isFirstFrame == true) 
		{
			isFirstFrame = false;
			continue; 
		}
		// 시간변환 카운트가 1.0 / 60.0 보다 작으면 시간을 계산해서 string으로 변환한 후 FPS값을 출력한다.
		if (renderDuration.count() < (1.0f / 60.0f))
			this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
		string fps_s = "FPS : " + to_string(fps);
		cout << fps_s << endl;

	}
}
// 에러 체크하는 함수이다.
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

// 키 값을 다른 인수로 넘겨주는 함수
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
// 가장 중요한 메인함수
int main(void) 
{
	Init(); //초기화 함수 호출
	Update(); //새로하기 함수 호출
	Release(); // 해제하기 함수 호출

	// 윈도우 창을 나간다.
	exit(EXIT_SUCCESS); 
}