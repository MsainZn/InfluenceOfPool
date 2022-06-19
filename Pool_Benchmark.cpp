#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pool_tst.h"
#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>

int main()
{
	
	std::clock_t c_start1;
	std::clock_t c_end1;

	// Declaring A Simple BST
	struct BSTNode* CVALS1;
	
	double DT1 = 0;
	
	for (size_t i = 0; i < 100; i++)
	{
		c_start1 = std::clock();

		// Create BST Node As Soon As We Require It We Do It For A Million Times In Our Code
		for (size_t i = 0; i < 1e6; i++)
			CVALS1 = (struct BSTNode*) calloc(1, sizeof(struct BSTNode));
		
		c_end1 = std::clock();
		DT1 += (static_cast <double> (c_end1) - static_cast <double> (c_start1)) / static_cast <double> (CLOCKS_PER_SEC);
		std::cout <<  i << " -> "<< std::fixed << std::showpoint << std::setprecision(8) << (static_cast <double> (c_end1) - static_cast <double> (c_start1))/ static_cast <double> (CLOCKS_PER_SEC) << std::endl;

	}
	
	std::cout << std::fixed << std::showpoint << std::setprecision(8) <<  "Elapsed time in Sec: " << DT1/100 << std::endl;
		
	

	struct BSTNode* CVALS2;
	std::clock_t c_start2;
	std::clock_t c_end2;
	double DT2 = 0;

	for (size_t i = 0; i < 100; i++)
	{
		c_start2 = std::clock();

		// Create A Million Elements (Pool Of BST) For Future Use
		CVALS2 = (struct BSTNode*) calloc(1e6, sizeof(struct BSTNode));

		c_end2 = std::clock();
		DT2 += (static_cast <double> (c_end2) - static_cast <double> (c_start2)) / static_cast <double> (CLOCKS_PER_SEC);
		std::cout << i << " -> " << std::fixed << std::showpoint << std::setprecision(8) << (static_cast <double> (c_end2) - static_cast <double> (c_start2)) / static_cast <double> (CLOCKS_PER_SEC) << std::endl;

	}

	std::cout << std::fixed << std::showpoint << std::setprecision(8) << "Elapsed time in Sec: " << DT2 / 100 << std::endl;


	std::cout << DT1 / DT2 << std::endl;


}

