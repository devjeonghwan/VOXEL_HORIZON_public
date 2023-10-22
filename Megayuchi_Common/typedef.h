#pragma once

#include <windows.h>
#include <stdio.h>
#include <Ole2.h>
#include "math.inl"
#include "emul_x86_simd.inl"
#include "emul_x86_generic.inl"
#include "mesh_flag.h"
#include "motion_flag.h"
#include "../Megayuchi_Common/define.h"

//#define	_INL_MATH_FUNC


#define ENGINE_DEFAULT_FONT_NAME_A "Tahoma"
#define ENGINE_DEFAULT_FONT_NAME_W L"Tahoma"

#define VECTOR3_SIZE	12
#define VECTOR4_SIZE	16

#define MIN_UNIT							10.0f
#define	ONE_CM								1.0f
#define MAX_NAME_BUFFER_LEN					128
#define MAX_NAME_LEN_						127

//#define	MAX_FILENAME_LEN				32

#define DEFAULT_LIGHT_RADIUS				100.0f
//#define DEFAULT_RENDER_ZORDER_UNIT			-1000.0f
#define DEFAULT_RENDER_ZORDER_UNIT			-1000.0f

#define DEFAULT_RENDER_ZORDER_UNIT_ATTACH	-100.0f

#define WORLDMAP_DEFAULT_TOP			400.0f
#define WORLDMAP_DEFAULT_BOTTOM			0.0f

#define FOG_DISTANCE_START				2000.0f
#define FOG_DISTANCE_END				8000.0f

// EXECUTIVE CONST VALUE
#define	DEFAULT_DECAL_TRI_NUM			64

#define	MAX_MODEL_NUM_PER_GXOBJECT		8
#define MAX_RENDER_OBJECT_NUM			8192
#define MAX_ATTATCH_OBJECTS_NUM			16
#define	MAX_PICK_OBJECT_NUM				256
#define ZORDER_LATEST_RENDER			1100
#define	MAX_SPAWN_POINT_NUM_PER_SCENE		16
#define SPAWN_POINT_NAME_BUFFER_LEN			16



// GEOMETRY CONST VALUE
#define PID_MODEL_LOD					"_LOD"
#define PID_MODEL_lod					"_lod"
#define PID_LEN							4

#define	MAX_PICK_DYNAMIC_RENDER_OBJECT_NUM		1024
#define DEFAULT_MODEL_LOD_UNIT			500.0
#define MAX_LOD_MODEL_NUM				3
#define MAX_HFINDEX_BUFER_NUM			128
#define MAX_OBJECTS_NUM_PER_MODEL		8192
#define	MAX_NOT_RENDER_OBJ_NAME_NUM		128
#define MAX_NOT_RENDER_OBJ_NAME_BUFFER_LEN		32
#define MAX_NOT_RENDER_OBJ_NAME_LEN				31
#define	MAX_SHADOW_SENDER_POINT_NUM		8192
#define LIMITED_TICK_RECYCLE_BIN_FULL	1000*60		// 휴지통이 꽉 찼을 경우 우선적으로 삭제할 오브젝트들의 경과시간 제한(1분지난 놈들 찾아서 삭제)
#define DEFAULT_RECYCLE_BIN_PERCENTAGE	0.5f		// 휴지통 크기 비율. 최대 오브젝트 개수 * 비율

#define MIN_QUAD_NODE_LENGTH				1000.0f		


#define DEFAULT_MAX_POLYGON_NUM_FOR_EDIT	65536*4
#define DEFAULT_MAX_VERTEX_NUM_FOR_EDIT		65536*4
#define DEFAULT_MAX_MEMORY_SIZE_FOR_EDIT	1024*1024*64

#define	DEFAULT_ZERO_VALUE_POLYGON_TOOL		0.05f
#define MAX_FIND_THREAD_NUM		64
//#define MAX_REALTIME_LIGHT_NUM			(MAX_STATIC_RTLIGHT_NUM_PER_SCENE + MAX_DYNAMIC_RTLIGHT_NUM_PER_SCENE)
#define	MAX_EXT_BOUNDING_SPHERE_NUM			32


#define MAX_BSP_NODE_NUM_ON_FIND		4096
#define DEFAULT_COLLISION_MESH_TREE_STACK_SIZE 256
#define MAX_CAMERA_NUM_PER_SCENE		128
#define MAX_MOTION_NUM					1024
#define	DEFAULT_AMBIENT_COLOR			0xff202020
#define	DEFAULT_EMISSIVE_COLOR			0xffffffff
#define MAX_RENDER_STATICMODEL_OBJ_NUM	4096
#define MAX_RENDER_HFIELD_OBJ_NUM		1024
//#define	DEFAULT_NEAR					100.0f
#define DEFAULT_FAR						80000.0f
//#define	DEFAULT_FOV					PI/4.0f
#define MAX_FILEITEM_NUM				8192
#define MAX_FILEBUCKET_NUM				256
#define MAX_VIEWPORT_NUM				256
#define MAX_MATRIX_NUM_IN_POOL			4096
#define MAX_LIGHT_INDEX_NUM_IN_POOL		4096
#define MAX_MODEL_REF_INDEX_NUM			(8192*4)
#define DEFAULT_RESOURCE_SCHDULE_DISTANCE	16.0f
#define	DEFAULT_OVERLAP_TILES_NUM		4
#define MAX_LAYER_NAME_LEN				16
#define MAX_RENDER_OBJECT_PER_TYPE				8192
#define MAX_OBJECT_NUM_IN_SPACE_PARTITION		65536

#define DEFAULT_SUB_COLMESH_WIDTH		1200.0f
#define DEFAULT_SUB_COLMESH_HEIGHT		1200.0f
#define MAX_EXTERIOR_ENTER_COUNT		64
#define MAX_VOXEL_OBJECT_NUM			65536

// RENDERER CONST VALUE
#define	MAX_RESOURCE_NUM				(8192*4)
#define	DEFAULT_VBCACHE_VERTEX_BUFFER_NUM		8
#define	DEFAULT_IBCACHE_INDEX_BUFFER_NUM		1
#define DEFAULT_VBCACHE_VERTEXNUM_PER_BUFFER	32768
#define	DEFAULT_IBCACHE_INDEXNUM_PER_BUFFER		32768

#define	DEFAULT_ALPHA_REF_VALUE			127
#define DEFAULT_LMMESH_ALPHA_REF_VALUE	250
#define DEFAULT_RENDER_TEXTURE_NUM		4
#define MAX_RENDER_TEXTURE_NUM			8
#define DEFAULT_RENDER_TEXTURE_SIZE		256
#define MAX_RENDER_TEXTURE_SIZE			1024
#define MAX_SPRITE_ZORDER_NUM			256
#define MAX_HFIELD_DETAIL_NUM			8
#define MAX_TILE_TEXTURE_NUM			65536				
#define MAX_SPRITE_FRAME_NUM			1024
#define MAX_RENDER_TARGET_NUM			8
#define	MAX_TEXTURE_NUM					25600
#define MAX_TEXBUCKET_NUM				256
#define WATER_FADE_DISTANCE				15.0f
#define DEFAULT_WATER_DEPTH				100.0f

const	DWORD MAX_RENDER_MESHOBJ_NUM = 8192;
const	DWORD MAX_RENDER_IMM_MESHOBJ_NUM = 8192;
const	DWORD MAX_RENDER_SHADOW_CASTER_NUM = 4096;
const	DWORD MAX_LATER_RENDER_MESHOBJ_NUM = 128;
const	DWORD DEFAULT_VOXEL_CB_NUM = 8192;

#define MAX_RENDER_TEXTBUFFER_SIZE		16384*4
#define MAX_LINES_BUFFER_SIZE			8192
#define MAX_INDEXED_TRIS_BUFFER_SIZE	(65536*2)
#define MAX_DYNAMIC_PRIMITIVE_BUFFER	(65536*8)
#define MAX_RENDER_SPRITE_NUM			1024
#define MAX_FONT_INFO_NUM				128	// 각각 다른 종류의 폰트 가지수
#define DEFULAT_CIRCLE_PIECES_NUM		32
#define MAX_CIRCLE_PIECES_NUM			64
#define MAX_MIPMAP_LEVEL_NUM			12
#define MAX_MIPMAP_SIZE					1
#define MAX_MATERIAL_NUM				8192
#define MAX_MATERIAL_SET_NUM			2048
#define	MAX_D3DRESOURCE_NUM				65536
#define	MAX_LAYER_NUM					65536
#define	DEFAULT_D3DRESOURCE_NUM			128
#define DEFAULT_VBCACHE_NUM						1024
#define DEFAULT_PHYSIQUE_OBJECT_NUM_PER_SCENE	32
#define DEFAULT_MOST_PHYSIQUE_VERTEX_NUM		800
#define MAX_PHYSIQUE_VERTEX_NUM					32768
#define MAX_PRJMESH_INDICES_NUM					16384
#define MAXSHINESTR_TO_SS3D_VAL					20.0f
#define DEFAULT_FREE_VBCACHE_RATE				0.25f
#define MAX_EFFECT_SHADER_NUM					1024	
#define DEFAULT_LIMITED_VERTEXTBUFFER_INDICES	65536
#define MAX_RESOURCE_POOL_NUM					32
#define MAX_MASK_TEX_NUM						2
#define MAX_POST_EFFECT_NUM						8
#define	DEFAULT_HW_OCCLUSION_TEST_NEAR_OFFSET	50.0f
#define	MAX_DYNAMIC_LIGHT_NUM_PER_SCENE			128
#define DEFAULT_GLOW_POW_CONSTANT				16.0f
//#define MAX_TRI_NUM_PER_COLLISION_CHECK			1024
//#define MAX_COLLISION_CHECK_NUM_PER_SAME_TIME	1024

#define MAX_ROOM_NUM_PER_SCENE					65536
#define DEFAULT_ROOM_NUM_PER_SCENE				65536

#define	MAX_OCCLUSION_NUM_PER_SCENE				1024

#define DEFAULT_SHADOW_MAP_WIDTH				1024
#define DEFAULT_SHADOW_MAP_HEIGHT				1024

#define DEFAULT_HEIGHT_MAP_WIDTH				1024
#define DEFAULT_HEIGHT_MAP_HEIGHT				1024

#define MAX_MIRROR_RENDER_TEXTURE_WIDTH_HEIGHT	1024

#define DEFAULT_POSTEFFECT_TEX_WIDTH			512
#define DEFAULT_POSTEFFECT_TEX_HEIGHT			512
#define	MAX_DYNAMIC_LIGHT_NUM_PER_OBJ			8
#define	MAX_RENDER_PARTICLE_BOX_NUM				1024
#define	MAX_RENDER_ELLIPSOID_MESH_NUM			256

#define DEFAULT_OUTLINE_THICK_CONST_VL			0.75f
#define DEFAULT_OUTLINE_THICK_CONST_LM			1.4f
#define DEFAULT_OUTLINE_THICK_CONST_HFM			16.0f

#define DEFAULT_TOON_COLOR_TONE_R	1.275f
#define DEFAULT_TOON_COLOR_TONE_G	1.15f
#define DEFAULT_TOON_COLOR_TONE_B	1.1f

#define DEFAULT_VL_COLOR_TONE_R	1.45f
#define DEFAULT_VL_COLOR_TONE_G	1.3f
#define DEFAULT_VL_COLOR_TONE_B	1.3f

const float CAM_POS_CMP_BIAS_DIST = 25.0f;
//const float CAM_RAY_CMP_BIAS_ANGLE = 0.04f;
const float CAM_RAY_CMP_BIAS_ANGLE = 0.261f;

const DWORD MAX_VERTEX_NUM_PER_MESHOBJ = 65536;
const DWORD MAX_FACEGROUP_NUM = 32;

enum UNIT_TYPE
{
	UNIT_TYPE_CM = 0,
	UNIT_TYPE_M = 1
};
enum RENDERER_TYPE
{
	RENDERER_TYPE_NULL = 0,
	RENDERER_TYPE_D3D9 = 1,
	RENDERER_TYPE_D3D11_FEATURE_LEVEL_10 = 2,
	RENDERER_TYPE_D3D11 = 3,
	RENDERER_TYPE_D3D12 = 4,
	RENDERER_TYPE_OPENGL = 5,
	RENDERER_TYPE_OPENGLES = 6
};

enum RENDERER_CREATE_TYPE
{
	RENDERER_CREATE_TYPE_ENABLE_CAPTURE = 0x00000001,
	RENDERER_CREATE_TYPE_DEBUG_DEVICE = 0x00000002,
	RENDERER_CREATE_TYPE_DEBUG_SHADER = 0x00000004,
	RENDERER_CREATE_TYPE_USE_NVGRID = 0x00000010,
	RENDERER_CREATE_TYPE_USE_NVAPI = 0x00000020,
	RENDERER_CREATE_TYPE_USE_NVENCODER = 0x00000040,
	RENDERER_CREATE_TYPE_USE_VOXEL = 0x00000080,
	RENDERER_CREATE_TYPE_USE_BLOCK_SHADING = 0x00000100,
	RENDERER_CREATE_TYPE_USE_DXR = 0x00000200
};
enum OCCLUSION_TEST_TYPE
{
	OCCLUSION_TEST_TYPE_HIZ_CS,
	OCCLUSION_TEST_TYPE_D3DQUERY
};

enum AXIS_TYPE
{

	AXIS_TYPE_NONE = 0,
	AXIS_TYPE_X = 1,
	AXIS_TYPE_Y = 2,
	AXIS_TYPE_Z = 3
};

enum PLANE_AXIS_TYPE
{
	PLANE_AXIS_TYPE_XZ,
	PLANE_AXIS_TYPE_XY,
	PLANE_AXIS_TYPE_YZ,
	PLANE_AXIS_TYPE_COUNT,

};
struct PATH_AND_FILE
{
	char szFileName[128];
	char szPath[128];
};
#define MAX_MIRROR_PLANE_NUM		4
#define MAX_MIRROR_TEXTURE_NUM		4

enum MIRROR_TEXTURE_TYPE
{
	MIRROR_TEXTURE_TYPE_REFLECT = 0,
	MIRROR_TEXTURE_TYPE_REFRACTION = 1
};
#define MIRROR_TEXTURE_TYPE_NUM			2

enum MAP_OBJECT_TYPE
{
	MAP_OBJECT_TYPE_CHARACTER = 0,
	MAP_OBJECT_TYPE_STRUCT = 1
};

enum MIRROR_TYPE
{
	MIRROR_TYPE_NONE = 0,
	MIRROR_TYPE_MIRROR = 1,
	MIRROR_TYPE_WATER = 2
};

enum POST_EFFECT_SHADER_TYPE
{
	POST_EFFECT_SHADER_BW = 1,
	POST_EFFECT_SHADER_SEPHIA = 2,
	POST_EFFECT_SHADER_NEGATIVE = 3,
	POST_EFFECT_SHADER_INVALID = -1
};

enum CHAR_CODE_TYPE
{
	CHAR_CODE_TYPE_ASCII = 1,
	CHAR_CODE_TYPE_UNICODE = 2
};

enum FONT_TYPE
{
	SS3D_FONT = 0,
	D3DX_FONT = 1
};

struct CUSTOM_FONT
{
	WCHAR wchFontFileName[_MAX_PATH];
	int	iResult;
};
enum RENDER_MODE
{
	RENDER_MODE_SOLID = 0x00000000,
	RENDER_MODE_POINT = 0x00000001,
	RENDER_MODE_WIREFRAME = 0x00000002
};

enum APPLY_PHYSIQUE_TYPE
{
	APPLY_PHYSIQUE_RECALC_NORMAL = 0x00000001,
	APPLY_PHYSIQUE_WRITE_UV = 0x00000002
};

enum DEBUG_DRAW_FLAG
{
	DEBUG_DRAW_MODEL_COL_MESH = 0x00000001,
	DEBUG_DRAW_BONE_COL_MESH = 0x00000002,
	DEBUG_DRAW_ROOM_MESH = 0x00000004,
	DEBUG_DRAW_HFIELD_COL_MESH = 0x00000008,
	DEBUG_DRAW_CHARACTER_COL_BOX = 0x00000010,
	DEBUG_DRAW_LIGHT_PROBE = 0x00000020
};

enum GET_COLLISION_TRI_TYPE
{
	GET_COLLISION_TRI_TYPE_STRUCT = 0x00000001,
	GET_COLLISION_TRI_TYPE_HFIELD = 0x00000002,
	GET_COLLISION_TRI_TYPE_OBJECT = 0x00000004
};
enum LIGHT_FLAG
{
	DISABLE_LIGHT = 0,
	ENABLE_LIGHT = 1
};

enum SHADOW_FLAG
{
	DISABLE_SHADOW = 0,
	ENABLE_SHADOW = 1
};

enum SHADOW_MAP_TYPE
{
	SHADOW_MAP_TYPE_CSSM,	// cascade shadow map
	SHADOW_MAP_TYPE_SINGLE,	// Single Shadow Map(Ortho,PSM,LiPSM)

};

enum AO_TYPE
{
	AO_TYPE_NO_AO = 0,
	AO_TYPE_SSAO,
	AO_TYPE_RTAO,
	AO_TYPE_RTAO_NO_DENOISING
};
enum BEGIN_RENDER_FLAG
{
	BEGIN_RENDER_FLAG_CLEAR_ZBUFFER = 0x00000000,
	BEGIN_RENDER_FLAG_CLEAR_FRAMEBUFFER = 0x00000000,
	BEGIN_RENDER_FLAG_DONOT_CLEAR_ZBUFFER = 0x00000001,
	BEGIN_RENDER_FLAG_DONOT_CLEAR_FRAMEBUFFER = 0x00000002,
	BEGIN_RENDER_FLAG_USE_RENDER_TEXTURE = 0x00000004,
	BEGIN_RENDER_FLAG_DISABLE_POST_EFFECT = 0x00000008,
	BEGIN_RENDER_FLAG_2D_RENDER_TO_TEXTURE = 0x00000010,
	BEGIN_RENDER_FLAG_PRE_RENDER_2D_ITEMS = 0x00000020,
	BEGIN_RENDER_FLAG_FILL_FRAMEBUFFER_WITH_SKY = 0x00000040,
	BEGIN_RENDER_FLAG_DO_RAYTRACING = 0x00000080


	//	BEGIN_RENDER_FLAG_DRAW_OUTLINE				=	0x00000010
};

enum MODEL_INITIALIZE_FLAG
{
	MODEL_INITIALIZE_FLAG_NOT_OPTIMIZE = 0x00000001,
	MODEL_INITIALIZE_FLAG_OPTIMIZE_ADVANCED = 0x00000002,
	MODEL_INITIALIZE_FLAG_NOT_COMMIT = 0x00000004

};


// 맵을 로딩할때 사용할 수 있는 플래그들.or로 조합해서 사용한다.
enum MAP_LOAD_FLAG
{
	STATIC_MODEL_LOAD_OPTIMIZE = 0x00000001,
	STATIC_MODEL_LOAD_DEFER_COMMIT_DEVICE = 0x00000002,
	HFIELD_MODEL_LOAD_OPTIMIZE = 0x00000008,
	HFIELD_MODEL_LOAD_NOT_RENDER = 0x00000010,

};
enum LOAD_MAP_FLAG
{
	LOAD_MAP_FLAG_DEFAULT_PROC_AUTOANIMATION = 0x00000100
};

/////////////////////////////////////////////////////////////////

enum SYMBOL_TYPE
{
	SYMBOL_TYPE_LIGHT = 0,
	SYMBOL_TYPE_TRIGGER = 1,
	SYMBOL_TYPE_VIEW_VOLUME = 2

};
#define SYMBOL_TYPE_NUM	2

enum SCHEDULE_FLAG
{
	SCHEDULE_FLAG_NOT_SCHEDULE = 0x00000001,
	SCHEDULE_FLAG_DISABLE_UNLOAD = 0x00000002,
	SCHEDULE_FLAG_NOT_RENDER = 0x10000000
};
enum UNLOAD_PRELOADED_RESOURCE_TYPE
{
	UNLOAD_PRELOADED_RESOURCE_TYPE_ONLY_UNLOAD_ENABLED = 0x00000000,
	UNLOAD_PRELOADED_RESOURCE_TYPE_ALL_PRELOADED = 0x00000001
};





enum LIGHTMAP_FLAG
{
	LIGHTMAP_FLAG_DISABLE_LIGHTMAP = 0x00000000,
	LIGHTMAP_FLAG_ENABLE_LIGHTMAP = 0x00000001,
	LIGHTMAP_FLAG_DISABLE_TEXTURE = 0x00000002,
	LIGHTMAP_FLAG_DISABLE_MAGFILTER = 0x00000004,
};

enum OBJECT_TYPE
{
	OBJECT_TYPE_UNKNOWN = 0xf000000,
	OBJECT_TYPE_LIGHT = 0xf1000000,
	OBJECT_TYPE_CAMERA = 0xf2000000,
	OBJECT_TYPE_CAMERA_TARGET = 0xf3000000,
	OBJECT_TYPE_MESH = 0xf4000000,
	OBJECT_TYPE_BONE = 0xf5000000,
	OBJECT_TYPE_ILLUSION_MESH = 0xf6000000,
	OBJECT_TYPE_COLLISION_MESH = 0xf7000000,
	OBJECT_TYPE_MATERIAL = 0x00f00000,
	OBJECT_TYPE_MOTION = 0x0000f000
};

enum MODEL_READ_TYPE
{
	MODEL_READ_TYPE_AS_LOD_SUBMODEL = 0x00000001,
	MODEL_READ_INVERSE_TEX_COORD_V = 0x00000002
};
enum GX_MAP_OBJECT_TYPE
{
	GX_MAP_OBJECT_TYPE_STRUCT = 0,
	GX_MAP_OBJECT_TYPE_HFIELD = 1,
	GX_MAP_OBJECT_TYPE_PARTICLE = 2,
	GX_MAP_OBJECT_TYPE_CHARACTER = 3,
	GX_MAP_OBJECT_TYPE_DECAL = 4,
	GX_MAP_OBJECT_TYPE_TRIGGER = 5,
	GX_MAP_OBJECT_TYPE_LIGHT = 6,
	GX_MAP_OBJECT_TYPE_VOXEL_OBJECT = 7,
	GX_MAP_OBJECT_TYPE_INVALID = -1
};
#define GX_MAP_DYNAMIC_OBJECT_START_INDEX	3
#define GX_MAP_DYNAMIC_OBJECT_END_INDEX		5

#define GX_MAP_OBJECT_RENDER_START_INDEX	0
#define GX_MAP_OBJECT_RENDER_END_INDEX		4

#define GX_MAP_OBJECT_RENDER_START_INDEX_TOOL	5
#define GX_MAP_OBJECT_RENDER_END_INDEX_TOOL		6

#define GX_MAP_OBJECT_TYPE_NUM		8
enum EFFECTIVE_AXIS_TYPE
{
	EFFECTIVE_AXIS_TYPE_Y = 0x00000001,
	EFFECTIVE_AXIS_TYPE_X = 0x00000002,
	EFFECTIVE_AXIS_TYPE_Z = 0x00000004
};

enum GXLIGHT_ATTACH_TYPE
{
	ATTACH_TYPE_ATTACH = 0x00000000,
	ATTACH_TYPE_LINK = 0x00000001
};
#define GXLIGHT_ATTACH_TYPE_MASK_			0x0000000f
#define GXLIGHT_ATTACH_TYPE_MASK_INVERSE	0xfffffff0

enum MESH_CONTROL_TYPE
{
	RESULT_MATRIX_ALIGN_VIEW = 0x00000001,
	UPDATE_VERTEX_NORMAL = 0x00000002
};

enum MATERIAL_ILLUNUM_TYPE
{
	SELF_ILLUNUM = 0x10000000
};

#define MATERIAL_ILLUNUM_TYPE_MASK	0x10000000
#define	MATERIAL_ILLUNUM_TYPE_MASK_INVERSE	0x8fffffff
enum MATERIAL_TRANSP_TYPE
{
	TRANSP_TYPE_FILTER = 0x00000001,
	TRANSP_TYPE_SUBTRACTIVE = 0x00000002,
	TRANSP_TYPE_ADDITIVE = 0x00000004

};
#define MATERIAL_TRANSP_TYPE_MASK			0x00000003
#define MATERIAL_TRANSP_TYPE_MASK_INVERSE	0xfffffffc

enum HFIELD_ADJUST_TYPE
{
	HFIELD_ADJUST_TYPE_SET = 0x00000001,
	HFIELD_ADJUST_TYPE_ADD = 0x00000002,
	HFIELD_ADJUST_TYPE_SUB = 0x00000004
};
enum VERTEX_TYPE
{
	VERTEX_TYPE_TEXTURE = 0x00000001,
	VERTEX_TYPE_PHYSIQUE = 0x01000000,
	VERTEX_TYPE_NORMAL = 0x00010000
};
enum TEXTURE_TYPE
{
	TEXTURE_TYPE_DEFAULT = 0x00000000,
	TEXTURE_TYPE_DETAIL = 0x00000001
};

enum RENDER_TEXTURE_TYPE
{
	RENDER_TEXTURE_TYPE_SHADOW = 0,
	RENDER_TEXTURE_TYPE_REFLECT = 1
};


enum CREATE_MATERIAL_TYPE
{
	// 최상위 8비트는 보더컬러 
	CREATE_MATERIAL_TYPE_TEXBORDER = 0x00000001

};
enum TEXTURE_MAP_TYPE
{
	TEXTURE_MAP_TYPE_AMBIENT = 0,
	TEXTURE_MAP_TYPE_DIFFUSE = 1,
	TEXTURE_MAP_TYPE_SPECULAR = 2,
	TEXTURE_MAP_TYPE_SHINE = 3,
	TEXTURE_MAP_TYPE_SHINESTRENGTH = 4,
	TEXTURE_MAP_TYPE_SELFILLUM = 5,
	TEXTURE_MAP_TYPE_OPACITY = 6,
	TEXTURE_MAP_TYPE_FILTERCOLOR = 7,
	TEXTURE_MAP_TYPE_TOONMAP_TABLE = 7,
	TEXTURE_MAP_TYPE_BUMP = 8,
	TEXTURE_MAP_TYPE_REFLECT = 9,

	TEXTURE_MAP_TYPE_CUBEMAP = 10			// 엔진 내에서만 사용.TEXTURE_MAP_TYPE_NUM에 포함시키지 않는다.
};
#define TEXTURE_MAP_TYPE_MAX_INDEX	9
#define	TEXTURE_MAP_TYPE_NUM	10

enum REDNER_TYPE
{
	RENDER_TYPE_AS_EFFECT = 0x00000001,
	RENDER_TYPE_CUTOFF_ALPHAREF_VALUE = 0x00000002,
	RENDER_TYPE_FOR_BUILD_BLOCK = 0x00000004,
	RENDER_TYPE_ENABLE_CLIP_PER_OBJECT = 0x00000008,
	RENDER_TYPE_DONOT_TRANSFORM = 0x00000010,		// 트랜스폼하지 않음. 입력 버텍스는 동차좌표계로 
	RENDER_TYPE_DRAW_OUTLINE = 0x00000020,		// 아웃라인 그림
	RENDER_TYPE_HIGHLIGHT_DIFFUSE_COLOR = 0x00000040,		// 주어진 DIFFUSE컬러 강조, (TEX * LIGHTING * DIFFUSE) + (DIFFUSE * C)
	RENDER_TYPE_SELF_ILLUMIN = 0x00000080,
	RENDER_TYPE_USE_ONLY_ALPHA_MTL = 0x00000100,		// 알파블랜딩 매터리얼이 적용된 FACE GROUP만 렌더링. Order Independant Transparency를 사용.
	RENDER_TYPE_SEND_SHADOW = 0x00000200,
	RENDER_TYPE_RECV_SHADOW = 0x00000400,
	RENDER_TYPE_DISABLE_ZCLIP = 0x00000800,
	RENDER_TYPE_MUL_TONE_COLOR = 0x00001000,		// 렌더링시 ToneColor값을 곱함.
	RENDER_TYPE_AS_SHADING_TYPE_VERTEX_LIGHT = 0x00002000,	// Character렌더링시 m_shadingType에 상관없이 SHADING_TYPE을 SHADING_TYPE_VERTEX_LIGHT로 설정
	RENDER_TYPE_ENABLE_ILLUSION = 0x00004000,
	RENDER_TYPE_ADD = 0x00008000,
	RENDER_TYPE_MUL = 0x00010000,
	RENDER_TYPE_USE_DIFFUSE_ALPHA_TO_MUL = 0x00020000,		// IDIMeshObject 렌더링 시 dwDiffuseColor의 알파성분을 (1.0 - 2.0) 사이의 곱하기 상수로 사용
	RENDER_TYPE_ONLY_OPAQUE = 0x00040000,					// 불투명매시(불투명 FACEGROUP)만 렌더링한다. oit를 사용할때 첫번째 패스(불투명) 렌더링에서 사용.
	RENDER_TYPE_BACKGROUND_LAYER = 0x00080000,
	RENDER_TYPE_ADD_HFIELD_WIREFRAME = 0x00100000,
	RENDER_TYPE_AS_WATER_BOTTOM = 0x00200000,		// 물 속 장면으로서 렌더링
	RENDER_TYPE_USE_SPECIFY_COLOR = 0x00400000,		// 캐릭터 별로 디퓨즈를 먹게하기 위한 플랙. ex) ICharacterObject::SetRenderFlags( dwFlags); ICharacterObject::SetDiffuseColor( 0xffa0a0a0); 
	RENDER_TYPE_USE_DEFAULT_COLOR = 0x00800000,		// room 렌더링에만 사용
	RENDER_TYPE_USE_OIT = 0x01000000,				// 명시적으로 OIT로 렌더링. RENDER_TYPE_AS_EFFECT인 경우는 RENDER_TYPE_USE_OIT가 자동 지정
	RENDER_TYPE_DISABLE_ZWRITE = 0x02000000,		// Z버퍼에 쓰지 않는다.
	RENDER_TYPE_DRAW_DEPTH = 0x04000000,		// 깊이값을 렌더링한다.
	RENDER_TYPE_THICK_OUTLINE = 0x08000000,

	// setframe에서 사용할 플래그.최상위 4비트만 사용한다
	RENDER_TYPE_UPDATE_COLLISION_BONEMESH_DESC = 0x10000000,
	RENDER_TYPE_UPDATE_ILLUSION_FRAME = 0x20000000,
	RENDER_TYPE_UPDATE_ALWAYS = 0x40000000,
	RENDER_TYPE_USE_PARENT_POS_ONLY = 0x80000000

};

enum REDNER_SPRITE_TYPE
{
	RENDER_TYPE_SPRITE_ADD = 0x00000001,
	RENDER_TYPE_SPRITE_MUL = 0x00000002,
	RENDER_TYPE_SPRITE_OPASITY = 0x00000004,
	RENDER_TYPE_SPRITE_DISABLE_TEX_FILTERING = 0x00000008,
	RENDER_TYPE_SPRITE_GRAY = 0x00000010
};

enum OIT_MODE
{
	OIT_MODE_SORT = 0,
	OIT_MODE_VF = 1
};
enum BLOCKED_MESH_DYNAMIC_SHADOW_TYPE	// Blocked Mesh로 렌더링하는 캐릭터의 Dynamic Shadow Map을 만들때 어떤
{
	BLOCKED_MESH_DYNAMIC_SHADOW_TYPE_AS_VLMESH = 0,	// Shadow Caster로 삼각형 매시를 사용
	BLOCKED_MESH_DYNAMIC_SHADOW_TYPE_AS_BLOCK = 1	// Shadow Caster로 BLOCKED MESH를 사용
};

enum RENDER_FONT_TYPE
{
	RENDER_FONT_TYPE_OUTLINE = 0x00000001,
	RENDER_FONT_TYPE_SHADOW = 0x00000002,
	RENDER_FONT_TYPE_GRAY = 0x00000004

};
enum TEST_RENDER_TYPE
{
	TEST_RENDER_TYPE_DISABLE_SW_OCCLUSION_TEST = 0x00000001,
	TEST_RENDER_TYPE_UPDATE_ALWAYS = 0x00000002,
	TEST_RENDER_TYPE_DISABLE_FIND_VOXEL_OBJ = 0x00000004
};

enum SHADING_TYPE
{
	SHADING_TYPE_VERTEX_LIGHT = 0x00000000,
	SHADING_TYPE_PERPIXEL_NORMAL = 0x00000001,
	SHADING_TYPE_TOON = 0x00000002,
	SHADING_TYPE_SKY = 0x00000003,
	SHADING_TYPE_STRUCT = 0x00000004,		// 건물 전용
	SHADING_TYPE_HFIELD = 0x00000005,
	SHADING_TYPE_SHADOW_CASTER = 0x00000006,		// 그림자 생성 등등
	SHADING_TYPE_POSTEFFECT = 0x00000007,		// 그림자 생성 등등
	SHADING_TYPE_WATER = 0x00000008,
	SHADING_TYPE_WATER_BOTTOM = 0x00000009,
	SHADING_TYPE_COLOR = 0x0000000A,		// 단색 컬러 렌더링,
	SHADING_TYPE_FLAT = 0x0000000C,			// Flat Shading
	SHADING_TYPE_BLOCK = 0x0000000D,		// as Blocks
	SHADING_TYPE_UNKNOWN = -1
};
const DWORD MAX_SHADING_TYPE_NUM = 13;

#define WATER_SHADING_PROPERTY_INDEX_MASK	0x0000ff00
#define RENDER_TYPE_UPDATE_MASK	0xf0000000

//#define RENDER_TYPE_UPDATE_SHADING_MASK_INVERSE	0xfffffeff
//#define RENDER_TYPE_SEND_SHADOW_MASK_INVERSE	0xffffbfff
//#define RENDER_TYPE_SELF_ILLUMIN_MASK_INVERSE	0xfffff7ff


enum PICK_TYPE
{
	PICK_TYPE_DEFAULT = 0x00000000,
	PICK_TYPE_PER_COLLISION_MESH = 0x00000001,
	PICK_TYPE_PER_FACE = 0x00000002,
	PICK_TYPE_PER_BONE_OBJECT = 0x00000004,

	PICK_TYPE_SORT = 0x00000010
};

#define PICK_TYPE_PURE_MASK			= 0x0000000f

enum SELECTED_MASK
{
	SELECTED_MASK_FOR_RENDER = 0x00000001,
	SELECTED_MASK_FOR_FIND_WITH_SPHERE = 0x00000002
};


// GXMapObject 속성 플래그 ///////////////////////////////////////////////////////////
// 최상위 8비트는 GXMAP_OBJECT_COMMON_FLAG 영역이므로 사용하지 않는다.
enum GXMAP_OBJECT_COMMON_FLAG
{
	GXMAP_OBJECT_COMMON_TYPE_NOT_PICKABLE = 0x01000000,
	GXMAP_OBJECT_COMMON_TYPE_NOT_USE_CLIPPER = 0x02000000,
	GXMAP_OBJECT_COMMON_TYPE_DISABLE_UNLOAD = 0x04000000,
	GXMAP_OBJECT_COMMON_TYPE_ENABLE_COLLISION_MESH = 0x08000000
};
//#define GXMAP_OBJECT_COMMON_TYPE_NOT_PICKABLE_INVERSE		0xfeffffff
//#define GXMAP_OBJECT_COMMON_TYPE_NOT_USE_CLIPPER_INVERSE	0xfdffffff

enum GXOBJECT_CREATE_TYPE
{
	// 최상위 8비트는 GXMAP_OBJECT_COMMON_FLAG 영역이므로 사용하지 않는다.
	GXOBJECT_CREATE_TYPE_OPTIMIZE = 0x00000001,
	GXOBJECT_CREATE_TYPE_NOT_OPTIMIZE = 0x00000000,
	GXOBJECT_CREATE_TYPE_EFFECT = 0x00000002,
	GXOBJECT_CREATE_TYPE_APPLY_HFIELD = 0x00000004,
	GXOBJECT_CREATE_TYPE_DEFAULT_PROC = 0x00000008,
	GXOBJECT_CREATE_TYPE_NOT_USE_MODEL = 0x00000010,
	GXOBJECT_CREATE_TYPE_DONOT_INSERT_SCENE_GRAPH = 0x00000020,
	GXOBJECT_CREATE_TYPE_ENABLE_AS_COLLISION_TRIMESH = 0x00000040,
	GXOBJECT_CREATE_TYPE_INITIALIZE_ILLUSION_MESH = 0x00000080,
	GXOBJECT_CREATE_TYPE_ENABLE_RECYCLE = 0x00000100,
	GXOBJECT_CREATE_TYPE_ENABLE_ONLY_COLLISION_MESH = 0x00000200,	// 충돌 처리용으로만 사용됨.렌더링 불가.
	GXOBJECT_CREATE_TYPE_SELF_ILLUMIN = 0x00000400,
	GXOBJECT_CREATE_TYPE_DRAW_OUTLINE = 0x00000800,
	GXOBJECT_CREATE_TYPE_NOT_USE_SCENE_TREE = 0x00001000,
	GXOBJECT_CREATE_TYPE_USE_COLLISION = 0x00002000,
	GXOBJECT_CREATE_TYPE_SCENE_TREE_AABB = 0x00004000,	// scenetree에서 Ellipsoid가 아닌 AABB로 처리(보스등)
	//GXOBJECT_CREATE_TYPE_ENABLE_AS_AABB_TRIMESH			= 0x00000080,
};
/*
//#define GXOBJECT_CREATE_TYPE_APPLY_HFIELD_INVERSE	0xfffffffb
//#define GXOBJECT_CREATE_TYPE_EFFECT_INVERSE			0xfffffffd
enum GXLIGHT_TYPE
{
	// 최상위 8비트는 GXMAP_OBJECT_COMMON_FLAG 영역이므로 사용하지 않는다.
	GXLIGHT_TYPE_TEX_PROJECTION						= 0x00000000,	// 이 경우 최하위 8비트가 라이트 인덱스
	GXLIGHT_TYPE_ENABLE_SHADOW						= 0x00000200,
	GXLIGHT_TYPE_ENABLE_SPOT						= 0x00000400,
	GXLIGHT_TYPE_DISABLE_LIGHT_COLOR				= 0x00000800,
	GXLIGHT_TYPE_STATIC								= 0x00001000,
	GXLIGHT_TYPE_STATIC_SHADOW_DISABLE				= 0x00002000,
	GXLIGHT_TYPE_ENABLE_DYNAMIC_LIGHT				= 0x00004000,
	GXLIGHT_TYPE_ENABLE_IMAGE_PROJECTION			= 0x00008000,
	GXLIGHT_TYPE_DISABLE_NOT_RENDER_MODEL_IN_TOOL	= 0x00010000,
	GXLIGHT_TYPE_ONLY_USE_TOOL						= 0x00020000
};
//#define GXLIGHT_TYPE_STATIC_SHADOW_DISABLE_INVERSE	0xffffdfff
//#define GXLIGHT_TYPE_ENABLE_DYNAMIC_LIGHT_INVERSE	0xffffbfff
*/

#define MAX_DIFFUSE_WEIGHT 4.0f
#define MAX_DIFFUSE_WEIGHT_DENSITY	200.0f

inline DWORD WeightConvertFloatToByte(float weight)
{
	if (weight > MAX_DIFFUSE_WEIGHT)
		weight = MAX_DIFFUSE_WEIGHT;

	if (weight < 0.0f)
		weight = 0.0f;

	float adj_weight = (weight / MAX_DIFFUSE_WEIGHT);

	DWORD	dwWeight = (DWORD)(adj_weight * MAX_DIFFUSE_WEIGHT_DENSITY);
	return dwWeight;
}

inline float GetWeightFromDiffuseColor(DWORD dwDiffuseColor)
{
	float	adj_weight = (float)((dwDiffuseColor & 0xff000000) >> 24) * 1.0f / MAX_DIFFUSE_WEIGHT_DENSITY;
	float	weight = adj_weight * MAX_DIFFUSE_WEIGHT;
	return weight;
}


inline BOOL IsDiffuseAlphaToMul(DWORD dwDiffuseColor)
{
	DWORD	dwAlphaElement = (dwDiffuseColor & 0xff000000);
	BOOL	bResult = ((dwAlphaElement == 0xff000000) | (dwAlphaElement == 0x00000000)) == 0;
	return bResult;
}
enum GXTRIGGER_TYPE
{
	// 최상위 8비트는 GXMAP_OBJECT_COMMON_FLAG 영역이므로 사용하지 않는다.
	GXTRIGGER_TYPE_MOVABLE = 0x00000001

};
#define GX_LIGHT_TYPE_TEX_INDEX_0		= 0x00000000
//////////////////////////////////////////////////////////////////////////////////////////////

enum SPRITE_CREATE_FLAG
{
	SPRITE_CREATE_DEFAULT = 0x00000000,
	SPRITE_CREATE_IMAGE = 0x00000001,
	SPRITE_WITHOUT_IMAGE = 0x00000010
};
enum TEXTURE_CREATE_FLAG
{
	TEXTURE_CREATE_RENDER_DEFAULT = 0x00000000,
	TEXTURE_CREATE_RENDER_TARGET = 0x00000001,
	TEXTURE_CREATE_SYSTEM_MAMANGED = 0x00000000,
	TEXTURE_CREATE_SYSTEM_MEMEORY = 0x00000100,
	TEXTURE_CREATE_SYSTEM_VIDEO = 0x00000200,
};


enum MATERIAL_TYPE
{
	MATERIAL_TYPE_2SIDE = 0x00000100

};
enum HEIGHT_FIELD_UPDATE_TYPE
{
	HEIGHT_FIELD_UPDATE_TYPE_TEXTURE = 0x00000000,
	HEIGHT_FIELD_UPDATE_TYPE_VERTEX_POS = 0x00000001
};


enum SCENE_GRAPH_INSERT_TYPE
{
	SCENE_GRAPH_INSERT_ABSOLUTELY_ONLY_GRID = 0x00000001,	// 파티클
	SCENE_GRAPH_NOT_INSERT = 0x00000002,			// 넣지 않음. 예를 들면 어태치된 오브젝트들..
	SCENE_GRAPH_OCCLUSION_MESH = 0x00000004,
	SCENE_GRAPH_INSERT_SCENE_TREE = 0x00000008,
	SCENE_GRAPH_AS_AABB_IN_SCENE_TREE = 0x00000010,
	SCENE_GRAPH_INSERT_ALLOW_GRID = 0x00000020	// HField
};
enum SCENE_GRAPH_READ_TYPE
{
	SCENE_GRAPH_READ_TYPE_NOT_USE_STATIC_COL_MESH = 0x00000001
};
enum SCENE_TREE_MESH_TYPE
{
	SCENE_TREE_MESH_TYPE_ELLIPSOID = 0,
	SCENE_TREE_MESH_TYPE_AABB = 1
};
enum EDIT_ALPHA_TEXEL_TYPE
{
	EDIT_ALPHA_TEXEL_OP_ADD = 0x01000000,
	EDIT_ALPHA_TEXEL_OP_SUB = 0x02000000,
	EDIT_ALPHA_TEXEL_BRIGHT_0 = 0x00000000,
	EDIT_ALPHA_TEXEL_BRIGHT_1 = 0x00000001,
	EDIT_ALPHA_TEXEL_BRIGHT_2 = 0x00000002,
	EDIT_ALPHA_TEXEL_BRIGHT_3 = 0x00000004
};
#define EDIT_ALPHA_TEXEL_OP_MASK		0xff000000
#define EDIT_ALPHA_TEXEL_BRIGHT_MASK	0x00000003

enum POSITION_STATE
{
	UP = 0,
	LEFT = 1,
	DOWN = 2,
	RIGHT = 3
};
#define	MATERIAL_TYPE_2SIDE_MASK	0x0000000f

#ifndef _MAX_EXP
// CUDA의 DEVICE코드에서의 사용을 위해 const float대신 #define을 사용한다.
#define PI			3.14159265358979323846f // Pi
#define PI_MUL_2	6.28318530717958623200f // 2 * Pi
#define PI_DIV_2	1.57079632679489655800f // Pi / 2
#define PI_DIV_4	0.78539816339744827900f // Pi / 4
#define INV_PI		0.31830988618379069122f // 1 / Pi
#define EPSILON		1.0e-5f;                 // Tolerance for FLOATs
#endif

#define R_565_MASK	0x0000F800
#define G_565_MASK	0x000007E0
#define B_565_MASK	0x0000001F

struct DWORD_RECT
{
	DWORD		left;
	DWORD		top;
	DWORD		right;
	DWORD		bottom;
};
struct FLOAT_RECT
{
	float	fLeft;
	float	fTop;
	float	fRight;
	float	fBottom;
};




union COLORVALUE
{
	struct
	{
		float	b;
		float	g;
		float	r;
		float	a;
	};
	float		value[4];
};
union COLOR3
{
	struct
	{
		float	r;
		float	g;
		float	b;

	};
	float		value[3];
	void	Set(float rr, float gg, float bb) { r = rr; g = gg; b = bb; }
};

struct TVERTEX
{
	float u;
	float v;
};

struct TPVERTEX
{
	float	x;
	float	y;
	float	z;
	float	tu;
	float	tv;
};

#define FILE_SCENE_HEADER_VERSION_4 0x00000004	// 아웃라인 검출용 element id추가.
#define FILE_SCENE_HEADER_VERSION_5 0x00000005	// decomp_affine에서 flip scale변환 항목 추가. 대신 NODE_TM에서 mat4Inverse멤버 제거
#define FILE_SCENE_HEADER_VERSION_CURRENT FILE_SCENE_HEADER_VERSION_5

struct NODE_TM
{
	//ptm = position component (t)
	//rtm = "essential" rotation (q)
	//srtm = "stretch" rotation (u)
	//stm = scale component (k)
	//ftm = the flip tm -> ScaleMatrix(Point3(ap.f,ap.f,ap.f));

	//Here's the correct way of reassembling the decomposed matrix:
	//Matrix3 srtm, rtm, ptm, stm, ftm;
	//ptm.IdentityMatrix();
	//ptm.SetTrans(ap.t); 
	//ap.q.MakeMatrix(rtm);
	//ap.u.MakeMatrix(srtm);
	//stm = ScaleMatrix(ap.k);
	//mat = Inverse(srtm) * stm * srtm * rtm * ftm * ptm;

	float		fRotAng;								// max에서 ap.q rotation - rad
	float		fPosX, fPosY, fPosZ;					// max에서 ap.t translation
	float		fRotAxisX, fRotAxisY, fRotAxisZ;		// max에서 ap.q rotation - axis
	float		fScaleX, fScaleY, fScaleZ;				// max에서 ap.k , scale
	float		fScaleAxisX, fScaleAxisY, fScaleAxisZ;	// max에서 ap.u , stretched rotation
	float		fScaleAngle;
	MATRIX4		mat4;
	union
	{
		struct
		{
			float reserved_value[16];//		MATRIX4		mat4Inverse; ver 4까지 Inverse(TM)
		};
		struct
		{
			float fFlipScale;	// max에서 ap.f 성분. flip scale
		};
	};

};


enum SHADOW_TYPE
{
	SHADOW_TYPE_NONE_SHADOW = 0x00000000,
	SHADOW_TYPE_STATIC_SHADOW = 0x00000001,
	SHADOW_TYPE_DYNAMIC_SHADOW = 0x00000002
};
#define SHADOW_TYPE_MASK			0x00000003
#define SHADOW_TYPE_MASK_INVERSE	~(SHADOW_TYPE_MASK)



struct LIGHT_DESC
{
	VECTOR3			v3Point;
	float			fRs;
	DWORD			dwColor;
	DWORD			dwShadowType;
};

struct DYNAMIC_LIGHT_DESC
{
	VECTOR3			v3Point;
	float			fRs;
	DWORD			dwColorCenter;
	DWORD			dwColorSide;
};

struct DIRECTIONAL_LIGHT_DESC
{
	DWORD			dwAmbient;
	DWORD			dwDiffuse;
	DWORD			dwSpecular;
	VECTOR3			v3Dir;
	BOOL			bEnable;
};

struct LIGHT_INDEX_DESC
{
	BYTE		bLightIndex;
	BYTE		bTexOP;
	BYTE		bReserved2;
	BYTE		bReserved3;

};

struct INDEX_POS
{
	DWORD		dwX;
	DWORD		dwY;
};

// 필드용
struct WORD_POS
{
	WORD		wX;
	WORD		wZ;
};

struct BYTE_POS
{
	BYTE	x;
	BYTE	y;
	BYTE	z;
	BYTE	reserved;
};
struct BYTE2
{
	BYTE	x;
	BYTE	y;
};
struct TILE_POS_BUFFER
{
	DWORD				dwNum;
	WORD_POS			wPos[1];
};
struct TILE_POS_ENTRY_BUFFER
{
	DWORD		dwTileIndex;
	DWORD		dwTriNum;
	DWORD		dwStartIndex;
	BOOL		bVisible;
};

struct DOUBLE_PLANE
{
	DOUBLE_VECTOR3		v3Up;
	float				D;
};

struct AABB
{
	VECTOR3	Min;
	VECTOR3	Max;
};
struct INT_AABB
{
	INT_VECTOR3 Min;
	INT_VECTOR3 Max;
};
struct PLANE
{
	VECTOR3		v3Up;
	float		D;
};
#define PLANE_D_OFFSET	VECTOR3_SIZE


struct PLANE_EXT : PLANE
{
	VECTOR3		v3Tri[3];
};


struct PATCH;
struct TEXTURE_PLANE
{
	VECTOR3			v3Normal;
	VECTOR3			v3Rect[4];
	DWORD			dwEntryPosX;
	DWORD			dwEntryPosY;
	PLANE			plane;
	DWORD			dwReserved;
	DWORD			dwPatchNum;
	PATCH*			pPatch;
	DWORD			dwTexelSize;
};
class CBaseObject;
class CMeshObject;

#pragma pack(push,1)

struct TGA_HEADER
{
	char idLength;
	char ColorMapType;
	char ImageType;
	WORD ColorMapFirst;
	WORD ColorMapLast;
	char ColorMapBits;
	WORD FirstX;
	WORD FirstY;
	WORD width;
	WORD height;
	char Bits;
	char Descriptor;
};
#pragma pack(pop)

#define	MAXEXP_MAX_MATERIAL_NUM		65536		
#ifdef _MAX_EXP

struct FACE
{
	WORD		a;
	WORD		b;
	WORD		c;
	WORD		mtlid;
	VECTOR3		v3Normal[3];
};
struct TFACE
{
	WORD		a;
	WORD		b;
	WORD		c;
	WORD		Flags;
};

#define	MAX_PHYSIQUE_OBJECT_NUM		512

struct POINT3D_REF_TVERTEX
{
	VECTOR3*				pv3Point;
	TVERTEX*				ptv;
	POINT3D_REF_TVERTEX*	pNext;
	WORD					wIndex;

};
struct PATCH
{
	VECTOR3			v3Point;
	VECTOR3			v3Normal;
	float			fDistance;
	DWORD			dwColor;
	DWORD			sx;
	DWORD			sy;
	TEXTURE_PLANE*	pTexPlane;
};


#else

struct PATCH
{
	DWORD		dwColor;
	VECTOR3		v3Point;
	WORD		sx;
	WORD		sy;
	DWORD		dwLightColor[4];
};

#define		PATCH_SX_OFFSET				4+VECTOR3_SIZE
#define		PATCH_SY_OFFSET				4+VECTOR3_SIZE+2
#define		PATCH_LIGHT_COLOR_OFFSET	4+VECTOR3_SIZE+2+2
#define		PATCH_SIZE					36				


#endif

#pragma pack(push,1)


union LINE2D
{
	struct
	{
		VECTOR2		v2Start;
		VECTOR2		v2End;
	};
	VECTOR2			v2Point[2];
};

union LINE3D
{
	struct
	{
		VECTOR3		v3Start;
		VECTOR3		v3End;
	};
	VECTOR3			v3Point[2];
};

union EDGE
{
	struct
	{
		VECTOR3		v3Start;
		VECTOR3		v3End;
	};
	VECTOR3	v3Point[2];

};

class CBaseObject;

struct BONE_OLD
{
	DWORD			dwBoneObjectIndex;		// 포인터를 대신하는인덱스
	float			fWeight;
	VECTOR3			v3Offset;
	VECTOR3			v3NormalOffset;
};


struct BONE
{
	DWORD			dwBoneObjectIndex;		// 포인터를 대신하는인덱스
	float			fWeight;
	VECTOR3			v3Offset;
	VECTOR3			v3NormalOffset;
	VECTOR3			v3TangentOffset;
};

struct BONE_LITE
{
	DWORD			dwBoneObjectIndex;		// 포인터를 대신하는인덱스
	float			fWeight;
	DWORD			dwLinearMatrixIndex;
};


struct BONE_MAX_EXP : BONE
{
	void*			pBoneObject;
};

struct PHYSIQUE_VERTEX_MAX_EXP
{
	BYTE				bBonesNum;
	BONE_MAX_EXP*		pBoneList;
};



struct PHYSIQUE_VERTEX_IN_FILE
{
	BYTE			bBonesNum;
	DWORD			dwBoneListEntryIndex;
};
#pragma pack(pop)

#pragma pack(push,4)
struct PHYSIQUE_VERTEX
{
	VECTOR3				v3Pos;			// 0
	VECTOR3				v3Normal;		// 12
	VECTOR3				v3Tangent;		// 24
	TVERTEX				tv;				// 36

	BYTE				bBonesNum;		// 44
	BYTE				bReserved0;		// 45
	BYTE				bReserved1;		// 46
	BYTE				bReserved2;		// 47
	BONE_LITE*			pBoneList;		// 48

};
#pragma pack(pop)


#define BONE_OLD_SIZE			32
#define BONE_SIZE				32+12



#define		PHYSIQUE_VERTEX_SIZE_X86	52
#define		BONE_LITE_SIZE				12

#define		BONE_NUM_OFFSE_IN_PHYVERTEX		44
#define		BONE_ENTRY_OFFSE_IN_PHYVERTEX	48

#define		POS_OFFSET_IN_PHYVERTEX			0
#define		NORMAL_OFFSET_IN_PHYVERTEX		12
#define		TANGENT_OFFSET_IN_PHYVERTEX		24
#define		TEXCOORD_OFFSET_IN_PHYVERTEX	36



struct COLLISION_FACE
{
	VECTOR3		v3Point[3];
	VECTOR3		v3Up;
	float		D;

};

#define TEXMAP_FILE_NAME_BUFFER_LEN		64
struct MATERIAL
{

	DWORD			dwTextureNum;
	DWORD			dwDiffuse;
	DWORD			dwAmbient;
	DWORD			dwSpecular;
	float			fTransparency;
	float			fShine;
	float			fShineStrength;
	char			szDiffuseTexmapFileName[TEXMAP_FILE_NAME_BUFFER_LEN];			// 0
	char			szToonTexMapFileName[TEXMAP_FILE_NAME_BUFFER_LEN];				// 1
	char			szReflectTexmapFileName[TEXMAP_FILE_NAME_BUFFER_LEN];			// 2
	char			szReservedTexmapFileName0[TEXMAP_FILE_NAME_BUFFER_LEN];		// 3
	char			szBumpTexmapFileName[TEXMAP_FILE_NAME_BUFFER_LEN];				// 4
	char			szReservedTexmapFileName1[TEXMAP_FILE_NAME_BUFFER_LEN];		// 5	

	DWORD			dwFlags;

	DWORD			GetFlags() { return dwFlags; }
	char*			GetDiffuseTexmapName() { return szDiffuseTexmapFileName; }
	char*			GetReflectTexmapName() { return szReflectTexmapFileName; }
	char*			GetBumpTexmapName() { return szBumpTexmapFileName; }
	char*			GetToonTexmapName() { return szToonTexMapFileName; }

	DWORD			GetDiffuse() { return dwDiffuse; }
	DWORD			GetAmbient() { return dwAmbient; }
	DWORD			GetSpecular() { return dwSpecular; }
	float			GetTransparency() { return fTransparency; }
	float			GetShine() { return fShine; }
	float			GetShineStrength() { return fShineStrength; }
};

struct MATERIAL_TABLE
{
	MATERIAL*		pMtl;
	DWORD			dwMtlIndex;
};

struct TEX_MTL_KR_KT
{
	// for raytraicing , 텍스처별로 추가적인 재질(반사,투명도) 설정
	char	szTexFileName[TEXMAP_FILE_NAME_BUFFER_LEN];
	float	Kr;	// 반사
	float	Kt;	// 투명도
};


struct VIEW_VOLUME
{
	VECTOR3		From;		// 카메라의 위치.
	VECTOR3		To;
	float		fFar;		// 시점으로부터 가장 먼곳의 거리.
	BOOL		bIsOrtho;
	float		fWidth;		// 오쏘그래픽일 경우만 유효하다.
	PLANE		Plane[6];	// 순서대로 왼쪽, 오른쪽, 아래, 위, far, near			2004년 11월 4일 고치다.
	VECTOR3		v3From[4];
	VECTOR3		v3To[4];	// 각각 From 입장에서 far를 볼 때, 뷰볼륨의 오른쪽위, 왼쪽위, 왼쪽아래, 오른쪽아래.
};
#define VIEW_VOLUME_PLANE_INDEX_FAR		4
#define VIEW_VOLUME_PLANE_INDEX_NEAR	5

// 매트릭스가 선형으로 배치되는 경우에 어떻게 배치될지를 결정하는 테이블
// 쉐이더 상수땜에 쓴다.
struct MATRIX_TRANSLATE_INDEX
{
	DWORD		dwLinearIndex;

};

struct MESH_DESC
{
	DWORD					dwVertexNum;
	DWORD					dwTotalFacesNum;
	VECTOR3*				pv3WorldList;
	VECTOR3*				pv3LocalList;
	DWORD					dwTexVertexNum;
	TVERTEX*				ptvTexCoordList;

	MATRIX4*				pMatrixWorldInverse;

	DWORD					dwFaceGroupNum;

	// physique
	DWORD					dwPhysiqueVertexNum;
	PHYSIQUE_VERTEX*		pPhyVertexList;


	VECTOR3*				pv3NormalLocal;
	VECTOR3*				pv3TangentULocal;
	DWORD*					pdwElementIDList;
	char					szLightTexFileName[MAX_NAME_BUFFER_LEN];
	char					szObjName[MAX_NAME_BUFFER_LEN];

	CMeshFlags				meshFlags;
};


struct CAMERA_DESC_COMMON
{
	VECTOR3			v3From;
	VECTOR3			v3Up;			// 카메라의 up.
	VECTOR3			v3EyeDir;
	float			fNear;
	float			fFar;

};
struct CAMERA_DESC : CAMERA_DESC_COMMON
{
	VECTOR3			v3To;
	float			fXRot;
	float			fYRot;
	float			fZRot;
	float			fFovX;
	float			fFovY;
	float			fAspect;
	float			fZoomScale;
	BOOL			bOrtho;

};


class CMaterial;

struct FACE_DESC
{
	WORD*			pIndex;				// face index 배열 포인터 
	DWORD			dwFacesNum;			// face갯수
	DWORD			dwMtlIndex;			// 매터리얼 인덱스
	MATERIAL*		pMaterial;			// material 
	TVERTEX*		ptUVLight0;			// 라이트 텍스쳐용 uv좌표.면순서와 1:1 대응 
	DWORD*			pdwMtlIndex;		// 매터리얼 인덱스 
};



struct IVERTEX
{
	float			x;
	float			y;
	float			z;


	float			nx;
	float			ny;
	float			nz;

	float			u0;
	float			v0;

	float			u1;
	float			v1;


	DWORD			dwMeshObjectIndex;
	DWORD			dwFaceGroupIndex;
	DWORD			dwFaceIndex;
	DWORD			dwMtlIndex;
	void*			pDataExt;
};

enum MOTION_INTPR_TYPE
{
	MOTION_INTPR_TYPE_OFF_INTPR = 0x00000000,
	MOTION_INTPR_TYPE_ON_INTPR = 0x00000001,
	MOTION_INTPR_TYPE_DISABLE_SET_FRAME = 0x00000002,
	MOTION_INTPR_TYPE_ON_INTPR_AND_DISABLE_SET_FRAME = (MOTION_INTPR_TYPE_ON_INTPR | MOTION_INTPR_TYPE_DISABLE_SET_FRAME)
};
struct MOTION_DESC
{
	DWORD					dwTicksPerFrame;
	DWORD					dwFirstFrame;
	DWORD					dwLastFrame;
	DWORD					dwFrameSpeed;
	DWORD					dwKeyFrameStep;
	char					szMotionName[MAX_NAME_BUFFER_LEN];
};

struct MATERIAL_LIB_DESC
{
	char					szMtlFileName[MAX_NAME_BUFFER_LEN];
	DWORD					dwMtlTableNum;
	MATERIAL_TABLE*			pMtlTable;
};


struct MOTION_INTP_PARAM
{
	WORD		wFromMotionIndex;
	WORD		wFromFrame;

	WORD		wToMotionIndex;
	WORD		wToFrame;
};

struct MODEL_STATUS
{
	DWORD		dwFrame;
	DWORD		dwMotionIndex;
	DWORD		dwLODLevel;
	float		fDistanceFromView;
	float		fDistanceFactor;
	BOOL		bBLASUpdated;
	void*		pMotion;

	//
	BOOL		bAxisAlignOK;

};



struct MOTION_STATUS
{
	DWORD		dwFrame;
	DWORD		dwMotionIndex;
	void*		pMotionUID;

	BOOL		bMotionIntp;
	MOTION_INTP_PARAM	motionIntpParam;

};


struct VERTEXT_LIST
{
	VECTOR3*		pv3PointList;
	DWORD			dwVertexNum;
	DWORD			dwMaxVertexNum;
};

union INDEXED_EDGE
{
	DWORD			dwIndex[2];
	struct
	{
		DWORD		dwStart;
		DWORD		dwEnd;
	};
};

enum POLYGON_FLAG
{
	POLYGON_FLAG_CHECKED = 0x00000001,
	POLYGON_FLAG_NOT_MESH = 0x00000002,
	POLYGON_FLAG_OVERLAPPED = 0x00000004

};
struct POLYGON
{
	void*				pPolygonTool;
	DWORD				dwMaxEdgeNum;

	DWORD				dwEdgeNum;
	DWORD				dwSize;
	DWORD				dwTexVertexOffset;
	DWORD				dwNormalVertexOffset;

	DWORD				dwFlags;
	void*				pData;

	POLYGON*			pPrv;
	POLYGON*			pNext;

	PLANE				plane;

	INDEXED_EDGE		edge[1];

public:
	TVERTEX* GetTexVertex(DWORD dwIndex) const
	{
		return (TVERTEX*)((char*)this + dwTexVertexOffset + dwIndex * sizeof(TVERTEX) * dwEdgeNum);
	}
	VECTOR3* GetNormalVertex() const
	{
		return (VECTOR3*)((char*)this + dwNormalVertexOffset);
	}

	void	Check() { dwFlags |= POLYGON_FLAG_CHECKED; }
	DWORD	IsChecked() const { return (dwFlags & POLYGON_FLAG_CHECKED); }

	void	SetNotMesh() { dwFlags |= POLYGON_FLAG_NOT_MESH; }
	DWORD	IsNotMesh() const { return (dwFlags & POLYGON_FLAG_NOT_MESH); }

	DWORD	GetTriNum() const { return dwEdgeNum - 2; }

};
#define MAX_EDGE_NUM_PER_POLYGON		32

const DWORD TRI_NUM_PER_BOX = 12;

struct BOUNDING_BOX
{
	VECTOR3			v3Oct[8];
	void SetWithAABB(const VECTOR3* pv3Min, const VECTOR3* pv3Max)
	{
		float	min_x = pv3Min->x;
		float	min_y = pv3Min->y;
		float	min_z = pv3Min->z;

		float	max_x = pv3Max->x;
		float	max_y = pv3Max->y;
		float	max_z = pv3Max->z;

		v3Oct[0].x = min_x;
		v3Oct[0].y = max_y;
		v3Oct[0].z = max_z;

		v3Oct[1].x = min_x;
		v3Oct[1].y = min_y;
		v3Oct[1].z = max_z;

		v3Oct[2].x = max_x;
		v3Oct[2].y = min_y;
		v3Oct[2].z = max_z;

		v3Oct[3].x = max_x;
		v3Oct[3].y = max_y;
		v3Oct[3].z = max_z;

		v3Oct[4].x = min_x;
		v3Oct[4].y = max_y;
		v3Oct[4].z = min_z;

		v3Oct[5].x = min_x;
		v3Oct[5].y = min_y;
		v3Oct[5].z = min_z;

		v3Oct[6].x = max_x;
		v3Oct[6].y = min_y;
		v3Oct[6].z = min_z;

		v3Oct[7].x = max_x;
		v3Oct[7].y = max_y;
		v3Oct[7].z = min_z;
	}
};

struct BOUNDING_SPHERE
{
	VECTOR3			v3Point;
	float			fRs;
};

struct BOUNDING_CYLINDER
{
	VECTOR3			v3Point;
	float			fRs;
	float			fAy;
};

struct BOUNDING_CAPSULE
{
	VECTOR3			v3From;
	VECTOR3			v3To;
	float			fRadius;
};

struct COLLISION_MESH_OBJECT_DESC_SAVELOAD
{
	BOUNDING_BOX		boundingBox;
	BOUNDING_SPHERE		boundingSphere;
	BOUNDING_CYLINDER	boundingCylinder;
	DWORD				dwObjIndex;
	char				szObjName[MAX_NAME_BUFFER_LEN];
};

struct COLLISION_MESH_OBJECT_DESC
{
	BOUNDING_BOX		boundingBox;
	BOUNDING_SPHERE		boundingSphere;
	BOUNDING_CYLINDER	boundingCylinder;
	DWORD				dwObjIndex;
};


struct COLLISION_MODEL_DESC
{
	COLLISION_MESH_OBJECT_DESC	colMeshModel;
	DWORD						dwColMeshObjectDescNum;
	COLLISION_MESH_OBJECT_DESC	colMeshObjectDesc[1];
};
struct OBJ_REF_DESC
{
	COLLISION_MESH_OBJECT_DESC	colMeshDescLocal;
	COLLISION_MESH_OBJECT_DESC	colMeshDescWorld;
	MATRIX4						matResult;
	MODEL_STATUS				modelStatus;
};

struct IMAGE_HEADER
{
	DWORD				dwWidth;
	DWORD				dwHeight;
	DWORD				dwPitch;
	DWORD				dwBPP;
};
struct IMAGE_DESC
{
	IMAGE_HEADER	imgHeader;
	char*			pBits;
};

struct TEXTURE_TABLE
{
	WORD		wIndex;
	char		szTextureName[MAX_NAME_BUFFER_LEN];

};
struct PACKFILE_NAME_TABLE
{
	char	szFileName[_MAX_PATH];
	DWORD	dwFlags;
};
struct HFIELD_CREATE_DESC
{
	float			left;
	float			top;
	float			right;
	float			bottom;
	float			fFaceSize;
	DWORD			dwFacesNumPerObjAxis;
	DWORD			dwObjNumX;
	DWORD			dwObjNumZ;
	DWORD			dwDetailLevelNum;
	DWORD			dwIndexBufferNumLV0;
	TEXTURE_TABLE*	pTexTable;
	DWORD			dwTileTextureNum;
	DWORD			dwLightMapDetail;


};
#pragma pack(push,4)

struct HFIELD_DESC_FILE_HEADER
{
	float			left;
	float			top;
	float			right;
	float			bottom;
	float			fFaceSize;

	DWORD			dwFacesNumPerObjAxis;
	DWORD			dwObjNumX;
	DWORD			dwObjNumZ;
	BYTE			bDetailLevelNum;
	BYTE			bReserved0;
	BYTE			bReserved1;
	BYTE			bBlendEnable;
	DWORD			dwIndexBufferNumLV0;



	DWORD			dwReserved;
	DWORD			dwYFNumX;
	DWORD			dwYFNumZ;
	float			width;
	float			height;
	DWORD			dwFacesNumX;
	DWORD			dwFacesNumZ;
	DWORD			dwTriNumPerObj;
	DWORD			dwVerticesNumPerObj;

	DWORD			dwFacesNumPerTileAxis;
	DWORD			dwTileNumPerObjAxis;
	DWORD			dwTileNumX;
	DWORD			dwTileNumZ;
	float			fTileSize;
};
#pragma pack(pop)


struct HFIELD_DESC : HFIELD_DESC_FILE_HEADER
{
	float*			pyfList;
	VECTOR3*		pv3NormalList;

	void			GetHFieldCreateDesc(HFIELD_CREATE_DESC* pOutDesc)
	{
		pOutDesc->left = left;
		pOutDesc->top = top;
		pOutDesc->right = right;
		pOutDesc->bottom = bottom;
		pOutDesc->fFaceSize = fFaceSize;
		pOutDesc->dwFacesNumPerObjAxis = dwFacesNumPerObjAxis;
		pOutDesc->dwObjNumX = dwObjNumX;
		pOutDesc->dwObjNumZ = dwObjNumZ;
		pOutDesc->dwDetailLevelNum = (DWORD)bDetailLevelNum;
		pOutDesc->dwIndexBufferNumLV0 = dwIndexBufferNumLV0;
		pOutDesc->pTexTable = nullptr;
		pOutDesc->dwTileTextureNum = 0;
		pOutDesc->dwLightMapDetail = 0;
	}

};



struct HFIELD_OBJECT_DESC
{
	DWORD			dwPosX;
	DWORD			dwPosZ;

	DWORD			dwObjPosX;
	DWORD			dwObjPosZ;


};

struct TILE_ENTRY_DESC
{
	// 4가지 경우에 대한 인덱스리스트의 엔트리.
	WORD		wTilePosEntry;
	WORD		wTilePosNum;
};

struct INDEX_ENTRY_DESC
{
	DWORD				dwStartIndex;
	DWORD				dwTriNum;
};


struct ALPHAMAP_DESC
{
	BYTE*				pAlphaMapBits;
	void*				pResource;		// D3DTexture
	SIZE_T				Descriptor;		// for D3D12
	WORD				wWidthHeight;			// max 256 * 256
	BYTE				bBitsPerPixel;
	bool				bVisible;
	BYTE				bProperty;				// update여부, 완전 백색,흑색 체크 등등..
	BYTE				bReserved;

	//	bool				bMustUpdate;

	void*				pCacheHandle;

	// 0x01 update mask 
	// 0x02	all white mask


	void		SetMustUpdate(BOOL bSwitch) { bProperty = (bProperty & (~(0x01))) | bSwitch; }
	BOOL		IsMustUpdate() { return (bProperty & 0x01); }
	BOOL		IsAllWhite() { return (bProperty & 0x02) >> 1; }
	void		SetAllWhite() { bProperty |= 0x02; }
	void		ClearAllWhite() { bProperty &= (~(0x02)); }





};


enum DISPLAY_TYPE
{
	WINDOW_WITH_BLT = 0x00000000,
	FULLSCREEN_WITH_BLT = 0x00000001,
	FULLSCREEN_WITH_FLIP = 0x10000001
};

#define FLIP_MASK			0x10000000
#define FULLSCREEN_MASK		0x00000001

struct DISPLAY_INFO
{
	DISPLAY_TYPE	dispType;
	DWORD			dwWidth;
	DWORD			dwHeight;
	DWORD			dwRefreshRate;
	DWORD			dwBPP;
	BOOL			bSyncRefreshRate;
	float			fScaleFactor;
};

struct TILE_TABLE_DESC
{
	float		fTop;
	float		fLeft;
	float		fBottom;
	float		fRight;

	DWORD		dwTileNumWidth;
	DWORD		dwTileNumHeight;
	DWORD		dwBytesOfTile;
	float		fTileWidth;
	float		fTileHeight;
};


interface IDynamicRenderObject;
interface IDynamicObjectManager;

typedef DWORD(__stdcall *GXSchedulePROC)(IDynamicObjectManager* pObjectManager, IDynamicRenderObject* pObj, DWORD msg, int arg1, int arg2, UINT64 ui64Data);
typedef DWORD(__stdcall *LIGHTMAP_SHADE_CALLBACK)(void* pVoid);
typedef DWORD(__stdcall *LIGHTMAP_AMB_OCC_CALLBACK)(void* pVoid);
typedef DWORD(__stdcall *LIGHTMAP_RADIOSITY_CALLBACK)(void* pVoid);


enum ERROR_TYPE
{
	ERROR_TYPE_ENGINE_CODE = 0,
	ERROR_TYPE_PARAMETER_INVALID = 1,
	ERROR_TYPE_DEVICE_NOT_SUPPROT = 2,
	ERROR_TYPE_D3D_ERROR = 3,
	ERROR_TYPE_RESOURCE_LEAK = 4,
	ERROR_TYPE_FILE_NOT_FOUND = 5,
	ERROR_TYPE_WARNING = 6
};
typedef DWORD(__stdcall *ErrorHandleProc)(ERROR_TYPE type, DWORD dwErrorPriority, void* pCodeAddress, WCHAR* wchStr);


//#include "GXSCHEDULE_PROC_MSG.h"






//	충돌처리용 바운딩 볼륨.
enum	BOUNDING_VOLUME_TYPE
{
	BOUNDING_VOLUME_TYPE_NONE,
	//	BOUNDING_VOLUME_TYPE_PARTICLE,
	BOUNDING_VOLUME_TYPE_SPHERE,
	BOUNDING_VOLUME_TYPE_AAELLIPSOID,
};




//	I3DModel에서 가지게 된다.
//	아직 하나의 MODEL 파일에 하나씩의 충돌 그룹을 갖는다...
struct	BOUNDING_VOLUME
{
	float	fShortRs;	// 단축의 반지름,바운딩 스피어.
	float	fLongRs;	// 장축의 반지름
	DWORD	dwType;		// 바운딩 볼륨의 타입BOUNDING_VOLUME_TYPE. 
};

#define		fFloatMin					1.0f


struct HFPOINT
{
	DWORD	dwPosX;
	DWORD	dwPosZ;
};

typedef void(__stdcall *FRAME_HOOK_CALLBACK_FUNC)(MATRIX4* pMatResult, const MATRIX4* pMatTransform, const NODE_TM* pTM, UINT64 ui64Data, DWORD dwFrame);

struct SET_FRAME_HOOK_DESC
{
	FRAME_HOOK_CALLBACK_FUNC	pFunc;
	UINT64						ui64Data;
};
typedef DWORD(__stdcall *LOAD_CALLBACK_FUNC)(DWORD dwCurCount, DWORD dwTotalCount, void* pArg);
typedef DWORD(__stdcall *GX_FUNC)();
typedef float(__stdcall *SHADE_FUNC)(float fLightRS, float fLightRsRs, float fDistance, float fDistDist, float cosang);


HRESULT typedef (__stdcall *CREATE_INSTANCE_FUNC)(void* ppv);

struct LOAD_CALLBACK_DESC
{
	DWORD				dwTotalCount;
	DWORD*				pdwCurCount;
	LOAD_CALLBACK_FUNC	pFunc;
};

struct TRI_FACE
{
	VECTOR3		v3Point;
	PLANE		plane;
	WORD		wIndex[4];

};
#define TRI_FACE_SIZE			12+16+8
#define TRI_FACE_NORMAL_OFFSET	12
#define TRI_FACE_D_OFFSET		24
#define TRI_FACE_INDEX_OFFSET	28



struct HFIELD_POS
{
	DWORD		dwX;
	DWORD		dwZ;

};

struct FOG_DESC
{
	float	fStart;
	float	fEnd;
	float	fTop;
	float	fBottom;
	float	fDensity;
	DWORD	dwColor;
	BOOL	bEnable;
};
struct	REALTIME_ROT_DESC
{
	BOOL		bEnable;
	float		fRad;
	VECTOR3		v3Axis;
	float		fWeight;
};


struct CASCADE_FRUSTUM
{
	PLANE			planeListWorld[6];
	PLANE			planeTop;
	PLANE			planeBottom;
	BOUNDING_BOX	boxWorld;
	VECTOR3			v3Center;
	float			fNear;
	float			fFar;
	MATRIX4			matProj;
};

#define MAX_CASCADE_NUM	4

struct VIEWPORT
{
	CAMERA_DESC					cameraDesc;

	VIEW_VOLUME					ViewVolume;
	PLANE						planeCameraEye;
	MATRIX4						matViewInverse;
	MATRIX4						matView;
	MATRIX4						matProj;
	MATRIX4						matForBillBoard;
	MATRIX4						matProjForSky;
	DWORD						dwAmbientColor;
	DWORD						dwEmissiveColor;
	RECT						rcClip;
	DWORD						dwClipWidth;
	DWORD						dwClipHeight;

	CASCADE_FRUSTUM				pCascadeFrustumList[MAX_CASCADE_NUM];
	BOOL						bFullScreen;
	BOOL						bUseDynamicShadow;
	BOOL						bPostEffect;
	BOOL						bPostEffectGlow;
	BOOL						bPostEffectDOF;
	BOOL						bUseAdvancedWaterEffect;

	BOOL						bDrawOutLine;
	FOG_DESC					fogDesc;
	float						fOffsetX;		// 2차원 투영 후 흔들기
	float						fOffsetY;
	DIRECTIONAL_LIGHT_DESC		dirLightDesc;

	// 이하는 렌더타겟에 렌더링할때 뷰포트의 옵션들을 싸그리 꺼놓고 복구하기 위한 변수들
	BOOL						bUseDynamicShadowBackup;
	BOOL						bPostEffectBackup;
	BOOL						bPostEffectGlowBackup;
	BOOL						bPostEffectDOFBackup;
	BOOL						bUseAdvancedWaterEffectBackup;

	BOOL						bDrawOutLineBackup;
	BOOL						bEnableFogBackup;

	void	ClearAndBackupOption()
	{
		bUseDynamicShadowBackup = bUseDynamicShadow;
		bPostEffectBackup = bPostEffect;
		bPostEffectGlowBackup = bPostEffectGlow;
		bPostEffectDOFBackup = bPostEffectDOF;
		bUseAdvancedWaterEffectBackup = bUseAdvancedWaterEffect;

		bDrawOutLineBackup = bDrawOutLine;
		bEnableFogBackup = fogDesc.bEnable;

		bUseDynamicShadow = FALSE;
		bPostEffect = FALSE;
		bPostEffectGlow = FALSE;
		bPostEffectDOF = FALSE;
		bUseAdvancedWaterEffect = FALSE;

		bDrawOutLine = FALSE;
		fogDesc.bEnable = FALSE;


	}
	void	RestoreOption()
	{
		bUseDynamicShadow = bUseDynamicShadowBackup;
		bPostEffect = bPostEffectBackup;
		bPostEffectGlow = bPostEffectGlowBackup;
		bPostEffectDOF = bPostEffectDOFBackup;
		bUseAdvancedWaterEffect = bUseAdvancedWaterEffectBackup;

		bDrawOutLine = bDrawOutLineBackup;
		fogDesc.bEnable = bEnableFogBackup;
	}
};

struct PARTIAL_FRUSTM
{
	PLANE	pPlaneList[6];
	DWORD	dwPlaneNum;
	float	min_x;
	float	min_y;
	float	max_x;
	float	max_y;
};

interface I3DModel;
struct MODEL_HANDLE
{
	I3DModel*		pModel;
	DWORD			dwRefIndex;
};



struct DECAL_DESC
{
	VECTOR3			v3Position;					// 데칼이 생기는 시작점.
	VECTOR3			v3FaceDirection;			// 데칼이 보는 방향. 
	VECTOR3			v3UpDirection;				// 데칼의 '위'를 나타내는 벡터. 들어오는 있는 그대로 믿는다.
	VECTOR3			v3XYZScale;					// 각 성분의 길이. 왼손 좌표계 기준으로 데칼의 오른쪽이 X, 윗쪽이 Z, 화면방향이 Y.
	BOOL			bLookAtPivot;
	//	void*			MaterialHandle;
	char			szMaterialName[MAX_NAME_BUFFER_LEN];
	DWORD			dwTextureCoordGenMethod;			// 텍스쳐링 방법. 아직 무효. 실린더매핑밖에 안된다.
	DWORD			dwTTL;								// 타임 투 라이브. 프레임단위. 영원히 할려면 0xffffffff
};


struct SET_FRAME_ARGS
{
	const MATRIX4*				pMatrixEntry;
	const COLLISION_MODEL_DESC*	pColModelDesc;
	const MATRIX4*			pParentMat;
	DWORD					dwMotionIndex;
	DWORD					dwOldMotionIndex;
	DWORD					dwFrame;
	DWORD					dwOldFrame;

	float					fAlphaMotion;
	float					fAlphaFrame;

	MATRIX4					matBillboard;
	MATRIX4					matTransform[2]; // 0은 parent, 1은 transform

	// 애니메이션 간 보간 있을 경우
//	BOOL					bMotionIntp;
//	MOTION_INTP_PARAM		motionIntpParam;
//	DWORD					dwIntpFrame;

	MATRIX4					matWorldForPhysique;




	DWORD					dwFlags;
};

struct FONT_PROPERTY_DESC
{
	// 내용 고정 
	HFONT	hFont;
	int		iWidth;
	int		iHeight;


	// 내용이 바뀔 블럭.
	void*			pszString;
	DWORD			dwStrLen;
	CHAR_CODE_TYPE	type;
};

struct PICK_GXOBJECT_DESC
{
	void*				gxo;
	VECTOR3				v3IntersectPoint;
	float				fDist;
	DWORD				dwModelIndex;
	DWORD				dwObjIndex;
};

struct LOCKED_RECT
{
	INT                 Pitch;
	void*               pBits;
};


enum TEXTURE_FORMAT
{
	TEXTURE_FORMAT_A8R8G8B8,
	TEXTURE_FORMAT_A4R4G4B4,
	TEXTURE_FORMAT_R5G6B5,
	TEXTURE_FORMAT_A1R5G5B5
};

enum TEXGEN_METHOD
{
	TEXGEN_METHOD_REFLECT_SPHEREMAP = 0,
	TEXGEN_METHOD_WAVE = 1
};

struct CUSTOM_EFFECT_DESC
{
	char			szEffectShaderName[32];
	TEXGEN_METHOD	method;
	BOOL			bDisableSrcTex;
	char			szTexName[MAX_NAME_BUFFER_LEN];
	DWORD			dwFlags;
	DWORD			dwReserved1;
	DWORD			dwReserved2;
	DWORD			dwReserved3;
	DWORD			dwReserved4;
};

enum TRANSFORM_MATRIX_TYPE
{
	TRANSFORM_MATRIX_TYPE_VIEW = 0,
	TRANSFORM_MATRIX_TYPE_WORLD = 1,
	TRANSFORM_MATRIX_TYPE_PRJ = 2
};

struct	AFTER_INTERPOLATION_CALL_BACK_ARG
{
	DWORD		dwIncreasedTick;					// 최근 게임 프레임에서 증가된 틱 카운트.
	DWORD		dwTickPerFrame;						// 한 프레임당 배정된 틱.   dwIncreasedTick의 최대값이다.
};

typedef DWORD(__stdcall *AfterInterpolationCallBack)(AFTER_INTERPOLATION_CALL_BACK_ARG* pArg);
// 익스큐티브::Run()에서 위치보간과 랜더링 사이에 호출되는 콜백.
// 카메라를 캐릭터에 붙이거나할 때 쓰면 유용하다.





//typedef DWORD (__stdcall *CollisionTestCallBackProcedure)(COLLISION_RESULT*	pResult);
// 지오메트리에서 충돌처리때 쓰일 콜백.


struct QUAD_NODE
{
	float		left_x;
	float		right_x;
	float		top_z;
	float		bottom_z;
};

#define PLANE_FRONT			1
#define PLANE_BACK			-1
#define PLANE_LEFT			1
#define PLANE_RIGHT			-1

#define PLANE_INCLUDE		0
#define PLANE_INTERSECT		3


#define INVALID_EDGE_SHORT_LENGTH		0x00000001
#define INVALID_EDGE_NOT_CLOSED			0x00000002
#define INVALID_EDGE_NOT_OVERLAPPED		0x00000004



typedef void(__stdcall *TEXTOUT_FUNC)(const void* szTxt, CHAR_CODE_TYPE type);



struct GUID_SCENE_OBJECT
{
	DWORD		dwData;
};

#pragma pack(push,1)
struct NAME_DESC
{
	BYTE		bSize;
	char		bChar[1];
};
#pragma pack(pop)

enum SCENE_GRAPH_RENDER_FLAG
{
	SCENE_GRAPH_RENDER_FLAG_DISABLE_EXTERIOR = 0x00000001,
	SCENE_GRAPH_RENDER_FLAG_DISABLE_INTERIOR = 0x00000002,
	SCENE_GRAPH_RENDER_FLAG_ENABLE_COLLISION_MESH = 0x00000004,
	SCENE_GRAPH_RENDER_FLAG_DISABLE_VOXEL_MESH = 0x00000008
};
/*
struct SHARED_FLAG
{
	DWORD		dwFlags;
	DWORD		dwRefCount;
	DWORD		dwIndexInRenderList;
//	BOOL		bOcclusionPass;
//	BOOL		bIsOcclusionMesh;
};
*/

struct LAYER_COMMON_DESC
{
	DWORD					dwTileTexIndex;
	DWORD					dwLayerNum;
	DWORD					dwLayerIndex;
	BOOL					bVisible;
	char					szName[MAX_LAYER_NAME_LEN];
	DWORD					dwNameLen;
};
struct IVERTEX_BUFFER_DESC
{
	IVERTEX*						pivList;
	DWORD							dwVertexNum;
	DWORD							dwFaceNum;
	COLLISION_MESH_OBJECT_DESC		colMeshObjDesc;
	void*							pExt;
};

struct IVERTEX_QUAD
{
	IVERTEX		pivList[4];
};

struct COLLISION_TRI_MESH
{
	DWORD			dwTriNum;
	VECTOR3*		pv3TriList;
};
#define PID_MOD_FILENAME	"*MOD_FILE_NAME"
#define PID_MOTION_NUM		"*MOTION_NUM"
#define PID_MATERIAL_NUM	"*MATERIAL_NUM"


enum EDIT_TYPE
{
	EDIT_TYPE_NONE = 0x00000000,
	EDIT_TYPE_MOVE = 0x00000001,
	EDIT_TYPE_ROT = 0x00000002,
	EDIT_TYPE_SCALE = 0x00000003,
	EDIT_TYPE_CREATE = 0x00000004,
	EDIT_TYPE_CREATE_FROM_MOD = 0x00000005,
	EDIT_TYPE_DRAW = 0x00000006,
	EDIT_TYPE_BOOLEAN = 0x00000007,
	EDIT_TYPE_CREATE_TRIGGER = 0x0000000f

};

enum WALL_TYPE
{
	WALL_TYPE_INTERIOR = 0x00000000,
	WALL_TYPE_EXTERIOR = 0x00000001
};
#define WALL_TYPE_MASK	0x00000001

typedef void*		ROOM_HANDLE;
typedef void*		PORTAL_HANDLE;
typedef void*		PORTAL_CREATE_ITEM_HANDLE;
typedef void*		GROUP_HANDLE;
typedef void*		OCCLUSION_HANDLE;
typedef void*		ROOM_CUTTER_HANDLE;
typedef void*		SPAWN_POINT_HANDLE;




enum ROOM_INDEX
{
	ROOM_A = 0,
	ROOM_B = 1
};

struct VERTEX_GRID_TRIANGLE
{
	DWORD	dwPointCoord[3];
};

struct INDEXED_TRIANGLE
{
	DWORD		dwPointIndex[3];
};

struct COLOR_TRI
{
	VECTOR3		v3Point[3];
	DWORD		dwColor;
};
struct INDEXED_MESH
{

	DWORD					dwVertexNum;
	DWORD					dwTriNum;
	INDEXED_TRIANGLE*		pTriList;
	VECTOR3*				pv3PointList;
};
struct INDEXED_TRI_PTR
{
	WORD*	pIndex;
	DWORD	Count;
};

struct HIZ_OCC_TEST
{
	BOUNDING_SPHERE	bs;
	BOOL			bTest;
};

#pragma pack(push,4)

struct TRIANGLE
{
	VECTOR3		v3Point[3];
};
struct TEX_TRIANGLE
{
	TVERTEX				tv[3];
};

struct D3DVLVERTEX
{
	float		x;				// 0      
	float		y;				// 4
	float		z;				// 8

	float		nx;				// 12
	float		ny;				// 16
	float		nz;				// 20

	float		tan_x;			// 24
	float		tan_y;			// 28
	float		tan_z;			// 32
	UINT		Property;
	//	float		tu;
	//	float		tv;

};

/*
struct D3DIMMVERTEX
{
	float		x;				// 0
	float		y;				// 4
	float		z;				// 8

	float		nx;				// 12
	float		ny;				// 16
	float		nz;				// 20

	float		tu;				// 24
	float		tv;				// 28
};

*/
struct D3DVLVERTEX_PHYSIQUE
{
	float		x;
	float		y;
	float		z;

	float		nx;
	float		ny;
	float		nz;

	float		tx;
	float		ty;
	float		tz;
	UINT		Property;
	BYTE		bIndex[4];
	//BYTE		bWeight[4];
	float		fWeight[4];


	//	float		tu;
	//	float		tv;
};

struct D3DLVERTEX
{
	float     x;
	float     y;
	float     z;

	DWORD     color;
};

struct D3DTVERTEX
{
	float		x;
	float		y;
	float		z;

	float		u;
	float		v;

};
struct D3DPLLMVERTEX
{
	float		x;			// 0           
	float		y;			// 4
	float		z;			// 8

	float		nx;			// 12
	float		ny;			// 16
	float		nz;			// 20

	float		tx;			// 24
	float		ty;			// 28
	float		tz;			// 32

	float		tu0;        // 36
	float		tv0;		// 40

	float		tu1;		// 44
	float		tv1;		// 48
};

struct HFIELDVERTEX
{
	float		x;
	float		y;
	float		z;

	float		nx;
	float		ny;
	float		nz;
};

struct SNOW_VERTEX
{
	float		x;
	float		fVel; // N cm per sec
	float		z;
};
struct VS_CONSTANT_LIGHT
{
	VECTOR3		v3Pos;
	float		fRsPow;
};
enum NODE_TRI_FLAGS
{
	NODE_TRI_FLAGS_DEFAULT = 0,
	NODE_TRI_FLAGS_OBSTACLE = 0x00000001,
	NODE_TRI_FLAGS_OBSTACLE_CANDIDATE = 0x00000002
};
struct NODE_TRI : TRIANGLE
{
	static const DWORD MAX_AROUND_TRI_NUM = 32;
	VECTOR3		v3BarycentricPoint;
	BYTE		bAroundTriNum;
	BYTE		bCostMulConst;	// 비용 계산할때 곱해줄 상수 기본 1
	BYTE		bReserved2;
	BYTE		bReserved3;
	const NODE_TRI*	ppAroundTriList[MAX_AROUND_TRI_NUM];
	EDGE		pAroundEdgeList[MAX_AROUND_TRI_NUM];
};
#pragma pack(pop)

#if defined(EMULATE_X86_SIMD)
union TRIANGLE_A
{
	VECTOR4	v4Point[3];
	__m128	Point[3];
};
#else
__declspec(align(16)) union TRIANGLE_A
{
	VECTOR4	v4Point[3];
	__m128	Point[3];
};
#endif

struct TEX_GEN_TRIANGLE : TRIANGLE
{
	void*				pFaceGrupPtr;
	DWORD				dwTriIndex;
	VECTOR3				v3ProjPoint[3];
	TVERTEX				tv[3];
};

struct QUADRANGLE
{
	VECTOR3	v3Point[4];
};

union MIN_MAX_AXIS
{
	struct
	{
		float		max_x;
		float		max_y;
		float		max_z;
		float		min_x;
		float		min_y;
		float		min_z;
	};
	float	fStream[6];

};

struct INT_XY
{
	int		x;
	int		y;
};

struct FACE_MESH
{
	WORD		a;
	WORD		b;
	WORD		c;

};
struct UINT2
{
	UINT x;
	UINT y;
};

struct UINT4
{
	UINT x;
	UINT y;
	UINT z;
	UINT w;
};
union COLOR_VALUE
{
	struct
	{
		float r;
		float g;
		float b;
		float a;
	};
	float	rgba[4];
	void Set(float rr, float gg, float bb, float aa) { r = rr; g = gg; b = bb; a = aa; }
	void Set(DWORD dwColor)
	{
		r = (float)((dwColor & 0x00ff0000) >> 16) / 255.0f;		// R
		g = (float)((dwColor & 0x0000ff00) >> 8) / 255.0f;		// G
		b = (float)((dwColor & 0x000000ff)) / 255.0f;			// B;
		a = (float)((dwColor & 0xff000000) >> 24) / 255.0f;		// A
	}
};




#pragma pack(push,1)

union BGR_PIXEL
{
	struct
	{
		BYTE	b;
		BYTE	g;
		BYTE	r;

	};
	BYTE		bColorFactor[3];
};

union BGRA
{
	struct
	{

		BYTE	b;
		BYTE	g;
		BYTE	r;
		BYTE	a;
	};
	BYTE		bColorFactor[4];
};

#ifndef _MAX_EXP
union RGBA
{
	struct
	{
		BYTE	r;
		BYTE	g;
		BYTE	b;
		BYTE	a;
	};
	BYTE		bColorFactor[4];
};
#endif
#pragma pack(pop)

#pragma pack(push,4)

struct LIGHTMAP_PATCH
{
	VECTOR3				v3Pos;
	VECTOR3				v3Normal;
};
#pragma pack(pop)

struct RADIOSITY
{
#ifdef RAIOSITY_16BIT_FLOAT
	HALF3				Radiosity;		// 최종 에너지량(렌더링될 컬러값)
	HALF3				DeltaRadiosity;	// 매 패스마다 받은 에너지량
	void	ClearDeltaRadiosity() { DeltaRadiosity.x = 0; DeltaRadiosity.y = 0; DeltaRadiosity.z = 0; }
	void	ClearRadiosity() { Radiosity.x = 0; Radiosity.y = 0; Radiosity.z = 0; }
#else
	COLOR3				Radiosity;		// 최종 에너지량(렌더링될 컬러값)
	COLOR3				DeltaRadiosity;	// 매 패스마다 받은 에너지량
	void	ClearDeltaRadiosity() { DeltaRadiosity.r = 0.0f; DeltaRadiosity.g = 0.0f; DeltaRadiosity.b = 0.0f; }
	void	ClearRadiosity() { Radiosity.x = 0; Radiosity.y = 0; Radiosity.z = 0; }
#endif
};

#pragma pack(push,1)
struct LIGHT_CUBE
{
	BGRA	pPixel[6];
};

struct LIGHT_PROBE
{
	VECTOR3		v3Pos;
	BGRA	pPixel[6];
};
#define DEFAULT_LIGHT_PROBE_RS		400.0f
#define MAX_LIGHT_PROBE_RS			1200.0f
//#define MIN_RADIOSITY_BRIGHT	0.025f


struct LIGHTMAP_PATCH_GROUP_FILE_HEADER
{
	PLANE				plane;
	WORD				wTexWidth;
	WORD				wTexHeight;
	WORD				wStartX;
	WORD				wStartY;

	VECTOR3				v3Rect[4];			// 꼭지점 네점
	DWORD				dwPatchNum;
	WORD				wSrcTriStartIndex;
	WORD				wSrcTriNum;
};

#pragma pack(pop)

struct LIGHTMAP_PATCH_GROUP
{
	PLANE				plane;
	WORD				wTexWidth;
	WORD				wTexHeight;
	WORD				wStartX;
	WORD				wStartY;

	VECTOR3				v3Rect[4];			// 꼭지점 네점
	DWORD				dwPatchNum;
	// 패치를 만들 당시의 원래의 매쉬 데이타
	WORD				wSrcTriStartIndex;		// LIGHTMAP_DESC가 가지고 있는 버텍스 리스트에서의 스타트 인덱스	
	WORD				wSrcTriNum;				// 삼각형 갯수

	LIGHTMAP_PATCH*		pPatchList;
	WORD*				pwSrcTriIndexList;



};
struct LIGHTMAP_FILE_INFO
{
	BOOL			bExistLightMapRoomMesh;
	BOOL			bExistLightMapHField;
	char			szFileNameRoomMesh[MAX_NAME_BUFFER_LEN];
	char			szFileNameHField[MAX_NAME_BUFFER_LEN];

};

struct SCOORD_VERTEX
{
	TVERTEX*		ptv;
	int				x;
	int				y;
};

struct	LINE_EQ
{
	float	a;
	float	b;
	float	x_const;
	float	y_const;
	BOOL	bConstX;
	BOOL	bConstY;

	LINE_EQ()
	{
		a = 0.0f;
		b = 0.0f;
		x_const = 0.0f;
		y_const = 0.0;
		bConstX = FALSE;
		bConstY = FALSE;
	}

};


struct HPOS_BLOCK
{
	DWORD	dwPosX;
	DWORD	dwPosZ;
	VECTOR3	v3IntersectPoint;
	float	fDist;
};

typedef void* LIGHTMAP_HANDLE;

typedef void* (*RESOURCR_ALLOC_FUNC)(void* pArg1, void* pArg2, void* pArg3, DWORD dwSize);
typedef void(*RESOURCR_FREE_FUNC)(void* pResource);


#define			MAX_TRIGGER_RESOURCE_NAME_LEN		31
#define			MAX_TRIGGER_RESOURCE_BUFFER_SIZE	32



struct EVENT_TRIGGER_DESC
{
	VECTOR3		v3Pos;
	VECTOR3		v3Scale;
	VECTOR3		v3Rot;
	DWORD		dwColor;
	DWORD		dwResourceNameLen;
	char		szResourceName[MAX_TRIGGER_RESOURCE_BUFFER_SIZE];
};

interface ICharacterObject;
interface IDynamicTriggerObject;

typedef int(__stdcall *OnCollisionTriggerFunc)(IDynamicTriggerObject* pTrigger, ICharacterObject* pChr, void* pVoid);

typedef DWORD(__stdcall *OnBeforeRenderFunc)(ICharacterObject* pChrObj, DWORD dwFlags);


struct MOUSE_STATUS
{
	int		iMoveX;
	int		iMoveY;
	int		iMoveZ;
	BYTE	bButtonPress[8];
};

struct	KEYBOARD_STATUS
{
	BYTE	bKeyPress[256];
};


enum LOADING_PROGRESS_STATUS
{
	LOADING_PROGRESS_STATUS_BEGIN = 1,
	LOADING_PROGRESS_STATUS_PROGRESS = 2,
	LOADING_PROGRESS_STATUS_END = 3
};
typedef int(__stdcall *ProgressCallBack)(float fProgress, LOADING_PROGRESS_STATUS status);

interface IMegayuchiRenderer;
typedef int(__stdcall *SHADER_COMPILE_PROGRESS_CALLBACK)(IMegayuchiRenderer* pRenderer, LOADING_PROGRESS_STATUS status, void* pArg);



enum RENDER_MESH_OBJECT_TYPE
{
	RENDER_MESH_OBJECT_TYPE_UNKNOWN = 0,
	RENDER_MESH_OBJECT_TYPE_VLOBJECT = 1,
	RENDER_MESH_OBJECT_TYPE_LMOBJECT = 2,
	RENDER_MESH_OBJECT_TYPE_HFIELD = 3,
	RENDER_MESH_OBJECT_TYPE_BILLBOARDOBJECT = 4,
	RENDER_MESH_OBJECT_TYPE_MIRROROBJECT = 5,
	RENDER_MESH_OBJECT_TYPE_WATEROBJECT = 6,
	RENDER_MESH_OBJECT_TYPE_IMMMESHOBJECT = 7,
	RENDER_MESH_OBJECT_TYPE_SKYOBJECT = 8
};

#define	RENDER_MESH_OBJECT_TYPE_NUM		9

interface	IDITextureMap;
#define LIGHTMAP_OBJECT_NAME_BUFFER_LEN		32


#pragma pack(push,1)

struct DRAW_LIGHTMAP_HISTORY_FILE_HEADER
{
	DWORD		dwVersion;
	DWORD		dwLightMapNum;
	DWORD		dwReserved0;
	DWORD		dwReserved1;
};
struct TEXTURE_DRAW_PROPERTY
{
	TVERTEX		tv;
	DWORD		dwColor;
	DWORD		dwPixelSize;
	float		fDensity;
};



struct LIGHTMAP_DRAW_HISTORY_HEADER
{
	DWORD					dwHFieldObjIndex;						// HFIELD일때, 라이트맵오브젝트식별, -1이면 매쉬오브젝트 그 외에는 필드오브젝트
	DWORD					dwLightMapObjNameLen;
	char					szLightMapObjName[LIGHTMAP_OBJECT_NAME_BUFFER_LEN];	// 매쉬일때라이트맵 식별
	DWORD					dwHistoryItemNum;								// TEXTURE_DRAW_HISTORY_ITEM개수


};

struct TEXTURE_DRAW_HISTORY_ITEM : TEXTURE_DRAW_PROPERTY
{
	DWORD			dwLayerCount;
};
#pragma pack(pop)


struct TEXTURE_DRAW_HISTORY_ITEM_EXT : TEXTURE_DRAW_HISTORY_ITEM
{
	IDITextureMap*		pTexMap;
};
#define DEFAULT_DRAW_RECORD_ITEM_NUM	4096
#define MAX_EDITABLE_TEXTURE_NUM		4096

enum COLLISION_MESH_TREE_BUILD_TYPE
{
	COLLISION_MESH_TREE_BUILD_TYPE_KDTREE = 0,
	COLLISION_MESH_TREE_BUILD_TYPE_BSP = 1
};

inline DWORD CreateEffectIndex(DWORD dwReflectTextureIndex, DWORD dwBottomRenderTexture)
{
	DWORD	dwEffectIndex = (dwReflectTextureIndex & 0x000000ff) | ((dwBottomRenderTexture & 0x000000ff) << 8);
	return dwEffectIndex;
}

inline DWORD GetReflectRenderTextureIndex(DWORD dwEffectIndex)
{
	DWORD dwReflectRenderTextureIndex = (dwEffectIndex & 0x000000ff);
	return dwReflectRenderTextureIndex;
}

inline DWORD GetBottomRenderTextureIndex(DWORD dwEffectIndex)
{
	DWORD dwBottomRenderTextureIndex = (dwEffectIndex & 0x0000ff00) >> 8;
	return dwBottomRenderTextureIndex;

}

struct RADIOSITY_CALC_PROGRESS
{
	DWORD	dwCurPatchCount;
	DWORD	dwTotalPatchCount;
	DWORD	dwCurPassCount;
	DWORD	dwMaxPassCount;
};

struct AMBOCC_CALC_PROGRESS
{
	DWORD	dwCurPatchCount;
	DWORD	dwTotalPatchCount;
};

struct LIGHT_CALC_PROGRESS
{
	DWORD	dwLightCount;
	DWORD	dwTotalLightCount;
};

struct PATCH_BUFFER
{
	DWORD	dwPatchNum;
	DWORD	pdwPatchBuffer[1];
};

struct CUBEMAP_PIXEL_COUNT
{
	DWORD	RedPixels;
	DWORD	BluePixels;
	DWORD	Reserved0;
	DWORD	Reserved1;

};

enum GPU_SELECT_MODE
{
	FIRST_PCI_BUS_ID,
	LAST_PCI_BUS_ID,
	MAX_GFLOPS,
	MIN_GFLOPS,
	SPECIFY_DEVICE_ID,
	GPU_SELECT_MODE_LAST = SPECIFY_DEVICE_ID
};


struct GPU_INFO
{
	char	szDeviceName[256];
	DWORD	sm_per_multiproc;
	DWORD	clock_rate;
	DWORD	multiProcessorCount;
	float	TFlops;
};

// voxels

#define				CHECK_MASK			0x80000000
#define				CHECK_MASK_INVERSE	(~(CHECK_MASK))

//#define COLLECT_BLOCK_METHOD_OLD

// 3d rect
enum RECT_STATUS
{
	RECT_STATUS_USED = 1

};
struct RECT3D
{
	VECTOR3	v3Point[4];
	PLANE	plane;
	DWORD	dwFlags;
};

typedef void* QUERY_HANDLE;

enum CUBEMAP_RENDER_GS_TYPE
{
	CUBEMAP_RENDER_GS_DEFAULT,
	CUBEMAP_RENDER_GS_FRONT_BACK,
	CUBEMAP_RENDER_GS_ZTEST
};

const DWORD MAX_VOXELS_PER_AXIS = 8;
const float MIN_VOXEL_SIZE = 50.0f;
const float MIN_VOXEL_SIZE_HALF = MIN_VOXEL_SIZE * 0.5f;
const float VOXEL_OBJECT_SIZE = (float)MAX_VOXELS_PER_AXIS * MIN_VOXEL_SIZE;
const float VOXEL_OBJECT_SIZE_HALF = VOXEL_OBJECT_SIZE * 0.5f;
const float VOXEL_OBJECT_SIZE_HALF_HALF = VOXEL_OBJECT_SIZE_HALF * 0.5f;
const DWORD TEX_WIDTH_DEPTH_HEIGHT_PER_VOXEL_OBJECT = MAX_VOXELS_PER_AXIS * 2;
const float VOXEL_PATCH_SIZE = MIN_VOXEL_SIZE / 2.0f;
const float VOXEL_PATCH_SIZE_HALF = VOXEL_PATCH_SIZE * 0.5f;	// 패치의 중심점이 필요하기 때문에 이걸로 나눠서 좌표를 계산한다.
const DWORD VOXEL_LIGHT_TEXTURE_WIDTH = 64;
const DWORD	VOXEL_LIGHT_TEXTURE_HEIGHT = 512;
const DWORD MAX_COMPRESSED_VOXELS_PATTERN_TABLE_COUNT = 16;	// 복셀데이터 압축시 2x2x2블럭의 패턴 종류 최대개수
const DWORD VXO_TREE_MAX_DEPTH = 20;
const DWORD	MAX_QUAD_COUNT_FOR_CREATE_COL_TRI_MESH = MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * 6 * 2;
const DWORD MAX_POINT_LIGHT_NUM_IN_VOXEL_WORLD = 256;
const DWORD MAX_POINT_LIGHT_NUM_PER_VOXEL_OBJ = 7;
const DWORD MAX_VOXEL_PALETEED_COLOR_NUM = 256;	// 이 수치가 바뀔 경우 rednerer의 shader도 수정해야한다.
const DWORD MAX_VOXEL_OBJ_NUM_FOR_RAY_TRACING_BUFFER = 65536 * 4;	// CUDA RayTracing Culling을 사용할 경우 최대 복셀 오브젝트 개수

const int	MAX_VOXEL_OBJ_MOVE_OFFSET = 32;	// m단위
const int	VOXEL_OBJ_MOVE_OFFSET_UNIT = 4;	// m단위

#define COMPRESS_COLOR_TABLE_WITH_2x2x2
#define COMPRESS_COLOR_TABLE_WITH_RLE
#ifdef COMPRESS_COLOR_TABLE_WITH_2x2x2
#undef COMPRESS_COLOR_TABLE_WITH_RLE
#endif


#pragma pack(push,1)
union COMPRESSED_COLOR_TABLE_2x2x2
{
	struct
	{
		BYTE	ResPerBlock;			// 범위는 0 - 8, 범위 표편에 4bits, 2x2x2일때 1x1x1개의 해상도 목록이 나오므로 ,4x1x1x1 = 4 bits	범위는 0 - 8 , 4 bits 데이터타입은 없으니 8 bits로 처리
		BYTE	bMinColorList;			// 2x2x2블럭당 최소 컬러값 -> 2x2x2개
		unsigned long pDistTable[2];	// 복셀당 2x2x2블럭 안에서의 컬러 거리 최대 8bits. 8x2x2x2 = 64 bits = 8 bytes
	};
	struct
	{
		BYTE	bOneColor;	// ResPerBlock과 같은 메모리를 공유한다. ResPerBlock의 하위 4 bits는 0-8사이이므로 bAllSameColor를 0b1111로 써넣으면 정상적인 ResPerBlock과 구분할 수 있다.
		BYTE	bColor;
	};
	static DWORD GetHeaderSize()
	{
		return (DWORD)(sizeof(COMPRESSED_COLOR_TABLE_2x2x2) - sizeof(pDistTable));
	}
	BOOL IsOneColor()
	{
		// 모든 복셀이 같은 컬러인지 체크
		BOOL bResult = (bOneColor & 0b1111) == 0b1111;
		return bResult;
	}
};
union COMPRESSED_COLOR_TABLE_4x4x4
{
	struct
	{
		unsigned long pResListPerBlock[1];	// 범위는 0 - 8, 범위 표편에 4bits, 4x4x4일때 2x2x2개의 해상도 목록이 나오므로 , 4x2x2x2 = 32 bits
		BYTE	bMinColorsSize;
		union
		{
			struct
			{
				char	pBuffer[8 + 64];
			};
			struct
			{
				// 최대 사이즈
				BYTE	MinColorList[8];		// 2x2x2블럭당 최소 컬러값 -> 2x2x2개
				unsigned long pDistTable[16];	// 복셀당 2x2x2블럭 안에서의 컬러 거리 최대 8bits. 8x4x4x4 = 512 bits = 64 bytes

			};
		};
	};
	struct
	{
		BYTE	bOneColor;	// pResListPerBlock[0]과 같은 메모리를 공유한다. pResListPerBlock[0]의 하위 4 bits는 0-8사이이므로 bOneColor를 0xff로 써넣으면 정상적인 pResListPerBlock[0]과 구분할 수 있다.
		BYTE	bColor;
	};
	BOOL IsOneColor()
	{
		// 모든 복셀이 같은 컬러인지 체크
		BOOL bResult = (bOneColor & 0b1111) == 0b1111;
		return bResult;
	}
	BYTE* GetUncompressedMinColorsPtr()
	{
		return (BYTE*)pBuffer;
	}
	COMPRESSED_COLOR_TABLE_2x2x2* GetCompressedMinColorsPtr()
	{
		return (COMPRESSED_COLOR_TABLE_2x2x2*)pBuffer;
	}
	unsigned long* GetDistTablePtr()
	{
		unsigned long* pDistTable;
		if (!bMinColorsSize)
		{
			// min 컬러테이블이 압축 안된 경우
			pDistTable = (unsigned long*)((DWORD_PTR)pBuffer + 8);
		}
		else
		{
			// min 컬러테이블이 압축된 경우
			pDistTable = (unsigned long*)((DWORD_PTR)pBuffer + (DWORD_PTR)bMinColorsSize);
		}
		return pDistTable;
	}
	static DWORD GetHeaderSize()
	{
		return (DWORD)(sizeof(COMPRESSED_COLOR_TABLE_4x4x4) - sizeof(pBuffer));
	}
};
union COMPRESSED_COLOR_TABLE_8x8x8
{
	struct
	{
		unsigned long pResListPerBlock[8];	//  범위는 0 - 8, 범위 표편에 4bits, 8x8x8일때 4x4x4개의 해상도 목록이 나오므로, 4x4x4x4 = 256 bits
		BYTE	bMinColorsSize;

		union
		{
			struct
			{
				char	pBuffer[64 + 512];
			};
			struct
			{
				// 최대 사이즈
				BYTE	MinColorList[64];
				unsigned long pDistTable[128];	// 복셀당 2x2x2블럭 안에서의 컬러 거리 최대 8bits. 8x8x8x8 = 4096 bits = 512 bytes
			};
		};
	};
	struct
	{
		BYTE	bOneColor;	// pResListPerBlock[0]과 같은 메모리를 공유한다. pResListPerBlock[0]의 하위 4 bits는 0-8사이이므로 bOneColor를 0xff로 써넣으면 정상적인 pResListPerBlock[0]과 구분할 수 있다.
		BYTE	bColor;
	};
	BOOL IsOneColor()
	{
		// 모든 복셀이 같은 컬러인지 체크
		BOOL bResult = (bOneColor & 0b1111) == 0b1111;
		return bResult;
	}
	BYTE* GetUncompressedMinColorsPtr()
	{
		return (BYTE*)pBuffer;
	}
	COMPRESSED_COLOR_TABLE_4x4x4* GetCompressedMinColorsPtr()
	{
		return (COMPRESSED_COLOR_TABLE_4x4x4*)pBuffer;
	}
	unsigned long* GetDistTablePtr()
	{
		unsigned long* pDistTable;
		if (!bMinColorsSize)
		{
			// min 컬러테이블이 압축 안된 경우
			pDistTable = (unsigned long*)((DWORD_PTR)pBuffer + 64);
		}
		else
		{
			// min 컬러테이블이 압축된 경우
			pDistTable = (unsigned long*)((DWORD_PTR)pBuffer + (DWORD_PTR)bMinColorsSize);
		}
		return pDistTable;
	}
	static DWORD GetHeaderSize()
	{
		return (DWORD)(sizeof(COMPRESSED_COLOR_TABLE_8x8x8) - sizeof(pBuffer));
	}
};
inline constexpr DWORD GetMax2x2x2ColorTableCompressedSize()
{
	return (DWORD)sizeof(COMPRESSED_COLOR_TABLE_8x8x8);
}
union COMPRESSED_MEM_BUFFER
{
	COMPRESSED_COLOR_TABLE_8x8x8	CompressedMem8x8x8;
	COMPRESSED_COLOR_TABLE_4x4x4	CompressedMem4x4x4;
	COMPRESSED_COLOR_TABLE_2x2x2	CompressedMem2x2x2;
	BYTE	pRawColorTable[MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS];
};
#pragma pack(pop)

#pragma pack(push,1)
struct RLE_STREAM
{
	BYTE	Color;
	BYTE	Count;
};
struct RLE_STREAM_HEADER
{
	WORD		wStreamCount;
	RLE_STREAM	pData[1];


};
#pragma pack(pop)
inline constexpr DWORD GetRleStreamSize(DWORD dwStreamCount)
{
	return (DWORD)(sizeof(RLE_STREAM_HEADER) - sizeof(RLE_STREAM) + sizeof(RLE_STREAM) * dwStreamCount);
}


#pragma pack(push,4)
struct VXO_DETAIL_LIST
{
	// 최대 64개까지.
	// 각 오브젝트별 width-detph-height를 저장해둔 테이블.
	// 1,2,4,8 -> 0,1,2,3으로 맵핑하면 2bits로 표현 가능. 2bits x 64 = 128 bits
	// 4 bytes 한 샘플당 16개씩 담는다.
	static const unsigned int MAX_OBJ_NUM = 64;
	unsigned long	pBits[MAX_OBJ_NUM * 2 / 8 / 4];	// 최대 64개일때 128bits, 16Bytes
	void	Init()
	{
		memset(pBits, 0, sizeof(pBits));
	}
	BOOL Set(UINT WidthDepthHeight, unsigned long ObjIndex)
	{
		if (ObjIndex >= MAX_OBJ_NUM)
		{
		#ifdef _DEBUG
			__debugbreak();
		#endif
			return FALSE;
		}

		unsigned long bits_value = 0;
		switch (WidthDepthHeight)
		{
			case 1:
				bits_value = 0;
				break;
			case 2:
				bits_value = 1;
				break;
			case 4:
				bits_value = 2;
				break;
			case 8:
				bits_value = 3;
				break;
			default:
				__debugbreak();
		}
		unsigned long dword_index = ObjIndex / 16;	// obj당 2비트씩, 4바이트 한샘플에 16개씩 들어간다.
		unsigned long bits_index = (ObjIndex % 16) * 2;

		pBits[dword_index] |= (bits_value << bits_index);
		return TRUE;
	}
	BOOL Get(UINT* pOutWidthDepthHeight, unsigned long ObjIndex) const
	{
		if (ObjIndex >= MAX_OBJ_NUM)
		{
		#ifdef _DEBUG
			__debugbreak();
		#endif
			return FALSE;
		}
		unsigned long dword_index = ObjIndex / 16;	// obj당 2비트씩, 4바이트 한샘플에 16개씩 들어간다.
		unsigned long bits_index = (ObjIndex % 16) * 2;

		unsigned long bits_value = (pBits[dword_index] >> bits_index) & 0b11;

		switch (bits_value)
		{
			case 0:
				*pOutWidthDepthHeight = 1;
				break;
			case 1:
				*pOutWidthDepthHeight = 2;
				break;
			case 2:
				*pOutWidthDepthHeight = 4;
				break;
			case 3:
				*pOutWidthDepthHeight = 8;
				break;
			default:
				__debugbreak();
		}
		return TRUE;
	}
	BOOL IsEqualVXODetailList(const VXO_DETAIL_LIST* pObjDetailListTarget) const
	{
		BOOL	bIsEqual = memcmp(pObjDetailListTarget->pBits, pBits, sizeof(pBits)) == 0;
		return bIsEqual;
	}

};
#pragma pack(pop)

interface IVoxelObject;
typedef void (__stdcall *ON_DELETE_VOXEL_OBJ_FUNC)(IVoxelObject* pVoxelObj);

interface IVoxelObjectLite;
typedef void (__stdcall *ON_DELETE_VOXEL_OBJ_LITE_FUNC)(IVoxelObjectLite* pVoxelObjLite);

enum TUNNEL_STATUS_BIT_INDEX
{
	// 직선 터널 
	TUNNEL_STATUS_BIT_INDEX_NEG_X_POS_X = 0,	// X축 터널
	TUNNEL_STATUS_BIT_INDEX_NEG_Y_POS_Y = 1,	// Y축 터널
	TUNNEL_STATUS_BIT_INDEX_NEG_Z_POS_Z = 2,	// Z축 터널

	// 대각선 터널
	TUNNEL_STATUS_BIT_INDEX_NEG_X_NEG_Y = 3,//
	TUNNEL_STATUS_BIT_INDEX_NEG_X_POS_Y = 4,//
	TUNNEL_STATUS_BIT_INDEX_NEG_X_NEG_Z = 5,//
	TUNNEL_STATUS_BIT_INDEX_NEG_X_POS_Z = 6,//
	TUNNEL_STATUS_BIT_INDEX_POS_X_NEG_Y = 7,//
	TUNNEL_STATUS_BIT_INDEX_POS_X_POS_Y = 8,//
	TUNNEL_STATUS_BIT_INDEX_POS_X_NEG_Z = 9,//
	TUNNEL_STATUS_BIT_INDEX_POS_X_POS_Z = 10,//

	TUNNEL_STATUS_BIT_INDEX_NEG_Y_NEG_Z = 11,//
	TUNNEL_STATUS_BIT_INDEX_NEG_Y_POS_Z = 12,//

	TUNNEL_STATUS_BIT_INDEX_POS_Y_NEG_Z = 13,//
	TUNNEL_STATUS_BIT_INDEX_POS_Y_POS_Z = 14//
};

enum VOXEL_OBJECT_TUNNEL_STATUS
{
	// 직선터널
	VOXEL_OBJECT_TUNNEL_NEG_X_POS_X = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_X_POS_X,
	VOXEL_OBJECT_TUNNEL_NEG_Y_POS_Y = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_Y_POS_Y,
	VOXEL_OBJECT_TUNNEL_NEG_Z_POS_Z = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_Z_POS_Z,

	// 대각선 터널
	VOXEL_OBJECT_TUNNEL_NEG_X_NEG_Y = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_X_NEG_Y,
	VOXEL_OBJECT_TUNNEL_NEG_X_POS_Y = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_X_POS_Y,
	VOXEL_OBJECT_TUNNEL_NEG_X_NEG_Z = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_X_NEG_Z,
	VOXEL_OBJECT_TUNNEL_NEG_X_POS_Z = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_X_POS_Z,
	VOXEL_OBJECT_TUNNEL_POS_X_NEG_Y = 1 << TUNNEL_STATUS_BIT_INDEX_POS_X_NEG_Y,
	VOXEL_OBJECT_TUNNEL_POS_X_POS_Y = 1 << TUNNEL_STATUS_BIT_INDEX_POS_X_POS_Y,
	VOXEL_OBJECT_TUNNEL_POS_X_NEG_Z = 1 << TUNNEL_STATUS_BIT_INDEX_POS_X_NEG_Z,
	VOXEL_OBJECT_TUNNEL_POS_X_POS_Z = 1 << TUNNEL_STATUS_BIT_INDEX_POS_X_POS_Z,

	VOXEL_OBJECT_TUNNEL_NEG_Y_NEG_Z = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_Y_NEG_Z,
	VOXEL_OBJECT_TUNNEL_NEG_Y_POS_Z = 1 << TUNNEL_STATUS_BIT_INDEX_NEG_Y_POS_Z,

	VOXEL_OBJECT_TUNNEL_POS_Y_NEG_Z = 1 << TUNNEL_STATUS_BIT_INDEX_POS_Y_NEG_Z,
	VOXEL_OBJECT_TUNNEL_POS_Y_POS_Z = 1 << TUNNEL_STATUS_BIT_INDEX_POS_Y_POS_Z
};
const DWORD TUNNEL_NEG_X_ELEMENT = VOXEL_OBJECT_TUNNEL_NEG_X_POS_X | VOXEL_OBJECT_TUNNEL_NEG_X_NEG_Y | VOXEL_OBJECT_TUNNEL_NEG_X_POS_Y | VOXEL_OBJECT_TUNNEL_NEG_X_NEG_Z | VOXEL_OBJECT_TUNNEL_NEG_X_POS_Z;
const DWORD TUNNEL_POS_X_ELEMENT = VOXEL_OBJECT_TUNNEL_NEG_X_POS_X | VOXEL_OBJECT_TUNNEL_POS_X_NEG_Y | VOXEL_OBJECT_TUNNEL_POS_X_POS_Y | VOXEL_OBJECT_TUNNEL_POS_X_NEG_Z | VOXEL_OBJECT_TUNNEL_POS_X_POS_Z;
const DWORD TUNNEL_NEG_Y_ELEMENT = VOXEL_OBJECT_TUNNEL_NEG_Y_POS_Y | VOXEL_OBJECT_TUNNEL_NEG_X_NEG_Y | VOXEL_OBJECT_TUNNEL_POS_X_NEG_Y | VOXEL_OBJECT_TUNNEL_NEG_Y_NEG_Z | VOXEL_OBJECT_TUNNEL_NEG_Y_POS_Z;
const DWORD TUNNEL_POS_Y_ELEMENT = VOXEL_OBJECT_TUNNEL_NEG_Y_POS_Y | VOXEL_OBJECT_TUNNEL_NEG_X_POS_Y | VOXEL_OBJECT_TUNNEL_POS_X_POS_Y | VOXEL_OBJECT_TUNNEL_POS_Y_NEG_Z | VOXEL_OBJECT_TUNNEL_POS_Y_POS_Z;
const DWORD TUNNEL_NEG_Z_ELEMENT = VOXEL_OBJECT_TUNNEL_NEG_Z_POS_Z | VOXEL_OBJECT_TUNNEL_NEG_X_NEG_Z | VOXEL_OBJECT_TUNNEL_POS_X_NEG_Z | VOXEL_OBJECT_TUNNEL_NEG_Y_NEG_Z | VOXEL_OBJECT_TUNNEL_POS_Y_NEG_Z;
const DWORD TUNNEL_POS_Z_ELEMENT = VOXEL_OBJECT_TUNNEL_NEG_Z_POS_Z | VOXEL_OBJECT_TUNNEL_NEG_X_POS_Z | VOXEL_OBJECT_TUNNEL_POS_X_POS_Z | VOXEL_OBJECT_TUNNEL_NEG_Y_POS_Z | VOXEL_OBJECT_TUNNEL_POS_Y_POS_Z;
const DWORD TUNNEL_ELEMENT_ALL = TUNNEL_NEG_X_ELEMENT | TUNNEL_POS_X_ELEMENT | TUNNEL_NEG_Y_ELEMENT | TUNNEL_POS_Y_ELEMENT | TUNNEL_NEG_Z_ELEMENT | TUNNEL_POS_Z_ELEMENT;
const DWORD TUNNEL_ELEMENT_NONE = 0;

enum PACKED_VOXEL_OBJECT_TUNNEL_STATUS
{
	PACKED_VOXEL_OBJECT_TUNNEL_NONE = 0,
	PACKED_VOXEL_OBJECT_TUNNEL_NEG_X = 0b00000001,
	PACKED_VOXEL_OBJECT_TUNNEL_POS_X = 0b00000010,
	PACKED_VOXEL_OBJECT_TUNNEL_NEG_Y = 0b00000100,
	PACKED_VOXEL_OBJECT_TUNNEL_POS_Y = 0b00001000,
	PACKED_VOXEL_OBJECT_TUNNEL_NEG_Z = 0b00010000,
	PACKED_VOXEL_OBJECT_TUNNEL_POS_Z = 0b00100000,
	PACKED_VOXEL_OBJECT_TUNNEL_ALL = PACKED_VOXEL_OBJECT_TUNNEL_NEG_X | PACKED_VOXEL_OBJECT_TUNNEL_POS_X | PACKED_VOXEL_OBJECT_TUNNEL_NEG_Y | PACKED_VOXEL_OBJECT_TUNNEL_POS_Y | PACKED_VOXEL_OBJECT_TUNNEL_NEG_Z | PACKED_VOXEL_OBJECT_TUNNEL_POS_Z

};

interface IVoxelObject;
struct VOXEL_DESC
{
	IVoxelObject*	pVoxelObj;
	int	x;
	int	y;
	int	z;
	BYTE	ColorIndex;
	void	Clear()
	{
		pVoxelObj = nullptr;
		x = 0;
		y = 0;
		z = 0;
		ColorIndex = 0;
	}
	BOOL	IsSameVoxel(VOXEL_DESC* pTarget)
	{
		BOOL	bResult = (pVoxelObj == pTarget->pVoxelObj) && (x == pTarget->x) && (y == pTarget->y) && (z == pTarget->z);
		return bResult;
	}
};
interface IVoxelObjectLite;
struct VOXEL_DESC_LITE
{
	IVoxelObjectLite*	pVoxelObj;
	int	x;
	int	y;
	int	z;
	BYTE	ColorIndex;
	void	Clear()
	{
		pVoxelObj = nullptr;
		x = 0;
		y = 0;
		z = 0;
		ColorIndex = 0;
	}
	BOOL	IsSameVoxel(VOXEL_DESC_LITE* pTarget)
	{
		BOOL	bResult = (pVoxelObj == pTarget->pVoxelObj) && (x == pTarget->x) && (y == pTarget->y) && (z == pTarget->z);
		return bResult;
	}
};

enum VOXEL_OBJECT_PROPERTY
{
	VOXEL_OBJECT_PROPERTY_DESTROYABLE = 0x00000001,
	VOXEL_OBJECT_PROPERTY_EDITABLE = 0x00000002,
	VOXEL_OBJECT_PROPERTY_AUTO_RECOVERY = 0x00000004
};

struct VOXEL_OBJ_PROPERTY
{
	UINT	WidthDepthHeight;
	float	VoxelSize;
};
#ifdef USE_NVCC
inline DWORD GetMaxColorTableSize()
{
	DWORD	MaxCompressedSize = (DWORD)sizeof(COMPRESSED_COLOR_TABLE_8x8x8);
	DWORD	ColorStreamSize = MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * sizeof(BYTE);

	DWORD	MaxColorTableSize = max(MaxCompressedSize, ColorStreamSize);
	return MaxColorTableSize;
}
#else
inline constexpr DWORD GetMaxColorTableSize()
{
	DWORD	MaxCompressedSize = GetMax2x2x2ColorTableCompressedSize();
	DWORD	ColorStreamSize = MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * sizeof(BYTE);

	DWORD	MaxColorTableSize = max(MaxCompressedSize, ColorStreamSize);
	return MaxColorTableSize;
}
#endif

#pragma pack(push,1)
struct COMPRESSED_VOXEL_GEOEMTRY_HEADER
{
	BYTE bPatternNum;
	BYTE pPatternTable[1];
	const unsigned long* GetBodyPtrForRead() const
	{
		const unsigned long* ptr = (const unsigned long*)(pPatternTable + ((DWORD)sizeof(BYTE) * (DWORD)bPatternNum));
		return ptr;
	}
	unsigned long* GetBodyPtrForWrite()
	{
		unsigned long* ptr = (unsigned long*)(pPatternTable + ((DWORD)sizeof(BYTE) * (DWORD)bPatternNum));
		return ptr;
	}
};
#pragma pack(pop)

inline constexpr DWORD GetCompressedVoxelDataBodySize(DWORD dwPatternCount, UINT WidthDepthHeight)
{
	DWORD	mul_value = 0;
	switch (WidthDepthHeight)
	{
		case 4:
			mul_value = 1;
			break;
		case 8:
			mul_value = 8;
			break;
		default:
			{
				int a = 0;
			}
	}
	DWORD	val = 1;
	DWORD	pow = 0;
	while (1)
	{
		if (val >= dwPatternCount)
			break;

		pow++;
		val = val << 1;
	}
	DWORD dwSize = pow * mul_value;
	return dwSize;
}

inline constexpr DWORD GetPureVoxelDataSizeWithVoxelCount(DWORD VoxelCount)
{
	DWORD dwSize = VoxelCount / 8 + (VoxelCount % 8 != 0);
	return dwSize;
}
inline constexpr DWORD GetPureVoxelDataSize(UINT WidthDepthHeight)
{
	DWORD dwSize = GetPureVoxelDataSizeWithVoxelCount(WidthDepthHeight * WidthDepthHeight * WidthDepthHeight);
	return dwSize;
}
inline constexpr DWORD GetCompressedVoxelDataSize(DWORD dwPatternCount, UINT WidthDepthHeight)
{
	DWORD	dwBodySize = GetCompressedVoxelDataBodySize(dwPatternCount, WidthDepthHeight);
	DWORD	dwHeaderSize = (DWORD)sizeof(COMPRESSED_VOXEL_GEOEMTRY_HEADER) - (DWORD)sizeof(BYTE) + (DWORD)sizeof(BYTE) * dwPatternCount;
	DWORD	dwSize = dwHeaderSize + dwBodySize;
	return dwSize;
}

//    Geometry Compressed	|	ColorTable Compressed	|	 ColorTableSize    |   Property	  |  WidthDepthHeight 
//			1(1)			|		   1(1)				|	 11 1111 1111(10)  |	 11(2)	  |		11(2) n = {0,1,2,3} , WidthDepthHeight = 2^n
const DWORD WIDTH_DEPTH_HEIGHT_2BITS = 0b11;
const DWORD PROPERTY_2BITS = 0b1100;
const DWORD PROPERTY_DESTROYABLE_1BITS = 0b0100;
const DWORD PROPERTY_RESERVED_1BITS = 0b1000;
const DWORD COLOR_TABLE_SIZE_10BITS = 0b1111111111;
const DWORD COLOR_TABLE_SIZE_MASK = (COLOR_TABLE_SIZE_10BITS << 4);
const DWORD COLOR_TABLE_COMPRESSED_1BIT = 0b1;
const DWORD COLOR_TABLE_COMPRESSED_MASK = (COLOR_TABLE_COMPRESSED_1BIT << 14);
const DWORD GEOMETRY_COMPRESSED_MASK = (0b1 << 15);

inline DWORD CalcPowN(UINT WidthDepthHeight)
{
	DWORD	n = 0;
	while (WidthDepthHeight > 1)
	{
		WidthDepthHeight = WidthDepthHeight >> 1;
		n++;
	}
	return n;
}
inline UINT CalcWidthDepthHeight(DWORD n)
{
	UINT WidthDepthHeight = 1;
	for (DWORD i = 0; i < n; i++)
	{
		WidthDepthHeight = WidthDepthHeight << 1;
	}
	return WidthDepthHeight;
}

#pragma pack(push,1)
struct VOXEL_SHORT_POS
{
	short	x;
	short	y;
	short	z;
};
struct VOXEL_WORD_POS
{
	// INT 좌표계를 2바이트로 저장.0보다 작은 경우는 없으므로 WORD를 사용한다.
	WORD	x;
	WORD	y;
	WORD	z;
};
struct VOXEL_OBJECT_STREAM_COMMON_HEADER
{
	VOXEL_SHORT_POS	Pos;
	WORD	wProps;

	void	SetColorTableSize(DWORD ColorTableSize, BOOL bCompressed)
	{
		wProps &= (~(COLOR_TABLE_COMPRESSED_MASK | COLOR_TABLE_SIZE_MASK));
		wProps |= ((bCompressed & COLOR_TABLE_COMPRESSED_1BIT) << 14);
		wProps |= ((ColorTableSize & COLOR_TABLE_SIZE_10BITS) << 4);
	}
	DWORD	GetColorTableSize() const
	{
		DWORD	dwSize = (DWORD)((wProps & COLOR_TABLE_SIZE_MASK) >> 4);
		return dwSize;
	}
	BOOL	IsColorTableCompressed() const
	{
		BOOL	bCompressed = ((wProps & COLOR_TABLE_COMPRESSED_MASK) != 0);
		return bCompressed;
	}
	void	SetGeometryCompressed(BOOL bCompressed)
	{
		wProps = (wProps & 0x7FFF) | (bCompressed << 15);
	}
	BOOL	IsGeometryCompressed() const
	{
		BOOL	bCompressed = ((wProps & GEOMETRY_COMPRESSED_MASK) != 0);
		return bCompressed;
	}
	void	SetWidthDepthHeight(UINT WidthDepthHeight)
	{
		DWORD n = CalcPowN(WidthDepthHeight);
		wProps &= (~WIDTH_DEPTH_HEIGHT_2BITS);
		wProps |= (n & WIDTH_DEPTH_HEIGHT_2BITS);
	}
	UINT	GetWidthDepthHeight() const
	{
		DWORD	n = (UINT)(wProps & WIDTH_DEPTH_HEIGHT_2BITS);
		UINT	WidthDepthHeight = CalcWidthDepthHeight(n);
	#ifdef _DEBUG
		if (WidthDepthHeight > MAX_VOXELS_PER_AXIS)
			__debugbreak();
	#endif
		return WidthDepthHeight;
	}
	void	SetDestroyable(BOOL bSwitch)
	{
		wProps &= (~PROPERTY_DESTROYABLE_1BITS);
		wProps |= ((bSwitch << 2) & PROPERTY_DESTROYABLE_1BITS);
	}
	BOOL	IsDestroyable() const
	{
		BOOL bDestroyable = (wProps & PROPERTY_DESTROYABLE_1BITS) >> 2;
		return bDestroyable;
	}
};
struct VOXEL_OBJECT_PACKET_STREAM_HEADER : public VOXEL_OBJECT_STREAM_COMMON_HEADER
{
	BYTE	pData[1];

	const BYTE*	GetVoxelDataPtrForRead() const { return pData; }
	BYTE*	GetVoxelDataPtrForWrite() { return pData; }

	DWORD	GetVoxelDataSize() const
	{
		DWORD dwSize = 0;
		UINT WidthDepthHeight = GetWidthDepthHeight();
		if (IsGeometryCompressed())
		{
			COMPRESSED_VOXEL_GEOEMTRY_HEADER*	pHeader = (COMPRESSED_VOXEL_GEOEMTRY_HEADER*)pData;
			dwSize = GetCompressedVoxelDataSize((DWORD)pHeader->bPatternNum, WidthDepthHeight);
		}
		else
		{
			dwSize = GetPureVoxelDataSize(WidthDepthHeight);
		}
		return dwSize;
	}
	const BYTE*	GetColorTablePtrForRead() const { return ((const BYTE*)pData + GetVoxelDataSize()); }
	BYTE*	GetColorTablePtrForWrite() { return ((BYTE*)pData + GetVoxelDataSize()); }
	VOXEL_OBJECT_PACKET_STREAM_HEADER*	Next()
	{
		DWORD	ColorTableSize = GetColorTableSize();
		UINT	WidthDepthHeight = GetWidthDepthHeight();
		DWORD	TotalVoxels = WidthDepthHeight * WidthDepthHeight * WidthDepthHeight;
		DWORD	VoxelDataSize = GetVoxelDataSize();
		DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - (DWORD)sizeof(BYTE) + VoxelDataSize + ColorTableSize;

		VOXEL_OBJECT_PACKET_STREAM_HEADER*	pNext = (VOXEL_OBJECT_PACKET_STREAM_HEADER*)((char*)this + MemSize);
		return pNext;
	}
	DWORD	GetNextOffset()
	{
		DWORD	ColorTableSize = GetColorTableSize();
		UINT	WidthDepthHeight = GetWidthDepthHeight();
		DWORD	TotalVoxels = WidthDepthHeight * WidthDepthHeight * WidthDepthHeight;
		DWORD	VoxelDataSize = GetVoxelDataSize();
		DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - (DWORD)sizeof(BYTE) + VoxelDataSize + ColorTableSize;
		return MemSize;
	}
};

struct VOXEL_OBJECT_FILE_STREAM_HEADER : VOXEL_OBJECT_STREAM_COMMON_HEADER
{
	// 파일에서 사용할때는 voxel data 압축하지 않음.
	INT64	i64OwnerSerial;
	DWORD	pData[1];

	unsigned long*	GetBitTablePtr() { return (unsigned long*)pData; }

	DWORD	GetVoxelDataSize()
	{
		UINT WidthDepthHeight = GetWidthDepthHeight();
		DWORD dwSize = GetPureVoxelDataSize(WidthDepthHeight);
		return dwSize;
	}
	BYTE*	GetColorTablePtr() { return ((BYTE*)pData + GetVoxelDataSize()); }
	VOXEL_OBJECT_FILE_STREAM_HEADER*	Next()
	{
		DWORD	ColorTableSize = GetColorTableSize();
		UINT	WidthDepthHeight = GetWidthDepthHeight();
		DWORD	TotalVoxels = WidthDepthHeight * WidthDepthHeight * WidthDepthHeight;
		DWORD	VoxelDataSize = GetVoxelDataSize();
		DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_FILE_STREAM_HEADER) - (DWORD)sizeof(DWORD) + VoxelDataSize + ColorTableSize;

		VOXEL_OBJECT_FILE_STREAM_HEADER*	pNext = (VOXEL_OBJECT_FILE_STREAM_HEADER*)((char*)this + MemSize);
		return pNext;
	}
};

#ifdef USE_NVCC
inline DWORD GetMaxVoxelObjectPacketStreamSize()
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(MAX_VOXELS_PER_AXIS);
	DWORD	MaxColorTableSize = GetMaxColorTableSize();
	DWORD	MemSize = sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - sizeof(BYTE) + VoxelDataSize + MaxColorTableSize;
	return MemSize;
}
inline DWORD GetMaxVoxelObjectFileStreamSize()
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(MAX_VOXELS_PER_AXIS);
	DWORD	MaxColorTableSize = GetMaxColorTableSize();
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_FILE_STREAM_HEADER) - (DWORD)sizeof(DWORD) + VoxelDataSize + MaxColorTableSize;
	return MemSize;
}
inline DWORD GetVoxelObjectPacketStreamSizeWithoutColorTable(UINT WidthDepthHeight)
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(WidthDepthHeight);
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - (DWORD)sizeof(BYTE) + VoxelDataSize;
	return MemSize;
}

inline DWORD GetCompressedVoxelObjectPacketStreamSizeWithoutColorTable(DWORD dwCompressedVoxelDeataSize)
{
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - (DWORD)sizeof(BYTE) + dwCompressedVoxelDeataSize;
	return MemSize;
}
inline DWORD GetVoxelObjectFileStreamSizeWithoutColorTable(UINT WidthDepthHeight)
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(WidthDepthHeight);
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_FILE_STREAM_HEADER) - (DWORD)sizeof(DWORD) + VoxelDataSize;
	return MemSize;
}
#else
inline constexpr DWORD GetMaxVoxelObjectPacketStreamSize()
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(MAX_VOXELS_PER_AXIS);
	DWORD	MaxColorTableSize = GetMaxColorTableSize();
	DWORD	MemSize = sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - sizeof(BYTE) + VoxelDataSize + MaxColorTableSize;
	return MemSize;
}

inline constexpr DWORD GetMaxVoxelObjectFileStreamSize()
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(MAX_VOXELS_PER_AXIS);
	DWORD	MaxColorTableSize = GetMaxColorTableSize();
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_FILE_STREAM_HEADER) - (DWORD)sizeof(DWORD) + VoxelDataSize + MaxColorTableSize;
	return MemSize;
}
inline constexpr DWORD GetVoxelObjectPacketStreamSizeWithoutColorTable(UINT WidthDepthHeight)
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(WidthDepthHeight);
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - (DWORD)sizeof(BYTE) + VoxelDataSize;
	return MemSize;
}

inline constexpr DWORD GetCompressedVoxelObjectPacketStreamSizeWithoutColorTable(DWORD dwCompressedVoxelDeataSize)
{
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_PACKET_STREAM_HEADER) - (DWORD)sizeof(BYTE) + dwCompressedVoxelDeataSize;
	return MemSize;
}

inline constexpr DWORD GetVoxelObjectFileStreamSizeWithoutColorTable(UINT WidthDepthHeight)
{
	DWORD	VoxelDataSize = GetPureVoxelDataSize(WidthDepthHeight);
	DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_FILE_STREAM_HEADER) - (DWORD)sizeof(DWORD) + VoxelDataSize;
	return MemSize;
}

#endif


struct VOXEL_OBJECT_COLOR_TABLE_HEADER
{
	WORD	wPosX;
	WORD	wPosY;
	WORD	wPosZ;
	WORD	wProps;
	DWORD	pData[1];

	void	SetColorTableSize(DWORD ColorTableSize, BOOL bCompressed)
	{
		wProps &= (~COLOR_TABLE_COMPRESSED_MASK);
		wProps |= (bCompressed & COLOR_TABLE_COMPRESSED_1BIT) << 14;
	}
	void	SetWidthDepthHeight(UINT WidthDepthHeight)
	{
		DWORD n = CalcPowN(WidthDepthHeight);
		wProps &= (~WIDTH_DEPTH_HEIGHT_2BITS);
		wProps |= (n & WIDTH_DEPTH_HEIGHT_2BITS);
	}
	UINT	GetWidthDepthHeight()
	{
		DWORD	n = (UINT)(wProps & WIDTH_DEPTH_HEIGHT_2BITS);
		UINT	WidthDepthHeight = CalcWidthDepthHeight(n);
		return WidthDepthHeight;
	}

	BOOL	IsColorTableCompressed()
	{
		BOOL	bCompressed = ((wProps & COLOR_TABLE_COMPRESSED_MASK) != 0);
		return bCompressed;
	}

	DWORD	GetColorTableSize()
	{
		DWORD	dwSize = (DWORD)((wProps & COLOR_TABLE_SIZE_MASK) >> 4);
		return dwSize;
	}
	BYTE*			GetColorTablePtr() { return ((BYTE*)pData); }


	VOXEL_OBJECT_COLOR_TABLE_HEADER*	Next()
	{
		DWORD	ColorTableSize = GetColorTableSize();
		DWORD	MemSize = (DWORD)sizeof(VOXEL_OBJECT_COLOR_TABLE_HEADER) - (DWORD)sizeof(DWORD) + ColorTableSize;

		VOXEL_OBJECT_COLOR_TABLE_HEADER*	pNext = (VOXEL_OBJECT_COLOR_TABLE_HEADER*)((char*)this + MemSize);
		return pNext;
	}
};
#pragma pack(pop)


enum CREATE_VOXEL_OBJECT_ERROR
{
	CREATE_VOXEL_OBJECT_ERROR_OK = 0,
	CREATE_VOXEL_OBJECT_ERROR_ALREADY_EXIST = 1,
	CREATE_VOXEL_OBJECT_ERROR_INVALID_POS = 2,
	CREATE_VOXEL_OBJECT_ERROR_FAIL_ALLOC_INDEX = 3
};
struct VOXELIZE_OBJ_DESC
{
	unsigned long pBitTable[MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS / 8 / 4];
	DWORD		dwVoxelsCount;
	UINT		WidthDepthHeight;
	WORD		x;
	WORD		y;
	WORD		z;
	WORD		wReserved;

};
#ifdef USE_NVCC
static const int	MAX_COMPRESSED_GEOMETRY_STREAM_BUFFER_SIZE = 1098;
static const int	MAX_FILE_GEOMETRY_STREAM_BUFFER_SIZE = 1106;
#else
static const int	MAX_COMPRESSED_GEOMETRY_STREAM_BUFFER_SIZE = (int)GetMaxVoxelObjectPacketStreamSize();
static const int	MAX_FILE_GEOMETRY_STREAM_BUFFER_SIZE = (int)GetMaxVoxelObjectFileStreamSize();
#endif
struct VOXEL_OBJECT_CREATE_DESC
{
	unsigned long pBitTable[MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS / 8 / 4];
	BYTE		pColorTable[MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS * MAX_VOXELS_PER_AXIS];
	UINT		WidthDepthHeight;
	VECTOR3		v3ObjPos;
	AABB		aabb;
	INT64		i64OwnerSerial;
	DWORD		dwProperty;
};

struct VOXEL_OBJECT_CREATE_DESC_CONTEXT : public VOXEL_OBJECT_CREATE_DESC
{
	DWORD	dwResult;
	BYTE	pGeometryStream[MAX_COMPRESSED_GEOMETRY_STREAM_BUFFER_SIZE];
	DWORD	dwGeometryStreamSize;
	void	SetResultFail() { dwResult = 0; }
	void	SetResultOK(BOOL bUpdated) { dwResult = 0x00000001 | ((bUpdated != 0) << 1); }
	BOOL	IsResultOK() { return (dwResult != 0); }
	BOOL	IsUpdated() { return ((dwResult & 0x00000002) != 0); }
};

enum ALIGN_MODE
{
	ALIGN_MODE_CENTER = 0x00000000,
	ALIGN_MODE_LEFT = 0x00000001,
	ALIGN_MODE_RIGHT = 0x00000002,
	ALIGN_MODE_TOP = 0x00000004,
	ALIGN_MODE_BOTTOM = 0x00000008
};

template <typename T>
inline void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

struct RENDERER_STATUS
{
	RENDERER_TYPE	RendererType;
	DWORD	dwTotalTexNum;
	DWORD	dwVertexBufferNum;
	DWORD	dwIndexBufferNum;
	DWORD	dwConstantBufferNum;
	DWORD	dwPipelineStateNum;
	DWORD	dwAlphaMapNum;
	DWORD	dwAllocFontNum;
	DWORD	dwActiveRenderThreadNum;
	DWORD	dwMaxRenderThreadNum;
	BOOL	bIsSupport_DriverCommandLists;
	BOOL	bIsSupport_DriverConcurrentCreates;
	BOOL	bIsSupport_GpuUploadHeap;
	size_t	GPUMemSize;
	DWORD	dwBackBufferWidth;
	DWORD	dwBackBufferHeight;
	WCHAR	wchAdapterName[64];
	WCHAR	wchGraphicsAPIType[64];
};

struct PERF_SEARCH
{
	DWORD64	AvgElapsedClock_Insert;
	DWORD64	AvgElapsedClock_Search;
	DWORD64	AvgElapsedClock_Delete;
};

struct VOXEL_OBJ_PERF
{
	BOOL		bNoCullingOnRaster;
	BOOL		bUseSWOccTest;
	float		fSWOccTestNodeLimitTime;
	float		fSWOccRasterLimitTime;
	float		fCamPosBiasDist;
	float		fCamRayBiasAngle;
	float		fAvgSWCulledNodeCount;
	float		fAvgSWCulledObjCount;
	DWORD		dwTotalObjCount;
	DWORD		dwTotalVoxelCount;
	DWORD		pdwVoxelCountList[4];
	DWORD		dwFoundObjCount;
	float		fAvgSWTestElapsedTicks;
	DWORD64		AvgSWTestElapsedClocks;
	float		fAvgSWRasterElapsedTicks;
	DWORD64		AvgSWRasterElapsedClocks;
	float		fAvgRasterTriCountPerFind;
	float		fAvgTestNodeCountPerFind;
	float		fAvgElapsedTickPerFind;
	DWORD		dwSWRasterThreadCount;
	DWORD		dwVoxelEditEventCount;	// 복셀이 변형되는 이벤트 발생 수
	DWORD		dwOptimizeSuccessCount;	// 복셀이 변형될때 최적화에 성공한 회수
	DWORD		dwLastUpdatingElapsedTick; // 마지막 업데이트(복셀 지오메트리 압축해제, 라이팅 등)에 걸린 시간.
	BOOL		bUseMultiThreadUpdateLightTexutre;	// 라이트 텍스처 업데이트에 멀티 스레드 사용 여부
	WCHAR		wchSWOccTesterInstType[32];
};

struct VOXEL_OBJ_MEM_PERF
{
	size_t	TotalMemSize;
	size_t	CompressedVoxelData;
	size_t	ColTriSize;
	size_t	PatchSize;
	size_t	ColotTableSize;

	void operator +=(VOXEL_OBJ_MEM_PERF& memObj)
	{
		TotalMemSize += memObj.TotalMemSize;
		CompressedVoxelData += memObj.CompressedVoxelData;
		ColTriSize += memObj.ColTriSize;
		PatchSize += memObj.PatchSize;
		ColotTableSize += memObj.ColotTableSize;
	}
	VOXEL_OBJ_MEM_PERF operator /(DWORD dwObjNum) const
	{
		VOXEL_OBJ_MEM_PERF	result = {};
		result.TotalMemSize = (size_t)((float)TotalMemSize / (float)dwObjNum);
		result.CompressedVoxelData = (size_t)((float)CompressedVoxelData / (float)dwObjNum);
		result.ColTriSize = (size_t)((float)ColTriSize / (float)dwObjNum);
		result.PatchSize = (size_t)((float)PatchSize / (float)dwObjNum);
		result.ColotTableSize = (size_t)((float)ColotTableSize / (float)dwObjNum);

		return result;
	}
};
struct VOXEL_MEM_PERF
{
	size_t	TotalMemSize;
	VOXEL_OBJ_MEM_PERF	objAvg;
	VOXEL_OBJ_MEM_PERF	objTotal;
	size_t	ObjSize;				// voxle objects
	size_t	TreeSize;				// m_pTree
	size_t	WorkingPtrBufferSize;
	size_t	OwnerTableSize;
	size_t	GeometryContextMemSize;
	size_t	ObjBitTableSize;
	size_t	CopyPatchMemSize;
	size_t	SortOccluderBufferMemSize;
	size_t	ObjTableMemSize;
	size_t	GlobalRefSrcSize;		// src ref bit table
	DWORD	ObjCount;
	DWORD	Reserved;
};
struct VOXEL_OBJ_MGR_CUDA_INFO
{
	int			Version;
	BOOL		bCanUseCUDA;
	BOOL		bUseCUDAForLighting;
	GPU_INFO	gpuInfo;
	size_t		GPUMemSizeFreed;
	size_t		GPUMemSizeTotal;
	WCHAR		wchCUDALibBuildType[64];
};

#define X_MASK 3			// 00000011
#define Y_MASK 12			// 00001100
#define Z_MASK 48			// 00110000

enum DIR_BIT_MASK
{
	POSITIVE_X_MASK = 1,	// 00000001
	NEGATIVE_X_MASK = 2,	// 00000010
	POSITIVE_Y_MASK = 4,	// 00000100
	NEGATIVE_Y_MASK = 8,	// 00001000
	POSITIVE_Z_MASK = 16,	// 00010000
	NEGATIVE_Z_MASK = 32	// 00100000
};

inline unsigned char ConvertFloatNormalToByteNormal(const VECTOR3* pv3Normal)
{
	unsigned char value = 0;

	// Set X
	if (pv3Normal->x > 0.95f && pv3Normal->x < 1.05f)
	{
		value |= POSITIVE_X_MASK;
	}
	else if (pv3Normal->x < -0.95f && pv3Normal->x > -1.05f)
	{
		value |= NEGATIVE_X_MASK;
	}

	// Set Y
	if (pv3Normal->y > 0.95f && pv3Normal->y < 1.05f)
	{
		value |= POSITIVE_Y_MASK;
	}
	else if (pv3Normal->y < -0.95f && pv3Normal->y > -1.05f)
	{
		value |= NEGATIVE_Y_MASK;
	}

	// Set Z
	if (pv3Normal->z > 0.95f && pv3Normal->z < 1.05f)
	{
		value |= POSITIVE_Z_MASK;
	}
	else if (pv3Normal->z < -0.95f && pv3Normal->z > -1.05f)
	{
		value |= NEGATIVE_Z_MASK;
	}
	return value;
}
inline void ConvertByteNormalToFloatNormal(VECTOR3* pv3OutNormal, unsigned char value)
{
	pv3OutNormal->x = 0.0f;
	pv3OutNormal->y = 0.0f;
	pv3OutNormal->z = 0.0f;

	// Get X
	if (value & POSITIVE_X_MASK)
	{
		pv3OutNormal->x = 1.0f;
	}
	else if (value & NEGATIVE_X_MASK)
	{
		pv3OutNormal->x = -1.0f;
	}

	// Get Y
	if (value & POSITIVE_Y_MASK)
	{
		pv3OutNormal->y = 1.0f;
	}
	else if (value & NEGATIVE_Y_MASK)
	{
		pv3OutNormal->y = -1.0f;
	}

	// Get Z
	if (value & POSITIVE_Z_MASK)
	{
		pv3OutNormal->z = 1.0f;
	}
	else if (value & NEGATIVE_Z_MASK)
	{
		pv3OutNormal->z = -1.0f;
	}
}

inline unsigned char ConvertFloatNormalToAxisIndex(const VECTOR3* pv3Normal)
{
	unsigned char value = 0;

	// Set X
	if (pv3Normal->x > 0.95f && pv3Normal->x < 1.05f)
	{
		return 0;
	}
	if (pv3Normal->x < -0.95f && pv3Normal->x > -1.05f)
	{
		return 1;
	}

	// Set Y
	if (pv3Normal->y > 0.95f && pv3Normal->y < 1.05f)
	{
		return 2;
	}
	if (pv3Normal->y < -0.95f && pv3Normal->y > -1.05f)
	{
		return 3;
	}

	// Set Z
	if (pv3Normal->z > 0.95f && pv3Normal->z < 1.05f)
	{
		return 4;
	}
	if (pv3Normal->z < -0.95f && pv3Normal->z > -1.05f)
	{
		return 5;
	}
	return 0;
}
inline void ConvertAxisIndexToFloatNormal(VECTOR3* pv3OutNormal, unsigned char axis_index)
{
	pv3OutNormal->Set(0, 0, 0);
	switch (axis_index)
	{
		case 0:
			pv3OutNormal->x = 1.0f;
			break;
		case 1:
			pv3OutNormal->x = -1.0f;
			break;
		case 2:
			pv3OutNormal->y = 1.0f;
			break;
		case 3:
			pv3OutNormal->y = -1.0f;
			break;
		case 4:
			pv3OutNormal->z = 1.0f;
			break;
		case 5:
			pv3OutNormal->z = -1.0f;
			break;
		#ifdef _DEBUG
		default:
			__debugbreak();
		#endif
	}
}

inline VECTOR3 GetPatchPosOffsetWithNormal(unsigned char axis_index)
{
	VECTOR3	v3Offset = {};
	switch (axis_index)
	{
		case 0: // +x
		case 1: // -x
			v3Offset.y = VOXEL_PATCH_SIZE_HALF;
			v3Offset.z = VOXEL_PATCH_SIZE_HALF;
			break;
		case 2: // +y
		case 3: // -y
			v3Offset.x = VOXEL_PATCH_SIZE_HALF;
			v3Offset.z = VOXEL_PATCH_SIZE_HALF;
			break;
		case 4: // +z
		case 5: // -z
			v3Offset.x = VOXEL_PATCH_SIZE_HALF;
			v3Offset.y = VOXEL_PATCH_SIZE_HALF;
			break;
		#ifdef _DEBUG
		default:
			__debugbreak();
		#endif
	}
	return v3Offset;
}
struct PACKED_VOXEL_VERTEX
{
	// oPos(9) + vPos(3) + N(3) + Quad Index(10) + qPos(2)

	//  qPos |  QuadIndex  |   N  | vPos  |    oPos
	//   00    00000 00000    000   000      000 000 000 
	DWORD	PackedData;
	// Position in Object (0 - 8) , 0 - 8 bits

	// ox : 0 - 8 (3 bits)
	// oy : 0 - 8 (3 bits)
	// oz : 0 - 8 (3 bits)
	// oz | oy | ox = 000 111 111 111
	void SetPosInObject(DWORD x, DWORD y, DWORD z)
	{
		PackedData &= (~0b111111111); // ~(000 111 111 111)
		PackedData |= ((z & 0b111) << 6) | ((y & 0b111) << 3) | (x & 0b111);
	}
	void GetPosInObject(DWORD* pOutX, DWORD* pOutY, DWORD* pOutZ) const
	{
		*pOutX = PackedData & 0b111;				//	000 000	111
		*pOutY = (PackedData & 0b111000) >> 3;		//	000	111 000
		*pOutZ = (PackedData & 0b111000000) >> 6;	//	111 000 000
	}

	// Offset in Voxel ( 0 - 1) , 9 - 11 bits
	// vx : 0 - 1 (1 bits)
	// vy : 0 - 1 (1 bits)
	// vz : 0 - 1 (1 bits)
	// vz | vy | vz = 111 000 000 000
	void SetPosInVoxel(BYTE x, BYTE y, BYTE z)
	{
		PackedData &= (~0b111000000000); // ~(111 000 000 000)
		PackedData |= ((z & 0b1) << 11) | ((y & 0b1) << 10) | ((x & 0b1) << 9);
	}
	void GetPosInVoxel(DWORD* pOutX, DWORD* pOutY, DWORD* pOutZ) const
	{
		*pOutX = (PackedData & 0b001000000000) >> 9;	//	001 000 000 000
		*pOutY = (PackedData & 0b010000000000) >> 10;	//  010 000 000 000
		*pOutZ = (PackedData & 0b100000000000) >> 11;	//	100 000 000 000
	}
	// Normal - Axis Index (0 - 5), 12 - 14 bits
	// Axis Index (3 bits) = // 111 000 000 000 000 
	void SetNormal(const VECTOR3* pv3Normal)
	{

		DWORD	AxisIndex = ConvertFloatNormalToAxisIndex(pv3Normal);
		PackedData &= (~0b111000000000000);	//111 000 000 000 000
		PackedData |= ((AxisIndex & 0b111) << 12);
	}
	void GetNormal(VECTOR3* pv3OutNormal) const
	{
		DWORD	AxisIndex = (PackedData & 0b111000000000000) >> 12;
		ConvertAxisIndexToFloatNormal(pv3OutNormal, (unsigned char)AxisIndex);
	}

	// QuadIndex (0 - 1023) , 15 - 24 bits(10 bits)
	// QuadIndex = 1 111 111 111 000 000 000 000 000
	void SetQuadIndex(DWORD QuadIndex)
	{
		PackedData &= (~0b1111111111000000000000000);
		PackedData |= ((QuadIndex & 0b1111111111) << 15);
	}
	DWORD GetQuadIndex() const
	{
		DWORD QuadIndex = (PackedData & 0b1111111111000000000000000) >> 15;
		return QuadIndex;
	}

	// Pos in Quad (0 - 1) , 25 - 26 bits(2 bits)
	// qx : 0 - 1 (1 bits)
	// qy : 0 - 1 (1 bits)
	// qy | qx = 11    00000 00000    000   000      000 000 000 
	void SetPosInQuad(DWORD u, DWORD v)
	{
		PackedData &= (~0b110000000000000000000000000);
		PackedData |= ((u & 0b1) << 25) | ((v & 0b1) << 26);
	}
	void GetPosInQuad(DWORD* pOutU, DWORD* pOutV)
	{
		*pOutU = (PackedData & 0b010000000000000000000000000) >> 25;
		*pOutV = (PackedData & 0b100000000000000000000000000) >> 26;
	}
	DWORD GetPosBitsInQuad()
	{
		DWORD	Bits = (PackedData & 0b110000000000000000000000000) >> 25;
		return Bits;

	}
	void GetVoxelCenterPosition(VECTOR3* pv3OutPos, float VoxelSize, float VoxelSizeHalf) const
	{
		VECTOR3	v3ObjMinPos =
		{
			MIN_VOXEL_SIZE * MAX_VOXELS_PER_AXIS * -0.5f,
			MIN_VOXEL_SIZE * MAX_VOXELS_PER_AXIS * -0.5f,
			MIN_VOXEL_SIZE * MAX_VOXELS_PER_AXIS * -0.5f
		};
		DWORD	ox, oy, oz;
		GetPosInObject(&ox, &oy, &oz);

		pv3OutPos->x = v3ObjMinPos.x + (float)ox * VoxelSize + VoxelSizeHalf;
		pv3OutPos->y = v3ObjMinPos.y + (float)oy * VoxelSize + VoxelSizeHalf;
		pv3OutPos->z = v3ObjMinPos.z + (float)oz * VoxelSize + VoxelSizeHalf;

	}
	void GetPosition(VECTOR3* pv3OutPos, float VoxelSize) const
	{
		VECTOR3	v3ObjMinPos =
		{
			MIN_VOXEL_SIZE * MAX_VOXELS_PER_AXIS * -0.5f,
			MIN_VOXEL_SIZE * MAX_VOXELS_PER_AXIS * -0.5f,
			MIN_VOXEL_SIZE * MAX_VOXELS_PER_AXIS * -0.5f
		};

		DWORD	ox, oy, oz;
		GetPosInObject(&ox, &oy, &oz);

		DWORD	vx, vy, vz;
		GetPosInVoxel(&vx, &vy, &vz);

		pv3OutPos->x = v3ObjMinPos.x + (float)(ox + vx) * VoxelSize;
		pv3OutPos->y = v3ObjMinPos.y + (float)(oy + vy) * VoxelSize;
		pv3OutPos->z = v3ObjMinPos.z + (float)(oz + vz) * VoxelSize;
	}
};

inline void Vector3ToVoxelShortPos(VOXEL_SHORT_POS* pOutShortPos, const VECTOR3* pv3ObjPos)
{
	pOutShortPos->x = (short)(int)((pv3ObjPos->x - VOXEL_OBJECT_SIZE_HALF) / VOXEL_OBJECT_SIZE);
	pOutShortPos->y = (short)(int)((pv3ObjPos->y - VOXEL_OBJECT_SIZE_HALF) / VOXEL_OBJECT_SIZE);
	pOutShortPos->z = (short)(int)((pv3ObjPos->z - VOXEL_OBJECT_SIZE_HALF) / VOXEL_OBJECT_SIZE);
}
inline void VoxelShortPosToVector3(VECTOR3* pv3OutPos, const VOXEL_SHORT_POS* pShortPos)
{
	pv3OutPos->x = (float)pShortPos->x * VOXEL_OBJECT_SIZE + VOXEL_OBJECT_SIZE_HALF;
	pv3OutPos->y = (float)pShortPos->y * VOXEL_OBJECT_SIZE + VOXEL_OBJECT_SIZE_HALF;
	pv3OutPos->z = (float)pShortPos->z * VOXEL_OBJECT_SIZE + VOXEL_OBJECT_SIZE_HALF;
}
struct PICK_OBJ
{
	float				fDist;
	VECTOR3				v3IntersectPoint;
	TVERTEX				tvIntersectPoint;
	GX_MAP_OBJECT_TYPE	type;
	void*				pObj;
};

struct PICK_RESULT
{
	VECTOR3				v3IntersectPoint;		// 픽킹 요청일때 픽킹위치
	BOOL				bPickResult;			// 픽킹 요청일때 픽킹 성공 여부
	float				t;
	void*				pChrObj;
	IVoxelObject*		pVoxelObj;	// 복셀에 충돌했을때
};

struct INTERSECT_RESULT
{
	VECTOR3				v3IntersectPoint;
	float				t;

};
/*
struct VOXEL_PATCH_LITE
{
	BYTE	x;		// 0
	BYTE	y;		// 1
	BYTE	z;		// 2
	BYTE	axis_index;	// 3
	BYTE	u;	// 사각형 내에서의 x성분 좌표	// 4
	BYTE	v;	// 사각형 내에서의 y성분 좌표	// 5
	WORD	wColor;							// 6
};
*/
#define PACKED_VOXEL_PATCH
#ifdef PACKED_VOXEL_PATCH
struct VOXEL_PATCH_LITE : public FLOAT3_12BITS
{
	static const unsigned __int64 TEX_COORD_MASK = 0x00000ff000000000ull;
	static const unsigned __int64 PATCH_POS_MASK = 0x07fff00000000000ull;
	static const unsigned __int64 AXIS_MASK = 0x3800000000000000ull;
	// reserved | axis index | patch pos(x,y,z) | tex coord(u,v) |     color
	//  2 bits	|	3 bits	 | (5,5,5)15 bits   |  (4,4)8 bits   | (12,12,12)36 bits
	// 
	// unsigned __int64 Data; <- 64 bits Data 필드는 FLOAT3_12BITS으로부터 상속.
	void SetTexCoord(BYTE2 Coord)
	{
	#ifdef _DEBUG
		if (Coord.x >= 16)
			__debugbreak();
		if (Coord.y >= 16)
			__debugbreak();
	#endif
		unsigned __int64 CoordData = ((unsigned __int64)(Coord.y & 0x0f) << 4) | (unsigned __int64)(Coord.x & 0x0f);
		Data = (Data & (~TEX_COORD_MASK)) | ((CoordData << 36) & TEX_COORD_MASK);
	}
	void SetTexCoord(BYTE u, BYTE v)
	{
	#ifdef _DEBUG
		if (u >= 16)
			__debugbreak();
		if (v >= 16)
			__debugbreak();
	#endif
		unsigned __int64 CoordData = ((unsigned __int64)(v & 0x0f) << 4) | (unsigned __int64)(u & 0x0f);
		Data = (Data & (~TEX_COORD_MASK)) | ((CoordData << 36) & TEX_COORD_MASK);
	}
	BYTE2 GetTexCoord() const
	{
		BYTE2	Coord;
		unsigned __int64 CoordData = (Data & TEX_COORD_MASK) >> 36;
		Coord.x = (BYTE)(CoordData & 0x0f);
		Coord.y = (BYTE)((CoordData >> 4) & 0x0f);
		return Coord;
	}
	void SetPatchPos(BYTE_POS Pos)
	{
	#ifdef _DEBUG
		if (Pos.x >= 16 + 1)
			__debugbreak();
		if (Pos.y >= 16 + 1)
			__debugbreak();
		if (Pos.z >= 16 + 1)
			__debugbreak();
	#endif
		unsigned __int64 PosData = ((unsigned __int64)(Pos.z & 0x1f) << 10) | ((unsigned __int64)(Pos.y & 0x1f) << 5) | (unsigned __int64)(Pos.x & 0x1f);
		Data = (Data & (~PATCH_POS_MASK)) | ((PosData << 44) & PATCH_POS_MASK);
	}
	void SetPatchPos(BYTE x, BYTE y, BYTE z)
	{
	#ifdef _DEBUG
		if (x >= 16 + 1)
			__debugbreak();
		if (y >= 16 + 1)
			__debugbreak();
		if (z >= 16 + 1)
			__debugbreak();
	#endif
		unsigned __int64 PosData = ((unsigned __int64)(z & 0x1f) << 10) | ((unsigned __int64)(y & 0x1f) << 5) | (unsigned __int64)(x & 0x1f);
		Data = (Data & (~PATCH_POS_MASK)) | ((PosData << 44) & PATCH_POS_MASK);
	}
	BYTE_POS GetPatchPos() const
	{
		BYTE_POS	Pos;
		unsigned __int64 PosData = (Data & PATCH_POS_MASK) >> 44;
		Pos.x = (BYTE)(PosData & 0x1f);
		Pos.y = (BYTE)((PosData >> 5) & 0x1f);
		Pos.z = (BYTE)((PosData >> 10) & 0x1f);
		return Pos;
	}
	void SetAxis(BYTE Axis)
	{
	#ifdef _DEBUG
		if (Axis >= 6)
			__debugbreak();
	#endif
		unsigned __int64 AxisData = (unsigned __int64)(Axis & 0x07);
		Data = (Data & (~AXIS_MASK)) | ((AxisData << 59) & AXIS_MASK);
	}
	BYTE GetAxis() const
	{
		BYTE Axis;
		unsigned __int64 AxisData = (Data & AXIS_MASK) >> 59;
		Axis = (BYTE)(AxisData & 0x07);
		return Axis;
	}
	void SetColor(float r, float g, float b)
	{
	#ifdef _DEBUG
		if (r > 511.0f)
			__debugbreak();

		if (g > 511.0f)
			__debugbreak();

		if (b > 511.0f)
			__debugbreak();
	#endif
		Set(r, g, b);
	}
	COLOR3 GetColor() const
	{
		COLOR3	ColorResult;
		Get(&ColorResult.r, &ColorResult.g, &ColorResult.b);
		return ColorResult;
	}
};
#else
struct VOXEL_PATCH_LITE
{
private:

	BYTE	x;			// 0
	BYTE	y;			// 1
	BYTE	z;			// 2
	BYTE	axis_index;	// 3
	BYTE	u;			// 4
	BYTE	v;			// 5
	WORD	wReserved0;	// 6
	COLOR3	Color;		// 8
	DWORD	dwReserved1;// 20
public:
	void SetTexCoord(BYTE2 Coord)
	{
		if (Coord.x >= 16)
			__debugbreak();

		if (Coord.y >= 16)
			__debugbreak();

		u = Coord.x;
		v = Coord.y;
	}
	void SetTexCoord(BYTE uu, BYTE vv)
	{
		if (uu >= 16)
			__debugbreak();

		if (vv >= 16)
			__debugbreak();

		u = uu;
		v = vv;
	}
	BYTE2 GetTexCoord() const
	{
		BYTE2	Coord = { u, v };
		return Coord;
	}
	void SetPatchPos(BYTE_POS Pos)
	{
		if (Pos.x >= 16 + 1)
			__debugbreak();

		if (Pos.y >= 16 + 1)
			__debugbreak();

		if (Pos.z >= 16 + 1)
			__debugbreak();

		x = Pos.x;
		y = Pos.y;
		z = Pos.z;
	}
	void SetPatchPos(BYTE sx, BYTE sy, BYTE sz)
	{
		if (sx >= 16 + 1)
			__debugbreak();

		if (sy >= 16 + 1)
			__debugbreak();

		if (sz >= 16 + 1)
			__debugbreak();

		x = sx;
		y = sy;
		z = sz;
	}
	BYTE_POS GetPatchPos() const
	{
		BYTE_POS	Pos = { x, y, z };
		return Pos;
	}
	void SetAxis(BYTE Axis)
	{
		if (Axis >= 6)
			__debugbreak();

		axis_index = Axis;
	}
	BYTE GetAxis() const
	{
		return axis_index;
	}
	void SetColor(float r, float g, float b)
	{
		if (r >= 512.0f)
			__debugbreak();

		if (g >= 512.0f)
			__debugbreak();

		if (b >= 512.0f)
			__debugbreak();

		Color.r = r;
		Color.g = g;
		Color.b = b;
	}
	COLOR3 GetColor() const
	{
		COLOR3	ColorResult = { Color.r, Color.g, Color.b };
		return ColorResult;
	}
};


#endif
enum CONTEXT_VOXEL_CREATE_TRI_MESH_MEM_TYPE
{
	CONTEXT_VOXEL_CREATE_TRI_MESH_MEM_TYPE_INVALID,
	CONTEXT_VOXEL_CREATE_TRI_MESH_MEM_TYPE_POOL,
	CONTEXT_VOXEL_CREATE_TRI_MESH_MEM_TYPE_HEAP
};

interface IQuadMerge;
struct CONTEXT_VOXEL_CREATE_TRI_MESH
{
	IQuadMerge* pQuadMerge;
	QUADRANGLE*	pWorkingQuadList;
	DWORD		dwMaxQuadNum;
	CONTEXT_VOXEL_CREATE_TRI_MESH_MEM_TYPE	MemType;
};
class CStack;
interface ITriMeshProvider
{
	virtual int __stdcall	FindTriListWithCapsuleRayMT(TRIANGLE* pOutTriList, int iMaxTriNum, const VECTOR3* pv3Orig, const VECTOR3* pv3Ray, float fRs, float near_zero, CStack* pStack, BOOL bTriCulling, DWORD dwFlags, BOOL* pbOutInsufficient) const = 0;
};
interface IVoxelObjectManager;
interface IVoxelObjectModifiedHandler
{
	virtual BOOL __stdcall	OnVoxelOjbectModified(IVoxelObjectManager* pVoxelObjManager, IVoxelObject* pVoxelObj, UINT64 ui64Data) = 0;
};

enum CPU_SIMD_FEATURE_TYPE
{
	CPU_SIMD_FEATURE_NONE,
	CPU_SIMD_FEATURE_SSE41,
	CPU_SIMD_FEATURE_AVX2
};

class CVoxelObject;
struct PRE_TRANSFORM_ITEM
{
	CVoxelObject*	pVoxelObj;
	TRIANGLE_A*	pTransformedTriList;
	DWORD		dwTransformedTriNum;
	TRIANGLE*	pVoxelObjTriList;
	DWORD		dwVoxelObjTriNum;
	DWORD		dwPrePixelCount;
	volatile LONG lCompleted;
	volatile LONG lCanceled;
};
struct PERF_DATA
{
	DWORD64	ElapsedClock;
	float	ElapsedTick;
};

struct Z_BUFFER_DESC
{
	float*	pZBuffer;
	DWORD	dwWidth;
	DWORD	dwHeight;
};
struct Z_BUFFER_VIEW_DESC
{
	volatile LONG lLockCount;
	float*	pZBuffer;
	DWORD	dwWidth;
	DWORD	dwHeight;
};

#define FONT_INFO LOGFONT

inline DWORD GetFontInfoSize(const FONT_INFO* pFontInfo)
{
	DWORD dwLen = (DWORD)wcslen(pFontInfo->lfFaceName);
	DWORD dwSize = (DWORD)((DWORD_PTR)(void*)pFontInfo->lfFaceName - (DWORD_PTR)(void*)pFontInfo) + (DWORD)(sizeof(WCHAR) * dwLen);
	return dwSize;
}
struct TRI_MESH
{
	TRIANGLE*		pTriList;
	DWORD			dwTriNum;
};

struct POS_TUENNL_STATUS_PER_DIR
{
	int x;
	int y;
	int z;
	DWORD tunnelFlags;
};

#pragma pack(push,1)
struct BUILD_VERSION
{
	unsigned short MajorVer;
	unsigned short MinorVer;
	unsigned short Build;
	unsigned short Revision;
	unsigned short Packet_BuildNumber;	// in game_typedef.h
};
#pragma pack(pop)

enum BUILD_CHAGNED_STATUS
{
	BUILD_CHAGNED_STATUS_FIRST_INSTALLED,
	BUILD_CHAGNED_STATUS_NO_CHAGNGE,
	BUILD_CHAGNED_STATUS_UPDATED,
	BUILD_CHAGNED_STATUS_UNKNOWN
};

enum CUDA_USE_FLAGS
{
	CUDA_USE_LIGHTING = 0x00000001,
	CUDA_USE_UPDATE_TUNNEL_STATUS = 0x00000002,
	CUDA_USE_AUTO = 0x00000004
};

//
// for voxel files
//

#pragma pack(push,4)
struct STATIC_LIGHT_IN_FILE : LIGHT_DESC	// for saving light in VoxelObjectManager
{
	INT64	i64AccountSerial;
};
#pragma pack(pop)


enum NV_EXT_TYPE
{
	NV_EXT_SHFL = 1,
	NV_EXT_SHFL_UP = 3,
	NV_EXT_SHFL_DOWN = 4,
	NV_EXT_SHFL_XOR = 5,
	NV_EXT_VOTE_ALL = 6,
	NV_EXT_VOTE_ANY = 7,
	NV_EXT_VOTE_BALLOT = 8,
	NV_EXT_GET_LANE_ID = 9,
	NV_EXT_FP16_ATOMIC = 10,
	NV_EXT_FP32_ATOMIC = 11,
	NV_EXT_UINT64_ATOMIC = 12,
	NV_EXT_GET_SHADING_RATE = 13,
	NV_EXT_VPRS_EVAL_ATTRIB_AT_SAMPLE = 14,
	NV_EXT_VPRS_EVAL_ATTRIB_SNAPPED = 15
};
enum HYBRID_CORE_TYPE
{
	HYBRID_CORE_TYPE_PCORE,
	HYBRID_CORE_TYPE_ECORE,
	HYBRID_CORE_TYPE_ALL,
	HYBRID_CORE_TYPE_COUNT
};
enum HT_CORE_TYPE
{
	HT_PHYSICAL_CORE,
	HT_LOGICAL_CORE,
	HT_CORE_ANY,
	HT_CORE_TYPE_COUNT
};

struct SWOCC_PERF
{
	DWORD dwMaxThreadNum;
	DWORD dwActiveThreadNum;
	float fAvgRasterLimitedRate;
	float fAvgTestLimitedRate;
	float fAvgTestedNodesPerCall;
	float fAvgRasteredTrisPerCall;
	float fAvgTicksPerFind;
	DWORD64 AvgClocksPerFind;
	BOOL	bHybridCoreEnabled;
	HYBRID_CORE_TYPE	CoreType;
};
struct SWOCC_PERF_PER_THREAD : SWOCC_PERF
{
	DWORD	dwTestedNodesCount;
	DWORD	dwRasteredTrisCount;
	BOOL	bRasterLimited;
	BOOL	bTestLimited;
	DWORD	dwCTotalCallCount;
	PERF_DATA	ElapsedDataPerFindCall;

	void Begin()
	{
		dwTestedNodesCount = 0;
		dwRasteredTrisCount = 0;
		ElapsedDataPerFindCall = {};
	}
	void End()
	{
	}
	void Clear()
	{
		dwTestedNodesCount = 0;
		dwRasteredTrisCount = 0;
		ElapsedDataPerFindCall = {};
	}
};

struct LEAF_INFO
{
	AABB	aabb;
	DWORD	dwLeafIndex;	// 자신이 속해있는 리프의 인덱스
};
struct PVS_PURE_CELL
{
	AABB	aabb;
	DWORD	dwLeafIndex;	// 자신이 속해있는 리프의 인덱스
	DWORD	dwSubAABBIndex;	// 자신이 속해있는 리프에서의 인덱스
};

const DWORD PURE_CELL_TYPE_NUM = 2;
enum PVS_PURE_CELL_TYPE
{
	PVS_PURE_CELL_TYPE_INSIDE = 0,
	PVS_PURE_CELL_TYPE_NOT_INSIDE = 1
};

struct AABB_LIST_PER_LEAF
{
	DWORD	dwLeafIndex;
	DWORD	dwAABBNum;
	const AABB*	pAABBList;
};

struct OCCLUDEE_MESH
{
	void*	pImmutableMesh;
};
enum SPACE_PARTITION_CULLING_MODE
{
	SPACE_PARTITION_CULLING_MODE_VIEWFRUSTUM,
	SPACE_PARTITION_CULLING_MODE_PVS
};
enum VOXEL_OBJECT_CULL_TYPE
{
	VOXEL_OBJECT_CULL_TYPE_UNKNOWN,
	VOXEL_OBJECT_CULL_TYPE_SWOCC,
	VOXEL_OBJECT_CULL_TYPE_CUDA_RAYTRACING
};

typedef void* BLAS_HANDLE;

struct VOXEL_OBJ_BLAS_DESC
{
	VECTOR3	v3Pos;
	UINT	WidthDepthHeight;
	void*	pVBHandle;
	const BYTE*	pColorTable;
};

struct RT_LIGHT
{
	static const UINT RTLIGHT_TYPE_DIRECTIONAL = 0;
	static const UINT RTLIGHT_TYPE_POINT = 1;
	union
	{
		VECTOR3 Pos;
		VECTOR3 Dir;	// 빛방향 * -1
	};
	float Rs;
	COLOR3 Color;
	UINT Type;
	BOOL ShadowEnabled;
	UINT Reserved0;
	UINT Reserved1;
	UINT Reserved2;
};
const float DEFAULT_RT_DIRECTIONAL_LIGHT_X = 0.75f;
const float DEFAULT_RT_DIRECTIONAL_LIGHT_Y = 1.0f;
const float DEFAULT_RT_DIRECTIONAL_LIGHT_Z = 0.5f;
const float DEFAULT_RT_DIRECTIONAL_LIGHT_RANGE = 40000.0f;
const float MAX_RT_DIRECTIONAL_LIGHT_RANGE = 40000.0f;

const UINT MAX_RTLIGHT_NUM_IN_SCENE = 128;

struct MIDI_NOTE
{
private:
	// Control / note | On / Off(1) | velocity(7) | key(7)
	static const DWORD ON_OFF_MASK = 0b1;
	static const DWORD VELOCITY_MASK = 0b1111111;
	static const DWORD KEY_MASK = 0b1111111;
	DWORD	dwRelativeTick;
	DWORD	dwValue;
public:
	BOOL IsControl() const
	{
		BOOL bResult = (dwValue & (1 << 15)) != 0;
		return bResult;
	}
	DWORD GetRelativeTick() const
	{
		return dwRelativeTick;
	}
	void SetRelativeTick(DWORD dwTick)
	{
		dwRelativeTick = dwTick;
	}

	// as note
	void SetAsNote(BOOL bOnOff, DWORD dwTick, DWORD dwVelocity, DWORD dwKey)
	{
		dwRelativeTick = dwTick;
		dwValue = (0 << 15) | ((bOnOff & ON_OFF_MASK) << 14) | ((dwVelocity & VELOCITY_MASK) << 7) | (dwKey & KEY_MASK);
	}
	BOOL GetOnOff() const
	{
		return (BOOL)((dwValue >> 14) & ON_OFF_MASK);
	}
	DWORD GetVelocity() const
	{
		return ((dwValue >> 7) & VELOCITY_MASK);
	}
	DWORD GetKey() const
	{
		return (dwValue & KEY_MASK);
	}
	// as controller
	void SetAsControl(DWORD dwTick, DWORD dwControlValue, DWORD dwController)
	{
		dwRelativeTick = dwTick;
		dwValue = (1 << 15) | ((1 & ON_OFF_MASK) << 14) | ((dwControlValue & VELOCITY_MASK) << 7) | (dwController & KEY_MASK);
	}
	DWORD GetControlValue() const
	{
		return ((dwValue >> 7) & VELOCITY_MASK);
	}
	DWORD GetController() const
	{
		return (dwValue & KEY_MASK);
	}
};
struct MIDI_NOTE_L
{
private:
	// Control / note | On / Off(1) | velocity(7) | key(7)
	static const DWORD CONTROL_NOTE_MASK = 0b1;
	static const DWORD ON_OFF_MASK = 0b1;
	static const DWORD VELOCITY_MASK = 0b1111111;
	static const DWORD KEY_MASK = 0b1111111;
	DWORD	dwValue;
public:
	// as note
	void SetAsNote(BOOL bOnOff, DWORD dwVelocity, DWORD dwKey)
	{
		dwValue = (0 << 15) | ((bOnOff & ON_OFF_MASK) << 14) | ((dwVelocity & VELOCITY_MASK) << 7) | (dwKey & KEY_MASK);
	}
	BOOL IsControl() const
	{
		BOOL bResult = (dwValue & (1 << 15)) != 0;
		return bResult;
	}
	BOOL GetOnOff() const
	{
		return (BOOL)((dwValue >> 14) & ON_OFF_MASK);
	}
	DWORD GetVelocity() const
	{
		return ((dwValue >> 7) & VELOCITY_MASK);
	}
	DWORD GetKey() const
	{
		return (dwValue & KEY_MASK);
	}

	// as controller
	void SetAsControl(DWORD dwControlValue, DWORD dwController)
	{
		dwValue = (1 << 15) | ((1 & ON_OFF_MASK) << 14) | ((dwControlValue & VELOCITY_MASK) << 7) | (dwController & KEY_MASK);
	}
	DWORD GetControlValue() const
	{
		return ((dwValue >> 7) & VELOCITY_MASK);
	}
	DWORD GetController() const
	{
		return (dwValue & KEY_MASK);
	}

};
const DWORD MAX_NOTE_NUM_PER_BLOCK = 8;

#pragma pack(push,1)
struct TILED_TEX_MIP_SLICE_HEADER
{
	DWORD dwWidth;
	DWORD dwHeight;
	DWORD dwRowPitch;
	DWORD dwSlicePitch;
};
struct TILED_TEX_FILE_HEADER
{
	DWORD dwVersion;
	DWORD Format;
	DWORD dwMipsCount;
	DWORD pdwMipSliceOffset[32];
};

#pragma pack(pop)

const UINT MAX_INSTANCE_COUNT = 256;
struct INSTANCING_DESC
{
	DWORD	dwInstanceCount;
	DWORD	dwMaxInstanceCount;
	MATRIX4 pMatList[1];
};
inline DWORD GetInstanceDescSize(DWORD dwInstanceCount)
{
	DWORD dwSize = (DWORD)(sizeof(INSTANCING_DESC) - sizeof(MATRIX4) + sizeof(MATRIX4) * dwInstanceCount);
	return dwSize;
}
struct MESHLET
{
	DWORD dwIndexedTriNum;
	DWORD dwIndexedTriStart;
	DWORD dwIndexedVertexNum;
	DWORD dwIndexedVertexStart;
	BOUNDING_SPHERE	bs;	// shader에선 float4로 처리
};
const UINT MAX_MESHLET_NUM_PER_FACEGROUP = 256;

enum DRAW_MESHLET_BOUNDING_MESH_FLAGS
{
	DRAW_MESHLET_BOUNDING_MESH_DO_NOT_DRAW = 0x00000000,
	DRAW_MESHLET_BOUNDING_MESH_DRAW = 0x00000001,
	DRAW_MESHLET_BOUNDING_MESH_WIREFRAME = 0x00000002,
	DRAW_MESHLET_BOUNDING_MESH_HIDE_MESH = 0x00000004
};

struct GEN_MESHLET_PERF
{
	float fElapsedTickSum;
	float fElapsedTickAvg;
	float fTreeBuildElapsedTickSum;
	float fTreeBuildElapsedTickAvg;
};

struct RAYTRACING_PERF
{
	UINT64	MaxRequestedScratchMemSize;
	UINT64	ScratchResourceMemSize;
	UINT64	D3DResourceMemSize;
	UINT	BlasHeapResourceCount;
	UINT	BlasInstanceCount;
	UINT	ScratchResourceCount;
	BOOL	bUseBLASHeap;
};

struct RESOURCE_BUFFER_HEAP_INFO
{
	UINT64 ui64MemoryUsage;
	UINT uiBufferCount;
	UINT uiMaxBufferCount;
	WCHAR wchDesc[64];
};

typedef void* WEB_CLIENT_HANDLE;