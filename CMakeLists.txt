cmake_minimum_required(VERSION 2.8.9)

project(BronchoscopyNavigation)

#-----------------------------------------------------------------------------
set(EXTENSION_HOMEPAGE "http://www.slicer.org/slicerWiki/index.php/Documentation/4.3/Extensions/BronchoscopyNavigation")
set(EXTENSION_CATEGORY "Endoscopy")
set(EXTENSION_CONTRIBUTORS "Pietro Nardelli & Alberto Corvo (University College Cork)")
set(EXTENSION_DESCRIPTION "lodable module for extraction of the centerline of a 3D model")
set(EXTENSION_ICONURL "http://viewvc.slicer.org/viewvc.cgi/Slicer4/trunk/Extensions/Testing/BronchoscopyNavigation/BronchoscopyNavigation.png?revision=21746&view=co")
set(EXTENSION_SCREENSHOTURLS "http://wiki.slicer.org/slicerWiki/images/4/42/Slicer-r19441-BronchoscopyNavigation-screenshot.png")

#-----------------------------------------------------------------------------
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

#-----------------------------------------------------------------------------
add_subdirectory(CenterlineExtraction)

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_CPACK})
