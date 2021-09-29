import java
.util.*;

class Main {
    static int[][]
    map;
    static int[]
    person;
    static int n;
    static int ans = Integer.MAX_VALUE;

    //시간초과가 나는데..자바라 잘 모르겠다 또 string을 쓰거나 해야 하나?
public

    static int computePower() {
        int start_power = 0;
        int link_power = 0;

        ArrayList <Integer> start = new ArrayList();
        ArrayList <Integer> link = new ArrayList();


        //1이면 스타트, 0이면 링크
        for (int i = 1; i <= n; i++) {
            if (person[i] == 1) start.add(i);
            else link.add(i);
        }
        //스타트
        for (int i = 0; i < start.size(); i++) {
            for (int j = i + 1; j < start.size(); j++) {
                start_power += map[Integer.parseInt(start.get(i).toString())][Integer.parseInt(
                        start.get(j).toString())];
                start_power += map[Integer.parseInt(start.get(j).toString())][Integer.parseInt(
                        start.get(i).toString())];
            }
        }

        //링크
        for (int i = 0; i < link.size(); i++) {
            for (int j = i + 1; j < link.size(); j++) {
                link_power += map[Integer.parseInt(link.get(i).toString())][Integer.parseInt(link.get(j).toString())];
                link_power += map[Integer.parseInt(link.get(j).toString())][Integer.parseInt(link.get(i).toString())];
            }
        }

        return Math.abs(start_power - link_power);
    }

    //조합 구현.
public

    static void selectStart(int start, int level, int target_level) {
        if (level == target_level) { //target_level 개를 다 골랐을 경우
            int power_sub = computePower(); //차이 구하기
            ans = Math.min(ans, power_sub);
            return;
        }

        for (int i = start; i <= n; i++) {
            person[i] = 1; //1로 설정한 것이 스타트팀.
            selectStart(i + 1, level + 1, target_level);
            person[i] = 0;
        }
    }

public

    static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        //입력
        n = kb.nextInt();
        map = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                map[i][j] = kb.nextInt();
            }
        }
        //스타트팀 기준으로, 1명~ n-1명의 조합을 구해야 함!
        for (int i = 1; i <= n - 1; i++) {
            person = new int[n + 1];
            selectStart(1, 0, i); //(start, level, target level) -> 1번 사람부터 시작
        }

        System.out.println(ans);
    }
}

