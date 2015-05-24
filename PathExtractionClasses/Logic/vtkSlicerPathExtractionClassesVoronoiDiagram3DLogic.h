/*=========================================================================

Program:   VMTK
Module:    $RCSfile: vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic.h,v $
Language:  C++
Date:      $Date: 2006/04/06 16:46:43 $
Version:   $Revision: 1.4 $

  Copyright (c) Luca Antiga, David Steinman. All rights reserved.
  See LICENCE file for details.

  Portions of this code are covered under the VTK copyright.
  See VTKCopyright.txt or http://www.kitware.com/VTKCopyright.htm 
  for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
  // .NAME vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic - Compute the Voronoi diagram of a set of points in 3D.
  // .SECTION Description
  // This class computes the Voronoi diagram of a set of points given their Delaunay tessellation. Basically, the output points are Delaunay tetrahedra circumcenters, and the cells are convex polygons constructed by connecting circumcenters of tetrahedra sharing a face. The radius of the circumsphere associated with each circumcenter is stored in a point data array with name specifed by RadiusArrayName. The id list of poles is also provided. Poles are the farthest inner and outer Voronoi points associated with a Delaunay point. Since this class is meant to deal with Delaunay tessellations which are internal to a given surface, only the internal pole is considered for each input point.

#ifndef __vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic_h
#define __vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic_h

#include "vtkPolyDataAlgorithm.h"
#include "vtkIdList.h"
#include "vtkCellArray.h"
//#include "vtkvmtkComputationalGeometryWin32Header.h"
#include "vtkSlicerPathExtractionClassesModuleLogicExport.h"

class vtkUnstructuredGrid;

class VTK_SLICER_PATHEXTRACTIONCLASSES_MODULE_LOGIC_EXPORT vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic : public vtkPolyDataAlgorithm
{
  public: 
  vtkTypeMacro(vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent); 

  static vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic *New();

  //  vtkSetMacro(BuildLines,int);
  //  vtkGetMacro(BuildLines,int);
  //  vtkBooleanMacro(BuildLines,int);

  // Description:
  // Set/Get the name of the point data array where circumsphere radius values are stored.
  vtkSetStringMacro(RadiusArrayName);
  vtkGetStringMacro(RadiusArrayName);

  // Description:
  // Get the id list of poles. The id list has the same size as input points. For every input point, one Voronoi point id is stored in the list.
  vtkGetObjectMacro(PoleIds,vtkIdList);

  protected:
  vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic();
  ~vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic();  

  int FillInputPortInformation(int, vtkInformation *info);

  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  void ExtractUniqueEdges(vtkUnstructuredGrid* input, vtkCellArray* edgeArray);
  void BuildVoronoiPolys(vtkUnstructuredGrid* input, vtkCellArray* voronoiPolys);
  void BuildVoronoiLines() {};   // not yet implemented

  int BuildLines;
  vtkIdList* PoleIds;
  char* RadiusArrayName;

  private:
  vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic(const vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic&);  // Not implemented.
  void operator=(const vtkSlicerPathExtractionClassesVoronoiDiagram3DLogic&);  // Not implemented.
};

#endif
