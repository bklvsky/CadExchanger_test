#include "./cylinder.h"

#include <iostream>
#include <string.h>

#include "/usr/local/cadexchanger/3.9.2/examples/cxx/cadex_license.cxx"

using namespace std;
using namespace cadex;

void WriteToSTL(ModelData_Model aModel, Base_UTF16String fileName) 
{
	STL_Writer aWriter;
	STL_WriterParameters aWriterParam = aWriter.Parameters();

	if (!aWriter.Transfer(aModel) || !aWriter.WriteFile (fileName)) {
		cout << "Unable to save the model " << fileName << endl;
	}
}

ModelData_Model createModel(ModelData_PolyRepresentation aPolyRep)
{
	ModelData_Part aCylinder (aPolyRep, "Cylinder");
	ModelData_Model aModel;
	ModelData_Instance anInstance(aCylinder);
	aModel.AddRoot (anInstance);
	return aModel;
}

int countTriangles(ModelData_PolyRepresentation aPolyRep)
{
	ModelData_PolyShapeList aList = aPolyRep.Get();

	// no need to iterate through all the list
	//as the polyrepresentation consists from one solid
	const ModelData_PolyVertexSet& aPVS = aList[0]; 

	if (aPVS.IsOfType<ModelData_IndexedTriangleSet>()) {  // fool-proof checking for the right type
		const auto& anITS = static_cast<const ModelData_IndexedTriangleSet&>(aPVS);
		return anITS.NumberOfFaces();
	}
	return -1;
}

ModelData_PolyRepresentation createTriangulation(ModelData_BRepRepresentation bRep)
{
	ModelAlgo_BRepMesherParameters aParam;
	aParam.SetAngularDeflection(ANGULAR_DEFLECTION);
	aParam.SetChordalDeflection(CHORDAL_DEFLECTION);

	ModelAlgo_BRepMesher aMesher(aParam);
	return aMesher.Compute(bRep, true);
}

int main(int argc, char **argv)
{
	auto aKey = LicenseKey::Value();
	if (argc != 4) {
		cout << "Usage: " << endl
			<< "cylinder [radius] [height] [name_of_file_wo_extension]" << endl
			<< "Example: cylinder 1.5 5.2 my_cylinder" << endl;
		return 1;
	}

	// Activate the license (aKey must be defined in cadex_license.cxx)
	if (!CADExLicense_Activate (aKey)) {
		cerr << "Failed to activate CAD Exchanger license." << endl;
		return 1;
	}

	// Initial Parameters
	double aRadius = atof(argv[1]);
	double aHeight = atof(argv[2]);
	if (aRadius <= 0 || aHeight <= 0) {
		cout << "Radius should be a positive number." << endl;
		return 1;
	}
	char *aFileName = strcat(argv[3], ".stl");

	// Create shapes
	ModelData_BRepRepresentation aCylinder = CreateCylinder(aRadius, aHeight);

	// Create a triangulation
	ModelData_PolyRepresentation aPolyRep = createTriangulation(aCylinder);

	// Compute number of triangles
	int theTrianglesNumber = countTriangles(aPolyRep);
	cout << "Model contains " << theTrianglesNumber << " triangles" << endl;

	//Create a model
	ModelData_Model aModel = createModel(aPolyRep);

	// Save the result:
	WriteToSTL(aModel, aFileName);

	return 0;
}