#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include "Eigen/Eigen"

namespace PolyhedralLibrary 
{
	struct PolyhedralMesh
	{
		int NumCell0Ds = 0; // numero di Cell0D
		std::vector<int> Cell0DsId = {}; // id vertici, (1 x NumCell0D)
		Eigen::MatrixXd Cell0DsCoordinates = {}; // coordinate dei punti, (3 x NumCell0D - (x,y,z))
		std::map<int, std::list<int>> ShortPathCell0Ds = {};

		int NumCell1Ds = 0; // numero di Cell1D
		std::vector<int> Cell1DsId = {}; // id lati, (1 x NumCell1D)
		Eigen::MatrixXi Cell1DsExtrema = {}; // estremi dei lati, (2 x NumCell1D) (fromId,toId)
		std::map<int, std::list<int>> ShortPathCell1Ds = {};

		int NumCell2Ds = 0; // numero di Cell2D
		std::vector<int> Cell2DsId = {}; // id poligoni, (1 x NumCell2D)
		std::vector<std::vector<int>> Cell2DsVertices = {}; // id vertici del poligono, (1 x NumCell2DVertices[NumCell2D])
		std::vector<std::vector<int>> Cell2DsEdges = {}; // id lati del poligono, (1 x NumCell2DEdges[NumCell2D])
		
		int NumCell3Ds = 0; // numero di Cell3D
		std::vector<int> Cell3DsId = {}; // id poligoni, (1 x NumCell3D)
		std::vector<std::vector<int>> Cell3DsVertices = {}; // id vertici del poligono, (1 x NumCell3DVertices[NumCell3D])
		std::vector<std::vector<int>> Cell3DsEdges = {}; // id lati del poligono, (1 x NumCell3DEdges[NumCell3D])
		std::vector<std::vector<int>> Cell3DsFaces = {}; // id facce del poligono, (1 x NumCell3Faces[NumCell3D])
	};
}