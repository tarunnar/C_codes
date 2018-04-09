/* C/C++ program to solve Rat in a Maze problem using
backtracking */
#include<stdio.h>

// Maze size
#define N 4 

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
	// if (x,y outside maze) return false
	if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;

	return false;
}

/* This function solves the Maze problem using Backtracking. It mainly
uses solveMazeUtil() to solve the problem. It returns false if no 
path is possible, otherwise return true and prints the path in the
form of 1s. Please note that there may be more than one solutions, 
this function prints one of the feasible solutions.*/
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { {0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	if(solveMazeUtil(maze, 0, 0, sol) == false)
	{
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol);
	return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x==N-1 && y==N-1){
        sol[x][y]=1;
        return true;
    }
    if(x>=N || x<0 || y>=N || y<0 || maze[x][y]==0)
	{
	    return false;
	}
	if(maze[x][y]){
	    sol[x][y]=1;
	    bool xy=solveMazeUtil(maze,x+1,y,sol) || solveMazeUtil(maze,x,y+1,sol) || solveMazeUtil(maze,x-1,y,sol) || solveMazeUtil(maze,x,y-1,sol);
	    if (xy)
	    {
	        return true;
	    }
	    else{
	        sol[x][y]=0;
	        return false;
	    }
	}
	
}
vector<vector<int,int>>  bfsbasedratinamaze(int maze[N][N] int x,int y){
    vector<vector<int,int>> path(N);
    vector<vector<int>> distance(N);
    int j,i;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            distance[i][j]=INT_MAX;
        }
    }
    path[x][y]=make_pair(-1,-1);
    queue<int,int> que;
    distance[x][y]=1;
    que.push(make_pair(x,y));
    int flag1=0;
    //int flag2=0;
    while(!que.empty()){
        pair<int,int> pr=que.front();
        int p=pr.first;
        int q=pr.second;
        if(p==N-1 && q==N-1){
            flag1=1;
	    
            break;
        }
        if(maze[p+1][q]==1 && p+1<N && p+1>=0 && q<N && q>=0)
	{
	    dis
	} 
        
    }
}

// driver program to test above function
int main()
{
	int maze[N][N] = { {1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};

	solveMaze(maze);
	return 0;
}

