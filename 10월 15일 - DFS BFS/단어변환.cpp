/*
/ 단어변환 : https://programmers.co.kr/learn/courses/30/lessons/43163
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 2147000000; //최솟값 구해야 함
bool visited[51]; //50개 이하 단어

void dfs(string str, int level, string target, vector<string> words) {

    if (str == target) {
        answer = min(answer, level); //최소 몇단계
        return;
    }

    for (int i = 0; i < words.size(); i++) {

        if (visited[i]) continue;

        string str2 = words[i]; //비교할 단어

        int cnt = 0;
        //한 글자씩 비교해보기
        for (int j = 0; j < str.size(); j++) {
            if (str2.at(j) != str.at(j)) cnt++; //다른 글자수
        }
        //다른 글자가 1개라면 해당 글자로 가지 뻗기
        if (cnt == 1) {
            visited[i] = true;
            dfs(str2, level + 1, target, words);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    //target이 words안에 있나
    bool found = false;
    for (int i = 0; i < words.size(); i++) {
        if (target == words[i]) {
            found = true;
            break;
        }
    }

    if (!found) return 0;

    dfs(begin, 0, target, words);
    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << solution(begin, target, words);
}