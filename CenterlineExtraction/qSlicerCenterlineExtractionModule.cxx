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

// Qt includes
#include <QtPlugin>

// CenterlineExtraction Logic includes
//#include "vtkSlicerCenterlineExtractionModuleLogic.h"

// CenterlineExtraction includes
#include "qSlicerCenterlineExtractionModule.h"
#include "qSlicerCenterlineExtractionModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerCenterlineExtractionModule, qSlicerCenterlineExtractionModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerCenterlineExtractionModulePrivate
{
public:
  qSlicerCenterlineExtractionModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerCenterlineExtractionModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerCenterlineExtractionModulePrivate
::qSlicerCenterlineExtractionModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerCenterlineExtractionModule methods

//-----------------------------------------------------------------------------
qSlicerCenterlineExtractionModule
::qSlicerCenterlineExtractionModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerCenterlineExtractionModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerCenterlineExtractionModule::~qSlicerCenterlineExtractionModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerCenterlineExtractionModule::helpText()const
{
  return "This loadable module facilitates python access of VMTK classes for centerline extraction";
}

//-----------------------------------------------------------------------------
QString qSlicerCenterlineExtractionModule::acknowledgementText()const
{
  return "This work was was partially funded by NIH grant 3P41RR013218-12S1";
}

//-----------------------------------------------------------------------------
QStringList qSlicerCenterlineExtractionModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Pietro Nardelli & Alberto Corvo (University College Cork)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerCenterlineExtractionModule::icon()const
{
  return QIcon(":/Icons/CenterlineExtraction.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerCenterlineExtractionModule::categories() const
{
  return QStringList() << "Endoscopy";
}

//-----------------------------------------------------------------------------
QStringList qSlicerCenterlineExtractionModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerCenterlineExtractionModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerCenterlineExtractionModule
::createWidgetRepresentation()
{
  return new qSlicerCenterlineExtractionModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerCenterlineExtractionModule::createLogic()
{
  //return vtkSlicerCenterlineExtractionModuleLogic::New();
  return 0;
}
