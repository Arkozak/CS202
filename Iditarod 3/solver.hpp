#ifndef SOLVER_HPP_
#define SOLVER_HPP_

#include "lists.h"
#include "nodes.hpp"
#include "path.hpp"
#include <random>

class TspSolver
{
public:
	void solveG(CityList& list, CityPath& path);
	void solveR(CityList& list, CityPath& path);

	int RandInt(int high, int low);
};
#endif