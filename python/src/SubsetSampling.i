// SWIG file

%{
#include "SubsetSampling.hxx"
%}

%include SubsetSampling.hxx
namespace OTSubset { %extend SubsetSampling { SubsetSampling(const SubsetSampling & other) { return new OTSubset::SubsetSampling(other); } } }
