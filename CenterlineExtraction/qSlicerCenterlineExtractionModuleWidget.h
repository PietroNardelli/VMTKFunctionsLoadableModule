/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qSlicerCenterlineExtractionModuleWidget_h
#define __qSlicerCenterlineExtractionModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerCenterlineExtractionModuleExport.h"

class qSlicerCenterlineExtractionModuleWidgetPrivate;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_CENTERLINEEXTRACTION_EXPORT qSlicerCenterlineExtractionModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerCenterlineExtractionModuleWidget(QWidget *parent=0);
  virtual ~qSlicerCenterlineExtractionModuleWidget();

public slots:


protected:
  QScopedPointer<qSlicerCenterlineExtractionModuleWidgetPrivate> d_ptr;
  
  virtual void setup();

private:
  Q_DECLARE_PRIVATE(qSlicerCenterlineExtractionModuleWidget);
  Q_DISABLE_COPY(qSlicerCenterlineExtractionModuleWidget);
};

#endif
