#include <iostream>
#include "Vector.h"
#include "RayDataStructure.h"

std::ostream& operator<<(std::ostream &flux, const Vector& v )
{
    v.print(flux);
    return flux;
}

int main()
{
	Vector test(1,2,3);
	Vector test2(1,2,4);
	RayDataStructure ray(&test,&test2);
	ray.print();
	test2.setX(3);
	ray.print();
	//test2.add(0,0,1.5);
	//test.multiply(1.1);
//	if (test==test2)
//	{
//	    std::cout << test.module();
//	}
}


