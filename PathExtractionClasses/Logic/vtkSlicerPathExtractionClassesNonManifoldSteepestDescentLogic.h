/*=========================================================================

Program:   VMTK
Module:    $RCSfile: vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic.h,v $
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
  // .NAME vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic - Abstract class for steepest descent on a polygonal non-manifold.
  // .SECTION Description
  // This class is an abstract filter used as base class for performing steepest descent on a non-manifold surface made of convex polygons (such as the Voronoi diagram) on the basis of a given scalar field. Steepest descent is performed on the edges of input polygons with a first order approximation.
  //
  // .SECTION See Also
  // vtkSteepestDescentLineTracer vtkSurfaceToCenterlines vtkVoronoiDiagram3D

#ifndef __vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic_h
#define __vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic_h

#include "vtkPolyDataAlgorithm.h"
#include "vtkDataArray.h"
//#include "vtkvmtkComputationalGeometryWin32Header.h"
#include "vtkSlicerPathExtractionClassesModuleLogicExport.h"

#define VTK_VMTK_DOWNWARD 0
#define VTK_VMTK_UPWARD 1

class VTK_SLICER_PATHEXTRACTIONCLASSES_MODULE_LOGIC_EXPORT vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic : public vtkPolyDataAlgorithm
{
  public:
  vtkTypeMacro(vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent); 

  static vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic *New();

  // Description:
  // Set/Get the name of the point data array used as the descent scalar field.
  vtkSetStringMacro(DescentArrayName);
  vtkGetStringMacro(DescentArrayName);

  vtkSetMacro(Direction,int);
  vtkGetMacro(Direction,int);
  void SetDirectionToDownward() 
  {this->SetDirection(VTK_VMTK_DOWNWARD); }
  void SetDirectionToUpward() 
  {this->SetDirection(VTK_VMTK_UPWARD); }

  protected:
  vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic();
  ~vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic();

  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  // Description:
  // Compute the steepest descent point in terms of edge (point id pair) and parametric coordinate on edge. It takes in input a starting point expressed in terms of edge (point id pair) and parametric coordinate on edge. It returns the descent value.
  double GetSteepestDescent(vtkPolyData* input, vtkIdType* edge, double s, vtkIdType* steepestDescentEdge, double &steepestDescentS);
  double GetSteepestDescentInCell(vtkPolyData* input, vtkIdType cellId, vtkIdType* edge, double s, vtkIdType* steepestDescentEdge, double &steepestDescentS, double &steepestDescentLength);

  vtkDataArray* DescentArray;
  char* DescentArrayName;

  int NumberOfEdgeSubdivisions;
  int Direction;

  private:
  vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic(const vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic&);  // Not implemented.
  void operator=(const vtkSlicerPathExtractionClassesNonManifoldSteepestDescentLogic&);  // Not implemented.
};

#endif

