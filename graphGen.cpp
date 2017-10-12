#include <stdlib.h>
#include <time.h>
#include <iostream>

#define MAXVERT 1000
#define MINVERT 50

void generateGraph(int numVert, int maxWgt);
int main()
{
	int numVert;
	int maxWgt = 15;
	srand(time(NULL));
	numVert = rand()%(MAXVERT-MINVERT + 1) + MINVERT;

	//numVert = 10;

	generateGraph(numVert, maxWgt);
	/*for(int i = 0; i < 10; i++)
	{
		numVert = rand()%(MAXVERT-MINVERT + 1) + MINVERT;
		std::cout << numVert << std::endl;
	}*/ 
	
	/*for(int i = 0; i < numVert; i++)
	{
		for(int j = 0; j < numVert; j++)
		{
			if(i != j)
			{
				std::cout << i <<" " <<  j << " " << rand()%(maxWgt+1)+0 << "\n";
			}
		}	
	}*/
}

void generateGraph(int numVert, int maxWgt)
{
	std::cout << numVert << std::endl;
	for(int i = 0; i < numVert; i++)
	{
		for(int j = 0; j < numVert; j++)
		{
			if(i != j)
			{
				std::cout << i << " " << j << " " << rand()%(maxWgt+1)+1 << "\n";
			}
			else
			{
				std::cout << i << " " << j << " " << "0\n";
			}
		}
	}

}
