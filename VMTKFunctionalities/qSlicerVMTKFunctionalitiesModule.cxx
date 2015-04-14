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
//#include "vtkSlicerVMTKFunctionalitiesModuleLogic.h"

// VMTKFunctionalities includes
#include "qSlicerVMTKFunctionalitiesModule.h"
#include "qSlicerVMTKFunctionalitiesModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerVMTKFunctionalitiesModule, qSlicerVMTKFunctionalitiesModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerVMTKFunctionalitiesModulePrivate
{
public:
  qSlicerVMTKFunctionalitiesModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerVMTKFunctionalitiesModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerVMTKFunctionalitiesModulePrivate
::qSlicerVMTKFunctionalitiesModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerVMTKFunctionalitiesModule methods

//-----------------------------------------------------------------------------
qSlicerVMTKFunctionalitiesModule
::qSlicerVMTKFunctionalitiesModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerVMTKFunctionalitiesModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerVMTKFunctionalitiesModule::~qSlicerVMTKFunctionalitiesModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerVMTKFunctionalitiesModule::helpText()const
{
  return "This loadable module facilitates python access of VMTK classes for centerline extraction";
}

//-----------------------------------------------------------------------------
QString qSlicerVMTKFunctionalitiesModule::acknowledgementText()const
{
  return "This work was was partially funded by NIH grant 3P41RR013218-12S1";
}

//-----------------------------------------------------------------------------
QStringList qSlicerVMTKFunctionalitiesModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Pietro Nardelli & Alberto Corvo (University College Cork)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerVMTKFunctionalitiesModule::icon()const
{
  return QIcon(":/Icons/VMTKFunctionalities.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerVMTKFunctionalitiesModule::categories() const
{
  return QStringList() << "Endoscopy";
}

//-----------------------------------------------------------------------------
QStringList qSlicerVMTKFunctionalitiesModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerVMTKFunctionalitiesModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerVMTKFunctionalitiesModule
::createWidgetRepresentation()
{
  return new qSlicerVMTKFunctionalitiesModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerVMTKFunctionalitiesModule::createLogic()
{
  //return vtkSlicerVMTKFunctionalitiesModuleLogic::New();
  return 0;
}
