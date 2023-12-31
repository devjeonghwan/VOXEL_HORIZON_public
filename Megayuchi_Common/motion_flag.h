#pragma once

//#include "stdafx.h"


enum MOTION_TYPE_KEYFRAME
{
	MOTION_TYPE_KEYFRAME_ENABLE		=		0x00000000,
	MOTION_TYPE_KEYFRAME_DISABLE	=		0x00000001
};
#define MOTION_TYPE_KEYFRAME_MASK			0x0000000f
#define MOTION_TYPE_KEYFRAME_MASK_INVERSE	0xfffffff0

enum MOTION_TYPE_VERTEX
{
	MOTION_TYPE_VERTEX_DISABLE		=		0x00000000,
	MOTION_TYPE_VERTEX_ENABLE		=		0x00000010
};
#define MOTION_TYPE_VERTEX_MASK				0x000000f0
#define MOTION_TYPE_VERTEX_MASK_INVERSE		0xffffff0f

enum MOTION_TYPE_UV
{
	MOTION_TYPE_UV_DISABLE			=		0x00000000,
	MOTION_TYPE_UV_ENABLE			=		0x00000100,
};
#define MOTION_TYPE_UV_MASK					0x00000f00
#define MOTION_TYPE_UV_MASK_INVERSE			0xfffff0ff



class CMotionFlags
{

	DWORD				m_dwFlags;

public:
	MOTION_TYPE_KEYFRAME	GetMotionTypeKeyFrame() {return (MOTION_TYPE_KEYFRAME)(m_dwFlags & MOTION_TYPE_KEYFRAME_MASK);}
	void					SetMotionTypeKeyFrame(MOTION_TYPE_KEYFRAME type) {m_dwFlags = (m_dwFlags & MOTION_TYPE_KEYFRAME_MASK_INVERSE) | type;}

	MOTION_TYPE_VERTEX		GetMotionTypeVertex() {return (MOTION_TYPE_VERTEX)(m_dwFlags & MOTION_TYPE_VERTEX_MASK);}
	void					SetMotionTypeVertex(MOTION_TYPE_VERTEX type) {m_dwFlags = (m_dwFlags & MOTION_TYPE_VERTEX_MASK_INVERSE) |type;}

	MOTION_TYPE_UV			GetMotionTypeUV() {return (MOTION_TYPE_UV)(m_dwFlags & MOTION_TYPE_UV_MASK);}
	void					SetMotionTypeUV(MOTION_TYPE_UV type) {m_dwFlags = (m_dwFlags & MOTION_TYPE_UV_MASK_INVERSE) |type;}

	void					Clear() {m_dwFlags = 0;}

	CMotionFlags()			{m_dwFlags = 0;}
};

