
find_package ( LATEX )
set ( IMAGEMAGICK_CONVERT convert )
set ( LATEX2HTML_CONVERTER latex2html )
include ( UseLATEX )

# latex part 
if ( PDFLATEX_COMPILER AND BIBTEX_COMPILER )

  if ( ${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} )
    # in-source build
    set ( LATEX_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build )
#     execute_process (
#       COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/src/logoOpenTURNS.jpg ${CMAKE_CURRENT_SOURCE_DIR}/logoOpenTURNS.jpg
#     )  
  else ()
    # out-of-source build
    set ( LATEX_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR} )
  endif ()
  add_latex_document ( OTSubset_Documentation.tex
    INPUTS GenericInformation.tex.in OTSubset_summary.tex OTSubset_UserManual.tex Math_Notations.sty OTSubset_ExamplesGuide.tex OTSubset_UseCasesGuide.tex OTSubset_title.tex OTSubset_Documentation.sty OTSubset_ReferenceGuide.tex OTSubset_Validation.tex OTSubset_ArchitectureGuide.tex
    IMAGES architecture.png capacity_and_demand_subset_sampling_1.pdf
    DEFAULT_PDF
    MANGLE_TARGET_NAMES
  ) 

  configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/GenericInformation.tex.in 
                  ${LATEX_OUTPUT_PATH}/GenericInformation.tex
                  @ONLY
  )
  
#   execute_process (
#     COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/latex2html/latex2html.sty ${LATEX_OUTPUT_PATH}/latex2html.sty
#     COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/src/Math_Notations.sty ${LATEX_OUTPUT_PATH}/Math_Notations.sty
#     COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/src/GenericInformation.tex ${LATEX_OUTPUT_PATH}/GenericInformation.tex
#   )     
  install ( FILES ${LATEX_OUTPUT_PATH}/OTSubset_Documentation.pdf DESTINATION ${DOC_INSTALL_PATH}/pdf )

endif ()
