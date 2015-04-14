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
#include <QDebug>

// SlicerQt includes
#include "qSlicerVMTKFunctionalitiesModuleWidget.h"
#include "ui_qSlicerVMTKFunctionalitiesModuleWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerVMTKFunctionalitiesModuleWidgetPrivate: public Ui_qSlicerVMTKFunctionalitiesModuleWidget
{
public:
  qSlicerVMTKFunctionalitiesModuleWidgetPrivate();
};

//-----------------------------------------------------------------------------
// qSlicerVMTKFunctionalitiesModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerVMTKFunctionalitiesModuleWidgetPrivate::qSlicerVMTKFunctionalitiesModuleWidgetPrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerVMTKFunctionalitiesModuleWidget methods

//-----------------------------------------------------------------------------
qSlicerVMTKFunctionalitiesModuleWidget::qSlicerVMTKFunctionalitiesModuleWidget(QWidget* _parent)
  : Superclass( _parent )
  , d_ptr( new qSlicerVMTKFunctionalitiesModuleWidgetPrivate )
{
}

//-----------------------------------------------------------------------------
qSlicerVMTKFunctionalitiesModuleWidget::~qSlicerVMTKFunctionalitiesModuleWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerVMTKFunctionalitiesModuleWidget::setup()
{
  Q_D(qSlicerVMTKFunctionalitiesModuleWidget);
  d->setupUi(this);
  this->Superclass::setup();
}

