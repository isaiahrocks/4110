/*
Author: Miguel Martinez
CSCE 4110
Program 4

I modified this from a previous Dijksta's assignment in 3110, however the previous implementation was NOT the 
adjacency matrix implementation
*/
#include <fstream>
#include <iostream>
#include <ctime>

// Number of vertices in the graph
#define V 1000
#define INF 99999

int minDist(int dist[], bool shortestPath[], int numVert);
int printSolution(int dist[], int n, int s);
//int printSolution(int dist[], int n, int s, int parent[]);
int dijkstra(int adjMat[V][V], int src, int numVert);
//void printPath(int parent[], int j);

int main(int argc, char *argv[])
{
	int adjMat[V][V];
	double total = 0;
	int numVert;
	int a, b, w;
 
  //file i/o stuff
	std::ifstream infile;
	infile.open(argv[1]);
	infile >> numVert;
 
  	for(int i = 0; i < numVert; i++) //initializing graph
	{
		for (int j = 0; j < numVert; j++)
		{
			adjMat[i][j] = 0;
		}
	}
 
	while (true) //reading in from input file
	{
		infile >> a >> b >> w;
    //std::cout << "a: " << a << " b: " << b << " w: " << w << std::endl;
		adjMat[a][b] = w;
    		//adjMat[b][a] = w;
    //std::cout << "graph[a][b] = " << graph[a][b] << "***graph[b][a] = " << graph[b][a] << std::endl;
		if (infile.eof()){ break; }
	}

 /* std::cout << "\n\n\n";
  for(int i = 0; i < numVert ; i++)
  {
    for(int j = 0; j < numVert; j++)
    {
      std::cout << adjMat[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << "\n\n\n";*/
	
  //looping through all vertices
	std::cout << "Vertex\tDistance";
	for(int i = 0; i < numVert; i++)
	{
		//std::cout << "source: " << i << std::endl;
		total += dijkstra(adjMat, i, numVert);
		std::cout << std::endl;
	}
	
	std::cout << "Total Processor Time: " << total << std::endl;
	//std::cout << (end_t - start_t)/double(CLOCKS_PER_SEC)*1000 << std::endl;
  
 
  std::cout << std::endl;

	return 0;
}

//find minimum distance
int minDist(int dist[], bool shortestPath[], int numVert)
{
	// Initialize min value
	int min = INF, min_index;

	for (int i = 0; i < numVert; i++)
	{
		if (shortestPath[i] == false && dist[i] <= min)
		{
			min = dist[i], min_index = i;
		}
	}
	return min_index;
}


//implements dijkstra's
int dijkstra(int adjMat[V][V], int src, int numVert)
{
	int start_t = clock();
	int dist[V]; //output array that holds distances 
	bool shortestPath[V];
  //int parent[V];

	//initializing generic array values
	for (int i = 0; i < numVert; i++)
	{
    //parent[src] = -1;
		dist[i] = INF;
		shortestPath[i] = false;
	}
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < numVert-1; count++)
	{
		// Pick the minimum distance vertex from the set
		int temp = minDist(dist, shortestPath, numVert);

		// Mark the picked vertex as visited
		shortestPath[temp] = true;

		// Update dist values
		for (int i = 0; i < numVert; i++)
		{
			//updating dist[i] according to rules
			if (!shortestPath[i] && adjMat[temp][i] && dist[temp] != INF && dist[temp] + adjMat[temp][i] < dist[i])
			{
        //parent[i] = temp;
				dist[i] = dist[temp] + adjMat[temp][i];
			}
		}
	}
	int end_t = clock();

	

	// print the constructed distance array
	printSolution(dist, numVert, src);
 	return (end_t - start_t)/double(CLOCKS_PER_SEC)*1000;
  //this was used to debug and make sure distances are correct
  //printSolution(dist, numVert, src, parent);
}

//printing distances from "source" vertex to all other vertices it's attached to (add ,parent[] at end to enable path output
int printSolution(int dist[], int n, int s)
{
	int src = s;
	//printf("Vertex\t Distance\tPath");
	for (int i = 0; i < n; i++)
	{
		std::cout << "\n" << src << "-> " << i << " \t\t " << dist[i];
    //printPath(parent, i);
	}
   

}


//this was used to check correctness of distances, uncomment all "parent[]" code in other functions to enable
/*void printPath(int parent[], int j)
{
	// Base Case : If j is source
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

  std::cout << ' ' << j << ' ';
}*/
