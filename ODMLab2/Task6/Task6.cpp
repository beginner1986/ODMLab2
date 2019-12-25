#include <iostream>
#include "Point.h"

// TASK 6: class templates - inheritance

int main()
{
	Point2D<int> intPoint2D(0, 0);
	intPoint2D.setY(3);
	intPoint2D.print();

	Point2D<double> doublePoint2D(2.5, 1.2);
	doublePoint2D.setY(3.14);
	doublePoint2D.print();

	Point3D<int> intPoint3D(3, 2, 1);
	intPoint3D.setY(5);
	intPoint3D.print();

	Point3D<double> doublePoint3D(3.4, 2.2, 1.9);
	doublePoint3D.print();

	Entity entity(8.5, 3.6, 'O');
	entity.print();

	return 0;
}
