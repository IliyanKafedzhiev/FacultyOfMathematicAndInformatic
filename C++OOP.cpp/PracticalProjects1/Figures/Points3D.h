#ifndef POINTS3D_H
#define POINTS3D_H

struct Points3D
{
	int x;
	int y;
	int z;
	Points3D& operator-(const Points3D&) const;
	Points3D();
	Points3D(int x, int y, int z);
};

#endif // !POINTS3D_H