set(target_name Quaternion)
add_library(${target_name} SHARED)
add_library(${PROJECT_NAMESPACE}::${target_name} ALIAS ${target_name})

target_include_directories(${target_name}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(${target_name}
	PRIVATE
		src/Quaternion.cpp
)

target_link_libraries(${target_name}
    PUBLIC
        MATH::Vector3f
)

dme_install(${target_name})