#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <time.h>



class Map{


public:
	int filas;
	int columnas;
	std::vector< std::vector<int> > v;

	Map(int nfilas, int ncol);
	void drawMap();
	void step();



};

Map::Map(int nfilas, int ncol){
	filas = nfilas;
	columnas = ncol;
	v.resize(filas);
	for(unsigned int i = 0; i < v.size(); ++i)
		v[i].resize(columnas);

	for( int j = 0; j < filas; ++j){

		for( int k = 0; k < columnas; ++k)
			v[j][k] = rand()%2;

	}



}


void Map::drawMap(){

	for( int i =0; i< filas; ++i){
		for( int j =0; j< columnas; ++j){
			if(v[i][j] ==1)
				std::cout << "#";
			else
				std::cout << "-";
		}
		std::cout << "\n";
	}
}


void Map::step(){
	unsigned int numVecinos;
	std::vector< std::vector<int> > aux = v;
	for( int i =0; i< filas-1; ++i){

		for( int j =0; j< columnas-1; ++j){
            numVecinos = 0;
			if((i-1 >= 0) && (j-1 >0))
				if(v[i-1][j-1] == 1)
					numVecinos++;
			if(i-1 >= 0)
				if(v[i-1][j] ==1)
					numVecinos++;
			if((i-1 >=0 ) && (j+1 <=columnas-1))
				if(v[i-1][j+1] ==1)
					numVecinos++;
			if(j+1 <= columnas-1)
				if(v[i][j+1]==1)
					numVecinos++;
			if(j-1 >=0)
				if(v[i][j-1] == 1)
					numVecinos++;
			if((i+1<= filas-1) && (j+1 <= columnas-1) )
				if(v[i+1][j+1] ==1)
					numVecinos++;
			if(i+1 <= filas-1)
				if(v[i+1][j] ==1)
					numVecinos++;
			if((i+1<= filas-1) &&(j-1 >= 0))
				if(v[i+1][j-1] == 1)
					numVecinos++;

			if (v[i][j] ==0){
				if(numVecinos == 3){
					aux[i][j] = 1;
				}

			}

			if (v[i][j] == 1){
				if(numVecinos !=2 || numVecinos !=3)
					aux[i][j] = 0;
			}


		}




	}

	std::swap(v,aux);



}


int main()
{
	/* code */
	srand(time(0));
	Map m(20,20);
	while(true){
        usleep(10000);
		m.drawMap();
		usleep(10000);
		m.step();
		system("CLS");

	}

	return 0;
}
