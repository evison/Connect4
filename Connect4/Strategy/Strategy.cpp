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
		
	���Ժ����ӿ�,�ú������Կ�ƽ̨����,ÿ�δ��뵱ǰ״̬,Ҫ�����������ӵ�,�����ӵ������һ��������Ϸ��������ӵ�,��Ȼ�Կ�ƽ̨��ֱ����Ϊ��ĳ�������
	
	input:
		Ϊ�˷�ֹ�ԶԿ�ƽ̨ά����������ɸ��ģ����д���Ĳ�����Ϊconst����
		M, N : ���̴�С M - ���� N - ���� ����0��ʼ�ƣ� ���Ͻ�Ϊ����ԭ�㣬����x��ǣ�����y���
		top : ��ǰ����ÿһ���ж���ʵ��λ��. e.g. ��i��Ϊ��,��_top[i] == M, ��i������,��_top[i] == 0
		_board : ���̵�һά�����ʾ, Ϊ�˷���ʹ�ã��ڸú����տ�ʼ���������Ѿ�����ת��Ϊ�˶�ά����board
				��ֻ��ֱ��ʹ��board���ɣ����Ͻ�Ϊ����ԭ�㣬�����[0][0]��ʼ��(����[1][1])
				board[x][y]��ʾ��x�С���y�еĵ�(��0��ʼ��)
				board[x][y] == 0/1/2 �ֱ��Ӧ(x,y)�� ������/���û�����/�г������,�������ӵ㴦��ֵҲΪ0
		lastX, lastY : �Է���һ�����ӵ�λ��, ����ܲ���Ҫ�ò�����Ҳ������Ҫ�Ĳ������ǶԷ�һ����
				����λ�ã���ʱ��������Լ��ĳ����м�¼�Է������ಽ������λ�ã�����ȫȡ�������Լ��Ĳ���
		noX, noY : �����ϵĲ������ӵ�(ע:��ʵ���������top�Ѿ����㴦���˲������ӵ㣬Ҳ����˵���ĳһ��
				������ӵ�����ǡ�ǲ������ӵ㣬��ôUI�����еĴ�����Ѿ������е�topֵ�ֽ�����һ�μ�һ������
				��������Ĵ�����Ҳ���Ը�����ʹ��noX��noY��������������ȫ��Ϊtop������ǵ�ǰÿ�еĶ�������,
				��Ȼ�������ʹ��lastX,lastY�������п��ܾ�Ҫͬʱ����noX��noY��)
		���ϲ���ʵ���ϰ����˵�ǰ״̬(M N _top _board)�Լ���ʷ��Ϣ(lastX lastY),��Ҫ���ľ�������Щ��Ϣ�¸������������ǵ����ӵ�
	output:
		������ӵ�Point
*/
extern "C" __declspec(dllexport) Point* getPoint(const int M, const int N, const int* top, const int* _board, 
	const int lastX, const int lastY, const int noX, const int noY){
	/*
		Do NOT modify this section of code
		��Ҫ������δ���
		Save your selected coordinate in x,y finally 
		���ս�������ӵ�浽x,y��
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
		�������Լ��Ĳ������������ӵ�,Ҳ���Ǹ�����Ĳ�����ɶ�x,y�ĸ�ֵ
		�ò��ֶԲ���ʹ��û�����ƣ�Ϊ�˷���ʵ�֣�����Զ����Լ��µ��ࡢ.h�ļ���.cpp�ļ�
	*/
	//Add your own code below
	
	
	
	/*
		Do NOT modify this section of code
		��Ҫ������δ���
	*/
	clearArray(M, N, board);
	return new Point(x, y);
}


/*
	the pointer to a Point structure returned by getPoint function is declared in this dll module, 
	to avoid stack errors, one should call this function in external codes to release memory rather
	than deleting the Point structure externally and directly.
	getPoint�������ص�Pointָ�����ڱ�dllģ���������ģ�Ϊ��������Ѵ���Ӧ���ⲿ���ñ�dll�е�
	�������ͷſռ䣬����Ӧ�����ⲿֱ��delete
*/
extern "C" __declspec(dllexport) void clearPoint(Point* p){
	delete p;
	return;
}

/*
	To clear top and board vectors
	���top��board����
*/
void clearArray(int M, int N, int** board){
	for(int i = 0; i < M; i++){
		delete[] board[i];
	}
	delete[] board;
}


/*
	Add your own assistant functions, you can declare your own classes, function, and add new .h and .cpp fies.
	������Լ��ĸ�������������������Լ����ࡢ����������µ�.h .cpp�ļ�������ʵ������뷨
*/
