#include "./cylinder.h"
#include <iostream>

using namespace std;
using namespace cadex;

ModelData_Face MakeCircularFace(const ModelData_Point& thePos, const ModelData_Direction& theDir, const ModelData_Edge& theBoundary)
{
	ModelData_Axis3Placement a3Axis(thePos, theDir, XDir);
	ModelData_Plane aPlane(a3Axis);
	ModelData_Face aFace(aPlane);

	ModelData_Wire aWire(theBoundary);
	aFace.Append(aWire);
	return aFace;
}

ModelData_Face MakeCylindricalFace(const ModelData_Point& thePos, const ModelData_Direction& theDir, double theRadius, double theLength,
										   ModelData_Edge& theTopEdge, ModelData_Edge& theBottomEdge,
										   ModelData_Curve& theTopPCurve, ModelData_Curve& theBottomPCurve)
{
	ModelData_Axis3Placement a3Axis (thePos, theDir, XDir);
	ModelData_CylindricalSurface aSurface (a3Axis, theRadius);
	ModelData_Face aFace(aSurface, 0, M_PI * 2 , 0, theLength);

	const ModelData_Wire& aWire = aFace.OuterWire();
	ModelData_Shape::Iterator anIt (aWire, ModelData_ST_Edge);
	while (anIt.HasNext()) {
		ModelData_Edge anEdge = ModelData_Edge::Cast (anIt.Next());
		ModelData_Point aP1 = anEdge.EndVertex().Point();
		ModelData_Point aP2 = anEdge.StartVertex().Point();
		if (aP1 == aP2) {
			array<double, 2> aParameters = {{0., M_PI * 2}};
			enum {First, Last};
			if (aP1.Z() == (theLength * theDir.Z())) {
				theTopEdge = anEdge;
				theTopPCurve = anEdge.Curve (aParameters[First], aParameters[Last]);
			} else {
				theBottomEdge = anEdge;
				theBottomPCurve = anEdge.Curve (aParameters[First], aParameters[Last]);
			}
		};
	}

	return aFace;
}

ModelData_BRepRepresentation CreateCylinder(double aRadius, double aLength)
{
	double aMajorRadius = aRadius * 1.3;

	// Cylindrical faces and their edges
	ModelData_Edge aTopEdge, aBottomEdge;
	ModelData_Curve aTopPCurve, aBottomPCurve;
	ModelData_Face aFace1 = MakeCylindricalFace (ModelData_Point (0., 0., 0.), ZDir, aRadius, aLength,
		aTopEdge, aBottomEdge,
		aTopPCurve, aBottomPCurve);
	// Top circle
	ModelData_Face aFace2 = MakeCircularFace(ModelData_Point (0., 0., aLength), ZDir, ModelData_Edge::Cast(aTopEdge.Reversed()));
	// Bottom circle
	ModelData_Face aFace3 = MakeCircularFace(ModelData_Point (0., 0., 0), ZDirR, ModelData_Edge::Cast(aBottomEdge.Reversed()));
 
	ModelData_Shell aShell;
	aShell.Append(aFace1);
	aShell.Append(aFace2);
	aShell.Append(aFace3);

	ModelData_Solid aSolid(aShell);

	// Check the cylinder
	ModelCheck_BRepChecker aChecker;
	aChecker.Check(aSolid);
	if (!aChecker.HasProblems()) {
		cout << "Succesfully created a cylinder" << endl;
	} else {
		cout << "Cylinder creation failed" << endl;
	}
	ModelData_BRepRepresentation aBRep(aSolid);

	return aBRep;
}