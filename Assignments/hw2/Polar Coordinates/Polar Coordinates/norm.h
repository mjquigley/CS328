///////////////////////////////////////////////////////////////////
/// @file norm.h
/// @author Matthew Quigley CS328 Section A
/// @brief definition of the norm class for polar coordinates
///////////////////////////////////////////////////////////////////
#ifndef norm_h
#define norm_h
#include "polarCoord.hpp"
#include <vector>
#define iterator typename std::vector<PolarCoord<T> >::const_iterator
template<typename T>
class Norm{
	public:
		T operator()(const std::vector<PolarCoord<T> >& set) const{
			T total = T();
			for (iterator iter = set.begin(); iter != set.end(); ++iter){
				total += ~(*iter);
			}
			return total;
		}
};
#endif
