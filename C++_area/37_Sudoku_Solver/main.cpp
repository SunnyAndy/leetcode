#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

class Solution {
  public:
    bool check_valid ( vector <vector <char >> &board  , int row , int col        ){

      // for the row  line  to check   
      for (int i=0; i < board.size () ; ++i){
	if (board[i][col]==board[row][col] and i!=row ){
	  return false; 
	}
      }
      // for the column checking

      for (int i = 0  ; i <board.size() ; ++i){	
	if (board[row][i]==board[row][col] and i!=col){
	  return false;
	}
      }

      int row_start= row/3;
      int col_start= col/3;
      for (int i=row_start*3 ; i < row_start*3+3;i++){
	for(int j=col_start*3 ; j<col_start*3+3 ; j++ ){
	  if (board[i][j]==board[row][col] and i!=row and j !=col){
	    return false;
	  }
	}
      }

      return true;
    }
    //    void  re_skudo (  int row ,  int n , vector <string> &cur   ,  vector <vector <char>> &board   ){
    void helper(vector <vector <char>> &board ){
      for (int i=0; i < board.size(); ++i){
	for (int j=0; j <board[0].size(); ++j){
	  cout<<board[i][j];
	}
	cout<<endl;
      }
    }

    bool helper_check(vector <vector <char>> &board ){
      for (int i=0; i < board.size(); ++i){
	for (int j=0; j <board[0].size(); ++j){
	  if(board[i][j]=='.'){
	    return false;
	  }
	}
      }
      return true;
    }
    void  re_skudo (    vector <vector <char>> &board  , bool &terminate_flag  ){
      helper(board);
      if (terminate_flag==true){
	return;
      }
      if (helper_check(board)){
	terminate_flag=true;
	return ;
      }
      for (int i=0 ; i < board.size();i++){
	for(int j=0 ; j <board[0].size(); j++ ){
	  if (board[i][j]=='.'){
	    for (int dot=49; dot <=58; dot++){
	      board[i][j]=dot;
	      
	      if(dot==58){
		board[i][j]='.'; //     roll back 
		return ;
	      }
	      if (check_valid(board, i, j  )){
		re_skudo(board , terminate_flag);
	      }
	      if(terminate_flag==true){
		return;
	      }
	    }
	  }
	}
      }
      return ;
    }

    void solveSudoku(vector<vector<char>>& board) {
      // input valided 

      bool terminate_flag=false;
      re_skudo (   board  , terminate_flag );

#ifdef DEBUG
      for (int  i =0 ; i <board.size() ; i ++){
	for (int j=0 ;j <board[i].size(); j++){
	  cout<<board[i][j];
	}
	cout<<endl;
      }
#endif 
      return ;
    }
};


int main (){
  vector <vector <char>> input = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
  //,{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
  //vector <vector <char>> a = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};


class Solution sol;
sol.solveSudoku( input) ;
return 0;
}
