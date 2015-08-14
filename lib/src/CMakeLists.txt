

ot_add_current_dir_to_include_dirs ()

ot_add_source_file ( SubsetSampling.cxx )
ot_add_source_file ( SubsetSamplingResult.cxx )

ot_install_header_file ( SubsetSampling.hxx )
ot_install_header_file ( SubsetSamplingResult.hxx )


include_directories ( ${INTERNAL_INCLUDE_DIRS} )

add_library ( otsubset ${SOURCEFILES} )
if ( BUILD_SHARED_LIBS )
  set_target_properties ( otsubset PROPERTIES COMPILE_DEFINITIONS "OTSUBSET_DLL_EXPORTS" )
endif ()

if ( NOT DEFINED LIB_VERSION ) 
  set ( LIB_VERSION 0.0.0 )
endif ()
if ( NOT DEFINED LIB_SOVERSION ) 
  set ( LIB_SOVERSION 0 )
endif ()
set_target_properties ( otsubset PROPERTIES VERSION ${LIB_VERSION} )
set_target_properties ( otsubset PROPERTIES SOVERSION ${LIB_SOVERSION} )
target_link_libraries (otsubset ${OPENTURNS_LIBRARY})

# Add targets to the build-tree export set
export (TARGETS otsubset FILE ${PROJECT_BINARY_DIR}/OTSubset-Targets.cmake)

# Install the export set for use with the install-tree
install(EXPORT OTSubset-Targets
        DESTINATION "${OTSUBSET_CONFIG_CMAKE_PATH}"
        COMPONENT Development)

install(TARGETS otsubset
        EXPORT  OTSubset-Targets 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${OTSUBSET_LIBRARY_PATH}
        ARCHIVE DESTINATION ${OTSUBSET_LIBRARY_PATH}
)

