#include <limits.h>
#include <fstream>
#include <iostream>
#include <ctime>

#define V 1000
#define INF 99999

int getTimeSpentFW(int adjMat[][V], int numVert);
void printSol(int dist[][V], int numVert);

int main(int argc, char *argv[])
{
  int adjMat[V][V];
  int numVert, a, b, w;
  double totalTimeSpent = 0;
  
  std::ifstream infile;
	infile.open(argv[1]);
	infile >> numVert;
	//std::cout << numVert << std::endl;
  	for(int i = 0; i < numVert; i++) //initializing graph
		{
			for (int j = 0; j < numVert; j++)
			{
				if(i != j)
				{				
					adjMat[i][j] = INF;
				}
				else
				{
					adjMat[i][j] = 0;
				}
			}
		}
 
	//std::cout << "after first for" << std::endl;
  	while (!infile.eof()) //reading in from input file
		{
			infile >> a >> b >> w;
			
			adjMat[a][b] = w;
    		//adjMat[b][a] = w;
		}
 
	//std::cout << "after while" << std::endl;
  /*std::cout << "\n\n\n";
  for(int i = 0; i < numVert ; i++)
	{
    for(int j = 0; j < numVert; j++)
    {
      std::cout << adjMat[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << "\n\n\n";*/
  

  	std::cout << "Vertex\tDistance\n";
		totalTimeSpent = getTimeSpentFW(adjMat, numVert);
		std::cout << "Total Processor Time: " << totalTimeSpent << std::endl;
  	return 0;
}


int getTimeSpentFW(int adjMat[][V], int numVert)
{
	int start_t = clock();
	int dist[V][V]; //holds output
	
	for(int i = 0; i < numVert; i++)
	{
		for(int j = 0; j < numVert; j++)
		{
			dist[i][j] = adjMat[i][j];
			//making distance array same as input
			//distance array is updated later
      
		}
	}
	//std::cout << "after dist initializing" << std::endl;
	for(int k = 0; k < numVert; k++) //this is literally the O(n^3) algorithm from the book :^)
	{
		for(int i = 0; i < numVert; i++)
		{
			for(int j = 0; j < numVert; j++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					//this pretty much just says if the vertex k is on shortest path, update dist[i][j]
          //std::cout << std::endl<< "dist[" << i << "][" << j << "] = " << dist[i][j] << " being replaced with " << dist[i][k] + dist[k][j] << std::endl;
					dist[i][j] = dist[i][k] + dist[k][j];
					//std::cout << "in O(n^3) for" << std::endl;
          
				}
			}
		}
	} 

	int end_t = clock();
	//std::cout << "before print" << std::endl;
	printSol(dist, numVert);
	return (end_t - start_t)/double(CLOCKS_PER_SEC)*1000;
}

void printSol(int dist[][V], int numVert)
{
	//std::cout << std::endl << std::endl;
	//std::cout << "in print" << std::endl;
	for(int i = 0; i < numVert; i++)
	{
		for(int j = 0; j < numVert; j++)
		{
			std::cout << i << "-> " << j << "\t\t" << dist[i][j] << std::endl;
			//std::cout << dist[i][j] << " ";
		}
   std::cout << std::endl;
	}
 
  /*for(int i = 0; i < numVert; i++)
  {
    for(int j = 0; j < numVert; j++)
    {
      std::cout << dist[i][j] << "\t";
    }
    std::cout << std::endl;
  }  
  std::cout << std::endl;*/
 
}
