#! /usr/bin/env python

# This script shows the interest of SubsetSumulation over Monte Carlo on the model G=R-S, R~N, S~N
# Taken from F. Deheeger, Couplage mecano-fiabiliste - 2SMART, 2008

from __future__ import print_function, division
from openturns import *
from math import *
from otsubset import *

TESTPREAMBLE()

def cleanScalar(inScalar) :
    if (fabs(inScalar) < 1.e-10) :
        inScalar = 0.0
    return inScalar

#########################################################################################################
# initialize the random generator
#########################################################################################################

RandomGenerator.SetSeed(0)


#########################################################################################################
# Physical model
#########################################################################################################

limitState = NumericalMathFunction(['u1', 'u2'], ['g'], ['u1-u2'])
dim = limitState.getInputDimension()

#########################################################################################################
# Probabilistic model
#########################################################################################################

mean = NumericalPoint(dim, 0.0)
mean[0] = 7.
mean[1] = 2.
sigma = NumericalPoint(dim, 1.0)

R = IdentityMatrix(dim)
myDistribution = Normal(mean, sigma, R)

start = myDistribution.getMean()

#########################################################################################################
# Limit state
#########################################################################################################

vect = RandomVector(myDistribution)

output = RandomVector(limitState, vect)

myEvent = Event(output, ComparisonOperator(Less()), 0.0)

#########################################################################################################
# Computation
#########################################################################################################
bs = 1

# Monte Carlo
myMC = MonteCarlo(myEvent)
myMC.setMaximumOuterSampling(int(1e6)// bs)
myMC.setBlockSize(bs)
myMC.setMaximumCoefficientOfVariation(-1.0)
myMC.run()

#########################################################################################################
# SubsetSampling
mySS = SubsetSampling(myEvent)
mySS.setMaximumOuterSampling(10000 // bs)
mySS.setBlockSize(bs)
mySS.run()

#########################################################################################################
# Results
#########################################################################################################

# Monte Carlo
ResultMC = myMC.getResult()
PFMC = ResultMC.getProbabilityEstimate()
CVMC = ResultMC.getCoefficientOfVariation()
Variance_PF_MC = ResultMC.getVarianceEstimate()
length90MC = ResultMC.getConfidenceLength(0.90)
N_MC = ResultMC.getOuterSampling()*ResultMC.getBlockSize()

#########################################################################################################
# SubsetSampling
ResultSS = mySS.getResult()
PFSS = ResultSS.getProbabilityEstimate()
CVSS = ResultSS.getCoefficientOfVariation()
Variance_PF_SS = ResultSS.getVarianceEstimate()
length90SS = ResultSS.getConfidenceLength(0.90)
N_SS = ResultSS.getOuterSampling()*ResultSS.getBlockSize()

#########################################################################################################

print("")
print("************************************************************************************************")
print("**************************************** MONTE CARLO *******************************************")
print("************************************************************************************************")
print("Pf estimation = %.5e" % PFMC)
print("Pf Variance estimation = %.5e" % Variance_PF_MC)
print("CoV = %.5f" % CVMC)
print("90% Confidence Interval =" , "%.5e" % length90MC)
print("CI at 90% =[", "%.5e" % (PFMC-0.5*length90MC) , "; %.5e" % (PFMC+0.5*length90MC) , "]")
print("Limit state calls =", N_MC)
print("************************************************************************************************")
print("")
print("************************************************************************************************")
print("******************************************* SUBSET SAMPLING **********************************************")
print("************************************************************************************************")
print("Pf estimation = %.5e" % PFSS)
print("Pf Variance estimation = %.5e" % Variance_PF_SS)
print("CoV = %.5f" % CVSS)
print("90% Confidence Interval =", "%.5e" % length90SS)
print("CI at 90% =[", "%.5e" % (PFSS-0.5*length90SS) , "; %.5e" % (PFSS+0.5*length90SS) , "]")
print("Limit state calls =", N_SS)
print("************************************************************************************************")
print("")
