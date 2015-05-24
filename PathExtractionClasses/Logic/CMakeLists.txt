project(vtkSlicer${MODULE_NAME}ModuleLogic)

set(KIT ${PROJECT_NAME})

set(${KIT}_EXPORT_DIRECTIVE "VTK_SLICER_${MODULE_NAME_UPPER}_MODULE_LOGIC_EXPORT")

set(${KIT}_INCLUDE_DIRECTORIES
  )

set(${KIT}_SRCS
  vtkSlicer${MODULE_NAME}CenterlineSmoothingLogic.h
  vtkSlicer${MODULE_NAME}CenterlineSmoothingLogic.cxx
  vtkSlicer${MODULE_NAME}InternalTetrahedraExtractorLogic.cxx
  vtkSlicer${MODULE_NAME}InternalTetrahedraExtractorLogic.h
  vtkSlicer${MODULE_NAME}MinHeapLogic.cxx
  vtkSlicer${MODULE_NAME}MinHeapLogic.h
  vtkSlicer${MODULE_NAME}NonManifoldFastMarchingLogic.cxx
  vtkSlicer${MODULE_NAME}NonManifoldFastMarchingLogic.h
  vtkSlicer${MODULE_NAME}NonManifoldSteepestDescentLogic.cxx
  vtkSlicer${MODULE_NAME}NonManifoldSteepestDescentLogic.h
  vtkSlicer${MODULE_NAME}PolyDataCenterlinesLogic.cxx
  vtkSlicer${MODULE_NAME}PolyDataCenterlinesLogic.h
  vtkSlicer${MODULE_NAME}SimplifyVoronoiDiagramLogic.cxx
  vtkSlicer${MODULE_NAME}SimplifyVoronoiDiagramLogic.h
  vtkSlicer${MODULE_NAME}SteepestDescentLineTracerLogic.cxx
  vtkSlicer${MODULE_NAME}SteepestDescentLineTracerLogic.h
  vtkSlicer${MODULE_NAME}VoronoiDiagram3DLogic.cxx
  vtkSlicer${MODULE_NAME}VoronoiDiagram3DLogic.h
  )

set(${KIT}_TARGET_LIBRARIES
  ${ITK_LIBRARIES}
  )

#-----------------------------------------------------------------------------
SlicerMacroBuildModuleLogic(
  NAME ${KIT}
  EXPORT_DIRECTIVE ${${KIT}_EXPORT_DIRECTIVE}
  INCLUDE_DIRECTORIES ${${KIT}_INCLUDE_DIRECTORIES}
  SRCS ${${KIT}_SRCS}
  TARGET_LIBRARIES ${${KIT}_TARGET_LIBRARIES}
  )