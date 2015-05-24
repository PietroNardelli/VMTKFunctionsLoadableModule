/*=========================================================================
Program:   VTK Blood Vessel Smoothing
Module:    $RCSfile: vtkSlicerPathExtractionClassesCenterlineSmoothingLogic.h,v $
Language:  C++
Date:      $Date: 2006/07/17 09:52:56 $
Version:   $Revision: 1.1 $
  Copyright (c) Luca Antiga, David Steinman. All rights reserved.
  See LICENCE file for details.
  Portions of this code are covered under the VTK copyright.
  See VTKCopyright.txt or http://www.kitware.com/VTKCopyright.htm 
  for details.
     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.
=========================================================================*/
  // .NAME vtkSlicerPathExtractionClassesCenterlineSmoothingLogic - ...
  // .SECTION Description
  // ...

#ifndef __vtkSlicerPathExtractionClassesCenterlineSmoothingLogic_h
#define __vtkSlicerPathExtractionClassesCenterlineSmoothingLogic_h

#include "vtkPolyDataAlgorithm.h"
#include "vtkSlicerPathExtractionClassesModuleLogicExport.h"

// STD includes
#include <cstdlib>

class vtkDoubleArray;

class VTK_SLICER_PATHEXTRACTIONCLASSES_MODULE_LOGIC_EXPORT vtkSlicerPathExtractionClassesCenterlineSmoothingLogic 
	: public vtkPolyDataAlgorithm
{
  public: 
  vtkTypeMacro(vtkSlicerPathExtractionClassesCenterlineSmoothingLogic,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent); 

  static vtkSlicerPathExtractionClassesCenterlineSmoothingLogic* New();

  vtkSetMacro(SmoothingFactor,double);
  vtkGetMacro(SmoothingFactor,double);

  vtkSetMacro(NumberOfSmoothingIterations,int);
  vtkGetMacro(NumberOfSmoothingIterations,int);

  static void SmoothLine(vtkPoints* linePoints, vtkPoints* smoothLinePoints, int numberOfIterations = 10, double relaxation = 0.1);

  protected:
  vtkSlicerPathExtractionClassesCenterlineSmoothingLogic();
  ~vtkSlicerPathExtractionClassesCenterlineSmoothingLogic();  

  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  double SmoothingFactor;
  int NumberOfSmoothingIterations;

  private:
  vtkSlicerPathExtractionClassesCenterlineSmoothingLogic(const vtkSlicerPathExtractionClassesCenterlineSmoothingLogic&);  // Not implemented.
  void operator=(const vtkSlicerPathExtractionClassesCenterlineSmoothingLogic&);  // Not implemented.
};

#endif
