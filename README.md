# 4110
Dijkstra/Floyd Warshall implementation with a dense graph generator

compile with: 
g++ -o dijkstras dijkstras.cpp
g++ -o fw floydWarshall.cpp
g++ -o graph graphGen.cpp

run with:
./graphGen > input.txt
./fw input.txt > fwOut.txt
./dijkstras input.txt > dijOut.txt
