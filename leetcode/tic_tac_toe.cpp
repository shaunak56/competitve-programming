#include<bits/stdc++.h>
using namespace std;

string tictactoe(vector<vector<int>>& moves) {
    char b[3][3];
    memset(b, 0, sizeof b);
    int turn = 0;
    for (vector<int> move: moves) {
        b[move[0]][move[1]] = 'A'+turn;
        turn = !turn;
    }
    string ans = "Pending";
    for (int i=0; i<3; i++) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] == 'A' ){
            ans = "A";
        }
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] == 'B' ){
            ans = "B";
        }
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] == 'A' ){
            ans = "A";
        }
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] == 'B' ){
            ans = "B";
        }
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] == 'A' ){
        ans = "A";
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] == 'B' ){
        ans = "B";
    }
    if (b[2][0] == b[1][1] && b[1][1] == b[0][2] && b[0][2] == 'A' ){
        ans = "A";
    }
    if (b[2][0] == b[1][1] && b[1][1] == b[0][2] && b[0][2] == 'B' ){
        ans = "B";
    }
    if (ans == "Pending" && moves.size() == 9)
        ans = "Draw";
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T = 1;
    // cin >> T;

    for(int t = 1; t <= T; t++) {
        vector<vector<int>> moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
        cout << tictactoe(moves) << endl;
    }

    return 0;
}
