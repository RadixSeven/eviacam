/////////////////////////////////////////////////////////////////////////////
// Name:        cmotioncalibration.h
// Purpose:  
// Author:      Cesar Mauri Loba (cesar at crea-si dot com)
// Modified by: 
// Created:     07/09/2010
// Copyright:   (C) 2008 Cesar Mauri Loba - CREA Software Systems
// 
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////
#pragma once

class wxDialog;

class CMotionCalibration {

public:
	CMotionCalibration();
	~CMotionCalibration();
	bool InitMotionCalibration();
	void ComputeMotionRange (float vx, float vy, bool warnFaceNotDetected);

private:
	void InitValues();
	
	wxDialog * volatile m_pDialog;		
	//unsigned long m_xSpeedBackup, m_ySpeedBackup;
	float m_posXVirt, m_posYVirt;
	float m_posXVirtMax, m_posYVirtMax;
	float m_posXVirtMin, m_posYVirtMin;
	unsigned long m_lastTimestamp;
	enum EState {BEFORE_WAITING_X, WAITING_X, MEASURING_X, BEFORE_WAITING_Y, WAITING_Y, MEASURING_Y, CONFIRMATION, ABORTING, FINISHED};
	EState volatile m_state;
};
