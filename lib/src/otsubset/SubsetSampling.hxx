//                                               -*- C++ -*-
/**
 *  @brief Subset simulation method
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
#ifndef OTSUBSET_SUBSETSAMPLING_HXX
#define OTSUBSET_SUBSETSAMPLING_HXX

#include <Simulation.hxx>
#include <StandardEvent.hxx>
#include "otsubset/OTSubsetprivate.hxx"

namespace OTSubset {

class OTSUBSET_API SubsetSampling
: public OT::Simulation
{
CLASSNAME
public:

  /** Default Parameters */
  static const OT::UnsignedInteger DefaultMaximumOuterSampling;
  static const OT::NumericalScalar DefaultProposalRange;
  static const OT::NumericalScalar DefaultTargetProbability;
  static const OT::NumericalScalar DefaultBetaMin;

  /** Default Constructor */
  SubsetSampling();

  /** Constructor with parameters */
  SubsetSampling(const OT::Event & event,
                 const OT::NumericalScalar proposalRange = DefaultProposalRange,
                 const OT::NumericalScalar targetProbability = DefaultTargetProbability);

  /** Virtual constructor */
  virtual SubsetSampling * clone() const;

  /** The range of the uniform proposal pdf */
  void setProposalRange(OT::NumericalScalar proposalRange);
  OT::NumericalScalar getProposalRange() const;

  /** Ratio parameter */
  void setTargetProbability(OT::NumericalScalar targetProbability);
  OT::NumericalScalar getTargetProbability() const;
  
  /** Accessor to the achieved number of steps */
  OT::UnsignedInteger getNumberOfSteps();
  
  /** @DEPRECATED Accessor to the intermediate thresholds */
  OT::NumericalPoint getThresholds() const;
  
  /** Stepwise result accessors */
  OT::NumericalPoint getThresholdPerStep() const;
  OT::NumericalPoint getGammaPerStep() const;
  OT::NumericalPoint getCoefficientOfVariationPerStep() const;
  OT::NumericalPoint getProbabilityEstimatePerStep() const;
  
  /** Keep event sample */
  void setKeepEventSample(bool keepEventSample);
  
  /** Event input/output sample accessor */
  OT::NumericalSample getEventInputSample() const;
  OT::NumericalSample getEventOutputSample() const;

  /** i-subset */
  void setISubset(OT::Bool iSubset);
  void setBetaMin(OT::NumericalScalar betaMin);
  
  /** Performs the actual computation. */
  void run();

  /** String converter */
  OT::String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  virtual void save(OT::Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(OT::Advocate & adv);

private:
  /** Compute the block sample */
  OT::NumericalSample computeBlockSample();

  /** Compute the new threshold corresponding to the target failure probability */
  OT::NumericalScalar computeThreshold();

  /** compute probability estimate on the current sample */
  OT::NumericalScalar computeProbability(OT::NumericalScalar probabilityEstimate, OT::NumericalScalar threshold);

  /** Sort new seeds */
  void initializeSeed(OT::NumericalScalar threshold);
  
  /** Compute the correlation on markov chains at the current state of the algorithm */
  OT::NumericalScalar computeVarianceGamma(OT::NumericalScalar currentFailureProbability, OT::NumericalScalar threshold);

  /** Generate new points in the conditional failure domain */
  void generatePoints(OT::NumericalScalar threshold);

  // some parameters
  OT::NumericalScalar proposalRange_;// width of the proposal pdf
  OT::NumericalScalar targetProbability_;// target probability at each subset
  OT::Bool iSubset_;// conditional pre-sampling
  OT::NumericalScalar betaMin_;// pre-sampling hypersphere exclusion radius
  OT::Bool keepEventSample_;// do we keep the event sample ?

  // some results
  OT::UnsignedInteger numberOfSteps_;// number of subset steps
  OT::NumericalPoint thresholdPerStep_;// intermediate thresholds
  OT::NumericalPoint gammaPerStep_;// intermediate gammas
  OT::NumericalPoint coefficientOfVariationPerStep_;// intermediate COVS
  OT::NumericalPoint probabilityEstimatePerStep_;// intermediate PFs
  OT::NumericalSample eventInputSample_;// event input sample
  OT::NumericalSample eventOutputSample_;// event output sample

  // attributes used for conveniency, not to be saved/loaded
  OT::StandardEvent standardEvent_;// the algorithm happens in U
  OT::UnsignedInteger dimension_;// input dimension
  OT::NumericalSample currentPointSample_;// X
  OT::NumericalSample currentLevelSample_;//f(X)

} ; /* class SubsetSampling */

} /* namespace OTSubset */

#endif /* OTSUBSET_SUBSETSAMPLING_HXX */
