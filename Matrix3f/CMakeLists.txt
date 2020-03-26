set(target_name Matrix3f)
add_library(${target_name} SHARED)
add_library(${PROJECT_NAMESPACE}::${target_name} ALIAS ${target_name})

target_include_directories(${target_name}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(${target_name}
	PRIVATE
        src/Matrix3f.cpp
        src/Matrix3fHelpers.cpp
)

dme_install(${target_name})