
/*Easymode code is related from the line
 In A2, I use the MinMax(which is using minimax) to AI move less, but for the easymode,I erase the condition "int thisScore = -MinMax(board, player*-1);" in the MinMax, so that AI can move as they want. The code is related to
 line 306: void humantocomputer() -> get the level, operation code
 line 255: void computerturneasy(int board[9]) -> set a board format
 line 235: int MinMaxeasy(int board[9], int player) ->make AI to move
 line
*/

#include <iostream>
#include <random>
#include <cmath>

using namespace std;
//initalization
int step=0;
int place=0;
char player;
void board();
int result =3;
char cell[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};//make a 10 empty array

//print board for human to human
void printboard(){
    // print out the board
    cout << cell[1] << "  | " << cell[2] << " | " << cell[3] << endl;
    cout << "---|---|--- " << endl;
    cout << cell[4] << "  | " << cell[5] << " | " << cell[6] << endl;
    cout << "---|---|---" << endl;
    cout << cell[7] << "  | " << cell[8] << " | " << cell[9] << endl;
}

void checkwin(){//return 1 Someone win, -1 game is in progress, 0 draw
    if(cell[1]==cell[2] && cell[2]==cell[3]&&cell[1]!=' '){//when the horizontal is same without empty character
        result= 1;
    }
    else if(cell[4]==cell[5] && cell[5]==cell[6]&&cell[4]!=' '){
        result= 1;
    }
    else if(cell[7]==cell[8] && cell[8]==cell[9]&&cell[7]!=' '){
        result= 1;
    }
    else if(cell[1]==cell[4] && cell[4]==cell[7]&&cell[1]!=' '){
        result= 1;
    }
    else if(cell[2]==cell[5] && cell[5]==cell[8]&&cell[2]!=' '){
        result= 1;
    }
    else if(cell[3]==cell[6] && cell[6]==cell[9]&&cell[3]!=' '){
        result= 1;
    }
    else if(cell[1]==cell[5] && cell[5]==cell[9]&&cell[1]!=' '){
        result= 1;
    }
    else if(cell[3]==cell[5] && cell[5]==cell[7]&&cell[3]!=' '){
        result= 1;
    }
    else if (cell[1] != ' ' && cell[2] != ' ' && cell[3] != ' '
      && cell[4] != ' ' && cell[5] != ' ' && cell[6] != ' '
             && cell[7] != ' ' && cell[8] != ' ' && cell[9] != ' '){
        result = 0;
    }
    else{//when does not make a line or does not fill out all cell
        result = -1;
    }
}
void printstate(){//to express which state is it by each term.
    if (result == -1){
        cout<< "Game is still in process"<<endl;
    }
    else if (result == 0){
        cout<< "Draw";
        step = 10;//to exit the while loop
    }
    else if (result == 1){
        cout <<(player)<<" win the game!";
        step = 10;//to exit the while loop
    }
}


void board() { // to print the board
    // replace cell[place] terems to the player which is O or X
    if (place == 1)
        cell[1] = player;
    else if (place == 2)
        cell[2] = player;
    else if (place == 3)
        cell[3] = player;
    else if (place == 4)
        cell[4] = player;
    else if (place == 5)
        cell[5] = player;
    else if (place == 6)
        cell[6] = player;
    else if (place == 7)
        cell[7] =player;
    else if (place == 8)
        cell[8] = player;
    else if (place == 9)
        cell[9] = player;
    printboard();
    checkwin();
    printstate();
}


void humantohumangame(){
    char cell[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};//make a 10 empty array
    int player1num=0; int player2num=0;
    cout <<"Now Roll the dice to choose the turn."<<endl;
    cout <<"Number who has a greater will play first and Mark is O"<<endl;
    cout << "Let's Roll the dice!"<<endl;
    
    //Roll the dice(choose random number between 1 to 6)
    player1num = rand()%6+1;
    cout << "Player1 number is:";
    cout << player1num<<endl;
    
    player2num = rand()%6+1;
    cout << "Player2 number is:";
    cout << player2num<<endl;
    
    // if the random number is same, roll the dice again until it is different
    while (player1num == player2num){
        cout<<"Roll the dice again!\n";
        player1num = rand()%6+1;
        player2num = rand()%6+1;
        cout << "Player1 number is:";
        cout << player1num<<endl;
        cout << "Player2 number is:";
        cout << player2num<<endl;
    }
    if(player1num > player2num){
        cout<< "Player 1 play first, and mark is O\n";
    }
    else if(player1num < player2num){
        cout<< "Player 2 play first mark is O\n";
    }
    
        
            player = 'O';

            while (step < 9) { // step starts from the 0 and repeat it until step is 8 because step 8 will show 9th term. Then end of the while loop when step is 9.
                
                if (player == 'O') {
                    cout << "Please enter the cell of ID for your move from 1 to 9: ";
                    cin >> place;
                    step++;  // increase step by 1
                    board();
                    
                    cout << "Now is X turns:􏰑"; //previous players was O so next turn should be X turn.
                    player ='X';
                    if (player != 'X'){
                        cout << "Error: it is the X's turn.\n"<<endl; //print out the error message if it is same as previous
                        cout << "􏰃􏰓􏰑􏰊􏰔􏰑Please enter X: 􏰑";
                        cin >> player;
                        }
                }
                    
                else if (player == 'X') { //if player is not a O turn which is X turn
                    cout << "Please enter the cell of ID for your move: ";
                    cin >> place;
                    step++;
                    board();

                    cout << "It's O turn:􏰑"; //previous players was X so next turn should be O turn.
                    player='O';
                    if (player != 'O'){
                        cout << "Error: it is the O's turn.\n"<<endl;
                        cout << "􏰃􏰓􏰑􏰊􏰔􏰑Please enter O: 􏰑";
                        cin >> player;
                    }
                }
            }
    cout << "The end"<<endl;
}

char location(int i) {
    switch(i){
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
    return 0;
}

void draw(int cell1[9]) {
    cout << location(cell1[0])<<" | "<<location(cell1[1])<<" | "<< location(cell1[2])<<endl;
    cout<< "--|---|--"<<endl;
    cout << location(cell1[3])<<" | "<<location(cell1[4])<<" | "<< location(cell1[5])<<endl;
    cout<< "--|---|--"<<endl;
    cout << location(cell1[6])<<" | "<<location(cell1[7])<<" | "<< location(cell1[8])<<endl;
}

int win(const int board[9]) {
    //To know whether it is win, return 0 when it is loose
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};//possible cases to win
    int i;
    for(i = 0; i < 8; ++i) { //out of 8 cases
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

int MinMax(int board[9], int player) { //Make AI to move more
    int winner = win(board);
    if(winner != 0) return winner*player;//when it is not in the process, return

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    
    for(i = 0; i < 9; ++i) {//In all move step
        if(board[i] == 0) {//If it is a illegal
            board[i] = player;//try to move
            int thisScore = -MinMax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }//Pick the one that's worst for the opponent
            board[i] = 0;//Reset the board after try
        }
    }
    if(move == -1) return 0;
    return score;
}

int MinMaxeasy(int board[9], int player) {
    int winner = win(board);
    if(winner != 0) return winner*player;//when it is not in the process, return

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    
    for(i = 0; i < 9; ++i) {//In all move step
        if(board[i] == 0) {//If it is a illegal
            board[i] = player;//try to move
            move=i;//Pick the one that's worst for the opponent
            board[i] = 0;//Reset the board after try
        }
    }
    if(move == -1) return 0;
    return score;
}


void computerturneasy(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {// for 9 term
        if(board[i] == 0) {
            board[i] = 1;
            
            int tempScore = -MinMaxeasy(board, -1);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax tree at a given node.
    board[move] = 1;
}

void computerturnhard(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {// for 9 term
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore = -MinMax(board, -1);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax tree at a given node.
    board[move] = 1;
}

void playerturn(int board[9]) {
    int move = 0;
    int enternumb =0;
    do {
        cout<< "Game is on the process";
        cout<<"\nPlease enter the cell of ID for your move from 1 to 9:";
        cin >> enternumb;
        move = enternumb-1;
    } while (move >= 9 || (move < 0 && board[move] == 0));
    board[move] = -1;
}

void humantocomputer(){
    int board[9] = {0}; //initalize the board with 0
    int level;
    cout<<"Press 0:Easy or 1:Hard\n";
    cin>> level;
    while (!(level == 0 || level == 1 )){//if input is not 0 or 1, rewrite the input
        cout<<"Error: Rewrite the level again";
        cin >> level;
    }
    cout<<"You are X, Computer is O. You play first"<<endl;
    int player =1;
    int step;
    for(step = 0; step < 9 && win(board) == 0; ++step) { //for loop when less than 9 step, and game is on process
        if((step+player) % 2 == 0){
            if (level == 1){computerturnhard(board);
            }
            else if (level ==0){
                computerturneasy(board);
            }
        }
        else {
            draw(board);
            playerturn(board);
        }
    }
    switch(win(board)) {
        case 0:
            draw(board);
            cout<<"A game is draw! Go to step2!\n"<<endl;
            break;
        case 1:
            draw(board);
            cout<<"You lose the game. Restart the game again\n"<<endl;
            break;
        case -1:
            draw(board);
            cout<<"Congratulations! You win the game! Go to step2.\n"<<endl;
            break;
    }
}

void sysc1(){//When typing a first system command
    int sysc1; //system command
    cout <<"\nPress 0 human vs computer or press 1 human vs human (each other):\n";
    cin>>sysc1;
    while (!(sysc1 == 0|| sysc1 == 1 )){
        cout<<"Error: Rewrite the system code again\n";
        cin >> sysc1;
    }
    if (sysc1 ==0){ // if operation command is 1, go to humantocomputer() function
        humantocomputer();
    }
    else if (sysc1 == 1){
        humantohumangame();
    }
}

void howtoplay(){//instruction
    cout<< "\n<How to play Tic Tac Toc>"<<endl;
    cout << "The board is 3 by 3"<<endl;
    cout << "Choose only one number and mark down on the board"<<endl;
    cout<<"Then next player also choose one number and mark it in"<<endl;
    cout << "Turns are alternative"<<endl;
    cout<<"Do not choose repeated number!\n"<<endl;
    cout <<"<Who will win the game?>"<<endl;
    cout<< "A person who fill out straight line win the game."<<endl;
    cout<< "Straight can be in vertical, horizontal, or diagonal"<<endl;
    cout<< "When all 9 squares are full, the game is over!"<<endl;
    
    cout <<"Here is what the game board looks like the IDs of each cell:"<<endl; // print the initial
            cout << " 1 | 2 | 3 "<<endl;
            cout << "---|---|--- "<<endl;
            cout << " 4 | 5 | 6 "<<endl;
            cout << "---|---|--- "<<endl;
            cout << " 7 | 8 | 9 \n"<<endl;
}


void sysc(){//When typing a first system command
    int sysc; //system command
    cout <<"Press 0 to exit the game or 1 to beginning the game:";
    cin>>sysc;
    while (!(sysc == 0 || sysc == 1 )){//if input is not 0 or 1, rewrite the input
        cout<<"Error: Rewrite the system code again";
        cin >> sysc;
    }
    if (sysc ==0){
        cout<<"Exit programme. Thank You.\n";
    }
    else {
        howtoplay(); //show the instruuction
        sysc1(); // select ssecond operation command
    }
}


void WelcomeMessage(){
    cout<<"Welcome to play Tic Tac Toe!"<<endl; //print welcoming meessage
    sysc();
}

void ResetBoard(){//reset the board when humantohuman function
    for (int i=0;i<=10;i++)
    cell[i]=' ';
}
int main(){
    for (int a=0;a>=0;a++){//infinite loop
        WelcomeMessage();
        ResetBoard();
        step =0;
    }
}
