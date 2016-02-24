// SWIG file

%{
#include "otsubset/SubsetSampling.hxx"
%}

%include otsubset/SubsetSampling.hxx
namespace OTSubset { %extend SubsetSampling { SubsetSampling(const SubsetSampling & other) { return new OTSubset::SubsetSampling(other); } } }
