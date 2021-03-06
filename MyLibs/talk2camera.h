/*
* Copyright 2018 Wenbin Yang <bysin7@gmail.com>
* This file is part of BLITZ (Behavioral Learning In The Zebrafish),
* which is adapted from MindControl (Andrew Leifer et al <leifer@fas.harvard.edu>
* Leifer, A.M., Fang-Yen, C., Gershow, M., Alkema, M., and Samuel A. D.T.,
* 	"Optogenetic manipulation of neural activity with high spatial resolution in
*	freely moving Caenorhabditis elegans," Nature Methods, Submitted (2010).
*
* BLITZ is a free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the license, or
* (at your option) any later version.
*
* Filename: talk2camera.h
* Abstract: this file contains all classes and functions' declarations
*			used in implementing Basler Pylon USB cameras
*
* Current Version: 2.0
* Author: Wenbin Yang <bysin7@gmail.com>
* Modified on: Apr. 28, 2018

* Replaced Version: 1.1
* Author: Wenbin Yang <bysin7@gmail.com>
* Created on: Jan. 1, 2018
*/



#ifndef _GUARD_TALK2CAMERA_H
#define _GUARD_TALK2CAMERA_H
// Include files to use the PYLON API.
#include <pylon/PylonIncludes.h>
#include <pylon/ImageFormatConverter.h>
#include <pylon/usb/BaslerUsbInstantCameraArray.h>
#ifdef PYLON_WIN_BUILD
#	include <pylon/PylonGUI.h>
#endif

// Include standard library
#include <vector>
#include <string>
#include <iostream>

// User-defined macros
#define MAX_CAMERAS 3

/* Define Basler Pylon properties and related methods for a single USB camera */
class CameraData
{
private:
	;// nothing for now
public:
	// methods
	CameraData() // constructor
	{
	
	}
	bool initialize(int nCams, int frameWidth, int frameHeight, int frameRate);
	/* Grab Pylon image from cameras */
	bool grabPylonImg();

	// properties
	Pylon::CDeviceInfo di[MAX_CAMERAS];
	Pylon::CBaslerUsbInstantCameraArray cameras;
	Pylon::CGrabResultPtr  ptrGrabResult;
	Pylon::CPylonImage pylonImg;
	Pylon::CImageFormatConverter formatConverter;
	intptr_t cIdx;// index of camera where the frame is grabbed from 
};





#endif // !_GUARD_TALK2CAMERA_H
