#ifndef MEDIANA_H
#define MEDIANA_H

#include <iostream>
#include "PriorityQueue.h"

class comparaMayor{
public:
	bool operator()(int n1, int n2){
		return n1 > n2;
	}
};

class Mediana{
private:
	PriorityQueue<int, comparaMayor> colaMenores;
	PriorityQueue<int> colaMayores;
	int media;

public:
	Mediana() : media(0){}

	void push(int n, int pos){
		if (media == 0){
			media = n;
		}
		else{
			if (pos % 2 == 0){
				if (n > media){
					colaMayores.push(n);
					colaMenores.push(media);
				}
				else{
					colaMenores.push(n);
					colaMayores.push(media);
				}
			}
			else{
				if (n > media){
					colaMayores.push(n);
					media = colaMayores.top();
					colaMayores.pop();
				}
				else{
					colaMenores.push(n);
					media = colaMenores.top();
					colaMenores.pop();
				}
			}
		}
	}

	int getMedia(int pos){
		if (pos % 2 == 0)
			return colaMenores.top() + colaMayores.top();
		else
			return 2 * media;
	}
};

#endif