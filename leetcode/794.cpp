#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x_count = 0, o_count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X')
                    x_count += 1;
                else
                    o_count += 1;
            }
        }
        if (x_count != o_count && x_count - 1 != o_count)
            return false;
        if (check(board, 'X') && x_count - 1 != o_count)
            return false;
        if (check(board, 'O') && x_count != o_count)
            return false;

        return true;
    }

    bool check(vector<string>& board, char p) {
        for (int i = 0; i < 3; ++i) {
            // 每一行
            if (p == board[i][0] && p == board[i][1] && p == board[i][2])
                return true;
            // 每一列
            if (p == board[0][i] && p == board[1][i] && p == board[2][i])
                return true;
        }
        // 两个对角线
        if (p == board[0][0] && p == board[1][1] && p == board[2][2])
            return true;
        if (p == board[0][2] && p == board[1][1] && p == board[2][0])
            return true;
        return false;
    }
};
