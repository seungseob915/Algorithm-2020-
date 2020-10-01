// 오픈채팅방.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef struct result{
    string cmd;
    string user_id;
}r;

//문자열 분리
vector<string> solution(vector<string> record) {
    vector <string> answer;

    //map을 통한 2가지 user정보 저장
    map<string, string> user;
    
    //메세지 출력
    vector <r> M;

    for (int i = 0; i < record.size(); i++) {
        vector<string> tempV;
        string temp = "";

        for (int j = 0; j < record[i].size(); j++) {
            if (record[i][j] == ' ') {
                tempV.push_back(temp);
                temp = "";
            }
            else {
                temp.push_back(record[i][j]);
            }
        }
        // 마지막에는 ' ' 공백이 없으므로 별도로 추가 실행
        tempV.push_back(temp);

        if (tempV[0] == "Enter") {
            //유저 정보 및 아이디 등록
            user[tempV[1]] = tempV[2];
            // 메세지 저장
            M.push_back({ "Enter", tempV[1]});
        }
        else if (tempV[0] == "Leave") {
            // 메세지 저장
            M.push_back({ "Leave", tempV[1]});
        }
        else {
            user[tempV[1]] = tempV[2];
        }
    }

    //결과 출력
    for (int i = 0; i < M.size(); i++) {
        if (M[i].cmd == "Enter") {
            answer.push_back(user[M[i].user_id] + "님이 들어왔습니다.");
        }
        else {
            answer.push_back(user[M[i].user_id] + "님이 나갔습니다.");
        }
    }
    return answer;
}

int main()
{
        
}

