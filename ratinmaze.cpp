/* C/C++ program to solve Rat in a Maze problem using
backtracking */
#include<bits/stdc++.h>
using namespace std;
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


vector< vector< pair <int,int> > >  bfsbasedratinamaze(int maze[N][N] ,int x,int y, vector<vector <int> > &distance){
    vector< vector< pair<int,int> > > path(N);
    int i,j;
    for (int i = 0; i < N; ++i)
    {
    	for (int j = 0; j < N; ++j)
    	{
    		path[i].push_back(make_pair(INT_MAX,INT_MAX));
    	}
    }
    path[x][y]=make_pair(-1,-1);
    cout << "path[0][0]="<< path[0][0].first << " "<<path[0][0].second << endl;
    queue<pair <int,int> > que;
    distance[x][y]=0;
    que.push(make_pair(x,y));
    int flag1=0;
    while(!que.empty()){
        pair<int,int> pr=que.front();
        int p=pr.first;
        int q=pr.second;
        if(p==N-1 && q==N-1){
            flag1=1;	    
            break;
        }
        cout << "p=" << p << " q=" << q << endl;
        if(maze[p+1][q]==1 && p+1<N && p+1>=0 && q<N && q>=0 )
		{
			if(distance[p+1][q] > distance[p][q]+1)
			{
				distance[p+1][q] = distance[p][q]+1;
				path[p+1][q]=make_pair(p,q);
			}
			
			if (p+1==N-1 && q==N-1)
			{
				flag1=1;
				break;
			}
			else{
				que.push(make_pair(p+1,q));
			}
			cout <<"p+1 =" << p+1 << " q="<< q << " distance[p+1][q] " <<distance[p+1][q] << "path[p+1][q]=(" << path[p+1][q].first << "," << path[p+1][q].second << ")" << endl;   
		} 
        if(maze[p-1][q]==1 && p-1<N && p-1>=0 && q<N && q>=0 )
		{
			if(distance[p-1][q] > distance[p][q]+1)
			{
				distance[p-1][q] = distance[p][q]+1;
				path[p-1][q]=make_pair(p,q);
			}
			
			if (p-1==N-1 && q==N-1)
			{
				flag1=1;
				break;
			}
			else{
				que.push(make_pair(p-1,q));
			}
			cout <<"p-1 =" << p-1 << " q="<< q << " distance[p-1][q] " <<distance[p-1][q] << "path[p-1][q]=(" << path[p-1][q].first << "," << path[p-1][q].second << ")" << endl;
		}
		if(maze[p][q+1]==1 && p<N && p>=0 && q+1<N && q+1>=0 )
		{
			if(distance[p][q+1] > distance[p][q]+1)
			{
				distance[p][q+1] = distance[p][q]+1;
				path[p][q+1]=make_pair(p,q);
			}
			
			if (p==N-1 & q+1==N-1)
			{
				flag1=1;
				break;
			}
			else{
				que.push(make_pair(p,q+1));
			}
			cout <<"p =" << p << " q+1="<< q+1 << " distance[p][q+1] " <<distance[p][q+1] << "path[p][q+1]=(" << path[p][q+1].first << "," << path[p][q+1].second << ")" << endl;
		}
		if(maze[p][q-1]==1 && p<N && p>=0 && q-1<N && q-1>=0 )
		{
			if(distance[p][q-1] > distance[p][q]+1)
			{
				distance[p][q-1] = distance[p][q]+1;
				path[p][q-1]=make_pair(p,q);
			}
			
			if (p==N-1 & q-1==N-1)
			{
				flag1=1;
				break;
			}
			else{
				que.push(make_pair(p,q-1));
			}
			cout <<"p =" << p << " q-1="<< q-1 << " distance[p][q-1] " <<distance[p][q-1] << "path[p][q-1]=(" << path[p][q-1].first << "," << path[p][q-1].second << ")" << endl;
		}
		que.pop();
    }
    return path;
}

bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { {0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	/*
	if(solveMazeUtil(maze, 0, 0, sol) == false)
	{
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol);
	return true;
	*/
	vector< vector<int> > distance(N);
    int j,i;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            distance[i].push_back(INT_MAX);
        }
    }
	vector<vector<pair<int,int> > > path=bfsbasedratinamaze(maze,0,0,distance);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << '(' << path[i][j].first << ","<<path[i][j].second << ")";	
		}
		cout << endl;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << distance[i][j] << " ";	
		}
		cout << endl;
	}
}

/* A recursive utility function to solve Maze problem */
/*
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
	
}*/


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
