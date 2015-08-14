//                                               -*- C++ -*-
/**
 *  @file  SubsetSamplingResult.hxx
 *  @brief Subset sampling result
 *
 *  Copyright 2012-2013 Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OTSUBSET_SUBSETSAMPLINGRESULT_HXX
#define OTSUBSET_SUBSETSAMPLINGRESULT_HXX

#include "OT.hxx"
#include "OTSubsetprivate.hxx"

namespace OTSubset {

class OTSUBSET_API SubsetSamplingResult
: public OT::SimulationResultImplementation
{
  CLASSNAME;
public:
  
  /** Constructor with parameters */
  SubsetSamplingResult();

  /** Constructor with parameters */
  SubsetSamplingResult(const OT::Event & event,
                       const OT::NumericalScalar probabilityEstimate,
                       const OT::NumericalScalar varianceEstimate,
                       const OT::UnsignedInteger outerSampling,
                       const OT::UnsignedInteger blockSize,
                       const OT::NumericalScalar coefficientOfVariation = 0.0);

  /** Virtual constructor */
  virtual SubsetSamplingResult * clone() const;

  /** Coefficient of variation estimate accessor */
  virtual OT::NumericalScalar getCoefficientOfVariation() const;

  /** String converter */
  virtual OT::String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  virtual void save(OT::Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(OT::Advocate & adv);

protected:
  OT::NumericalScalar coefficientOfVariation_;

private:

} ; /* class SubsetSamplingResult */

} /* namespace OTSubset */

#endif /* OTSUBSET_SUBSETSAMPLINGRESULT_HXX */
