/*
 * 드래곤 커 : https://www.acmicpc.net/problem/15685
 */
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 100 + 1; //격자 사이즈

//우, 상, 좌, 하
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

//크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것이 개수 구하기
int cntSquare(vector<vector<bool>> &board) {
    int ans = 0; // 개수 변수
    for (int i = 0; i < SIZE - 1; i++) { // 100*100 크기의 정사각형
        for (int j = 0; j < SIZE - 1; j++) { //100*100 크기의 정사각형
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] &&
                board[i + 1][j + 1]) // 현재 지점 기준이 왼쪽 맨 위 꼭짓점이고, 그 기준으로 1*1 정사각형 네 꼭짓점이 모두 드래곤 커브이면
                ans++; //개수 세줌
        }
    }
    return ans; //최종 개수 변수 리턴
}

// point : 호출 시 끝점, direct : 호출 시 그 전 세대까지의 방향 정보
// 다음 끝점 : 전 세대 방향 정보 개수 만큼, 그 전 세대 방향들을 거꾸로 보면서, 90도 회전해서 전진
ci makeDragonCurve(vector<vector<bool>> &board, vector<int> &direc, ci point) {
    int size = direc.size(); // direc : 그 전 세대까지의 방향 정보
    for (int i = size - 1; i >= 0; i--) { // 그 전 세대 방향을 거꾸로 보면서
        int new_direc = (direc[i] + 1) % 4; //현재 시작 점의 방향 : 거꾸로 보고있는 전 세대 방향을 90도로 회전한 것
        // => (우(0) -> 상(1) / 상(1) -> 좌(2) / 좌(2) -> 하(3) / 하(3) -> 우(0))
        point = {point.first + dy[new_direc], point.second + dx[new_direc]}; //인자로 받은 끝점을 정해진 방향으로 한 칸 이동해서 새로운 끝점이 됨
        board[point.first][point.second] = true; //현재 끝점 true (범위는 안벗어나므로 검사할 필요 없다)
        direc.push_back(new_direc); //현재 방향 정보 삽입
    }
    return point; // 끝점 return
}

/**
 * x: 열, y: 행
 *
 * 드래곤 커브 = 선분들로 이루어짐
 * => 각 선분들의 방향을 저장해서 드래곤 커브의 좌푯값을 구해나가자
 *
 * 드래곤 커브는 각 세대마다 끝 점을 기준으로 시계 방향으로 90도 회전
 * -> 드래곤 커브 세대의 각 선분 방향 = 전 세대 방향들에서 차례로 끝 점을 기준으로 시계방향으로 이동한 것과 같음
 * -> (우(0) -> 상(1) / 상(1) -> 좌(2) / 좌(2) -> 하(3) / 하(3) -> 우(0)) 로 이동
 * ex) 0세대: 우
 *     1세대: 상
 *     2세대: 좌 상 (1세대 + 0세대의 상, 우에서 각각 시계방향 이동)
 *     3세대: 좌 하 좌 상 (2세대 + 1세대 + 0세대에서 각각 시계방향 이동)
 *
 * 0세대는 이미 방향이 주어지므로 먼저 처리
 * 드래곤 커브는 격자 밖으로 나가지 않음 -> 범위 검사 필요 x
 */

int main() {
    int n, x, y, d, g;

    //입력 & 연산
    cin >> n;
    vector<vector<bool>> board(SIZE, vector<bool>(SIZE, false)); //100x100 사이즈 격자
    while (n--) { // n개의 드래곤 커브
        cin >> x >> y >> d >> g; // x,y : 드래곤 커브 시작점 d: 시작방향 g : 세대
        vector<int> direc; //세대의 방향 정보 저장 및 보존하는 벡터
        ci end_point = {y + dy[d], x + dx[d]}; //0세대 끝점 (현재 방향으로 한 칸 이동한)
        board[y][x] = board[end_point.first][end_point.second] = true; //0세대 시작점, 끝점 초기화 (커브가 생긴 곳은 true)
        direc.push_back(d); //0세대 방향 삽입
        while (g--) { //각 세대마다 드래곤 커브 만들기
            end_point = makeDragonCurve(board, direc, end_point); // 끝점 갱신하면서 호출 // board를 주소로 주어서 그 안의 값이 바뀌는 거?
        }
    }

    //출력
    cout << cntSquare(board) << '\n'; //크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것이 개수 구하기
    return 0;
}