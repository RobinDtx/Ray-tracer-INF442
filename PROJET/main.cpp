#include <iostream>
using namespace std;
#include "Vector.h"
#include "RayDataStructure.h"
#include "Color.h"

std::ostream& operator<<(std::ostream &flux, const Vector& v )
{
    v.print(flux);
    return flux;
}

int main()
{
	Color color(300,80,5);
	color.setRed(260);
	color.print();
	//test2.add(0,0,1.5);
	//test.multiply(1.1);
//	if (test==test2)
//	{
//	    std::cout << test.module();
//	}
}


