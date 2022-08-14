#include <iostream>

using namespace std;

// 연산자 오버로딩

//연산자 vs함수
// - 연산자는 피연산자의 개수/타입이 고정되어 있음

//연산자 오버로딩?
//일단[연산자 함수]를 정의 해야함
//함수도 멤버함수 vs 전역함수가 존재하는것처럼, 연산자 함수도 두가지 방식으로 만들수있음

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽으로 기준으로 실행됨 (a가 클래스여야 가능. a를 기준 피연산자 라고함)
// -- 한계) a가 클래스가 아니면 사용못함

// -전역 연산자 함수 version
// --a op b형태라면 a,b모두를 연산자 함수의 피연산자

class Position
{
public:
    //멤버 연산자 버전
    Position operator+(const Position& arg)
    {
        Position pos;

        pos._x = _x + arg._x;
        pos._y = _y + arg._y;

        return pos;
    }

    Position operator+(int arg)
    {
        Position pos;

        pos._x = _x + arg;
        pos._y = _y + arg;

        return pos;
    }

    bool operator==(const Position& arg)
    {
        return _x == arg._x && _y == arg._y;
    }

public:
    int _x;
    int _y;
};

//전역연산자 버전
Position operator+(int a, const Position& b)
{
    Position ret;
    ret._x = b._x + a;
    ret._y = b._y + a;

    return ret;
}

int main()
{
    Position pos;
    pos._x = 0;
    pos._y = 0;

    Position pos2;
    pos._x = 1;
    pos._y = 2;

    Position pos3 = pos + pos2;
    //pos3 = pos.operator+(pos2);

    Position pos4 = pos3 + 1;

    bool isSame = (pos3 == pos4);
}