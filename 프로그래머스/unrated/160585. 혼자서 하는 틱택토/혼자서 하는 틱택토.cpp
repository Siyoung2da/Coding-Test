#include <string>
#include <vector>

using namespace std;

int o, x;

bool win(vector<string> board, char c) {
    for(int i=0;i<3;i++) {
        if(board[i][0] == c && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == c && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if(board[0][0] == c && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == c && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    
    return false;
}


int solution(vector<string> board) {
    int answer = 0;
        
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j] == 'O') {
                o++;
            }
            else if(board[i][j] == 'X') {
                x++;
            }
        }
    }
    
    if(o-x > 1 || o < x) return 0;
    
    if(win(board, 'O') && o-x != 1)
        return 0;
    if(win(board, 'X') && o-x != 0)
        return 0;
    if(win(board, 'O') && win(board, 'X'))
        return 0;
    
    return 1;
}