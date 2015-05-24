/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "qSlicerPathExtractionClassesFooBarWidget.h"
#include "ui_qSlicerPathExtractionClassesFooBarWidget.h"

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_PathExtractionClasses
class qSlicerPathExtractionClassesFooBarWidgetPrivate
  : public Ui_qSlicerPathExtractionClassesFooBarWidget
{
  Q_DECLARE_PUBLIC(qSlicerPathExtractionClassesFooBarWidget);
protected:
  qSlicerPathExtractionClassesFooBarWidget* const q_ptr;

public:
  qSlicerPathExtractionClassesFooBarWidgetPrivate(
    qSlicerPathExtractionClassesFooBarWidget& object);
  virtual void setupUi(qSlicerPathExtractionClassesFooBarWidget*);
};

// --------------------------------------------------------------------------
qSlicerPathExtractionClassesFooBarWidgetPrivate
::qSlicerPathExtractionClassesFooBarWidgetPrivate(
  qSlicerPathExtractionClassesFooBarWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerPathExtractionClassesFooBarWidgetPrivate
::setupUi(qSlicerPathExtractionClassesFooBarWidget* widget)
{
  this->Ui_qSlicerPathExtractionClassesFooBarWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerPathExtractionClassesFooBarWidget methods

//-----------------------------------------------------------------------------
qSlicerPathExtractionClassesFooBarWidget
::qSlicerPathExtractionClassesFooBarWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerPathExtractionClassesFooBarWidgetPrivate(*this) )
{
  Q_D(qSlicerPathExtractionClassesFooBarWidget);
  d->setupUi(this);
}

//-----------------------------------------------------------------------------
qSlicerPathExtractionClassesFooBarWidget
::~qSlicerPathExtractionClassesFooBarWidget()
{
}
