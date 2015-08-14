// SWIG file

%module(docstring="otsubset module") otsubset
%feature("autodoc","1");

%{
#include "OT.hxx"
#include "PythonWrappingFunctions.hxx"
%}

// Prerequisites needed
%include typemaps.i
%include exception.i
%ignore *::load(OT::Advocate & adv);
%ignore *::save(OT::Advocate & adv) const;

%import base_module.i
%import uncertainty_module.i

// The new classes
%include OTSubsetprivate.hxx
%include SubsetSampling.i
%include SubsetSamplingResult.i

