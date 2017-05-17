#include <iostream>
#include "Vector.h"

std::ostream& operator<<(std::ostream &flux, const Vector& v )
{
    v.print(flux);
    return flux;
}

int main()
{
	Vector test(1,2,3);
	Vector test2(1,2,3);
	//test2.add(0,0,1.5);
	//test.multiply(1.1);
	if (test==test2)
	{
	    std::cout << test.module();
	}
}


