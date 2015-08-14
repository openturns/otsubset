// SWIG file

%{
#include "SubsetSamplingResult.hxx"
%}

%include SubsetSamplingResult.hxx
namespace OTSubset { %extend SubsetSamplingResult { SubsetSamplingResult(const SubsetSamplingResult & other) { return new OTSubset::SubsetSamplingResult(other); } } }
