#
# Build PxTask
#

SET(GW_DEPS_ROOT $ENV{GW_DEPS_ROOT})

SET(PXSHARED_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../../src)

SET(LL_SOURCE_DIR ${PXSHARED_SOURCE_DIR}/task)

SET(PXTASK_COMPILE_DEFS 
	${PXSHARED_WINDOWS_COMPILE_DEFS};_LIB
	
	$<$<CONFIG:debug>:${PXSHARED_WINDOWS_DEBUG_COMPILE_DEFS};>
	$<$<CONFIG:checked>:${PXSHARED_WINDOWS_CHECKED_COMPILE_DEFS};>
	$<$<CONFIG:profile>:${PXSHARED_WINDOWS_PROFILE_COMPILE_DEFS};>
	$<$<CONFIG:release>:${PXSHARED_WINDOWS_RELEASE_COMPILE_DEFS};>
)

# include PxTask common
INCLUDE(../common/PxTask.cmake)
