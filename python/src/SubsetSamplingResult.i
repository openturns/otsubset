// SWIG file

%{
#include "otsubset/SubsetSamplingResult.hxx"
%}

%include otsubset/SubsetSamplingResult.hxx
namespace OTSubset { %extend SubsetSamplingResult { SubsetSamplingResult(const SubsetSamplingResult & other) { return new OTSubset::SubsetSamplingResult(other); } } }
