#include <iostream> // 입출력 표준 라이브러리
#include <iomanip> // 입출력 조정자 라이브러리
#define _USE_MATH_DEFINES // 수학 관련 매크로 정의
#include <math.h> // 수학 관련 라이브러리
#define ROWS 3 // 행 매크로 정의
#define COLS 3 // 열 매크로 정의
#include <vector> // 동적 배열 구조

using namespace std;

//행렬 벡터간 덧셈
vector <vector<int>> sumMatrix(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> answer;
    

    //answer.resize(A.size(), vector(A[0].size(), 0));

    int i, j = 0;

    for (int i = 0; i < A.size(); i++)
    {
        vector<int> temp;

        for (int j = 0; j < A[0].size(); j++)
        {
            temp.push_back(A[i][j] + B[i][j]);
        }

        answer.push_back(temp);
    }

    
    
    

    return answer;
    
}
//행렬 벡터간 뺄셈
vector <vector<int>> minusMatrix(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> anr;


    //answer.resize(A.size(), vector(A[0].size(), 0));

    int i, j = 0;

    for (int i = 0; i < A.size(); i++)
    {
        vector<int> temp;

        for (int j = 0; j < A[0].size(); j++)
        {
            temp.push_back(A[i][j] - B[i][j]);
        }

        anr.push_back(temp);
    }





    return anr;

}


//1. 단위행렬
void identity() {
    int column = 1, row = 1;
    while (column <= 10)
    {
        row = 1;
        while (row <= 10)
        {
            cout << setw(4) << (row == column ? 1 : 0);
            row++;
        }
        cout << endl;
        column += 1;
        continue;
    }

}

//2. 전치행렬
    void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) {
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++) {
                B[c][r] = A[r][c];
            }
        }

    }

    void matrix_print(int A[ROWS][COLS]) {
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                printf("%d ", A[r][c]);
            }
            cout << endl;
        }
    }

// 상수 곱셈, 나눗셈
void print(int n) {
    
       const int result_1 = 90 / n;
       const int result_2 = 100 * n;
        printf("%d %d\n", result_1, result_2);
}

    



int main() {

    vector<vector<int>> a{ { 10 }}, b{ { 3 } };
    vector<vector<int>> answer = sumMatrix(a, b);
    vector<vector<int>> anr = minusMatrix(a, b);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[0].size(); j++)
        {
            cout << answer[i][j] << " " ;
            
        }
        cout << "\n";
    }
    

    for (int i = 0; i < anr.size(); i++)
    {
        for (int j = 0; j < anr[0].size(); j++)
        {
            cout << anr[i][j] << " " ;

        }
        cout << "\n";
    }
    cout << endl;

    int arr1[ROWS][COLS] = {
        {2,3,0},
        {8,9,1},
        {7,0,5}
    };
    int arr2[ROWS][COLS] = { 0 };

    matrix_transpose(arr1, arr2);
    matrix_print(arr1);
    cout << endl;
    matrix_print(arr2);
    cout << endl;
    identity();
    cout << endl;
    
    
    cout << endl;    
    print(9);
    cout << endl;
    



 
}