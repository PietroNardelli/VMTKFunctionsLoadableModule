/*=========================================================================

Program:   VMTK
Module:    $RCSfile: vtkSlicerPathExtractionClassesMinHeapLogic.cxx,v $
Language:  C++
Date:      $Date: 2006/04/06 16:46:43 $
Version:   $Revision: 1.3 $

  Copyright (c) Luca Antiga, David Steinman. All rights reserved.
  See LICENCE file for details.

  Portions of this code are covered under the VTK copyright.
  See VTKCopyright.txt or http://www.kitware.com/VTKCopyright.htm 
  for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "vtkSlicerPathExtractionClassesMinHeapLogic.h"
#include "vtkDoubleArray.h"
#include "vtkIdList.h"
#include "vtkObjectFactory.h"
#include "vtkvmtkConstants.h"

//vtkCxxRevisionMacro(vtkSlicerPathExtractionClassesMinHeapLogic, "$Revision: 1.3 $");
vtkStandardNewMacro(vtkSlicerPathExtractionClassesMinHeapLogic);

vtkSlicerPathExtractionClassesMinHeapLogic::vtkSlicerPathExtractionClassesMinHeapLogic()
{
  this->MinHeapScalars = NULL;
  this->Heap = vtkIdList::New();
  this->BackPointers = vtkIdList::New();
}

vtkSlicerPathExtractionClassesMinHeapLogic::~vtkSlicerPathExtractionClassesMinHeapLogic()
{
  if (this->MinHeapScalars)
    {
    this->MinHeapScalars->Delete();
    this->MinHeapScalars = NULL;
    }

  this->Heap->Delete();
  this->BackPointers->Delete();
}

void vtkSlicerPathExtractionClassesMinHeapLogic::Initialize()
{
  vtkIdType i;

  if (this->MinHeapScalars == NULL)
    {
    vtkErrorMacro(<< "No HeapScalars.");
    return;
    }

  this->Heap->Initialize();
  this->BackPointers->Initialize();
  vtkIdType numberOfScalars;
  numberOfScalars = this->MinHeapScalars->GetNumberOfTuples();
  this->BackPointers->SetNumberOfIds(numberOfScalars);
  for (i=0; i<numberOfScalars; i++)
    {
    this->BackPointers->SetId(i,-1);
    }
}

void vtkSlicerPathExtractionClassesMinHeapLogic::InsertNextId(vtkIdType id)
{
  if (this->MinHeapScalars == NULL)
    {
    vtkErrorMacro(<< "No MinHeapScalars.");
    return;
    }

  vtkIdType numberOfScalars;
  numberOfScalars = this->MinHeapScalars->GetNumberOfTuples();

  if ((id<0)||(id>=numberOfScalars))
    {
    vtkErrorMacro(<< "Id inserted exceeds MinHeapScalars dimension.");
    return;
    }

  vtkIdType currentLoc;

  currentLoc = this->Heap->InsertNextId(id);
  this->BackPointers->InsertId(id,currentLoc);

  this->SiftUp(currentLoc);

  while (this->BackPointers->GetNumberOfIds() < numberOfScalars)
    {
    this->BackPointers->InsertNextId(-1);
    }

  if (this->BackPointers->GetNumberOfIds() < numberOfScalars)
    {
    this->BackPointers->SetNumberOfIds(numberOfScalars);
    }
}

int  vtkSlicerPathExtractionClassesMinHeapLogic::GetSize()
{
  return this->Heap->GetNumberOfIds();
}

void vtkSlicerPathExtractionClassesMinHeapLogic::UpdateId(vtkIdType id)
{
  if (this->MinHeapScalars == NULL)
    {
    vtkErrorMacro(<<"No MinHeapScalars.");
    return;
    }

  if ((id<0)||(id>=this->MinHeapScalars->GetNumberOfTuples()))
    {
    vtkErrorMacro(<<"Id inserted exceeds MinHeapScalars dimension.");
    return;
    }

  this->SiftUp(this->BackPointers->GetId(id));

}

int vtkSlicerPathExtractionClassesMinHeapLogic::IsLeaf(vtkIdType loc)
{
  vtkIdType heapSize;
  heapSize = this->Heap->GetNumberOfIds();

  if ((loc<0)||(loc>=heapSize))
    {
    vtkErrorMacro(<<"Heap smaller than requested location.");
    return -1;
    }

  if ((loc >= heapSize/2)&&(loc < heapSize))
    return 1;

  return 0;
}

vtkIdType vtkSlicerPathExtractionClassesMinHeapLogic::GetLeftChild(vtkIdType loc)
{
  vtkIdType heapSize;
  heapSize = this->Heap->GetNumberOfIds();

  if ((loc<0)||(loc>=heapSize))
    {
    vtkErrorMacro(<<"Heap smaller than requested location.");
    return -1;
    }

  if (loc >= heapSize/2)
    return -1;

  return 2*loc + 1;
}

vtkIdType vtkSlicerPathExtractionClassesMinHeapLogic::GetRightChild(vtkIdType loc)
{
  vtkIdType heapSize;
  heapSize = this->Heap->GetNumberOfIds();

  if ((loc<0)||(loc>=heapSize))
    {
    vtkErrorMacro(<< "Heap smaller than requested location.");
    return -1;
    }

  if (loc >= (heapSize-1)/2)
    return -1;

  return 2*loc + 2;
}

vtkIdType vtkSlicerPathExtractionClassesMinHeapLogic::GetParent(vtkIdType loc)
{
  if (loc<0)
    {
    vtkErrorMacro(<<"Negative location requested.");
    return -1;
    }

  if (loc==0)
    return -1;

  return (loc-1)/2;
}

void vtkSlicerPathExtractionClassesMinHeapLogic::SiftUp(vtkIdType loc)
{
  if (this->MinHeapScalars == NULL)
    {
    vtkErrorMacro(<<"No MinHeapScalars.");
    return;
    }

  vtkIdType heapSize;
  heapSize = this->Heap->GetNumberOfIds();

  if ((loc<0)||(loc>=heapSize))
    {
    vtkErrorMacro(<<"Heap smaller than requested location.");
    return;
    }

  vtkIdType parentLoc;

  while (loc>0) 
    {
    parentLoc = this->GetParent(loc);

    if (this->MinHeapScalars->GetValue(this->Heap->GetId(loc)) - this->MinHeapScalars->GetValue(this->Heap->GetId(parentLoc)) > VTK_VMTK_DOUBLE_TOL)
      {
      return;
      }

    this->Swap(loc,parentLoc);
    loc = parentLoc;
    }
}

void vtkSlicerPathExtractionClassesMinHeapLogic::SiftDown(vtkIdType loc)
{
  if (this->MinHeapScalars == NULL)
    {
    vtkErrorMacro(<<"No MinHeapScalars.");
    return;
    }

  vtkIdType heapSize;
  heapSize = this->Heap->GetNumberOfIds();

  if ((loc<0)||(loc>=heapSize))
    {
    vtkErrorMacro(<<"Heap smaller than requested location.");
    return;
    }

  vtkIdType minChildLoc, leftChildLoc, rightChildLoc;

  while (!this->IsLeaf(loc))
    {
    leftChildLoc = this->GetLeftChild(loc);
    rightChildLoc = leftChildLoc + 1;

    minChildLoc = leftChildLoc;
    if ((leftChildLoc<this->Heap->GetNumberOfIds()-1) && 
        (this->MinHeapScalars->GetValue(this->Heap->GetId(leftChildLoc)) - this->MinHeapScalars->GetValue(this->Heap->GetId(rightChildLoc))) > VTK_VMTK_DOUBLE_TOL)
      {
      minChildLoc = rightChildLoc;
      }

    if (this->MinHeapScalars->GetValue(this->Heap->GetId(loc)) - this->MinHeapScalars->GetValue(this->Heap->GetId(minChildLoc)) < -VTK_VMTK_DOUBLE_TOL)
      {
      return;
      }

    this->Swap(loc,minChildLoc);

    loc = minChildLoc;
    }
}

vtkIdType vtkSlicerPathExtractionClassesMinHeapLogic::RemoveMin()
{
  vtkIdType minId, lastElementLoc;

  minId = this->Heap->GetId(0);
  lastElementLoc = this->Heap->GetNumberOfIds()-1;
  this->Swap(0,lastElementLoc);
  this->Heap->SetNumberOfIds(lastElementLoc);
  this->BackPointers->SetId(minId,-1);

  if (this->Heap->GetNumberOfIds()>0)
    {
    this->SiftDown(0);
    }

  return minId;
}

vtkIdType vtkSlicerPathExtractionClassesMinHeapLogic::GetMin()
{
  vtkIdType minId;

  minId = this->Heap->GetId(0);

  return minId;
}

vtkIdType vtkSlicerPathExtractionClassesMinHeapLogic::RemoveAt(vtkIdType loc)
{
  vtkIdType heapSize;
  heapSize = this->Heap->GetNumberOfIds();

  if ((loc<0)||(loc>=heapSize))
    {
    vtkErrorMacro(<<"Heap smaller than requested location.");
    return -1;
    }

  vtkIdType locId, lastElementLoc;

  locId = this->Heap->GetId(loc);
  lastElementLoc = heapSize-1;
  this->Swap(locId,lastElementLoc);
  this->Heap->SetNumberOfIds(lastElementLoc);
  this->BackPointers->SetId(locId,-1);

  if (this->Heap->GetNumberOfIds()>0)
    this->SiftDown(loc);

  return locId;
}

void vtkSlicerPathExtractionClassesMinHeapLogic::Swap(vtkIdType loc0, vtkIdType loc1)
{
  vtkIdType temp;

  vtkIdType heapSize;
  heapSize = this->Heap->GetNumberOfIds();

  if ((heapSize<loc0)||(heapSize<loc1))
    {
    vtkErrorMacro(<<"Heap smaller than requested location.");
    return;
    }

  temp = this->Heap->GetId(loc0);
  this->Heap->SetId(loc0,this->Heap->GetId(loc1));
  this->Heap->SetId(loc1,temp);

  this->BackPointers->SetId(this->Heap->GetId(loc0),loc0);
  this->BackPointers->SetId(this->Heap->GetId(loc1),loc1);
}

void vtkSlicerPathExtractionClassesMinHeapLogic::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
