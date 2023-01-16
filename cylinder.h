#pragma once

#include <cadex/ModelData_Curve.hxx>
#include <cadex/ModelData_Plane.hxx>
#include <cadex/ModelAlgo_BRepMesher.hxx>
#include <cadex/ModelAlgo_BRepMesherParameters.hxx>
#include <cadex/ModelData_BRepRepresentation.hxx>
#include <cadex/ModelData_Face.hxx>
#include <cadex/ModelData_IndexedTriangleSet.hxx>
#include <cadex/ModelData_Part.hxx>
#include <cadex/ModelData_PolyRepresentation.hxx>
#include <cadex/LicenseManager_Activate.h>
#include <cadex/ModelAlgo_BRepFeatures.hxx>
#include <cadex/ModelCheck_BRepChecker.hxx>
#include <cadex/ModelData_PolyShapeList.hxx>
#include <cadex/ModelData_Axis3Placement.hxx>
#include <cadex/ModelData_BRepRepresentation.hxx>
#include <cadex/ModelData_CylindricalSurface.hxx>
#include <cadex/ModelData_Direction.hxx>
#include <cadex/ModelData_Edge.hxx>
#include <cadex/ModelData_Face.hxx>
#include <cadex/ModelData_Instance.hxx>
#include <cadex/ModelData_Part.hxx>
#include <cadex/ModelData_Point.hxx>
#include <cadex/ModelData_Shape.hxx>
#include <cadex/ModelData_Shell.hxx>
#include <cadex/ModelData_Solid.hxx>
#include <cadex/ModelData_Vector.hxx>
#include <cadex/ModelData_Vertex.hxx>
#include <cadex/ModelData_Wire.hxx>
#include <cadex/STL_WriterParameters.hxx>
#include <cadex/STL_Writer.hxx>
#include <cadex/ModelData_PolyVertexSet.hxx>

using namespace cadex;

#define ANGULAR_DEFLECTION (M_PI * 30 / 180)
#define CHORDAL_DEFLECTION 0.003

const ModelData_Direction XDir  = ModelData_Direction::XDir(),
								 YDir  = ModelData_Direction::YDir(),
								 ZDir  = ModelData_Direction::ZDir(),
								 XDirR = ModelData_Direction (-1.,  0.,  0.),
								 YDirR = ModelData_Direction ( 0., -1.,  0.),
								 ZDirR = ModelData_Direction ( 0.,  0., -1.);

ModelData_BRepRepresentation CreateCylinder(double aRadius, double aLength);
