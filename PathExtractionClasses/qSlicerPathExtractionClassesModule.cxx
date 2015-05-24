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

// VMTKFunctionalities Logic includes
//#include "vtkSlicerPathExtractionClassesModuleLogic.h"

// PathExtractionClasses includes
#include "qSlicerPathExtractionClassesModule.h"
#include "qSlicerPathExtractionClassesModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerPathExtractionClassesModule, qSlicerPathExtractionClassesModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerPathExtractionClassesModulePrivate
{
public:
  qSlicerPathExtractionClassesModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerPathExtractionClassesModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerPathExtractionClassesModulePrivate
::qSlicerPathExtractionClassesModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerPathExtractionClassesModule methods

//-----------------------------------------------------------------------------
qSlicerPathExtractionClassesModule
::qSlicerPathExtractionClassesModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerPathExtractionClassesModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerPathExtractionClassesModule::~qSlicerPathExtractionClassesModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerPathExtractionClassesModule::helpText()const
{
  return "This loadable module facilitates python access of VMTK classes for centerline extraction";
}

//-----------------------------------------------------------------------------
QString qSlicerPathExtractionClassesModule::acknowledgementText()const
{
  return "This work was was partially funded by NIH grant 3P41RR013218-12S1";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPathExtractionClassesModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Pietro Nardelli & Alberto Corvo (University College Cork)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerPathExtractionClassesModule::icon()const
{
  return QIcon(":/Icons/PathExtractionClasses.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerPathExtractionClassesModule::categories() const
{
  return QStringList() << "Endoscopy";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPathExtractionClassesModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerPathExtractionClassesModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerPathExtractionClassesModule
::createWidgetRepresentation()
{
  return new qSlicerPathExtractionClassesModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerPathExtractionClassesModule::createLogic()
{
  //return vtkSlicerPathExtractionClassesModuleLogic::New();
  return 0;
}
