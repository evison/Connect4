#include <iostream>
#include "Point.h"
#include "Strategy.h"

using namespace std;

/*
	Interface for the Strategy, this function will be called by the Competing platform. Each time the platform give you the current state
	of the chess board, and you are required to output the coordinate on chess board that your strategy want to put the next piece. This
	coordinate must be a valide legal one, or the competing platform will treat you as failed.
	
	input:
		To avoid modifying the data transfered in by the platform, all the variables are const.
		M, N: Size of the board, M is the number of rows, N is the number of columns, starting from 0. The left-top conner of the chess 
			board is treated as origin. We us x to denote row indices, and y for column indices.
		top: The positions of the current column tops, e.g., if the i-th column is empty, then _top[i]==M, and if the i-th column is full,
			then _top[i]==0.
		_board : The current board as a one-dimensional vector. For easy use, we trasform the one-dimensional _board vector to two-dimensional
			vector (matrix) board at the beginning of the function, so you just need to use board. The left-top conner is origin and the matrix
			starts from [0][0] (rather than [1][1]).
			board[x][y] represents the cross of the x-th row and y-th column (indexing from 0 both)
			board[x][y] == 0/1/2 represents that the coordinate (x,y) has no / user's / computer's piece. Note that the forbidden coordinate 
			is also set a 0.
		lastX, lastY : last coordinate that your competitor  put his piece. You may not need this information, or that you may need more than 
			the last one step of your competitor, depending on your own strategy.
		noX, noY: the forbidden coordinate on board. You are not allowed to put pieces on this position, this is to avoid using the solved 
			algorithms for the Connect4 game. (Note: The top vector has actually taken the forbidden coordinate into consideration, namely,
			if any of you or your competitor put a piece on the coordinate right below the forbidden coordinate in some step, then the top vector
			on that column will be automatically minus 1 by the platform, then transfer the vector to you. So you may not take further consideration
			of noX and noY any more, and use the top vector directly and safely. Of course, things will be different if you would like to use the 
			lastX and lastY parameters for more intelligent AI's.)
		The variables above describe both the current state of the board by (M, N, _top, _board) and the chronological historical information by
		(lastX, lastY), what you need to do is to produce the coordinate to put your piece as intelligent as possible.
	output:
		Your coordinate for next piece: an instance of Point class.
		
	策略函数接口,该函数被对抗平台调用,每次传入当前状态,要求输出你的落子点,该落子点必须是一个符合游戏规则的落子点,不然对抗平台会直接认为你的程序有误
	
	input:
		为了防止对对抗平台维护的数据造成更改，所有传入的参数均为const属性
		M, N : 棋盘大小 M - 行数 N - 列数 均从0开始计， 左上角为坐标原点，行用x标记，列用y标记
		top : 当前棋盘每一列列顶的实际位置. e.g. 第i列为空,则_top[i] == M, 第i列已满,则_top[i] == 0
		_board : 棋盘的一维数组表示, 为了方便使用，在该函数刚开始处，我们已经将其转化为了二维数组board
				你只需直接使用board即可，左上角为坐标原点，数组从[0][0]开始计(不是[1][1])
				board[x][y]表示第x行、第y列的点(从0开始计)
				board[x][y] == 0/1/2 分别对应(x,y)处 无落子/有用户的子/有程序的子,不可落子点处的值也为0
		lastX, lastY : 对方上一次落子的位置, 你可能不需要该参数，也可能需要的不仅仅是对方一步的
				落子位置，这时你可以在自己的程序中记录对方连续多步的落子位置，这完全取决于你自己的策略
		noX, noY : 棋盘上的不可落子点(注:其实这里给出的top已经替你处理了不可落子点，也就是说如果某一步
				所落的子的上面恰是不可落子点，那么UI工程中的代码就已经将该列的top值又进行了一次减一操作，
				所以在你的代码中也可以根本不使用noX和noY这两个参数，完全认为top数组就是当前每列的顶部即可,
				当然如果你想使用lastX,lastY参数，有可能就要同时考虑noX和noY了)
		以上参数实际上包含了当前状态(M N _top _board)以及历史信息(lastX lastY),你要做的就是在这些信息下给出尽可能明智的落子点
	output:
		你的落子点Point
*/
extern "C" __declspec(dllexport) Point* getPoint(const int M, const int N, const int* top, const int* _board, 
	const int lastX, const int lastY, const int noX, const int noY){
	/*
		Do NOT modify this section of code
		不要更改这段代码
		Save your selected coordinate in x,y finally 
		最终将你的落子点存到x,y中
	*/
	int x = -1, y = -1;
	int** board = new int*[M];
	for(int i = 0; i < M; i++){
		board[i] = new int[N];
		for(int j = 0; j < N; j++){
			board[i][j] = _board[i * N + j];
		}
	}
	
	/*
		Return your selected coordinate according to your intelligent strategy, namely, choose values for x and y
		There is no specific restrictions on this section of code, you can define and implement your own classes, .h files, .cpp files for your convenience
		根据你自己的策略来返回落子点,也就是根据你的策略完成对x,y的赋值
		该部分对参数使用没有限制，为了方便实现，你可以定义自己新的类、.h文件、.cpp文件
	*/
	//Add your own code below
	
	
	
	/*
		Do NOT modify this section of code
		不要更改这段代码
	*/
	clearArray(M, N, board);
	return new Point(x, y);
}


/*
	the pointer to a Point structure returned by getPoint function is declared in this dll module, 
	to avoid stack errors, one should call this function in external codes to release memory rather
	than deleting the Point structure externally and directly.
	getPoint函数返回的Point指针是在本dll模块中声明的，为避免产生堆错误，应在外部调用本dll中的
	函数来释放空间，而不应该在外部直接delete
*/
extern "C" __declspec(dllexport) void clearPoint(Point* p){
	delete p;
	return;
}

/*
	To clear top and board vectors
	清除top和board数组
*/
void clearArray(int M, int N, int** board){
	for(int i = 0; i < M; i++){
		delete[] board[i];
	}
	delete[] board;
}


/*
	Add your own assistant functions, you can declare your own classes, function, and add new .h and .cpp fies.
	添加你自己的辅助函数，你可以声明自己的类、函数，添加新的.h .cpp文件来辅助实现你的想法
*/
